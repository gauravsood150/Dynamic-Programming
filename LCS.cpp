/*Given two sequences, find the length of longest subsequence present in both of

them. A subsequence is a sequence that appears in the same relative order, but

not necessarily contiguous.*/

#include <iostream>
#include <cstring>
#include <algorithm>

int LCS(std::string str1, std::string str2, int m, int n)
{
	int table[m+1][n+1];

	for(int i=0; i<=m; i++)
		for(int j=0; j<=n; j++)
		{
			if(i==0 || j==0) table[i][j]=0;

			else if(str1[i-1]==str2[j-1])
				table[i][j]=1+table[i-1][j-1];
			else 
				table[i][j]=std::max(table[i-1][j], table[i][j-1]);
		}
	return table[m][n];
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
