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

// Reverse List
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

Node* solve(Node* Num1, Node* Num2){
    Num1 = reverse(Num1);
    Num2 = reverse(Num2);

    Node* temp1 = Num1;
    Node* temp2 = Num2;
    int car = 0;
    int sm = 0;
    int digit=0;

    while(temp1!=NULL && temp2!=NULL){
        sm = temp1->data + temp2->data+car;
        digit = sm%10;
        car = sm/10;
        temp1->data = digit;
        if(temp1->next==NULL && car>0){
            Node* newNode = new Node(car);
            temp1->next = newNode;
            newNode->next = NULL;
            temp1=NULL;
            break;
        }
        temp1 =temp1->next;
        temp2 =temp2->next;
    }
    while(temp1!=NULL){
        sm = temp1->data+car;
        digit = sm%10;
        car = sm/10;
        temp1->data = digit;
        if(car>0 && temp1->next==NULL){
            Node* newNode = new Node(car);
            temp1->next = newNode;
            newNode->next = NULL;
            break;
        }
        temp1 = temp1->next;

    }
    Num1 = reverse(Num1);
    return Num1;
}
Node* addNumber(Node* Num1, Node* Num2){
    if(!Num1){
        return Num2;
    }
    if(!Num2){
        return Num1;
    }
    int len1 = 0;
    int len2 = 0;

    Node* temp1 = Num1;
    Node* temp2 = Num2;

    while(temp1!=NULL){
        len1++;
        temp1 = temp1->next;
    }
    while(temp2!=NULL){
        len2++;
        temp2 = temp2->next;
    }

    if(len1>=len2){
        return solve(Num1,Num2);
    }
    else{
        return solve(Num2, Num1);
    }
}
int main(){
    Node* n1 = new Node(9);
    Node* n2 = new Node(9);
    Node* n3 = new Node(9);
    Node* n4 = new Node(9);
    Node* n5 = new Node(9);
    Node* n6 = new Node(9);

    Node* head1 = n1;
    Node* head2 = n4;
    // Node* tail = n6;
    

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;

    printList(head1);
    printList(head2);
    Node* result = addNumber(head1, head2);
    printList(result);

    return 0;
}