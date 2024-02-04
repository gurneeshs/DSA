/*
    Using Floyd Cycle Detection Detect Circular Loop
    Time Complexity:O(n)
    Space Complexity:O(1)
*/

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

// Loop Detection
Node* detectLoop(Node* &head){
    
    if(head==NULL || head->next==NULL)
        return NULL;
    
    if(head->next==head)
        return head;
    
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow=slow->next;

        // loop detected
        if(fast==slow){
            return slow;
        }
    }
    return NULL;
}
// Starting node of loop
Node* getStartNode(Node* head){
    if(head==NULL)
        return NULL;
    Node* intersection = detectLoop(head);
    if(intersection==NULL)
        return NULL;

    Node* slow = head;
    while(slow!=intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return intersection;
}
void removeLoop(Node* head){
    if (head==NULL)
        return ;

    Node* startLoop = getStartNode(head);
    // if(startLoop==NULL)
    //     return head;
    Node* temp = startLoop;

    while(temp->next!=startLoop){
        temp=temp->next;
    }
    temp->next=NULL;
}
// Printing List
void printList(Node* &head){
    Node* temp = head;
    Node* startLoop = getStartNode(head);
    while(temp!=NULL && temp!=startLoop){
        if(temp->next==NULL || temp->next==head ||temp->next==startLoop){
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
    Node* n6 = new Node(30);

    Node* head = n1;
    Node* tail = n6;
    

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n3;
    cout<<getStartNode(head)->data<<endl;
    printList(head);
    // removeLoop(head);
    // printList(head);
    return 0;
}