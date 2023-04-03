#include <conio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

void insertRandomValues(int **arr, int x, int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            arr[i][j] = rand() % x;
        }
    }
}

void displayArray(int **arr, int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    getch();
}

void displayMax(int **arr, int a, int b) {
    int temp = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (arr[i][j] > temp) {
                temp = arr[i][j];
            }
        }
    }
    cout << "Max value is: " << temp;
}

int main() {
    // creating the array
    int a;
    cout << "Insert number of rows: ";
    cin >> a;
    int b;
    cout << "Insert number of columns: ";
    cin >> b;

    int **arr = new int *[a];
    for (int i = 0; i < a; i++) {
        arr[i] = new int[b];
    }

    cout << endl;
    char option;
    do {
        system("cls");
        cout << "==== MENU ===" << endl;
        cout << "1. Insert random values (0 - x)" << endl;
        cout << "2. Display Array" << endl;
        cout << "3. Max value in array" << endl;
        cout << "Choose option: ";
        option = getche();
        cout << endl;

        switch (option) {
        case '1':
            int x;
            cout << "Insert max value: ";
            cin >> x;
            insertRandomValues(arr, x, a, b);
            break;

        case '2':
            displayArray(arr, a, b);
            break;

        case '3':
            displayMax(arr, a, b);
            break;
        }

    } while (true);

    return 0;
}