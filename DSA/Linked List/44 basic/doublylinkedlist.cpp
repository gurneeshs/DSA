#include <iostream>
using namespace std;

// Node
class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(){
            this->data = 0;
            this->next = NULL;
            this->prev = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
        ~Node(){
            int value = this->data;
            if(this->next!=NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory is freed for data"<<value<<endl;

        }
};

// *****************************INSERTION***********************************
// Insert At Beginning
void insertAtBegining(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    // no node
    if(head==NULL){
        head = newNode;
        tail = newNode;
        head->prev = NULL;
        head->next = NULL;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert At End
void insertAtEnd(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    // no node
    if(head==NULL){
        head = newNode;
        tail = newNode;
        head->prev = NULL;
        head->next = NULL;
        return;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Insert At Position
void insertAtPosition(Node* &head, Node* &tail, int data, int pos){
    if(pos<=0){
        cout<<"Invalid Position"<<endl;
        return;
    }
    Node* newNode = new Node(data);
    // no node
    if(head==NULL){
        head = newNode;
        tail = newNode;
        head->prev = NULL;
        head->next = NULL;
        return;
    }
    // at beginning
    if(pos==1){
        insertAtBegining(head,tail,data);
        return;
    } 

    int cnt = 1;
    Node* temp = head;
    while(cnt<pos-1){
        temp=temp->next;
        if(temp==NULL && cnt+1<pos){
            cout<<"Invalid Position"<<endl;
            return;
        }
        cnt++;
    }
    // at end
    if(temp->next==NULL){
        insertAtEnd(head,tail,data);
        return;
    }
    // at position
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next=newNode;
}   
// *****************************DELETION************************************
// Deletion from Beginning
void deleteAtBeg(Node* &head,Node* &tail){
    // no node
    if(head==NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    // single node
    if(head->next==NULL){
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}

// Deletion At End
void deleteAtEnd(Node* &head, Node* &tail){
    // no node
    if(head==NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    // single node
    if(head->next==NULL){
        delete head;
        head = NULL;
        return;
    }
    Node *temp = tail;
    temp->prev->next = NULL;
    tail = temp->prev;
    temp->prev = NULL;
    delete temp;
}

// Deletion at Position
void deletionAtPosition(Node* &head, Node* &tail, int position){
    if(position<=0){
        cout<<"Invalid Position"<<endl;
        return;
    }
    // no node
    if(head==NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    // single node
    if(head->next==NULL){
        if(position==1){
            delete head;
            head = NULL;
            return;
        }
        else{
            cout<<"Invalid Position"<<endl;
            return;
        }
    }
    if(position==1){
        deleteAtBeg(head,tail);
        return;
    }
    int cnt = 1;
    Node* temp = head->next;
    Node* back = head;

    while(cnt<position-1){
        temp = temp->next;
        back = back->next;
        if(temp==NULL && cnt+1<position){
            cout<<"Invalid Position"<<endl;
            return;
        }
        cnt++;
    }
    if(temp->next==NULL){
        deleteAtEnd(head,tail);
        return;
    }
    Node* del = temp;
    back->next = temp->next;
    temp->next->prev = temp->prev;
    del->next  = NULL;
    del->prev = NULL;
    delete del;
}
// Deletion by value
void deletionByvalue(Node* &head, Node* &tail, int data){
    if(head==NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    // single node
    if(head->next==NULL){
        if(head->data==data){
            delete head;
            head = NULL;
            return;
        }
        else{
            cout<<"No node to delete"<<endl;
            return;
        }
    }
    // beginning node
    if(head->data==data){
        deleteAtBeg(head,tail);
        return;
    }
    Node* temp = head->next;
    Node* back = head;

    while(temp!=NULL){
        if(temp->data==data){
            if(temp->next==NULL){
                deleteAtEnd(head,tail);
                return;
            }
            Node* delNode = temp;
            back->next = temp->next;
            temp->next->prev = temp->prev;
            delNode->next=NULL;
            delNode->prev = NULL;
            delete delNode;
            return;
        }
        temp = temp->next;
        back = back->next;
        if(temp==NULL){
            cout<<"No node to delete"<<endl;
            return;
        }
    }
    cout<<"No node to delete"<<endl;
}
// *******************************PRINT*************************************
void printList(Node* head){
    Node* temp = head;
    while (temp!=NULL)
    {
        if(temp->next==NULL){
            cout<<"[ "<<temp->prev<<" | "<<temp->data<<" | "<<temp->next<<" ]"<<endl;
            return;
        }
        cout<<"[ "<<temp->prev<<" | "<<temp->data<<" | "<<temp->next<<" ]"<<"<-->";
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

    n1->prev = NULL;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;
    n5->next = NULL;

    printList(head);
    // insertAtBegining(head,tail,1);
    // insertAtEnd(head,tail,30);
    // insertAtPosition(head,tail,124,2);

    // deleteAtBeg(head,tail);
    // deleteAtEnd(head,tail);
    // deletionAtPosition(head,tail,5);
    // deletionByvalue(head,tail,15);
    printList(head);
    return 0;
}