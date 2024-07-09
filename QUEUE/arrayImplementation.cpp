#include <iostream>
using namespace std;

class Queue {
public:
    int front;
    int back;
    int arr[5];
    
    Queue() {
        front = 0;
        back = 0;
    }
    
    void push(int val) {
        if (back == 5) {
            cout << "Queue is full" << endl;
        } else {
            arr[back] = val;
            back++;
        }
    }
    
    void pop() {
        if (front-back == 0) {
            cout << "Queue is empty" << endl;
            return;
        } 
        front++;
        
    }
    
    int getFront() {
        if (front-back == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    
    int getBack() {
        if (front-back == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[back - 1];
    }
    
    int size() {
        return back - front;
    }
    
    bool empty() {
        return front == back;
    }
    
    void display() {
        if (front == back) {
            cout << "Queue is empty" << endl;
        } else {
            for (int i = front; i < back; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    // push, pop, front, back, size, empty
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);
    q.display();
    q.pop();
    q.display();
    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.getBack() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;
    return 0;
}
