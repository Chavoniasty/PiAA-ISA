#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

fstream file;

void insertRandomValues(int arr[], int x) {
    // O(n)
    for (int i = 0; i < 5; i++) {
        arr[i] = rand() % x;
    }
}

void saveToTXT(int arr[]) {
    file.open("array.txt", ios::out | ios::app);
    if (file.is_open()) {
        for (int i = 0; i < 5; i++) {
            file << arr[i] << endl;
        }
        file.close();
    }
}

void loadFromTXT(int arr[]) {
    file.open("array.txt", ios::in);
    if (file.is_open()) {
        for (int i = 0; i < 5; i++) {
            file >> arr[i];
        }
        file.close();
    }
}

void saveToBIN(int arr[]) {
    ofstream file("array2.bin", ios::binary);
    if (file.is_open()) {
        for (int i = 0; i < 5; i++) {
            file << arr[i] << endl;
        }
        file.close();
    }
}

void loadFromBIN(int arr[]) {
    ifstream file("array2.bin", ios::binary);
    if (file.is_open()) {
        for (int i = 0; i < 5; i++) {
            file >> arr[i];
        }
        file.close();
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    char option;
    do {
        system("cls");
        cout << "==== ARRAY ===" << endl;
        // O(n)
        for (auto i : arr) {
            cout << i << " ";
        }
        cout << endl;
        cout << "==== MENU ===" << endl;
        cout << "1. Insert random values to array" << endl;
        cout << "2. Save to txt file" << endl;
        cout << "3. Load from txt file" << endl;
        cout << "4. Save to bin file" << endl;
        cout << "5. Load from bin file" << endl;
        cout << "Choose option: ";
        option = getche();
        cout << endl;

        switch (option) {
        case '1':
            int x;
            cout << "Insert max value: ";
            cin >> x;
            insertRandomValues(arr, x);
            break;

        case '2':
            saveToTXT(arr);
            break;

        case '3':
            loadFromTXT(arr);
            break;

        case '4':
            saveToBIN(arr);
            break;

        case '5':
            loadFromBIN(arr);
            break;
        }

    } while (true);
}