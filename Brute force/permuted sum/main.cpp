#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
string a, b, c, re = "NO", p;
int w;

void permu(string a, int n, int h = 0){
    if (h == n) {
        if ((a[0] != '0')) {
            int q = atoi(c.c_str()) - atoi(a.c_str());
            string z = to_string(q);
            sort(z.begin(), z.end());
            sort(b.begin(), b.end());
            if (z == b) {
                re = "YES";
                w = q;
                p = a;
            }
        }
    }
    else {
        for (int i = h; i < n; i++){
            swap(a[h], a[i]);
            permu(a, n, h + 1);
            swap(a[h], a[i]);
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> a >> b >> c;
    permu(a, a.length());
    if (re == "YES") {
        fout << re << endl;
        fout << p << ' ' << w;
    } else
        fout << re;
}