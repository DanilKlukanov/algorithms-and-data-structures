#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <set>
#define infi 111111
using namespace std;

int N, M, S, ai, bi, ci;
vector<vector<pair<int, int>>> graph(100001);
set<pair<int, int>> fluck;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> N >> M >> S;
    vector<int> dp(N + 1, infi);

    for (int i = 1; i <= M; i++){
        fin >> ai >> bi >> ci;
        graph[ai].emplace_back(make_pair(bi, ci));
    }
    dp[S] = 0;
    fluck.insert(make_pair(0, S));

    while(!fluck.empty()){

        int i = fluck.begin()->second;
        fluck.erase(fluck.begin());

        for (auto peaks: graph[i]){
            if (dp[i] + peaks.second < dp[peaks.first]){
                fluck.erase(make_pair(dp[peaks.first], peaks.first));
                dp[peaks.first] = dp[i] + peaks.second;
                fluck.insert(make_pair(dp[peaks.first], peaks.first));
            }
        }
    }
    for (int i = 1; i < dp.size(); i++)
        if (dp[i] == infi) dp[i] = -1;

    for (int i = 1; i < dp.size(); i++)
        fout << dp[i] << ' ';
}