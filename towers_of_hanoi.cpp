#include <deque>
#include <iostream>

using namespace std;
using Tower = deque<int>;

void solve(Tower& source, Tower& buffer, Tower& target, int num) {
    // Helper to move one disk
    auto moveOne = [](Tower& source, Tower& target) {
        auto d = source.back();
        source.pop_back();
        target.emplace_back(d);
    };

    if (num == 1) {
        // Base case
        moveOne(source, target);  // Just move one disk
    } else {
        // Recurse
        solve(source, target, buffer, num - 1);  // One less to buffer
        moveOne(source, target);                 // Move current disk to target
        solve(buffer, source, target, num - 1);  // Rest from buffer to target
    }
}

void print(const char* name, Tower& tower) {
    cout << name << ": ";
    for (auto e : tower) {
        cout << e << " ";
    }
    cout << endl;
}

int main(int argc, const char* argv[]) {
    Tower source = {3, 2, 1};
    Tower buffer;
    Tower target;

    solve(source, buffer, target, source.size());

    print("Source", source);
    print("Buffer", buffer);
    print("Target", target);
    return 0;
}

