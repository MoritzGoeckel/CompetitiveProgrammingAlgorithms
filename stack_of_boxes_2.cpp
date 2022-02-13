
/*
 * Stack boxes (width, depth, height). A box can only be put on a smaller box
 * (width & depth). Find the maximum sum of heights that can be achieved.
 */

#include <iostream>
#include <vector>

using namespace std;

struct Box {
    int w;
    int d;
    int h;

    Box(int w, int d, int h) : w(w), d(d), h(h) {}
};

int solve(const vector<Box>& bs, vector<bool>& taken, int w, int d, int h) {
    int result = h;
    for (int i = 0; i < bs.size(); ++i) {
        const Box& b = bs[i];
        if (!taken[i] && b.w < w && b.d < d) {
            taken[i] = true;
            result = max(result, solve(bs, taken, b.w, b.d, h + b.h));
            taken[i] = false;
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
    vector<Box> bs{{2, 3, 5}, {3, 2, 2}, {4, 3, 1}, {1, 1, 3}, {2, 4, 4}};

    vector<bool> taken;
    taken.resize(bs.size(), false);

    int result = solve(bs, taken, numeric_limits<int>::max(),
                       numeric_limits<int>::max(), 0);

    cout << "Result: " << result << endl;
}

