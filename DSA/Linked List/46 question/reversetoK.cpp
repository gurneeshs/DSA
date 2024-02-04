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

// Reverse to k group
Node* reverse(Node* head, int k){
    // base case
    if(head==NULL){
        return NULL;
    }
    
    Node* next = NULL;
    Node* prev = NULL;
    Node* curr = head;
    int count = 0;
    
    // 1st case
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

        count++;
    }
    // recursion
    if(next!=NULL){
        head->next = reverse(curr,k);
    }
    
    // ans
    return prev;
}

int main(){
    Node* n1 = new Node(5);
    Node* n2 = new Node(10);
    Node* n3 = new Node(15);
    Node* n4 = new Node(20);
    Node* n5 = new Node(25);
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
    head = reverse(head,6);
    printList(head);
    return 0;
}