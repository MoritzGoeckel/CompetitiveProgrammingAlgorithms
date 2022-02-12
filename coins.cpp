#include <iostream>
#include <unordered_map>
#include <vector>
#include "hash_pair.h"

using namespace std;

unordered_map<pair<int, int>, int, hash_pair> memo;

int solve(int n, const vector<int>& coins, int idx = 0) {
    if (coins[idx] == 1) return 1;

    if (auto aFound = memo.find(make_pair(n, idx)); aFound != memo.end()) {
        return aFound->second;
    }

    int result = 0;
    for (int s = 0; s <= n; s += coins[idx]) {
        result += solve(n - s, coins, idx + 1);
    }

    memo[make_pair(n, idx)] = result;
    return result;
}

int main(int argc, char* argv[]) {
    vector<int> coins{25, 10, 5, 1};
    cout << "Result: " << solve(10, coins) << endl;
    return 0;
}
