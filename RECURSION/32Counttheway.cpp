/* ************************************************************************
Count the number of way to reach n-th Stair

Given n number of stairs, you have to find the number of ways we can
reach to n-th stairs
At a time, the person can only take either 1 step or 2 step
***************************************************************************
*/

#include <iostream>
using namespace std;

int no_of_ways(int n){
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    
    return no_of_ways(n-1) + no_of_ways(n-2);
}

int main(){
    int n;
    cout<<"Enter the Number of stairs: ";
    cin>>n;
    cout<<"No. of Ways we can reach to nth stair is: "<<no_of_ways(n);
    return 0;
}