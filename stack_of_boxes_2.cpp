
/*
 * Stack boxes (width, depth, height). A box can only be put on a smaller box
 * (width & depth). Find the maximum sum of heights that can be achieved.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Box {
    int w;
    int d;
    int h;

    Box(int w, int d, int h) : w(w), d(d), h(h) {}
};

int solve(const vector<Box>& bs, int idx, int w, int d, vector<int>& m) {
    if (idx >= bs.size()) return 0;  // No boxes left

    if (m[idx] != -1) {
        if (bs[idx].w < w && bs[idx].d < d) {
            return m[idx];
        } else {
            return 0;  // Cached box does not fit on base
        }
    }

    int result = 0;
    for (int i = idx /* only search forward */; i < bs.size(); ++i) {
        const Box& b = bs[i];
        if (b.w < w && b.d < d) {
            // This box fits on base, try it
            result = max(result, b.h + solve(bs, i + 1, b.w, b.d, m));
        }
    }

    return m[idx] = result;
}

int main(int argc, char* argv[]) {
    vector<Box> bs{{2, 3, 5}, {3, 2, 2}, {4, 3, 1}, {1, 1, 3}, {2, 4, 4}};
    vector<int> m;
    m.resize(bs.size(), -1);

    // Sort along one axis. So we can start searching after the last taken
    sort(bs.begin(), bs.end(),
         [](const Box& a, const Box& b) { return a.w > b.w; });

    int maxInt = numeric_limits<int>::max();
    cout << "Result: " << solve(bs, 0, maxInt, maxInt, m) << endl;
}

