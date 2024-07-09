#include <iostream>
using namespace std;
class Stack{// user defined data struc
public: 
    int arr[5];
    int idx;
    Stack(){
        idx = -1;
    }
    void push(int val) {
        if(idx == sizeof(arr)/sizeof(arr[0]) -1){
            cout<<"Stack is Full!"<<endl;
            return;
        }
        idx++;
        arr[idx] = val;
    }


    void pop(){
        if(idx=-1){
            cout << "Stack is Empty!" << endl;
            return;
        }
        idx--;
    }
    int top(){
        if(idx == -1){
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        return arr[idx];
    }
    int size(){
        return idx+1;
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
    cout<<stk.size()<<endl;
    // stk.pop();
    // cout<<stk.size()<<endl;
    cout<<stk.top();
}