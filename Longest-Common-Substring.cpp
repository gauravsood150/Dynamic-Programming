/*Given two strings ‘X’ and ‘Y’ of lengths N and M respectively, find the length of

the longest common substring.*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>

int LCS(std::string str1, std::string str2, int m, int n)
{
	int table[m+1][n+1];
	int maxi=INT_MIN;
	for(int i=0; i<=m; i++)
		for(int j=0; j<=n; j++)
		{
			if(i==0 || j==0) table[i][j]=0;

			else if(str1[i-1]==str2[j-1])
			{	
				table[i][j]=1+table[i-1][j-1];
				if(maxi < table[i][j])
					maxi=table[i][j];
			}
			else
				table[i][j]=0;
		}
	return maxi;
}		

int main()
{
	std::string str1;
	std::string str2;
	std::cin>>str1>>str2;
	int m=str1.size();
	int n=str2.size();
	std::cout<<LCS(str1,str2,m,n)<<std::endl;
	return 0;
}
