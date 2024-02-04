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

// find middle
Node* findMiddle(Node* head){
    if(head==NULL || head->next==NULL ||head->next->next==NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast->next!=NULL){
        fast = fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* fwd = NULL;
    Node* curr = head;

    while(curr!=NULL){
        fwd = curr->next;
        curr->next = prev;

        prev = curr;
        curr = fwd;
    }
    head = prev;
    return head;
}

bool checkPalindrome(Node* head){
    Node* mid = findMiddle(head);
    mid->next = reverse(mid->next);

    Node* pnt1 = head;
    Node* pnt2 = mid->next;

    while(pnt1!=mid->next && pnt2!=NULL){
        if(pnt1->data!=pnt2->data){
            return false;
        }
        pnt1 = pnt1->next;
        pnt2 = pnt2->next;
    }
    mid->next = reverse(mid->next);
    return true;
}
int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(3);
    Node* n5 = new Node(1);
    Node* n6 = new Node(1);

    Node* head = n1;
    // Node* head2 = n4;
    // Node* tail = n6;
    

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;

    printList(head);
    cout<<checkPalindrome(head)<<endl;
    printList(head);
    return 0;
}