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

// remove duplicate
void removeDuplicate(Node* &head){
    if(head==NULL || head->next==NULL){
        return;
    }

    Node* curr = head;
    Node* toDelete = NULL;
    Node* nexttonext = NULL;
    while(curr!=NULL){
        if((curr->next!=NULL) && curr->data==curr->next->data){
            nexttonext = curr->next->next;
            toDelete = curr->next;
            toDelete->next = NULL;
            curr->next = nexttonext;
            delete toDelete;
        }
        else{
            curr=curr->next;
        }
    }
    
}
int main(){
    Node* n1 = new Node(5);
    Node* n2 = new Node(10);
    Node* n3 = new Node(10);
    Node* n4 = new Node(20);
    Node* n5 = new Node(20);
    Node* n6 = new Node(30);

    Node* head = n1;
    Node* tail = n6;
    

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;

    printList(head);
    removeDuplicate(head);
    printList(head);
    return 0;
}