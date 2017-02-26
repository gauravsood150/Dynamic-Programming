#include <iostream>
#include <limits.h>

int coin_change(int* coins, int V, int n)
{
	int table[V+1],temp;
	table[0]=0;
	for (int i = 1; i <=V; ++i)
		table[i]=INT_MAX;

	for(int i=0; i<=V; i++)
		for(int j=0; j<n; j++)
		{
			if(coins[j]<=i)
			{
				temp=table[i-coins[j]];
				if(1+ temp < table[i])
					table[i]=1+temp;
			}
		}
	for (int i = 0; i <=V; ++i)
	{
		std::cout<<table[i]<<" ";
	}
	return table[V];
}

int main()
{
	int n;
	std::cin>>n;
	int coins[n];
	for (int i = 0; i < n; ++i)
		std::cin>>coins[i];
	int V;
	std::cin>>V;
	std::cout<<std::endl<<coin_change(coins,V,n)<<std::endl;
	return 0;
}