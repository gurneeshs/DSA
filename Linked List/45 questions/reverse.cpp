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

// approach 1, Using While loop
Node* reverseList(Node* &head){
    // no node or single node
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *fwd = head;

    while (curr!=NULL)
    {
        fwd = curr->next;
        curr->next = prev;

        prev = curr;
        curr = fwd;   
    }
    head = prev;
    return head;
}
// approach 2, using recursion
Node* reverseUsingRecursion(Node* &head, Node* &prev, Node* &fwd){
    if(head->next==NULL){
        head->next = prev;
        return head;
    }

    fwd = head->next;
    head->next = prev;

    prev = head;
    head = fwd;
    reverseUsingRecursion(head,prev,fwd);
}
Node* reverseRecursion(Node* &head){
    Node* prev = NULL;
    Node* fwd = head;
    return reverseUsingRecursion(head,prev,fwd);
}
int main(){
    Node* n1 = new Node(5);
    Node* n2 = new Node(10);
    Node* n3 = new Node(15);
    Node* n4 = new Node(20);
    Node* n5 = new Node(25);

    Node* head = n1;
    Node* tail = n5;
    

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    printList(head);
    // cout<<reverseList(head)<<endl;
    cout<<reverseRecursion(head)<<endl;
    printList(head);
    return 0;
}