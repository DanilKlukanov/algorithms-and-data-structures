#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

int N, M, ai, bi;
vector<int> graph[100001];
set<int> f;
bool used[100001];
int timer, t_in[100001], f_up[100001];

void dfs(int v, int p = -1){
    used[v] = true;
    t_in[v] = f_up[v] = timer++;
    int children = 0;

    for (size_t i = 0; i < graph[v].size(); ++i) {
        int to = graph[v][i];

        if (used[to])
            f_up[v] = min(f_up[v], t_in[to]);

        else {
            dfs (to, v);
            f_up[v] = min(f_up[v], f_up[to]);

            if (f_up[to] >= t_in[v] && p != -1)
                f.insert(v);
            children++;
        }
    }
    if (p == -1 && children > 1)
        f.insert(v);
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> N >> M;

    for (int i = 0; i < M; i++){
        fin >> ai >> bi;
        graph[ai].push_back(bi);
        graph[bi].push_back(ai);
    }
    timer = 0;
    for (int i = 1; i <= N; ++i)
        used[i] = false;
    dfs (1);

    fout << f.size() << " ";
    copy( f.begin(), f.end(), ostream_iterator<int>(fout, " "));
}