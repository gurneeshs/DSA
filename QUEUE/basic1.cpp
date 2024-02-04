/*
    Implement Queue using linked list
*/

#include <iostream>
using namespace std;

class Node{
    public:

        int data;
        Node* next;
        Node(){
            this->data = data;
            this->next = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Queue {
    Node* qfront;
    Node* rear;
    int size;
public:
    Queue() {
        qfront = NULL;
        rear = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront==rear && rear==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
        Node* newnode = new Node(data);
        if(qfront==rear && qfront==NULL){
            qfront = newnode;
            rear = newnode;
            rear->next = NULL;
        }
        else{
            rear->next = newnode;
            rear = newnode;
        }
    }

    int dequeue() {
        if(qfront==rear && rear==NULL){
            return -1;
        }
        else{
            int ans = qfront->data;
            Node* temp = qfront;
            qfront = qfront->next;
            temp->next = NULL;
            delete temp;
            if(qfront==rear->next){
                qfront = rear = NULL;
            }
            return ans;

        }
    }

    int front() {
        if(qfront==rear && rear==NULL){
            return -1;
        }
        else{
            return qfront->data;
        }
        
    }
};

int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    cout<<q.dequeue()<<endl;

    return 0;
}