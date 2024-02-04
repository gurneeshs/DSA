#include <iostream>
using namespace std;

// Node
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

// *************************************INSERTION***************************************
// Insertion at beginning
void insertBeginning(Node* &head,Node* &tail, int data){
    Node* temp = new Node(data);
    if(head==NULL){
        head = temp;
        tail = temp;
        head->next=head;
        return;    
    }
    temp->next = head;
    head = temp;
    tail->next=head;
}

// Insertion at End
void insertEnd(Node* &head,Node* &tail,int data){
    Node* temp = new Node(data);
    if(head==NULL){
        head = temp;
        tail = temp;  
        head->next=head;
        return;  

    }
    tail->next = temp;
    tail = temp;
    tail->next=head;
}

// Insertion at particular position
void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    Node* temp = new Node(data);
    Node* temp1 = head;
    
    // No Node
    if(head==NULL){
        head = temp;
        tail = temp; 
        head->next = head; 
        return;  
    }

    // First Position
    if(position==1){
        insertBeginning(head,tail,data);
        return;
    }
    int cnt=1;
    do{
        
        temp1=temp1->next;
        cnt++;
        if(temp1==head && cnt<position){
            cout<<"Invalid position"<<endl;
            return;
        }
        
    }
    while(cnt<position-1);

    // Last Position
    if(temp1->next==head){
        insertEnd(head,tail,data);
        return;
    }

    // Particular Position
    temp->next = temp1->next;
    temp1->next = temp;
}

// *************************************DELETION****************************************
// Deletion from Beginning
void deletionBeginning(Node* &head,Node* &tail){
    // No Node
    if(head==NULL){
        cout<<"No Node to delete"<<endl;
        return;
    }
    // Single Node
    if(head->next==head){
        delete head;
        head=NULL;
        head->next=NULL;
        return;
    }
    Node* temp = head;
    head = head->next;
    tail->next=head;
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
    if(head->next==head){
        delete(head);
        head=NULL;
        head->next=NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    Node* temp1 = temp->next;
    tail = temp;
    tail->next=head;
    temp1->next=NULL;
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
    if(head->next==head){
        delete(head);
        head=NULL;
        head->next=NULL;
        return;
    }
    // beginning node
    if(position==1){
        deletionBeginning(head,tail);
        return;
    }

    int cnt=1;
    Node* prev = head;
    Node* Next= head->next;
    while(cnt<position-1){
        Next = Next->next;
        prev=prev->next;
        if(Next==head && cnt+1<position){
            cout<<"Invalid Positon"<<endl;
            return;
        }
        cnt++;
    }
    if(Next->next==head){
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
    if(head->next==head){
        if(head->data==data){
            delete head;
            head=NULL;
            head->next=NULL;
            return;
        }
        else{
            cout<<"No node to delete"<<endl;
            return;
        }
    }
    // beginning node
    if(head->data==data){
        deletionBeginning(head,tail);
        return;
    }
    Node* temp = head->next;
    Node* prev = head;
    while(temp!=head){
        if(temp->data==data){
            if(temp->next==NULL){
                deletionEnd(head,tail);
                return;
            }

            prev->next = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        }
        temp=temp->next;
        prev=prev->next;
    }
    cout<<"No node to delete";

}

// ***************************************PRINT*****************************************
void printList(Node* &head){
    Node* temp = head;
    do{
        if(temp->next==head){
            cout<<"||"<<temp->data<<"|"<<temp->next<<"||"<<endl;
            return;
            
        }
        cout<<"||"<<temp->data<<"|"<<temp->next<<"||"<<"-->";
        temp = temp->next;
    }while(temp!=head);
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
    n5->next = n1;

    printList(head);
    // insertBeginning(head,tail,3);
    // insertEnd(head,tail,35);
    // insertAtPosition(head,tail,1245,6);

    // deletionBeginning(head,tail);
    // deletionEnd(head,tail);
    // deletionAtPosition(head,tail,6);
    // deletionFromValue(head,tail,15);
    printList(head);
    return 0;
}
