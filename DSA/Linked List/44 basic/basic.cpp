// Creating a node and a single linked list

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

int main(){
    Node* n1 = new Node(5);
    Node* n2 = new Node(10);

    n1->next = n2;
    printList(n1);
    return 0;
}
