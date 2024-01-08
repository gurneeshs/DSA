#include <iostream>
using namespace std;

// Creating Node
class Node{
    public:
        int data;
        Node* next;
        Node* child;

        // Constructor
        Node(){
            this->data = 0;
            this->next = NULL;
            this->child = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->child = NULL;
        }
        // Destructor
        ~Node(){
            int value = this->data;
            if(this->next!=NULL){
                delete next;
                this->next = NULL;
                this->child = NULL;
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
Node* flattenLinkedList(Node* head) 
{
	if(head==NULL){
		return head;
	}
	Node* temp = head;
	Node* next = NULL;
	while(temp!=NULL){
		if(temp->child!=NULL){
			next = temp->next;
			temp->next = temp->child;
			temp->child = NULL;
		}
		else if(temp->next==NULL && next!=NULL){
			temp->next = next;
			next = NULL;
		}
		temp = temp->next;
	}
	return head;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(8);
    Node* n3 = new Node(18);
    Node* n4 = new Node(29);
    // Node* n5 = new Node(20);
    Node* nc1 = new Node(2);
    Node* nc2 = new Node(3);
    Node* nc3 = new Node(10);
    Node* nc4 = new Node(15);
    Node* nc5 = new Node(22);
    // Node* nc6 = new Node(12);

    Node* head = n1;
    // Node* head2 = n4;
    // Node* tail = n6;
    

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    // n5->next = NULL;
    nc1->next = nc2;
    nc3->next = nc4;

    n1->child = nc1;
    n2->child = nc3;
    n3->child = nc5;
    n4->child = NULL;

    printList(head);
    head = flattenLinkedList(head);
    printList(head);

    return 0;
}