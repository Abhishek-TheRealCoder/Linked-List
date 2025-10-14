#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        this -> data = val;
        next = NULL;
    }
};

void removeCycle(Node*&head){
    Node*slow = head;
    Node*fast = head;
    
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;

        if(fast == slow) break;
    }
    if(fast == NULL || fast -> next == NULL) return;

    Node*temp = head;
    while(temp != slow){
        slow = slow -> next;
        temp = temp -> next;
    }

    while(fast->next != temp){
        fast = fast -> next;
    }
    fast -> next = NULL;    
    return;
}

void display(Node* &head){
    Node*temp = head;
    while(temp != NULL){
        cout<< temp -> data <<"->";
        temp = temp -> next;
    }
    return ;
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
 
    cout<<"Created cycle at element 4 now we need to see that in output : ";
    head->next->next->next->next->next->next->next->next = head->next->next->next;

    removeCycle(head);
    display(head);
    return 0;
}