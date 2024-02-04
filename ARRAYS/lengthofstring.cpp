#include <iostream>
using namespace std;

int main(){
    char name[20];
    cout<<"Enter any name:";
    cin>>name;
    int cnt=0;
    for(int i=0;i<name[i]!='\0';i++){
        cnt++;
    }

    cout<<"Lenght of string is:"<<cnt<<endl;
    return 0;
}