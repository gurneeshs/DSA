// *****************DOUBLE POINTERS*******************
#include <iostream>
using namespace std;
void update(int **ptr){
    // ptr = ptr+1;
    **ptr = **ptr + 1;
}
int main(){
    int i = 5;
    int *p1 = &i;
    int **p2 = &p1;

    // cout<<"Value of i: "<<i<<" "<<*p1<<" "<<**p2<<endl;
    // cout<<"Value of p1: "<<p1<<" "<<&i<<" "<<*p2<<endl;
    // cout<<"Value of p2: "<<p2<<" "<<&p1<<endl;

    cout<<"Before"<<endl;
    cout<<"Value of i: "<<i<<endl;
    cout<<"Value of p1: "<<p1<<endl;
    cout<<"Value of p2: "<<p2<<endl;
    update(p2);
    cout<<"After"<<endl;
    cout<<"Value of i: "<<i<<endl;
    cout<<"Value of p1: "<<p1<<endl;
    cout<<"Value of p2: "<<p2<<endl;

    return 0;
}



