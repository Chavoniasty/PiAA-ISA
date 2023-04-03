#include <iostream>

using namespace std;

int Potega(int x, int p) {
    if (p == 0)
        return 1;
    return x * Potega(x, p - 1);
}

int Silnia(int x) {
    if (x == 1)
        return 1;
    return x * Silnia(x - 1);
}

int main() {
    cout << Potega(2, 3) << endl;
    cout << Silnia(5);
}