#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        this->data=val;
        this->next=NULL;
    }
};

void display(Node*head){
    Node*temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
    return ;
}

int countNodes(Node*head){
    Node*temp = head;
    int cnt = 0;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

Node* intersectPoint(Node* head1, Node* head2) {
    if(head1 == NULL || head2 == NULL) return NULL;
    int n1 = countNodes(head1);
    int n2 = countNodes(head2);
    if(n2 > n1){
        int n = n2 - n1;
        Node*temp = head2;
        for(int i = 0;i < n;i++){
            temp = temp->next;
        }
        Node*temp1 = temp;
        Node*temp2 = head1;
        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }else{
        int n = n1 - n2;
        Node*temp = head1;
        for(int i = 0;i < n;i++){
            temp = temp->next;
        }
        Node*temp1 = temp;
        Node*temp2 = head2;
        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
        
    }
    return NULL;
}


int main(){
    Node*head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);
    head1->next->next->next->next->next->next = new Node(7);
    
    Node*head2 = new Node(3);
    head2->next = new Node(6);
    head2->next->next = head1->next->next->next->next;

    cout<<"This is first list : ";
    display(head1);

    cout<<"This is second list : ";
    display(head2); 

    Node*meetingPoint = intersectPoint(head1,head2);
    cout<<meetingPoint->data<<" ";
}