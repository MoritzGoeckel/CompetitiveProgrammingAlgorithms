#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(int op, int cl, int pairs, string& s, vector<string>& results) {
    if (op == cl && cl == pairs) {
        // done, add
        results.emplace_back(s);
        return;
    }

    if (op < pairs) {
        // Try open
        s += '(';
        solve(op + 1, cl, pairs, s, results);
        s.pop_back();
    }

    if (cl < op) {
        // Try close
        s += ')';
        solve(op, cl + 1, pairs, s, results);
        s.pop_back();
    }
}

int main(int argc, const char* argv[]) {
    vector<string> results;
    string s;
    solve(0, 0, 3, s, results);

    for (string& elem : results) {
        cout << elem << " ";
    }
    cout << endl;
}

