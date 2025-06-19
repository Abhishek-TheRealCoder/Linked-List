#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node*next;
    Node(int val){
	this->data = val;
	next = NULL;
    }
};

Node* reverseNode(Node*&head){
    Node*prev = NULL;
    Node*front = head;
    Node*curr = head;

    while(front != NULL){
	front = front -> next;
	curr -> next = prev;
	prev = curr;
	curr = front;
    }

    return prev;
}


void display(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head -> next;
    }
    return;
}


int main(){
    Node*head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    cout<<"Before reversing : ";
    
    display(head);
    
    cout<<"After reversing : ";
 
    head = reverseNode(head);
    display(head);
    return 0;	
}
