#include <iostream>
#include <vector>

using namespace std;
using BoolRef = std::vector<bool>::reference;

void print(const vector<vector<bool>>& pos) {
    static int solution = 0;

    cout << "-- " << ++solution << " --" << endl;
    for (const auto& v : pos) {
        for (const auto& b : v) {
            cout << (b ? "q" : " ");
        }
        cout << endl;
    }
}

void solve(int board_size, int r, vector<bool>& rs, vector<bool>& cs,
           vector<bool>& d0, vector<bool>& d1, vector<vector<bool>>& pos) {
    if (r == rs.size()) {
        print(pos);
        return;
    }

    for (int y = r; y < rs.size(); ++y) {
        for (int x = 0; x < cs.size(); ++x) {
            BoolRef diag0 = d0[x + y];
            BoolRef diag1 = d1[(x - y) + board_size];
            BoolRef row = rs[y];
            BoolRef column = cs[x];

            if (!diag0 && !diag1 && !row && !column) {
                diag0 = true;
                diag1 = true;
                row = true;
                column = true;

                pos[y][x] = true;
                solve(board_size, r + 1, rs, cs, d0, d1, pos);
                pos[y][x] = false;

                diag0 = false;
                diag1 = false;
                row = false;
                column = false;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int board_size = 8;

    vector<bool> rs;
    rs.resize(board_size, false);

    vector<bool> cs;
    cs.resize(board_size, false);

    vector<bool> d0;
    d0.resize(2 * board_size, false);

    vector<bool> d1;
    d1.resize(2 * board_size, false);

    vector<vector<bool>> pos;
    pos.resize(board_size, vector<bool>(board_size, false));

    solve(board_size, 0, rs, cs, d0, d1, pos);
    cout << "Done" << endl;
    return 0;
}
