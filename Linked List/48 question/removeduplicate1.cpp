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
Node* merge(Node* L, Node* R){
    if(L==NULL)
        return R;
    if(R==NULL)
        return L;

    Node* h = NULL;
    if(L->data < R->data){
        h = L;
        h->next = merge(L->next,R);
    }
    else{
        h = R;
        h->next = merge(L,R->next);
    }
    return h;
}
// Merge Sort
Node* MergeSort(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    // find middle
    Node* slow = head;
    Node* fast = head->next;
    while(fast->next!=NULL){
        fast = fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }

    Node* left = head;
    Node* right = slow->next;
    slow->next = NULL;

    left = MergeSort(left);
    right = MergeSort(right);
    return merge(left, right);
}


// remove duplicate
void removeDuplicate(Node* &head){
    if(head==NULL || head->next==NULL){
        return;
    }
    head = MergeSort(head);
    Node* curr = head;
    Node* toDelete = NULL;
    Node* nexttonext = NULL;
    while(curr!=NULL){
        if((curr->next!=NULL) && curr->data==curr->next->data){
            nexttonext = curr->next->next;
            toDelete = curr->next;
            toDelete->next = NULL;
            curr->next = nexttonext;
            delete toDelete;
        }
        else{
            curr=curr->next;
        }
    }    
}

int main(){
    Node* n1 = new Node(4);
    Node* n2 = new Node(2);
    Node* n3 = new Node(5);
    Node* n4 = new Node(4);
    Node* n5 = new Node(2);
    Node* n6 = new Node(2);

    Node* head = n1;
    Node* tail = n6;
    

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;

    printList(head);
    removeDuplicate(head);
    // head = MergeSort(head);
    printList(head);
    return 0;
}