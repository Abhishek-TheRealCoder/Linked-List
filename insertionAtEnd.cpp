#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int val){
        this -> data = val;
        this -> next = NULL;
    }
};

void insertAtEnd(Node**headPtr,int val){
    Node* newNode = new Node(val);
    if(*headPtr == NULL){
        *headPtr = newNode;
        return;
    }
    Node* temp = *headPtr;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    return ;
}
void insertionInEnd(Node*&headPtr,int val){
    Node* newNode = new Node(val);
    if(headPtr == NULL){
        headPtr = newNode;
        return;
    }
    Node* temp = headPtr;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    return ;
}

void display(Node**head){
    Node* temp = *head;
    while(temp != NULL){
        cout<<temp -> data<< " ";
        temp = temp -> next;
    } 
    return ;
}

int main(){
    Node* head = NULL;
    insertAtEnd(&head,1);
    insertAtEnd(&head,2);
    insertAtEnd(&head,3);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    insertAtEnd(&head,6);
    insertAtEnd(&head,7);
    insertAtEnd(&head,8);
    insertAtEnd(&head,9);
    insertAtEnd(&head,10);
    display(&head);
    cout<<endl;
    Node* newHead = NULL;
    insertionInEnd(newHead,10);
    insertionInEnd(newHead,20);
    insertionInEnd(newHead,30);
    insertionInEnd(newHead,40);
    insertionInEnd(newHead,50);
    insertionInEnd(newHead,60);
    insertionInEnd(newHead,70);
    insertionInEnd(newHead,80);
    insertionInEnd(newHead,90);
    insertionInEnd(newHead,100);
    display(&newHead);
    return 0;
}