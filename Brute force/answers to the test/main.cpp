#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<int> enums;
vector<string> reply;
vector<char> all_repeat;
vector<vector<char>> rejoin;
void P_R(string signs, int n, int k, int h = 0) {
    if (h == k) {
        for (int i = 0; i < reply.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < k; j++) {
                reply[i][j] == all_repeat[j] ? cnt++: cnt;
            }
            if (i == reply.size() - 1 && cnt == enums[i])
                rejoin.push_back(all_repeat);
            else if (cnt != enums[i])
                return;
        }
    } else {
        for (int i = 0; i < n; i++) {
            all_repeat.push_back(signs[i]);
            P_R(signs, n, k, h + 1);
            all_repeat.pop_back();
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int P, Q;
    int c;
    string a, signs = "+-";

    fin >> P >> Q;

    for (int i = 0; i < P; i++) {
        fin >> a;
        reply.push_back(a);
        fin >> c;
        enums.push_back(c);
    }

    P_R(signs, 2, Q);
    for (int i = 0; i < Q; i++) {
            fout << rejoin[0][i];
    }
}