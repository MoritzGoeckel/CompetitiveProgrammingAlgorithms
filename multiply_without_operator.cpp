#include <iostream>

using namespace std;

int multiply(int a, int b) {
    int sum = 0;
    for (int i = 0; i < sizeof(a); ++i) {
        if (a & (1 << i)) sum += b;  // Bit i is 1
        b = b << 1;                  // * 2
    }
    return sum;
}

int main(int argc, const char* argv[]) {
    int a = 12;
    int b = 17;
    cout << a << " * " << b << " = " << (a * b) << endl;  // 204
    cout << "Result: " << multiply(a, b) << endl;         // 204
}

