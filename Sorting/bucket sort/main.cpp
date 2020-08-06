#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
vector<int> sup_mass(256);
vector<string> new_mass;

void bucketSort(vector<string> &mass, int n, int k){
    for (int i = 0; i < 256; i++)
        sup_mass[i] = 0;

    //берем букву и ставим ее на позиции массива равной ее acsii коду, увеличиваем не единицу
    for (int i = 0; i < n; i++) {
        if (k < mass[i].size()) {
            sup_mass[mass[i][k] + 1] = sup_mass[mass[i][k] + 1] + 1;
        }
    }

    //приобвляем единицу, чтобы мы смогли понять на какое местов ставить слово
    for (int i = 1; i < 256; i++){
        sup_mass[i] += sup_mass[i - 1];
    }

    //расставляем слова в порядке возрастания
    for (int i = n - 1; i >= 0; i--) {
        if (k < mass[i].size()){
            new_mass[sup_mass[mass[i][k] + 1] - 1] = mass[i];
            sup_mass[mass[i][k] + 1] = sup_mass[mass[i][k] + 1] - 1;
        }
    }

    for(int i = 0; i < n; i++){
        mass[i] = new_mass[i];
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;
    vector<string> mass;
    new_mass.resize(n);
    string word;
    for (int i = 0; i < n; i++) {
        fin >> word;
        mass.push_back(word);
    }

    for (int digit = mass[0].size(); digit > 0; digit--){
        bucketSort(mass, n, digit - 1);
    }

    for (int i = 0; i < n; i++){
        fout << mass[i] << endl;
    }
}