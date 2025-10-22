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

Node*mergeTwoLists(Node*head1,Node*head2){
    Node*dummy = new Node(-1);
    Node*temp = dummy;
    Node*temp1 = head1;
    Node*temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            temp->next = temp1;
            temp1 = temp1->next;
        }else{
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }

    while(temp1){
        temp->next = temp1;
        temp1 = temp1->next;
        temp = temp->next;
    }
    while(temp2){
        temp->next = temp2;
        temp2 = temp2->next;
        temp = temp->next;
    }

    return dummy->next;
}

void display(Node*&head){
    Node*temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    return;
}

int main(){
    Node*head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);
    head1->next->next->next = new Node(40);

    Node*head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(7);
    head2->next->next->next = new Node(9);

    Node*head = mergeTwoLists(head1,head2);
    display(head);
    return 0;
}