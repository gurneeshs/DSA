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
// Approach 1
Node* Sort012(Node* &head){
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;
    Node* temp = head;
    while (temp!=NULL)
    {
        if(temp->data==0){
            countZero++;
        }
        else if(temp->data==1){
            countOne++;
        }
        else if(temp->data==2){
            countTwo++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp!=NULL)
    {
        if(countZero!=0){
            temp->data = 0;
            countZero--;
        }
        else if(countOne!=0){
            temp->data = 1;
            countOne--;

        }
        else if(countTwo!=0){
            temp->data = 2;
            countTwo--;
        }
        temp = temp->next;
        /* code */
    }
    return head;
}

// Approach 2
Node* Sort012New(Node* &head){
    Node* head0 = new Node(404);
    Node* head1 = new Node(404);
    Node* head2 = new Node(404);

    Node* temp0 = head0;
    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==0){
            temp0->next = temp;
            temp0 = temp0->next;
        }
        else if(temp->data==1){
            temp1->next=temp;
            temp1 = temp1->next;
        }
        else if(temp->data==2){
            temp2->next = temp;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }

    head = head0->next;
    head0->next = NULL;
    temp0->next = head1->next;
    head1->next=NULL;
    temp1->next = head2->next;
    head2->next = NULL;
    temp2->next = NULL;

    delete head0;
    delete head1;
    delete head2;

    return head;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(0);
    Node* n3 = new Node(2);
    Node* n4 = new Node(1);
    Node* n5 = new Node(2);
    // Node* n6 = new Node(2);

    Node* head = n1;
    // Node* tail = n6;
    

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    // n6->next = NULL;

    printList(head);
    head = Sort012New(head);
    printList(head);
    return 0;
}