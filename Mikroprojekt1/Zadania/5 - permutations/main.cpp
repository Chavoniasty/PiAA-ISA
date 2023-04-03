#include <iostream>
using namespace std;

string palList[120];
int counter = 0;

bool jestPal(string testStr) {
    if (testStr.length() <= 1) {
        return true;
    } else if (testStr.front() == testStr.back()) {
        return jestPal(testStr.substr(1, testStr.length() - 2));
    } else {
        return false;
    }
}

void permute(string a, int l, int r) {
    if (l == r) {
        // checking if permutation is palindrome - if it is push it to array
        if (jestPal(a)) {
            palList[counter] = a;
            counter++;
        }
    } else {
        for (int i = l; i <= r; i++) {
            // swaping left index with i index
            swap(a[l], a[i]);
            // recursive call to itself with incrementing left index (ex. change from 1st to 2nd letter)
            permute(a, l + 1, r);
        }
    }
}

void usunDup() {
    for (int i = 0; i < counter; i++) {
        for (int j = i + 1; j < counter; j++) {
            if (palList[i] == palList[j]) {
                for (int k = j; k < counter - 1; k++) {
                    palList[k] = palList[k + 1];
                }
                counter--;
                j--;
            }
        }
    }
}

// Driver Code
int main() {
    cout << "Type string - max. 5 chars" << endl;
    string str;
    cin >> str;
    int n = str.size();

    // Function call
    permute(str, 0, n - 1);

    for (int i = 0; i < counter; i++) {
        cout << i << " " << palList[i] << endl;
    }
    cout << "===" << endl;

    usunDup();

    for (int i = 0; i < counter; i++) {
        cout << i << " " << palList[i] << endl;
    }

    return 0;
}