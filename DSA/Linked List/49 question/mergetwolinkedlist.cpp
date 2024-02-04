/*
    Merge two sorted Linked List
    Try to solve in linear time complexity & constant space complexity
    List may or may not be Null
*/

#include <iostream>
using namespace std;

// Creating Node
class Node{
    public:
        int data;
        Node* next;

        // Constructor
        Node(){
            this->data = 0;
            this->next = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        // Destructor
        ~Node(){
            int value = this->data;
            if(this->next!=NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory is freed for data"<<value<<endl;
        }
};

// Printing List
void printList(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->next==NULL){
            cout<<"||"<<temp->data<<"|"<<temp->next<<"||"<<endl;
            return;
            
        }
        cout<<"||"<<temp->data<<"|"<<temp->next<<"||"<<"-->";
        temp = temp->next;
    }
}
void solve(Node* &head1, Node* &head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* curr1 = head1;
    Node* curr2 = head2;

    while(temp1!=NULL && temp2!=NULL){
        if(temp2->data<temp1->data){

        }
    }

}
Node* mergeLinkedList(Node* head1, Node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1==NULL && head2==NULL){
        return head1;
    }

    if(head1->data<=head2->data){
        solve(head1,head2);
    }
    else{
        solve(head2,head1);
    }

}
int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(4);
    Node* n3 = new Node(5);
    Node* n4 = new Node(2);
    Node* n5 = new Node(3);
    Node* n6 = new Node(5);

    Node* head1 = n1;
    Node* head2 = n4;
    // Node* tail = n6;
    

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;

    printList(head1);
    printList(head2);
    return 0;
}