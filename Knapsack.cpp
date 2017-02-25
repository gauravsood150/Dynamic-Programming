/*Given weights and values of n items, put these items in a knapsack of capacity W

to get the maximum total value in the knapsack. In other words, given two integer

arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated

with n items respectively. Also given an integer W which represents knapsack

capacity, find out the maximum value subset of val[] such that sum of the weights

of this subset is smaller than or equal to W. You cannot break an item, either pick

the complete item, or don’t pick it (0-1 property). */

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
