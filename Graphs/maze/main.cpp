#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#define infi 1234
using namespace std;

int N, xf, yf, xt, yt;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<pair<int, int>> start_finish;

void BFS(bool *used[], int *support[]){
    queue<pair<int, int>> q;
    q.push(start_finish[0]);
    used[start_finish[0].first][start_finish[0].second] = 1;
    support[start_finish[0].first][start_finish[0].second] = 0;
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (!used[v.first + dy[i]][v.second + dx[i]]) {
                support[v.first + dy[i]][v.second + dx[i]] = support[v.first][v.second] + 1;
                used[v.first + dy[i]][v.second + dx[i]] = true;
                q.push(make_pair(v.first + dy[i], v.second + dx[i]));
            }
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> N >> xf >> yf >> xt >> yt;

    start_finish.push_back(make_pair(yf, xf));
    start_finish.push_back(make_pair(yt, xt));

    char **board = new char *[N + 2];
    bool **used = new bool *[N + 2];
    int **support = new int *[N + 2];
    for (int i = 0; i < N + 2; i++) {
        board[i] = new char[N + 2];
        used[i] = new bool[N + 2]{false};
        support[i] = new int[N + 2];
    }

    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < N + 2; j++) {
            if (i > 0 && i < N + 1 && j > 0 && j < N + 1){
                fin >> board[i][j];
            }
            else {
                board[i][j] = '#';
            }
            if (board[i][j] == '#')
                used[i][j] = true;
            support[i][j] = infi;
        }
    }
    BFS(used, support);
    fout << support[start_finish[1].first][start_finish[1].second];
}