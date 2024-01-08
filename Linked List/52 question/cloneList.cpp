#include <iostream>
#include <map>
using namespace std;

// Creating Node
class Node{
    public:
        int data;
        Node* next;
        Node* random;

        // Constructor
        Node(){
            this->data = 0;
            this->next = NULL;
            this->random = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }
        // Destructor
        ~Node(){
            int value = this->data;
            if(this->next!=NULL){
                delete next;
                this->next = NULL;
                this->random = NULL;
            }
            cout<<"Memory is freed for data"<<value<<endl;
        }
};

// Printing List
void printList(Node* &head){
    cout<<"Node->data"<<" "<<"Node->next"<<" "<<"Node->random->data"<<endl;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->next==NULL){
            cout<<"||"<<temp->data<<"|"<<temp->next<<"|"<<temp->random->data<<"||"<<endl;
            return;
            
        }
        cout<<"||"<<temp->data<<"|"<<temp->next<<"|"<<temp->random->data<<"||"<<"-->";
        temp = temp->next;
    }
}
// Approach 2
Node* cloneLinkedList(Node* head){
    if(head==NULL){
        return head;
    }

    map<Node*,Node*> mapping;
    
    Node* clonehead = new Node(head->data);
    mapping[head] = clonehead;
    Node* temp = head->next;
    Node* tempc = clonehead;

    while(temp!=NULL){
        Node* newNode = new Node(temp->data);
        tempc->next = newNode;
        mapping[temp] = newNode;

        temp = temp->next;
        tempc = tempc->next;
    }

    tempc = clonehead;
    temp = head;

    while(tempc!=NULL){
        tempc->random = mapping[temp->random];
        temp = temp->next;
        tempc = tempc->next;
    }
    return clonehead;
}
// Approach 3
Node* cloneLinkedList2(Node* head){
    if(head==NULL){
        return head;
    }

    Node* clonehead = new Node(head->data);
    Node* temp = head->next;
    Node* tempc = clonehead;

    while(temp!=NULL){
        Node* newNode = new Node(temp->data);
        tempc->next = newNode;
        temp = temp->next;
        tempc = tempc->next;
    }

    tempc = clonehead;
    temp = head;
    Node* next1 = temp->next;
    Node* next2 = tempc->next;

    while(temp!=NULL && tempc!=NULL){
        temp->next = tempc;
        tempc->next = next1;

        temp = next1;
        tempc = next2;
        if(next1!=NULL && next2!=NULL){
            next1 = next1->next;
            next2 = next2->next;
        }
    }
    temp = head;
    while(temp!=NULL){
        temp->next->random = temp->random->next;
        temp = temp->next->next;
    }
    tempc = clonehead;
    while(tempc!=NULL){
        if(tempc->next==NULL){
            break;
        }
        tempc->next = tempc->next->next;
        tempc = tempc->next;
    }
    return clonehead;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    // Node* n5 = new Node(5);

    Node* head = n1;
    // Node* tail = n6;
    

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    // n5->next = NULL;
    // n6->next = NULL;
    n1->random = n2;
    n2->random = n4;
    n3->random = NULL;
    n4->random = NULL;
    // n5->random = n2;

    // printList(head);
    Node* clonehead = cloneLinkedList2(head);
    printList(clonehead);
    return 0;
}