// Implement the stack

#include <iostream>
using namespace std;

class Stack{
    public:
        int *arr;
        int top;
        int size;

        // Constructor
        Stack(int size){
            this->size = size;
            arr = new int(size);
            top = -1;
        }

        // Functions
        void push(int data){
            if(top==size-1){
                cout<<"Stack is full"<<endl;
            }
            else{
                top++;
                arr[top] = data;
            }
        }
        void pop(){
            if(top<0){
                cout<<"Stack is empty"<<endl;
            }
            else{
                cout<<arr[top]<<"is popped"<<endl;
                arr[top] = -1;
                top--;
            }
        }
        int peek(){
            if(top<0){
                cout<<"stack is empty"<<endl;
                return -1;
            }
            else{
                return arr[top];
            }
        }
        bool isempty(){
            if(top<0){
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){
    Stack s(5);
    cout<<s.peek()<<endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(1);
    s.push(2);
    s.push(3);

    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;

    return 0;
}