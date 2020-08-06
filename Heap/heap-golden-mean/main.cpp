#include <fstream>
#include <vector>

using namespace std;

vector<int> main_out;

//heap_max
void SIFTUPMAX(int i, vector<int> &max_heap) {
    if (i > 0) {
        int parent_i = (i - 1) / 2;
        if (max_heap[parent_i] < max_heap[i]) {
            swap(max_heap[parent_i], max_heap[i]);
            SIFTUPMAX(parent_i, max_heap);
        }
    }
}

void SIFTDOWNMAX(int i, vector<int> &max_heap) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int ind_i = i;

    if (left < max_heap.size() && max_heap[left] > max_heap[i])
        ind_i = left;
    if (right < max_heap.size() && max_heap[right] > max_heap[ind_i])
        ind_i = right;
    if (ind_i != i) {
        swap(max_heap[i], max_heap[ind_i]);
        SIFTDOWNMAX(ind_i, max_heap);
    }
}

//heap_min
void SIFTUPMIN(int i, vector<int> &min_heap) {
    if (i > 0) {
        int parent_i = (i - 1) / 2;
        if (min_heap[parent_i] > min_heap[i]) {
            swap(min_heap[parent_i], min_heap[i]);
            SIFTUPMIN(parent_i, min_heap);
        }
    }
}

void SIFTDOWNMIN(int i, vector<int> &min_heap) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int ind_i = i;

    if (left < min_heap.size() && min_heap[left] < min_heap[i])
        ind_i = left;
    if (right < min_heap.size() && min_heap[right] < min_heap[ind_i])
        ind_i = right;
    if (min_heap[ind_i] < min_heap[i]) {
        swap(min_heap[i], min_heap[ind_i]);
        SIFTDOWNMIN(ind_i, min_heap);
    }
}

//heap_max_public
int pop_max(vector<int> &max_heap) {
    long long max = max_heap[0];
    swap(max_heap[0], max_heap[max_heap.size() - 1]);
    max_heap.pop_back();
    SIFTDOWNMAX(0, max_heap);
    return max;
}

//heap_min_public
int pop_min(vector<int> &min_heap) {
    long long min = min_heap[0];
    swap(min_heap[0], min_heap[min_heap.size() - 1]);
    min_heap.pop_back();
    SIFTDOWNMIN(0, min_heap);
    return min;
}

void work_with_max_heap(vector<int> &max_heap, vector<int> &min_heap, int element) {
    if (element > min_heap[0]) {
        max_heap.push_back(pop_min(min_heap));
        SIFTUPMAX(max_heap.size() - 1, max_heap);
        min_heap.push_back(element);
        SIFTUPMIN(min_heap.size() - 1, min_heap);
    } else {
        max_heap.push_back(element);
        SIFTUPMAX(max_heap.size() - 1, max_heap);
    }
    main_out.push_back(max_heap[0]);
}

void work_with_min_heap(vector<int> &max_heap, vector<int> &min_heap, int element) {
    if (element < max_heap[0]) {
        min_heap.push_back(pop_max(max_heap));
        SIFTUPMIN(min_heap.size() - 1, min_heap);
        max_heap.push_back(element);
        SIFTUPMAX(max_heap.size() - 1, max_heap);
    } else {
        min_heap.push_back(element);
        SIFTUPMIN(min_heap.size() - 1, min_heap);
    }
    main_out.push_back(max_heap[0]);
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, elements;
    fin >> n;

    vector<int> max_heap;
    vector<int> min_heap;


    fin >> elements;
    max_heap.push_back(elements);
    SIFTUPMAX(max_heap.size() - 1, max_heap);
    main_out.push_back(elements);

    for (int i = 1; i < n; i++) {
        fin >> elements;
        if (i % 2 == 0)
            work_with_max_heap(max_heap, min_heap, elements);
        if (i % 2 == 1)
            work_with_min_heap(max_heap, min_heap, elements);
    }

    for (int i = 0; i < main_out.size(); i++) {
        fout << main_out[i] << " ";
    }

}
