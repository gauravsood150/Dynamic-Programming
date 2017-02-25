#include <iostream>
#include <algorithm>

int knapsack(int n, int* wt, int* val, int W)
{
	int table[n+1][W+1];

	for(int i=0; i<=n; i++)
		for(int j=0; j<=W; j++)
		{
			if(i==0 || j==0)
				table[i][j]=0;
			else if(wt[i-1]<=j)
				table[i][j]= std::max(val[i-1]+table[i-1][j-wt[i-1]],table[i-1][j]);
			else 
				table[i][j]=table[i-1][j];
			//std::cout<<table[i][j]<<" ";
		}
	return table[n][W];
}

int main()
{
	int n=4,W=6;
	std::cin>>n;
	int wt[n], val[n];
	for (int i = 0; i < n; ++i)
		std::cin>>wt[i];
	for (int i = 0; i < n; ++i)
		std::cin>>val[i];
	std::cin>>W;
	int c=knapsack(n,wt,val,W);
	std::cout<<c<<std::endl;
	return 0;
}