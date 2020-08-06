#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#define modul 1000000007
using namespace std;

vector<long long> calc_fac(int n){
    vector<long long> res(n + 1);
    for (int i = 2; i <= n; i++){
        int a = i;
        for (int j = 2; j <= sqrt(a); j++){
            while (a % j == 0){
                res[j]++;
                a /= j;
            }
        }
        res[a]++;
    }
    return res;
}

vector <long long> count (int partial, vector<long long> support){
    auto dividend = calc_fac(partial);
    for (int i = 0; i < support.size(); i++){
        if (dividend.size() > i)
           support[i] = support[i] - dividend[i];
    }
    return support;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int xm, ym, zm, xb, yb, zb;
    long long res1 = 1;
    fin >> xm >> ym >> zm >> xb >> yb >> zb;

    vector<long long>  n_m_k = calc_fac(abs(xb - xm) + abs(yb - ym) + abs(zb - zm));
    vector<long long> n_m_k_n = count(abs(xb - xm), n_m_k);
    vector<long long> n_m_k_m = count(abs(yb - ym), n_m_k_n);
    vector<long long> n_m_k_k = count(abs(zb - zm), n_m_k_m);

    for (int i = 0; i < n_m_k_k.size(); i++){
        if (n_m_k_k[i] != 0){
            long long po = pow(i, n_m_k_k[i]);
            long long po1 = res1 % modul;
            res1 = (po % modul) * po1;
            res1 = res1 % modul;
        }
    }
    fout << res1 % modul;
}