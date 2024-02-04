#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // declaration
    vector<int> vct = {2,9,7,8,1};

    // Traversal
    for (int itm:vct){
        cout<<itm<<" ";
    }
    cout<<endl;
    for (int i =0;i<vct.size();i++){
        cout<<vct[i]<<" ";
    }
    cout<<endl;

    // Methods
    // cout<<"Size of vctay:"<<vct.size()<<endl;
    // cout<<"Item at 2 Position:"<<vct.at(2)<<endl;
    // cout<<"Is vctay Empty:"<<vct.empty()<<endl;
    // cout<<"Front Element:"<<vct.front()<<endl;
    // cout<<"Back Element:"<<vct.back()<<endl;
    // cout<<"Capacity:"<<vct.capacity()<<endl;
    // cout<<"Pushing Element in Vector:"<<endl;
    // vct.push_back(21);
    // cout<<"Capacity:"<<vct.capacity()<<endl;
    // sort(vct.begin(),vct.end());
    // cout<<"Sorted Vector:";
    // for (int itm:vct){
    //     cout<<itm<<" ";
    // }
    // cout<<endl;
    // cout<<"Poping Element from Vector:";
    // vct.pop_back(); 

    cout<<vct.find(7);
    return 0;
}