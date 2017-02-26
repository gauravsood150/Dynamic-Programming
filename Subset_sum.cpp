#include <iostream>

bool subset_sum(int *set, int n, int sum)
{
	bool table[n+1][sum+1];

	for (int i=0; i <=n; i++)
	{
		for(int j=0; j<=sum; j++)
		{
			if(i==0) table[i][j]=false;
			if(j==0) table[i][j]=true;
			else if(set[i-1]==j)
				table[i][j]=true;

			else if(set[i-1]<j)
			{
				if(table[i-1][j-set[i-1]])
					table[i][j]=true;
				else
					table[i][j]=table[i-1][j];
			}
			else 
				table[i][j]=table[i-1][j];

		}
	}
	for (int i=0; i <=n; i++)
	{
		for(int j=0; j<=sum; j++)
		{
			std::cout<<table[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return table[n][sum];
}


int main()
{
	int sum,n;
	std::cin>>n;
	int set[n];
	for (int i=0; i<n; ++i)	std::cin>>set[i];
	std::cin>>sum;
	std::cout<<subset_sum(set, n, sum);
}