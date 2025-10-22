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

void display(Node*&head){
    Node*temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

Node *removeDuplicates(Node *&head) {
    map<int,int>mp;
    Node*newHead = NULL;
    Node*temp = NULL; 
    while(head){
        if(mp.find(head->data) == mp.end()){
            Node*newnode = new Node(head->data);
            if(newHead == NULL){
                newHead = temp = newnode;
            }else{
                temp -> next = newnode;
                temp = temp->next;
            }
        }
        mp[head->data]++;
        head = head->next;
    }
    return newHead;
}

int main(){
    Node*head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(3);

    cout<<"Linked List before removing duplicates : ";
    display(head);

    cout<<"Linked List after removing duplicates : ";
    Node*newHead = removeDuplicates(head);
    display(newHead);
    return 0 ; 
}


