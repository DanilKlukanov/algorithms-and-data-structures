#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N;
long long L, R, p;
long long first_border, last_border, center_border;
long long page = 0, days = 0, count_book, now_days;
vector<pair<pair<long long, long long>, long long>> book;
vector<pair<pair<long long, long long>, long long>> min_heap;

bool comporator(pair<pair<long long, long long>, long long> &a, pair<pair<long long, long long>, long long> &b){
    return a.first.first < b.first.first;
}

void SIFTUPMIN(int i, vector<pair<pair<long long, long long>, long long>> &min_heap) {
    if (i > 0) {
        int parent_i = (i - 1) / 2;
        if (min_heap[parent_i].first.second > min_heap[i].first.second) {
            swap(min_heap[parent_i], min_heap[i]);
            SIFTUPMIN(parent_i, min_heap);
        }
    }
}

void SIFTDOWNMIN(int i, vector<pair<pair<long long, long long>, long long>> &min_heap) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int ind_i = i;

    if (left < min_heap.size() && min_heap[left].first.second < min_heap[i].first.second)
        ind_i = left;
    if (right < min_heap.size() && min_heap[right].first.second < min_heap[ind_i].first.second)
        ind_i = right;
    if (min_heap[ind_i].first.second < min_heap[i].first.second) {
        swap(min_heap[i], min_heap[ind_i]);
        SIFTDOWNMIN(ind_i, min_heap);
    }
}

void pop_min(vector<pair<pair<long long, long long>, long long>> &min_heap) {
    swap(min_heap[0], min_heap[min_heap.size() - 1]);
    min_heap.pop_back();
    SIFTDOWNMIN(0, min_heap);
}

void read(long long k, vector<pair<pair<long long, long long>, long long>> &min_heap){
    if (min_heap.size() > 0) {
        if (min_heap[0].second <= k) {
            k -= min_heap[0].second;
            pop_min(min_heap);
            read(k, min_heap);
        } else {
            min_heap[0].second -= k;
        }
    }
}

bool state(vector<pair<pair<long long, long long>, long long>> &min_heap){
    if (min_heap[0].first.second > now_days) return true;
    if (min_heap.size() == 0) return true;
    return false;
}

bool main_func(long long k, vector<pair<pair<long long, long long>, long long>> &min_heap){
    min_heap.clear();
    count_book = 0;
    for (now_days = 1; now_days <= days; now_days++){
        while (count_book < N && now_days == book[count_book].first.first) {
            min_heap.push_back(book[count_book++]);
            SIFTUPMIN(min_heap.size() - 1, min_heap);
        }
        if (!state(min_heap)) return false;
        read(k, min_heap);
    }
    return true;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> N;

    for (int i = 0; i < N; i++){
        fin >> L >> R >> p;
        book.emplace_back(make_pair(L, R), p);
        page += p;
        if (R > days)
            days = R;
    }
    sort(book.begin(), book.end(), comporator);

    first_border = 1;
    last_border = page;
    center_border = (first_border + last_border + 1) / 2;

    while (first_border <= last_border){
        if (main_func(center_border, min_heap)) {
            last_border = center_border - 1;
        }
        else {
            first_border = center_border + 1;
        }
        center_border = (last_border + first_border + 1) / 2;
    }
    fout << center_border;
}