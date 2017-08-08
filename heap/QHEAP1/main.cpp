#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>

#define NMax (1 << 20)

std::vector<int> heap(NMax, std::numeric_limits<int>::max());
std::unordered_map<int, int> pos;

int n = 1;

int parent(int i) {
    return i >> 1;
}

int left(int i) {
    return i << 1;
}

int right(int i) {
    return (i << 1) + 1;
}

void lift(int i) {
    int p = parent(i);
//    std::cout << "lift at " << i << " (" << heap[i] << ")" << " p = " << p << std::endl;
    while (p > 0 && heap[p] > heap[i]) {
//        std::cout << "lift at " << i << " (" << heap[i] << ")" << " p = " << p << std::endl;
        std::swap(heap[p], heap[i]);
        pos[heap[p]] = p, pos[heap[i]] = i;
        i = p;
        p = parent(i);
    }
}

void sift(int i) {
    int l = left(i), r = right(i);
    int m = i;
    if (l < n && heap[l] < heap[m])
        m = l;
    if (r < n && heap[r] < heap[m])
        m = r;
    if (m != i)
    {
        std::swap(heap[i], heap[m]);
        pos[heap[m]] = m, pos[heap[i]] = i;
        sift(m);
    }
}

void insert(int v) {
    heap[n++] = v;
    pos[v] = n - 1;
    lift(n - 1);
}

void remove(int v) {
    int i = pos[v];
    pos.erase(v);
    heap[i] = heap[--n];
    pos[heap[i]] = i;
    sift(i);
}

int main() {
    int q;
    std::cin >> q;
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int x;
            std::cin >> x;
            insert(x);
        } else if (type == 2) {
            int x;
            std::cin >> x;
            remove(x);
        }
        else if (type == 3)
            std::cout << heap[1] << std::endl;
    }
    return 0;
}