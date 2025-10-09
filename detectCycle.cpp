#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

bool detectCycle(Node*&head){
    Node*slow = head;
    Node*fast = head;
    while(fast != NULL && fast ->next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(fast == slow) return true;
    }
    return false;
}

void display(Node*&head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<< " ";
        temp = temp -> next;
    } 
    cout<<endl;
    return ;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    
    cout<<"Before solving : "<<endl;
    display(head);
    cout<<"Creating a loop" <<endl;
    head->next->next->next->next->next = head->next->next->next;
    bool ans = detectCycle(head);
    cout<<ans;
}