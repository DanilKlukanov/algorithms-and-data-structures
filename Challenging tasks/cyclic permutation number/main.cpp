#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int ascii_mass[128] = {0};
vector<int> class_equality;
vector<pair<pair<int, int>, int>> classes_and_index;

void count_sort(string str){;
    for (int i = 0; i < str.size(); i++)
        ascii_mass[str[i] + 1]++;

    int ind = 0;
    for (int i = 0; i < 128; i++, ind++) {
        if (ascii_mass[i] != 0) ascii_mass[i] = ind;
    }

    for (int i = 0; i < str.size(); i++)
        class_equality[i] = ascii_mass[str[i] + 1];
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string str;
    fin >> str;
    class_equality.resize(str.size());
    count_sort(str);

    int k = 2;
    for (int i = k / 2; i < str.size(); i *= 2) {
        classes_and_index.clear();
        for (int j = 0; j < str.size(); j++) {
            classes_and_index.emplace_back(make_pair(class_equality[j], class_equality[(j + i) % str.size()]), j);
        }
        sort(classes_and_index.begin(), classes_and_index.end());

        int ind = 0;
        for (int f = 0; f < classes_and_index.size(); f++) {
            if (f == 0) class_equality[classes_and_index[f].second] = 0;
            if (classes_and_index[f].first.first == classes_and_index[f - 1].first.first && classes_and_index[f].first.second == classes_and_index[f - 1].first.second)
                ind -= 1;
            class_equality[classes_and_index[f].second] = ind;
            ind += 1;
        }
    }

    int res = 0;
    for (int i = 0; i < classes_and_index.size(); i++) {
        if (i > 0 && classes_and_index[i].first.first == classes_and_index[i - 1].first.first &&
                classes_and_index[i].first.second == classes_and_index[i - 1].first.second)
            continue;
        else {
            if (classes_and_index[i].second == 0)
                fout << res;
            res++;
        }
    }
    if (res == 0) fout << res;
}