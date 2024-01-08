#include <iostream>
using namespace std;

class TwoStack {

public:
    int siz,top1=-1,top2=-1;
    int* arr;

    // Initialize TwoStack.
    TwoStack(int s) {
        arr = new int(siz);
        top1 = -1;
        top2 = siz;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top1<top2){
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top1<top2){
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1<0){
            return -1;
        }
        else{
            cout<<arr[top1]<<endl;
            top1--;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2>=siz){
            return -1;
        }
        else{
            cout<<arr[top2]<<endl;
            top2++;
        }
    }
};
