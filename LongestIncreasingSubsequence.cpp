#include <iostream>
#include <limits.h>
int LIS(int* set, int n)
{
	int table[n],max=INT_MIN;
	for (int i = 0; i < n; ++i) table[i]=1;

	for (int i=0; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(set[i]>set[j] && table[i]< table[j]+1)
				table[i]=table[j]+1;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(max<table[i])
			max=table[i];
	}
	for(int i=0; i<n; i++) std::cout<<table[i]<<" ";
	return max;
}

int main()
{
	int n;
	std::cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
		std::cin>>a[i];
	std::cout<<LIS(a,n);
	return 0;
}