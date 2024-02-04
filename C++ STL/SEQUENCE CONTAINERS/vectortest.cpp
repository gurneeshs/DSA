#include <bits/stdc++.h> 
#include <algorithm>
#include <vector>
int findArrayIntersection(int arr1[], int n, vector<int> arr2, int m)
{
	vector<int> retArr;
	
	if(n>=m){
		sort(arr2.end(),arr2.begin());
		int i=0;
		while(i!=n){
			if(arr1[i]>arr2.back()){
				arr2.pop_back();
			}
			else if (arr1[i]==arr2.back()){
				retArr.push_back(arr1[i]);
				i++;
				arr2.pop_back();
			}
			else if(arr1[i]<arr2.back() or arr2.empty()){
				i++;
			}
		}
	}

	else{
		sort(arr1.end(),arr1.begin());
		int i=0;
		while(i!=m){
			if(arr2[i]>arr1.back()){
				arr1.pop_back();
			}
			else if (arr2[i]==arr1.back()){
				retArr.push_back(arr2[i]);
				i++;
				arr1.pop_back();
			}
			else if(arr2[i]<arr1.back() or arr1.empty()){
				i++;
			}
		}
	}
	return retArr;
}