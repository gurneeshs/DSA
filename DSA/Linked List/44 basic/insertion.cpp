/*Insertion in Linked List*/
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

// Insertion at beginning
void insertBeginning(Node* &head,Node* &tail, int data){
    Node* temp = new Node(data);
    if(head==NULL){
        head = temp;
        tail = temp;
        return;    
    }
    temp->next = head;
    head = temp;
}

// Insertion at End
void insertEnd(Node* &head,Node* &tail,int data){
    Node* temp = new Node(data);
    if(head==NULL){
        head = temp;
        tail = temp;  
        return;  
    }
    tail->next = temp;
    tail = temp;
}

// Insertion at particular position
void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    Node* temp = new Node(data);
    Node* temp1 = head;
    cout<<head<<" "<<temp1<<endl;
    
    // No Node
    if(head==NULL){
        head = temp;
        tail = temp;  
        return;  
    }

    // First Position
    if(position==1){
        insertBeginning(head,tail,data);
        return;
    }
    int cnt=1;
    while(cnt<position-1){
        temp1=temp1->next;
        cnt++;
    }

    // Last Position
    if(temp1->next==NULL){
        insertEnd(head,tail,data);
        return;
    }

    // Particular Position
    temp->next = temp1->next;
    temp1->next = temp;
}
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
    Node* head, *tail;
    head=NULL;
    tail=NULL;
    insertBeginning(head,tail,4);
    insertEnd(head,tail,8);
    insertEnd(head,tail,12);
    insertAtPosition(head,tail,9,4);

    printList(head);
    return 0;
}