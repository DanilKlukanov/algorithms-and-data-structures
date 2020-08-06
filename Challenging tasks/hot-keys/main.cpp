#include <fstream>
#include <vector>
#include <string>
#define F 11;
using namespace std;

vector<bool> Bool(27);
vector<int> ind(10);
vector<int> last;

int sum(vector<int> &mass) {
    int summ = 0;
    for (int i = 0; i < mass.size(); i++)
        summ += mass[i];
    return summ;
}

void hot_keys(vector<string> &words, int n, int h = 0) {
    if (h == n) {
        if (sum(ind) < sum(last))
            last = ind;
        return;
    } else {
        for (int i = 0; i < words[h].size(); i++) {
            if (!Bool[words[h][i] - 'a' + 1]) {
                Bool[words[h][i] - 'a' + 1] = true;
                ind[h] = i;
                if (sum(ind) < sum(last))
                    hot_keys(words, n, h + 1);
                Bool[words[h][i] - 'a' + 1] = false;
            }
            if (i == words[h].size() - 1) {
                ind[h] = F;
                hot_keys(words, n, h + 1);
                ind[h] = -1;
            }
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    vector<string> words;
    fin >> N;

    string str;
    for (int i = 0; i < N; i++) {
        last.push_back(13);
        fin >> str;
        words.push_back(str);
    }

    hot_keys(words, N);

    for (int i = 0; i < N; i++) {
        if (last[i] != 11) {
            words[i].insert(last[i], "&");
            fout << words[i];
        } else
            fout << words[i];
        fout << endl;
    }
}