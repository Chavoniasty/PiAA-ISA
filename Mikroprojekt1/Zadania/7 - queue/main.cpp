#include <conio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node *next;

    Node(int tempValue) {
        this->value = tempValue;
        this->next = NULL;
    }
};

class Queue {
private:
    Node *head;
    Node *tail;

public:
    Queue() {
        this->head = NULL;
        this->tail = NULL;
    }

    void displayQueue() {
        Node *current = head;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->next;
        }
    }

    void enqueue(int tempValue) {
        Node *newNode = new Node(tempValue);

        if (head == NULL && tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            current = current->next;
            current->next = NULL;
            tail = current;
        }
    }

    void dequeue() {
        if (head == NULL) {
            cout << "Queue is empty!";
        } else if (head == tail) {
            Node *current = head;
            delete current;
            head = NULL;
            tail = NULL;
        } else {
            Node *current = head;
            head = current->next;
            delete current;
        }
    }

    void deleteAll() {
        while (head != NULL) {
            dequeue();
        }
    }
};

int main() {
    Queue queue1;
    char option;
    do {
        system("cls");
        cout << "==== DISPLAYED QUEUE ====" << endl;
        queue1.displayQueue();
        cout << endl;
        cout << "==== MENU ====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Delete all" << endl;
        cout << "Choose option: ";
        option = getche();
        cout << endl;

        switch (option) {
        case '1':
            int x;
            cout << "Insert value: ";
            cin >> x;
            queue1.enqueue(x);
            break;

        case '2':
            queue1.dequeue();
            break;

        case '3':
            queue1.deleteAll();
            break;
        }

    } while (true);
}
