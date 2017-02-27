#include <iostream>
#include <algorithm>

int maximumSumWithNoAdj(int *a, int n)
{
	int table[n+1];
	table[0]=0;
	for(int i=1; i<=n; i++)
		table[i]=a[i-1];
	int maxi= 0;

	for(int i=2; i<=n; i++)
	{
		maxi=std::max(maxi,table[i-2]);
		table[i]+=maxi;
	}

	// for(int i=0; i<=n; i++) std::cout<<table[i]<<" ";
	return std::max(table[n],table[n-1]);
}

int main()
{
	int n;
	std::cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		std::cin>>a[i];
	std::cout<<maximumSumWithNoAdj(a,n);
	return 0;
}