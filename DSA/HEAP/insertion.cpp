/*
    write a program to insert data in heap.
    Follow (1-based) indexing

    if parent = i, left = 2i, right = 2i+1;

*/

#include <iostream>
using namespace std;


class Heap{
    public:
        int arr[100];
        int size = 0;

        Heap(){
            arr[0] = -1;
            size = 0;
        }

        void insertion(int val){
            size++;
            int index = size;
            arr[index] = val;

            int i = size;
            int item = arr[size];

            while(i>1 && (arr[i/2]<item)){
                arr[i] = arr[i/2];
                i = i/2;
            }
            arr[i] = item;
        }

        void maxHeapify(int* arr, int n,int largest){
                int i = largest;

                int l = 2*i;
                int r = 2*i+1;

                if(l<n && arr[l]>arr[largest]){
                    largest = l;
                }
                if(r<n && arr[r]>arr[largest]){
                    largest = r;
                }

                if(largest!=i){
                    swap(arr[i],arr[largest]);
                    maxHeapify(arr,n,largest);
                }
        }
        void deletion(){
            if(size<1){
                cout<<"Heap is Empty"<<endl;
                return;
            }

            arr[1] = arr[size];
            size--;
            maxHeapify(arr,size,1);
        }


        void printHeap(){
            for (int i=1;i<=this->size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    Heap h;
    h.insertion(80);
    h.insertion(45);
    h.insertion(70);
    h.insertion(40);
    h.insertion(35);
    h.insertion(50);
    h.insertion(90);
    h.printHeap();
    h.deletion();
    h.printHeap();

    return 0;
}