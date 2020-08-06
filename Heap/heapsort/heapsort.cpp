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

public:
    void INSERT(int key) {
        heap_mass.push_back(key);
        heapS = heapS + 1;
        SIFTUP(heapS - 1);
    }

    vector<int> print_mass(){
        vector<int> new_heap;
        for (int i = 0; i < heapS; i++)
            new_heap.push_back(heap_mass[i]);
        return new_heap;
    }

};


int main() {
    ifstream fin("heapsort.in");
    ofstream fout("heapsort.out");

    int n;
    fin >> n ;

    HEAP mass;

    for (int i = 2; i <= n; i++) {
        mass.INSERT(i);
    }
    mass.INSERT(1);
    vector<int> new_mass = mass.print_mass();
    for (int i=0; i < new_mass.size(); i++) {
        fout << new_mass[i] << " ";
    }
}