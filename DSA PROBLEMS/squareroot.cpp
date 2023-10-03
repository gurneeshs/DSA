#include <iostream>
using namespace std;

long long int mySqrt(int x)
{
    long long int s = 0, e = x, ans;
    long long int mid = s + ((e - s) / 2);

    while (s <= e)
    {
        if (mid * mid > x)
        {
            e = mid - 1;
        }
        else if (mid * mid <= x)
        {
            ans = mid;
            s = mid + 1;
        }
        mid = s + ((e - s) / 2);
    }
    return ans;
}
double morePrecision(int n,int p, int temp){
    double factor = 1;
    double ans = temp;

    for(int i=0;i<p;i++){
        factor = factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans = j;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the Integer";
    cin>>n;

    int tempSol = mySqrt(n);
    cout<<"Answer is"<<morePrecision(n,4,tempSol);
    return 0;
}
