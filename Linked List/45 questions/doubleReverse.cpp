#include <iostream>
using namespace std;

// Creating Node
class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        // Constructor
        Node(){
            this->data = 0;
            this->next = NULL;
            this->prev = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
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
void printList(Node* head){
    Node* temp = head;
    while (temp!=NULL)
    {
        if(temp->next==NULL){
            cout<<"[ "<<temp->prev<<" | "<<temp->data<<" | "<<temp->next<<" ]"<<endl;
            return;
        }
        cout<<"[ "<<temp->prev<<" | "<<temp->data<<" | "<<temp->next<<" ]"<<"<-->";
        temp = temp->next;
    }
    
}
// approach 1, Using While loop
Node* reverseList(Node* &head){
    // no node or single node
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node *prev1 = NULL;
    Node *curr = head;
    Node *fwd = head;

    while (curr!=NULL)
    {
        fwd = curr->next;
        curr->next = prev1;
        curr->prev = fwd;

        prev1 = curr;
        curr = fwd;   
    }
    head = prev1;
    return head;
}
// approach 2, using recursion
Node* reverseUsingRecursion(Node* &head, Node* &prev1, Node* &fwd){
    if(head->next==NULL){
        head->next = prev1;
        head->prev = NULL;
        return head;
    }

    fwd = head->next;
    head->next = prev1;
    head->prev = fwd;


    prev1 = head;
    head = fwd;
    reverseUsingRecursion(head,prev1,fwd);
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
    n1->prev = NULL;
    n2->next = n3;
    n2->prev = n1;
    n3->next = n4;
    n3->prev = n2;
    n4->next = n5;
    n4->prev = n3;
    n5->next = NULL;
    n5->prev = n4;

    printList(head);
    // cout<<reverseList(head)<<endl;
    cout<<reverseRecursion(head)<<endl;
    printList(head);
    return 0;
}