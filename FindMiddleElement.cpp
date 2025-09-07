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

void insertion(Node*&headPtr,int val){
    Node*newNode = new Node(val);
    if(headPtr == NULL) {
        headPtr = newNode;
        return;
    }
    Node*temp = headPtr; 
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

int findMiddleElem(Node*& head){
    if (head == NULL) return -1;
    Node*slow = head;
    Node*fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow->data;
}

void display(Node*& head){
    Node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    } 
    cout<<endl;
}

int main(){
    Node*head = NULL;
    while(true){
        cout<<"Enter the number to insert in Linked List : ";
        int num;
        cin>>num;
        if(num == 0) break;
        insertion(head,num);
    }

    display(head);
    
    int ans = findMiddleElem(head);
    cout<<ans;
    return 0;
}