#include <bits/stdc++.h>
using namespace std;
long long sz,result;
long long arr[21];
//                 1          1
bool check(long long sum,long long index)
{
	if(index == sz){
		 return sum == result;
	}
	bool route1 = check(sum+arr[index],index+1);
	bool route2 = check(sum-arr[index],index+1);
	return route1 || route2;
}
int main() {
	long long i;
	cin>>sz>>result;
	for(i=0;i<sz;i++){
		cin>>arr[i];
	}
	if(check(arr[0],1)){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
 
}