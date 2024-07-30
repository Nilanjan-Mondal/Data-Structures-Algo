#include <iostream>
#include <vector>
using namespace std;

class Queue {
public:
    int front;
    int back;
    int size;
    int capacity;
    vector<int> arr;
    
    Queue(int k) {
        front = 0;
        back = 0;
        size = 0;
        capacity = k;
        arr.resize(k);
    }
    
    void push(int val) {
        if (size == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        arr[back] = val;
        back++;
        if (back == capacity) back = 0;
        size++;
    }
    
    void pop() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        front++;
        if (front == capacity) front = 0;
        size--;
    }
    
    int getFront() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    
    int getBack() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (back == 0) return arr[capacity - 1];
        return arr[back - 1];
    }
    
    bool empty() {
        return size == 0;
    }
    
    void display() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        int count = size;
        while (count > 0) {
            cout << arr[i] << " ";
            i++;
            if (i == capacity) i = 0;
            count--;
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display(); // Should display: 10 20 30 40 50
    q.push(60);  // Should display "Queue is full"
    q.pop();
    q.pop();
    q.display(); // Should display: 30 40 50
    q.push(60);
    q.push(70);
    q.display(); // Should display: 30 40 50 60 70
    cout << "Front: " << q.getFront() << endl; // Should display 30
    cout << "Back: " << q.getBack() << endl;  // Should display 70
    cout << "Empty: " << q.empty() << endl;    // Should display 0 (false)
    return 0;
}
