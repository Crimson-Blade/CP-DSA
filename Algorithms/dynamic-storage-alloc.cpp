#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block { int id, size; bool allocated; };
struct Process { int id, size, block_id = -1; };

vector<Block> blocks;
vector<Process> processes;

void input_data() {
    int n, m, s;
    cout << "Enter the number of blocks: "; cin >> n;
    cout << "Enter the number of processes: "; cin >> m;
    cout << "Enter the size of each block: ";
    for (int i = 0; i < n; i++) { cin >> s; blocks.push_back({i, s, false}); }
    cout << "Enter the size of each process: ";
    for (int i = 0; i < m; i++) { cin >> s; processes.push_back({i, s}); }
}

void first_fit() {
    for (auto& p : processes) {
        for (auto& b : blocks) {
            if (!b.allocated && b.size >= p.size) { b.allocated = true; p.block_id = b.id; break; }
        }
    }
}

void best_fit() {
    for (auto& p : processes) {
        auto best = blocks.end();
        for (auto it = blocks.begin(); it != blocks.end(); it++) {
            if (!it->allocated && it->size >= p.size) {
                if (best == blocks.end() || it->size < best->size) { best = it; }
            }
        }
        if (best != blocks.end()) { best->allocated = true; p.block_id = best->id; }
    }
}

void print_allocation() {
    cout << "Process\tSize\tBlock" << endl;
    for (auto& p : processes) {
        cout << p.id << "\t" << p.size << "\t";
        if (p.block_id == -1) { cout << "Not allocated" << endl; }
        else { cout << p.block_id << endl; }
    }
}

int main() {
    input_data();
    cout << "First Fit:" << endl; first_fit(); print_allocation();
    for (auto& b : blocks) { b.allocated = false; }
    cout << "Best Fit:" << endl; best_fit(); print_allocation();
    return 0;
}