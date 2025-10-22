#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

int lengthOfCycle(Node*&head){
    Node*slow = head;
    Node*fast = head;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast == slow) break;
    }
    if(fast == NULL || fast -> next == NULL) return -1;

    Node* temp = head;
    while(temp != slow){
        temp = temp->next;
        slow = slow->next;
    }
    
    int length = 1;
    Node*len = slow->next;
    while(len != slow){
        len = len->next;
        length++;
    }
    return length;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next = head->next->next->next;

    int length = lengthOfCycle(head);
    cout<<length;
    return 0;
}