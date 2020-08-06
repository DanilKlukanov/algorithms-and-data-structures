#include <fstream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> graph[100001];
int color[100001]{0};
vector<int> support;
int N, M, ai, bi;

void topologic_sort(int v) {
    color[v] = 1;
    for (int i = 0; i < graph[v].size(); i++) {
        if (color[graph[v][i]] == 0)
            topologic_sort(graph[v][i]);
        if (color[graph[v][i]] == 1){
            fout << "-1";
            exit(0);
        }
    }
    color[v] = 2;
    support.push_back(v);
}

int main() {
    fin >> N >> M;

    for (int i = 0; i < M; i++) {
        fin >> ai >> bi;
        graph[ai].push_back(bi);
    }

    for (int i = 1; i <= N; i++) {
        if (color[i] == 0)
            topologic_sort(i);
    }

    for (int i = support.size() - 1; i >= 0; i--)
        fout << support[i] << " ";
}