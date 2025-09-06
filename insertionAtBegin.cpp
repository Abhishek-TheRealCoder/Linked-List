#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;                           
    Node(int val){               //    4 byte    4 byte
        this->data = val;        //  --------------------
        this->next = NULL;       // |  data   |    ptr   |
                                 //  --------------------
    }
};

// pointer to pointer
void insertAtBegin(Node**headPtr,int val){             
    Node* newNode = new Node(val);  
                                        //                                             -------------------
                                        //                                            |    1    |   NULL  |
                                        //                                             -------------------
                                        //                                                    100
                                        //                     1000                            ^
                                        //                  -------------                      |
                                        //                 |    100      |----------------------
                                        //                  -------------
                                        //                      head
                                        //      2000             ^  
                                        //  ------------         |
                                        // |    1000    |---------
                                        //  ------------
                                        //     headPtr       // but if i write *headPtr indirectly i am referencing to head pointer   
                                        //                   // *headPtr = newnode we are saying (head = newnode)                                                  
    if(*headPtr == NULL){   
        *headPtr = newNode;
        return ;
    }
    newNode -> next = *headPtr;
    *headPtr = newNode;
    return ;
}


void display(Node**head){
    Node*temp = *head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    } 
}

int main(){
    Node* head = NULL;         
    insertAtBegin(&head,1);
    insertAtBegin(&head,2);
    insertAtBegin(&head,3);
    display(&head);
    insertAtBegin(&head,5);
    cout<<endl;
    display(&head);
    return 0;
}

