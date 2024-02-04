// Deletion of Node

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

// Deletion from Beginning
void deletionBeginning(Node* &head){
    // No Node
    if(head==NULL){
        cout<<"No Node to delete"<<endl;
        return;
    }
    // Single Node
    if(head->next==NULL){
        delete(head);
        head=NULL;
        return;
    }
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete(temp);
}

// Deletion from end
void deletionEnd(Node* head, Node* tail){
    // No Node
    if(head==NULL){
        cout<<"No Node to delete"<<endl;
        return;
    }
    // Single Node
    if(head->next==NULL){
        delete(head);
        head=NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node* temp1 = temp->next;
    tail = temp;
    temp->next=NULL;
    delete(temp1);
}
// Deletion at Position
void deletionAtPosition(Node* &head, Node* &tail, int position){
    if(position<=0){
        cout<<"Invalid Position"<<endl;
        return;
    }
    // no node
    if(head==NULL){
        cout<<"No Node to delete"<<endl;
        return;
    }
    // Single Node
    if(head->next==NULL){
        delete(head);
        head=NULL;
        return;
    }
    // beginning node
    if(position==1){
        deletionBeginning(head);
        return;
    }

    int cnt=1;
    Node* prev = head;
    Node* Next= head->next;
    while(cnt<position-1){
        Next = Next->next;
        prev=prev->next;
        if(Next==NULL && cnt+1<position){
            cout<<"Invalid Positon"<<endl;
            return;
        }
        cnt++;
    }
    if(Next->next==NULL){
        deletionEnd(head,tail);
        return;
    }
    Node* temp = Next;

    prev->next = Next->next;
    temp->next = NULL;
    delete temp;
    // delete(Next);

}

// Deletion from a value
void deletionFromValue(Node* &head, Node* &tail, int data){
    // no node
    if(head==NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    // single node
    if(head->next==NULL){
        if(head->data==data){
            delete head;
            head=NULL;
            return;
        }
        else{
            cout<<"No node to delete"<<endl;
            return;
        }
    }
    // beginning node
    if(head->data==data){
        deletionBeginning(head);
        return;
    }
    Node* temp = head->next;
    Node* prev = head;
    while(temp!=NULL){
        if(temp->data==data){
            if(temp->next==NULL){
                deletionEnd(head,tail);
                return;
            }

            prev->next = temp->next;
            delete temp;
            return;
        }
        temp=temp->next;
        prev=prev->next;
    }
    cout<<"No node to delete";

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
    // deletionEnd(head,tail);
    deletionAtPosition(head,tail,4);
    // deletionFromValue(head,tail,25);
    printList(head);
    return 0;
}
