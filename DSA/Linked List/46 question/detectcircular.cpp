/*
    Using Map Detect Circular Loop
    Time Complexity:O(n)
    Space Complexity:O(n)
*/
#include <iostream>
#include <map>
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
    while(temp!=NULL || temp!=head){
        if(temp->next==NULL || temp->next==head){
            cout<<"||"<<temp->data<<"|"<<temp->next<<"||"<<endl;
            return;
            
        }
        cout<<"||"<<temp->data<<"|"<<temp->next<<"||"<<"-->";
        temp = temp->next;
    }
}

// void detect circular
bool detectCircular(Node* head){
    if(head==NULL || head->next == head){
        return true;
    }
    if(head->next == NULL){
        return false;
    }
    map<Node*,bool> m1;


    Node* temp = head;
    while(temp!=NULL){

        if(temp->next==NULL){
            return false;
        }
        if(m1[temp]==true){
            return true;
        }
        
        m1[temp] = true;
        cout<<temp<<" "<<m1[temp]<<endl;
        temp=temp->next;
    }
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

    // printList(head);
    bool result = detectCircular(head);
    cout<<result;
    // printList(head);
    return 0;
}