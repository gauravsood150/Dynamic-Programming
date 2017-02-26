#include <iostream>
#include <cstring>
#include <algorithm>

int LPS(std::string str1, int m)
{
	int table[m+1][m+1];

	for(int i=0; i<=m; i++)
		for(int j=0; j<=m; j++)
		{
			if(i==0 || j==0) table[i][j]=0;

			else if(str1[i-1]==str1[m-j])
				table[i][j]=1+table[i-1][j-1];
			else 
				table[i][j]=std::max(table[i-1][j], table[i][j-1]);
		}
// 	for(int i=0; i<=m; i++)
// 	{	for(int j=0; j<=m; j++)
// 			std::cout<<table[i][j]<<" ";
// 		std::cout<<std::endl;
// 	}
	return table[m][m];
}

int main()
{
	std::string str1;
	std::cin>>str1;
	int m=str1.size();
	std::cout<<LPS(str1,m)<<std::endl;
	return 0;
}
