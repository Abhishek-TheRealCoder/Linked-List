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

int count(Node*&head){
    int cnt = 0;
    Node*temp = head;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

Node*reverseKGroup(Node*head,int k){
    if(head == NULL || k == 0) return head;
    int n = count(head);
    
    if(n < k) return head;

    Node*prev = NULL;
    Node*curr = head;
    Node*front = head;
    Node*temp = head;
    int cnt = 0;
    while(front != NULL && cnt != k){
        cnt++;
        front = front->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    temp->next = reverseKGroup(front,k);

    return prev;
}

void display(Node*&head){
    Node*temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    return ;
}

int main(){
    Node*head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;

    Node*newHead =  reverseKGroup(head,k);
    display(newHead);
    return 0;
}