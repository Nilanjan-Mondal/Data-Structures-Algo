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

int main(){
    
    Node a(10);
    Node b(20);   // Method 1
    Node c(30);
    Node d(40);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    // cout << b.val << endl;
    Node temp = a;
    while(1){
        cout<<temp.val<<" ";
        if(temp.next==NULL) break;
        temp = *(temp.next);
    }


    Node* e = new Node(10);
    Node* f = new Node(20);  // method 2
    Node* g = new Node(30);
    Node* h = new Node(40);
    e->next = f;
    f->next = g;
    g->next = h;
    Node* tempp = e;
    cout<<endl;
    while(tempp!=NULL) {
        cout<<tempp->val<<" ";
        tempp = tempp->next;
    }
}