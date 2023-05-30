
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addNode(string value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->prev = nullptr;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeNodes(int k) {
        int count = 0;
        Node* current = tail;

        while (current != nullptr && count < k) {
            Node* temp = current;
            current = current->prev;
            delete temp;
            count++;
        }

        if (current == nullptr) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            current->next = nullptr;
            tail = current;
        }
    }

    void insertAfter(string key, string value) {
        Node* current = head;

        while (current != nullptr && current->data != key) {
            current = current->next;
        }

        if (current != nullptr) {
            Node* newNode = new Node;
            newNode->data = value;

            if (current == tail) {
                tail = newNode;
            }
            else {
                current->next->prev = newNode;
                newNode->next = current->next;
            }

            current->next = newNode;
            newNode->prev = current;
        }
    }

    void printList() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void saveListToFile(string fileName) {
        ofstream outFile(fileName);

        if (outFile.is_open()) {
            Node* current = head;

            while (current != nullptr) {
                outFile << current->data << endl;
                current = current->next;
            }

            outFile.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }

    void destroyList() {
        Node* current = head;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
    }

    void restoreListFromFile(string fileName) {
        ifstream inFile(fileName);

        if (inFile.is_open()) {
            string value;

            while (getline(inFile, value)) {
                addNode(value);
            }

            inFile.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }
};

int main() {
    LinkedList list;

    list.addNode("apple");
    list.addNode("banana");
    list.addNode("cherry");
    list.addNode("date");

    list.printList();

    list.insertAfter("banana", "orange");
    list.insertAfter("kiwi", "grape");

    list.printList();

    list.removeNodes(2);

    list.printList();

    list.saveListToFile("fruits.txt");

    list.destroyList();

    list.restoreListFromFile("fruits.txt");

    list.printList();

    return 0;
}