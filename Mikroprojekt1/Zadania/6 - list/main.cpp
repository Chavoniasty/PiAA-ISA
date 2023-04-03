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

class List {
private:
    Node *head;

public:
    List() {
        head = NULL;
    }

    void displayList() {
        Node *current = head;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void addLast(int tempValue) {
        Node *newNode = new Node(tempValue);
        // checking if head is empty
        if (head == NULL) {
            head = newNode;
            // if not - make pointer in the "last one" to new one
        } else {
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            current = current->next;
            current->next = NULL;
        }
    }

    void addFirst(int tempValue) {
        Node *newNode = new Node(tempValue);
        // checking if head is empty
        if (head == NULL) {
            head = newNode;
            // if not - repin head to new node, and use "old head" as new node's next
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void deleteByValue(int tempValue) {
        // check if link is empty
        if (head == NULL) {
            cout << "List is empty!";
        } else {
            // if searched value is head
            if (head->value == tempValue) {
                Node *tempNode = head;
                head = head->next;
                delete tempNode;
                // if not - search first element with
            } else {
                Node *current = head;
                while (current->next != NULL) {
                    if (current->next->value == tempValue) {
                        Node *tempNode = current->next;
                        current->next = current->next->next;
                        delete tempNode;
                    }
                    current = current->next;
                }
            }
        }
    }

    void deleteAll() {
        Node *current = head;
        while (current != NULL) {
            Node *tempNode = current;
            current = current->next;
            delete tempNode;
        }
        head = NULL;
    }
};

int main() {
    List list1;
    char option;
    do {
        system("cls");
        cout << "==== DISPLAYED LIST ====" << endl;
        list1.displayList();
        cout << endl;
        cout << "==== MENU ====" << endl;
        cout << "1. Add at end" << endl;
        cout << "2. Add at front" << endl;
        cout << "3. Delete by value" << endl;
        cout << "4. Delete all" << endl;
        cout << "Choose option: ";
        option = getche();
        cout << endl;

        switch (option) {
        case '1':
            int x1;
            cout << "Insert value: ";
            cin >> x1;
            list1.addLast(x1);
            break;

        case '2':
            int x2;
            cout << "Insert value: ";
            cin >> x2;
            list1.addFirst(x2);
            break;

        case '3':
            int x3;
            cout << "Insert value: ";
            cin >> x3;
            list1.deleteByValue(x3);
            break;
        case '4':
            list1.deleteAll();
            break;
        }
    } while (true);
}