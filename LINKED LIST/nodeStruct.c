#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}node;



void display(node* temp){
    if(temp == NULL) printf("\nLL is empty");
    while(temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

int main(){
    node* node1 = (node*) malloc(sizeof(node));
    node* node2 = (node*) malloc(sizeof(node));
    node* node3 = (node*) malloc(sizeof(node));
    node* node4 = (node*) malloc(sizeof(node));

    node1->val = 10;
    node1->next = node2;
    node2->val = 20;
    node2->next = node3;
    node3->val = 30;
    node3->next = node4;
    node4->val = 40;
    node4->next = NULL;
    display(node1);
}