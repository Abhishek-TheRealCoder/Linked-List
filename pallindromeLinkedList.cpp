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

Node* reverse(Node*&head){
    Node*prev = NULL;
    Node*curr = head;
    Node*front = head;
    while(front != NULL){
        front = front -> next;
        curr -> next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

bool isPalindrome(Node* &head) {
    if(head == NULL || head->next == NULL) return head;
    //find middle
    Node*slow = head;
    Node*fast = head;
    Node*prev = NULL;
    while(fast != NULL && fast -> next != NULL){
        prev = slow;
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    prev -> next = NULL;
    Node* newHead = reverse(slow);
    Node* temp1 = head;
    Node* temp2 = newHead;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data != temp2->data) return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}


int main(){
    Node* head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(3);
    head -> next -> next -> next -> next = new Node(2);
    head -> next -> next -> next -> next -> next = new Node(1);

    bool ans = isPalindrome(head);
    cout<<ans;
    return 0;
}