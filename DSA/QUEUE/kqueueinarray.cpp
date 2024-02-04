/*
    Given an array of size N, You have to implement 
    K queues in the array.
*/

#include <iostream>
using namespace std;

class kQueue{
    public:
        int *front, *rear, *next, *arr;
        int freespot, n , k;

        kQueue(int N, int K){
            this->n = N;
            this->k = K;

            front = new int[k];
            rear = new int[k];
            next = new int[n];
            arr = new int[n];

            for(int i=0;i<k;i++){
                front[i]=-1;
                rear[i]=-1;
            }
            for(int i=0;i<n;i++){
                next[i] = i+1;
            }
            next[n-1]=-1;
            freespot = 0;

        }

        void enqueue(int data, int q){
            // Overflow
            if(freespot==-1){
                cout<<"Overflow"<<endl;
                return;
            }
            // find index
            int index = freespot;
            // update freespot
            freespot = next[index];

            // first element
            if(front[q-1]==-1){
                front[q-1] = index;
            }
            else{
                next[rear[q-1]]=index;
            }
            next[index] = -1;
            // update rear
            rear[q-1] = index;
            // push element
            arr[index] = data;
        }
        
        void dequeue(int q){
            // Underflow
            if(front[q-1]==-1){
                cout<<"Underflow"<<endl;
                return;
            }
            // find index
            int index = front[q-1];
            // update front
            front[q-1] = next[index];

            // update next and freespot
            next[index] = freespot;
            freespot = index;

            cout<<arr[index]<<"is deleted"<<endl;
        }

        void printQueue(int q){
            if(front[q-1]==-1){
                cout<<"Queue is empty"<<endl;
                return;
            }
            int st = front[q-1];
            while(st!=-1){
                cout<<arr[st]<<" ";
                st = next[st];
            }
            cout<<endl;
        }
};

int main(){
    kQueue Q(6,3);

    Q.enqueue(5,1);
    Q.enqueue(10,1);
    Q.enqueue(15,2);
    Q.enqueue(20,2);
    Q.enqueue(25,3);
    Q.enqueue(30,1);
    Q.dequeue(1);
    Q.printQueue(1);
    Q.printQueue(2);
    Q.printQueue(3);
    return 0;
}