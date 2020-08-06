#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comporator (pair<int, int> a, pair<int, int> b){
    return (a.second < b.second);
}

void SIFTUP(int i, vector<pair<int, int>> &vct){
    if (i > 0){
        int par_i = (i - 1) / 2;
        if (vct[par_i] > vct[i]){
            swap(vct[par_i], vct[i]);
            SIFTUP(par_i, vct);
        }
    }
}

void SIFTDOWN(int i, vector<pair<int, int>> &vct){
    int levo = 2 * i + 1;
    int pravo = 2 * i + 2;
    int larger_el = i;

    if (levo < vct.size() && vct[levo] < vct[larger_el])
        larger_el = levo;
    if (pravo < vct.size() && vct[pravo] < vct[larger_el])
        larger_el = pravo;
    if (larger_el != i){
        swap(vct[i], vct[larger_el]);
        SIFTDOWN(larger_el, vct);
    }
}

int MIN_POP (vector<pair<int, int>> &vct){
    int minimum = vct[0].first;
    swap(vct[0], vct[vct.size() - 1]);
    vct.pop_back();
    SIFTDOWN(0, vct);
    return minimum;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int elements, n, m;
    fin >> n >> m;
    vector<pair<int, int>> vct;

    for (int i = 0; i < n; i++) {
        fin >> elements;
        vct.push_back(make_pair(elements, i));
        SIFTUP(i, vct);
    }

    for (int i = 0; i < m; i++) {
        vct.push_back(make_pair(MIN_POP(vct) + MIN_POP(vct), n + i));
    }

    sort(vct.begin(), vct.end(), comporator);

    for (auto i = vct.begin(); i != vct.end(); i++) {
        fout << i->first << " ";
    }
}