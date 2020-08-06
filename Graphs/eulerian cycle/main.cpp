#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ai, bi, fluck = 0;
vector<int> graph[100001];
vector<int> support;

void dfs(int v = 1) {
    for (int i = 0; i < graph[v].size(); i++) {
        int top = graph[v][i];
        graph[v].erase(graph[v].begin() + i);
        graph[top].erase(find(graph[top].begin(), graph[top].end(), v));
        dfs(top);
    }
    support.push_back(v);
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> N >> M;

    for (int i = 0; i < M; i++){
        fin >> ai >> bi;
        graph[ai].push_back(bi);
        graph[bi].push_back(ai);
    }

    for (int i = 1; i <= N; i++){
        if (graph[i].size() % 2 == 1) {
            fluck = -1;
        }
    }
    if (fluck == -1)
        fout << fluck;
    else{
        dfs();
        for (int i = 0; i < support.size(); i++)
            fout << support[i] << ' ';
    }
}