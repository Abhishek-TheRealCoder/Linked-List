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
void rearrangeEvenOdd(Node*&head) {
    if(head == NULL || head->next == NULL) return ;
    Node*odd = head;
    Node*temp1 = head;
    Node*even = head->next;
    Node*temp2 = head->next;

    while(temp2!= NULL && temp2->next != NULL){
        temp1->next = temp2->next;
        temp1 = temp1->next;
        temp2->next = temp1->next;
        temp2 = temp2->next;
    }

    temp1->next = even;
    
}

void display(Node*&head){
    Node*temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
int main(){
    Node*head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    // head->next->next->next->next = new Node(5);

    cout<<"Before : ";
    display(head);

    cout<<"After : ";
    rearrangeEvenOdd(head);
    display(head);

}