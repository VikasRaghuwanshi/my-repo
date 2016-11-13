/*Factorial Hundred program*/
#include <bits/stdc++.h>
#define MAX_LENGTH 10001
using namespace std;
/*This function will take t testcases,followed by t nubbers for which factorial needs to be calculated*/
int main(int argc, char const *argv[])
{
	int t;
	int n;
	cin>>t;
	long long int fact[MAX_LENGTH];
	while(t--){
		cin>>n;
		/*Initializing factorial array with zoroes*/
		memset(fact,0,sizeof(int)*MAX_LENGTH);
		fact[MAX_LENGTH-1]=1;
		int length=1;
		long long int carry;
		for (int i = 2; i <=n; ++i)
		{
			/*Initialy carry is zero*/
			carry=0;
			/*Multiplying current factorial by i*/
			for (int j = MAX_LENGTH-1; j>MAX_LENGTH-1-length; --j)
			{
				fact[j]*=i;
				fact[j]+=carry;
				carry=fact[j]/10;
				fact[j]%=10;
			}
			/*Processing of last element, if carry is there*/
			if (carry>0)
			{
				while(carry>0){
					fact[MAX_LENGTH-1-length]=carry%10;
					length++;
					carry/=10;
				}
			}
		}
		/*Iterating over factorial array to print factorial value*/
		for (int i = MAX_LENGTH-length; i <MAX_LENGTH; ++i)
		{
			cout<<fact[i];
		}
		cout<<endl;
	}
	return 0;
}