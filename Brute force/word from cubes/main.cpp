#include <iostream>
#include <fstream>
#include <vector>
#include <string>
std::ofstream fout("output.txt");
using namespace std;

int N;
string word, kubik;
bool Bool[12] = {false};
vector<string> kubiki;
int number_order[12];
int result[12];
bool O = false;

void gen_permu(int n, int h = 0){
    if (n == h){
        for (int i = 0; i < n; i++){
            fout << number_order[i] << " ";
        }
        exit(0);
    }
    else{
        for (int i = 0; i < N; i++){
            if (Bool[i] == !true){
                if (kubiki[i].find(word[h]) != -1) {
                    number_order[h] = i + 1;
                    Bool[i] = true;
                    gen_permu(n, h + 1);
                    Bool[i] = false;
                }
            }
        }
    }
}

int main() {
    ifstream fin("input.txt");

    fin >> N;
    fin >> word;
    int len = word.size();

    for (int i = 0; i < N; i++){
        fin >> kubik;
        kubiki.push_back(kubik);
    }
    gen_permu(len);

    if (O == false)
        fout << 0;
}