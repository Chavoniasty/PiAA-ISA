#include <conio.h>
#include <cstdlib>
#include <iostream>
#define SIZE 10

using namespace std;

class Deque {
public:
    int dequeArr[SIZE] = {
        0};
    int front = -1;
    int rear = -1;
    int currentSize = 0;

    Deque() {}

    void getSize() {
        cout << "Size of deque" << currentSize;
    }

    void isEmpty() {
        if (currentSize == 0) {
            cout << "Deque is empty";
        } else {
            cout << "Deque is not empty";
        }
    }

    int getFront() {
        if ((front == -1) && (rear == -1)) {
            throw "Deque is empty";
        } else {
            return dequeArr[front];
        }
    }

    int getRear() {
        if ((front == -1) && (rear == -1)) {
            throw "Deque is empty";
        } else {
            return dequeArr[rear];
        }
    }

    void insertFront(int tempValue) {
        if (((front == 0) && (rear == SIZE - 1)) || (front == rear + 1)) {
            throw "Deque is full";
        } else if (front == -1 && rear == -1) {
            front = rear = 0;
            dequeArr[front] = tempValue;
            currentSize++;
        } else if (front == 0) {
            front = SIZE - 1;
            dequeArr[front] = tempValue;
            currentSize++;
        } else {
            front--;
            dequeArr[front] = tempValue;
            currentSize++;
        }
    }

    void deleteFront() {
        if ((front == -1) && (rear == -1)) {
            throw "Deque is empty";
        } else if (front == rear) {
            front = -1;
            rear = -1;
            currentSize--;
        } else if (front == (SIZE - 1)) {
            front = 0;
            currentSize--;
        } else {
            front++;
            currentSize--;
        }
    }

    void insertRear(int tempValue) {
        if (((front == 0 && rear == SIZE - 1) || front == rear + 1)) {
            throw "Deque is full";
        } else if (front == -1 && rear == -1) {
            rear = 0;
            dequeArr[rear] = tempValue;
            currentSize++;
        } else if (rear == SIZE - 1) {
            rear = 0;
            dequeArr[rear] = tempValue;
            currentSize++;
        } else {
            rear++;
            dequeArr[rear] = tempValue;
            currentSize++;
        }
    }

    void deleteRear() {
        if ((front == -1) && (rear == -1)) {
            throw "Deque is empty";
        } else if (front == rear) {
            front = -1;
            rear = -1;
            currentSize--;
        } else if (rear == 0) {
            rear = SIZE - 1;
            currentSize--;
        } else {
            rear--;
            currentSize--;
        }
    }

    void displayDeque() {
        if (currentSize > 0) {
            int i = front;
            while (i != rear) {
                cout << dequeArr[i];
                i = (i++) % SIZE;
                cout << " ";
            }
            cout << dequeArr[rear];
        } else {
            cout << "Deque is empty";
        }
    }

    void jestPal() {
        if (currentSize <= 1) {
            cout << "Palindome!";
        } else if (this->getFront() == this->getRear()) {
            this->deleteFront();
            this->deleteRear();
            jestPal();
        } else {
            cout << "It is not a palindrome.";
        }
    }
};

int main() {
    Deque deque1;
    char option;
    do {
        system("cls");
        cout << "==== DISPLAYED DEQUE ====" << endl;
        deque1.displayDeque();
        cout << endl;
        cout << "==== MENU ====" << endl;
        cout << "1. Get size of Deque" << endl;
        cout << "2. Check if Deque is empty" << endl;
        cout << "3. Get front value" << endl;
        cout << "4. Get rear value" << endl;
        cout << "5. Insert at front" << endl;
        cout << "6. Insert at rear" << endl;
        cout << "7. Delete front" << endl;
        cout << "8. Delete rear" << endl;
        cout << "9. isPal" << endl;
        cout << "Choose option: ";
        option = getche();
        cout << endl;

        switch (option) {
        case '1':
            deque1.getSize();
            break;

        case '2':
            deque1.isEmpty();
            break;

        case '3':
            deque1.getFront();
            break;

        case '4':
            deque1.getRear();
            break;

        case '5':
            cout << "Insert value:";
            int temp;
            cin >> temp;
            deque1.insertFront(temp);
            break;

        case '6':
            cout << "Insert value:";
            cin >> temp;
            deque1.insertRear(temp);
            break;

        case '7':
            deque1.deleteFront();
            break;

        case '8':
            deque1.deleteRear();
            break;

        case '9':
            deque1.jestPal();
            break;
        }
        cout << endl;
        system("pause");
    } while (true);
}