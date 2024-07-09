#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Queue {
public:
    Node* head;
    Node* tail;
    int size;

    Queue() {
        head = tail = NULL;
        size = 0;
    }

    void push(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void pop() {
        if (size == 0) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    int front() {
        if (size == 0) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return head->val;
    }

    int back() {
        if (size == 0) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return tail->val;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);
    q.display();
    q.pop();
    q.display();
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.getSize() << endl;
    cout << "Empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
