
/*
 * Stack boxes (width, depth, height). A box can only be put on a smaller box
 * (width & depth). Find the maximum sum of heights that can be achieved.
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

struct Box {
    int w;
    int d;
    int h;

    Box(int w, int d, int h) : w(w), d(d), h(h) {}

    bool operator==(const Box& rhs) const {
        return rhs.w == w && rhs.d == d && rhs.h == h;
    }
};

struct hash_box {
    size_t operator()(const Box& b) const {
        return hash<int>{}(b.w) ^ hash<int>{}(b.d) ^ hash<int>{}(b.h);
    }
};

int solve(const vector<Box>& bw, const vector<Box>& bd, int bwi, int bdi,
          unordered_set<Box, hash_box>& taken, int w, int d) {
    // Advance bwi
    while (bwi < bw.size() &&
           (taken.count(bw[bwi]) == 1 || bw[bwi].w >= w || bw[bwi].d >= d))
        ++bwi;

    // Advance bdi
    while (bdi < bd.size() &&
           (taken.count(bd[bdi]) == 1 || bd[bdi].w >= w || bd[bdi].d >= d))
        ++bdi;

    // No boxes left, sum height
    if (bwi == bw.size() && bdi == bd.size()) {
        int sum = accumulate(taken.begin(), taken.end(), 0,
                             [](int sum, const Box& b) {
                                 cout << b.h << " ";
                                 return sum + b.h;
                             });
        cout << " -> " << sum << endl;
        return sum;
    }

    // Recurse
    int r = 0;

    // Take next by width
    if (bwi < bw.size()) {
        const Box& choosen = bw[bwi];
        taken.insert(choosen);
        r = max(r, solve(bw, bd, bwi + 1, bdi, taken, choosen.w, choosen.d));
        taken.erase(choosen);
    }

    // Take next by depth
    if (bdi < bd.size()) {
        const Box& choosen = bd[bdi];
        taken.insert(choosen);
        r = max(r, solve(bw, bd, bwi, bdi + 1, taken, choosen.w, choosen.d));
        taken.erase(choosen);
    }

    // Take none
    if (bwi < bw.size() && bdi < bd.size()) {
        r = max(r, solve(bw, bd, bwi + 1, bdi + 1, taken, w, d));
    }

    return r;
}

int main(int argc, char* argv[]) {
    vector<Box> boxes{{2, 3, 5}, {3, 2, 2}, {4, 3, 1}, {1, 1, 3}, {2, 4, 4}};
    unordered_set<Box, hash_box> taken{};
    vector<Box> bw = boxes;
    sort(bw.begin(), bw.end(),
         [](const Box& a, const Box& b) { return a.w > b.w; });

    vector<Box> bd = boxes;
    sort(bd.begin(), bd.end(),
         [](const Box& a, const Box& b) { return a.d > b.d; });

    int result = solve(bw, bd, 0, 0, taken, numeric_limits<int>::max(),
                       numeric_limits<int>::max());

    cout << "Result: " << result << endl;
}
