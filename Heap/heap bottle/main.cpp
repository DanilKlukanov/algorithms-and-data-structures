#include <fstream>
#include <vector>
using namespace std;

class HEAP {
    vector<long long> heap_mass;
    int heapS = 0;

    void SIFTUP(int i) {
        if (i > 0) {
            int parent_i = (i - 1) / 2;
            if (heap_mass[parent_i] < heap_mass[i]) {
                swap(heap_mass[parent_i], heap_mass[i]);
                SIFTUP(parent_i);
            }
        }
    }

    void SIFTDOWN(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int ind_i = i;

        if (left < heapS && heap_mass[left] > heap_mass[i])
            ind_i = left;
        if (right < heapS && heap_mass[right] > heap_mass[ind_i])
            ind_i = right;
        if (ind_i != i) {
            swap(heap_mass[i], heap_mass[ind_i]);
            SIFTDOWN(ind_i);
        }
    }

public:
    void INSERT(int key) {
        heap_mass.push_back(key);
        heapS = heapS + 1;
        SIFTUP(heapS - 1);
    }

    int max() {
        long long maxim = heap_mass[0];
        swap(heap_mass[0], heap_mass[heapS - 1]);
        heapS--;
        heap_mass.pop_back();
        SIFTDOWN(0);
        return maxim;
    }

    long long sum_count() {
        long long sum = 0;
        for (int i = 0; i < heapS; i++)
            sum += heap_mass[i];
        return sum;
    }
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;
    long long elements;

    HEAP mass;

    for (int i = 0; i < n; i++) {
        fin >> elements;
        mass.INSERT(elements);
    }

    for (int i = 0; i < m; i++) {
        mass.INSERT(mass.max() / 10);
    }

    fout << mass.sum_count();
}