#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> best_positions(25);
vector<string> positions(25);
int count = 0, best_moves = 0;
int row[4] = {1, -1, 1, -1};
int col[4] = {1, 1, -1, -1};

void long_take_permu(char **fie, int x, int y, int h = 0) {
    for (int i = 0; i < 4; i++){
        if (fie[x + row[i]][y + col[i]] == 'O') {
            fie[x + row[i]][y + col[i]] = '.';
            positions[h] = char(y + 95) + to_string(x - 1);
            long_take_permu(fie, x + 2 * row[i], y + 2 * col[i], h + 1);
            fie[x + row[i]][y + col[i]] = 'O';
        }
    }
    if (h > best_moves) {
        best_positions = positions;
        best_moves = h;
        count = h;
        best_positions.push_back(char(y + 95) + to_string(x - 1));
        return;
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;

    char **board = new char *[N + 4];
    for (int i = 0; i < N + 4; i++)
        board[i] = new char[N + 4];

    char ch;
    for (int i = N + 1; i >= 2; i--) {
        for (int j = 2; j < N + 2; j++) {
            fin >> ch;
            board[i][j] = ch;
        }
    }

    for (int i = N + 1; i >= 2; i--) {
        for (int j = 2; j < N + 2; j++) {
            if (board[i][j] == 'X') {
                long_take_permu(board, i, j);
            }
        }
    }

    if (count == 0)
        fout << "Impossible";
    else{
        for (int i = 0; i < best_positions.size(); i++){
            if (best_positions[i].empty() == false) {
                fout << best_positions[i];
                if (i != best_positions.size() - 1)
                    fout << '-';
            }
        }
    }
}





















