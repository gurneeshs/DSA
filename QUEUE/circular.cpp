#include <iostream>
using namespace std;

class CircularQueue{
    int *arr,front,rear,size;

    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        this->size = n;
        arr = new int[size];
        front=-1;
        rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if(front==rear && front!=-1){
            return false;
        }
        else{
            if(front==rear && front==-1){
                front = front+1;
                rear = rear+1;
            }
            arr[rear] = value;
            rear = (rear+1)%size;
            return true;
        }
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front==-1){
            return -1;
        }
        else{
            int ans = arr[front];
            front = (front+1)%size;
            if(front==rear){
                front= -1;
                rear = -1;
            }
            return ans;
        }
    }
};

int main(){
    CircularQueue q(27);
    cout<<q.enqueue(39)<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.enqueue(22)<<endl;
    cout<<q.enqueue(34)<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    // cout<<q.enqueue(39)<<endl;
    // cout<<q.enqueue(39)<<endl;
    // cout<<q.enqueue(39)<<endl;

    return 0;
}