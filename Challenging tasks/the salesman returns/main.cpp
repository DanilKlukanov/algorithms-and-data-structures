#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#define maxi 12345678
using namespace std;

int N;
vector<vector<int>> a;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> N;
    int dp[1 << N][N];
    int mini = maxi;
    int **coordinates = new int *[N];
    for (int i = 0 ; i < N; i++)
        coordinates[i] = new int[N];

    int num;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            fin >> num;
            coordinates[i][j] = num;
        }
    }

    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = maxi;
        }
    }

    for (int i = 0; i < N; i++) {
        dp[1 << i][i] = 0;
    }

    for (int mask = 0; mask < (1 << (N)); mask++) {
        for (int i = 0; i < N; i++) {
            if (dp[mask][i] == maxi)
                continue;
            for (int j = 0; j < N; j++) {
                if (!(mask & (1 << j)) && coordinates[i][j] != -1)
                    dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + coordinates[i][j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (dp[(1 << N) - 1][i] < mini)
            mini = dp[(1 << N) - 1][i];
    }

    fout << mini;
}