#include <chrono>
#include <iostream>
#include <string>

using namespace std;
using namespace std::chrono;

bool jestPal(string testStr) {
    if (testStr.length() <= 1) {
        return true;
    } else if (testStr.front() == testStr.back()) {
        return jestPal(testStr.substr(1, testStr.length() - 2));
    } else {
        return false;
    }
}

int main() {
    cout << jestPal("kajak");
}