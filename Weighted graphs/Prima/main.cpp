#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <set>
#include <numeric>
#define infi 111111
using namespace std;

int N, M, S, ai, bi, ci;
vector<vector<pair<int, int>>> graph(100001);
set<pair<int, int>> fluck;

void dfs(vector<vector<pair<int, int>>> &graph, vector<bool> &visited, int v) {
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); i++)
        if (!visited[graph[v][i].first])
            dfs(graph, visited, graph[v][i].first);
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> N >> M;
    vector<int> dp(N + 1, infi);

    //заполнение массива
    for (int i = 1; i <= M; i++){
        fin >> ai >> bi >> ci;
        graph[ai].emplace_back(make_pair(bi, ci));
        graph[bi].emplace_back(make_pair(ai, ci));
    }
    //

    //проверка на то, что граф связный
    vector<bool> visited(N + 1, false);
    dfs(graph, visited, 1);
    for (int i = 1; i < visited.size(); i++)
        if (!visited[i]) {
            fout << -1;
            return 0;
        }
    //

    //алгоритм Прима
    dp[1] = 0;
    fluck.insert(make_pair(0, 1));
    vector<bool> Visited(N + 1, false);
    while (!fluck.empty()) {
        int v = fluck.begin()->second;
        fluck.erase(fluck.begin());
        for (auto peaks: graph[v]) {
            if (!Visited[peaks.first] && peaks.second < dp[peaks.first]) {
                fluck.erase(make_pair(dp[peaks.first], peaks.first));
                dp[peaks.first] = peaks.second;
                fluck.insert(make_pair(dp[peaks.first], peaks.first));
            }
        }
        Visited[v] = true;
    }
    fout << accumulate(dp.begin() + 1, dp.end(), 0);
}