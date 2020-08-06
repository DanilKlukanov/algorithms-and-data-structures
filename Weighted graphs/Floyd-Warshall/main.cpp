#include <fstream>
#include <vector>
#define infi 111111
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, M, ai, bi, ci;
    fin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, infi));

    for (int i = 1; i <= N; i++)
        graph[i][i] = 0;

    for (int i = 1; i <= M; i++){
        fin >> ai >> bi >> ci;
        graph[ai][bi] = ci;
    }

    //Флойд
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            for (int k = 1; k <= N; k++){
                if (graph[j][i] < infi && graph[i][k] < infi)
                    graph[j][k] = min(graph[j][i] + graph[i][k], graph[j][k]);
            }
        }
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++)
            if (graph[i][j] != infi)
                fout << graph[i][j] << " ";
        fout << endl;
    }
}