#include <iostream>
using namespace std;

class Node{
public: 
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Stack{   // user defined data structure
public: 
    Node* head;
    int size;
    Stack(){
        head = NULL;
        size = 0;
    }
    void push(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }
    void pop(){
        if(head == NULL){
            cout << "Stack is Empty!" << endl;
            return;
        }
        head = head->next;
        size--;
    }
    int top(){
        if(head == NULL){
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        return head->val;
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Stack stk;
    cout<<stk.top()<<endl;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);
    cout<<stk.size<<endl;
    cout<<stk.top()<<endl;
    stk.display();
}