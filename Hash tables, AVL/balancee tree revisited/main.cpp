#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

vector<int> numbers;
list<int> table[4001];
vector<int> result;

int hash_func(int num){
    string str;
    str = to_string(num);
    int sum = 0;
    for (int i = 0; i < str.size(); i++)
        sum = (num + i + i^2) % 4001;
    return sum;
}

void push(int num, list<int> *table){
    int key = hash_func(num);
    auto list = find(table[key].begin(), table[key].end(), num);
    if (list == table[key].end()) table[key].push_back(num);
}

void pop(int num, list<int> *table){
    int index = hash_func(num);

    list<int>::iterator list;
    for (list = table[index].begin(); list != table[index].end(); list++)
        if (*list == num) break;

    if (list != table[index].end())
        table[index].erase(list);
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int number;
    while (fin >> number){
        numbers.push_back(number);
    }

    for (int i = 0; i < numbers.size(); i++){
        if (numbers[i] > 0) push(numbers[i], table);
        if (numbers[i] < 0) pop(-numbers[i], table);
        if (numbers[i] == 0) break;
    }

    for (int i = 0; i < 4001; i++) {
        for (auto element : table[i])
            result.push_back(element);
    }

    sort(result.begin(), result.end());
    for (int i : result) fout << i << ' ';
}