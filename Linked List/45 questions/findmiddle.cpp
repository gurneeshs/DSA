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

// iterative approach
Node* findMid(Node* head){
    Node* temp = head;
    int cnt = 0,mid=0;

    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    if(cnt%2==0){
        mid = (cnt/2)+1;
    }
    else{
        mid = cnt/2;
    }

    temp = head;
    cnt = 1;
    while(cnt<mid){
        temp = temp->next;
        cnt++;
    }
    return temp;
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
    cout<<findMid(head)<<endl;


    return 0;
}