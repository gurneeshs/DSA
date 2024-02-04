#include <iostream>
using namespace std;

class Deque
{
    int *arr, front,rear,siz;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        this->siz = n;
        arr = new int[siz];
        front=-1;
        rear=-1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if((rear+1)%siz==front){
            return false;
        }
        else{
            if(front==rear && front==-1){
                front = front+1;
                rear = rear+1;
                arr[front] = x;
            }
            else{
                if(front==0){
                    front = siz-1;
                }
                else{
                    front--;
                }
                arr[front] = x;
            }
            return true;
        }
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if((rear+1)%siz==front){
            return false;
        }
        else{
            if(front==rear && front==-1){
                front = front+1;
                rear = rear+1;
            }
            else{
                rear = (rear+1)%siz;
            }
            arr[rear] = x;
            return true;
        }
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(front==-1){
            return -1;
        }
        else{
            int ans = arr[front];
            if(front==rear){
                front=-1;
                rear=-1;                
            }
            else{
                front = (front+1)%siz;
            }
            return ans;
        }
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(front==-1){
            return -1;
        }
        else{
            int ans = arr[rear];
            if(front==rear){
                front=-1;
                rear=-1;
            }
            else if(rear==0){
                rear = siz-1;
            }
            else{
                rear--;
            }
            return ans;
        }
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(front==-1){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(front==-1){
            return -1;
        }
        else{
            return arr[rear];
        }
    }


    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front==-1){
            return true;
        }
        else{
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((rear+1)%siz==front){
            return true;
        }
        else{
            return false;
        }
    }
};