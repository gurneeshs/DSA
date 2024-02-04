#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    /***************************************************************/
    // CREATION:
    unordered_map<string,int> um;

    /***************************************************************/
    // INSERTION:
    // 1.
    pair<string,int> p = make_pair("Gurneesh",3);
    um.insert(p);

    // 2.
    pair<string,int> p2("Singh",4);
    um.insert(p2);

    // 3.
    um["Narang"] = 3;

    /***************************************************************/
    // TRAVERSING
    for(auto i:um){
        cout<<i.first<<" "<<i.second<<endl;
    }
    // using iterator
    // In unordered map, elements wil print in random order
    unordered_map<string,int>::iterator it = um.begin();
    while (it != um.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    
    /***************************************************************/
    // UPDATION:
    um["Narang"] = 4;

    /***************************************************************/
    // SEARCHING:
    cout<<um["Gurneesh"]<<endl;
    cout<<um.at("Singh")<<endl;
    // cout<<um.at("unknown")<<endl; 
    cout<<um["unknown"]<<endl;
    cout<<um.at("unknown")<<endl; 

    /***************************************************************/
    // SIZE:
    cout<<um.size()<<endl;

    /***************************************************************/
    // TO CHECK ENTRIES:
    cout<<um.count("Gurneesh");

    /***************************************************************/
    // DELETION
    um.erase("Gurneesh");

    /***************************************************************/
    return 0;
}