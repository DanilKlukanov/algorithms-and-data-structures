#include <fstream>
#include <vector>
using namespace std;

bool used[100001]{false};
vector<int> graph[100001];
vector<int> suport;

void DFS(int v){
    used[v] = true;
    for (int i = 0; i < graph[v].size(); i++){
        int to = graph[v][i];
        if (!used[to])
            DFS(to);
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, M, ai, aj;
    fin >> N >> M;

    for (int i = 0; i < M; i++){
        fin >> ai >> aj;
        graph[ai].push_back(aj);
        graph[aj].push_back(ai);
    }

    for (int i = 1; i <= N; ++i){
        if (!used[i]){
            DFS(i);
            suport.push_back(i);
        }
    }
    fout << suport.size();
}