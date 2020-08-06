#include <iostream>

using namespace std;
int res[10];
bool us[10];

void permu(int n, int h = 0) {
    if (h == n) {
        for (int i = 0; i < n; i++)
            cout << res[i] << ' ';
        cout << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            if (!us[i]) {
                us[i] = true;
                res[h] = i;
                permu(n, h + 1);
                us[i] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    permu(n);
}