#include <iostream>
#include <cstring>

int EditDistance(std::string str1, std::string str2)
{
	int m=str1.size();
	int n=str2.size();
	int table[m+1][n+1];
	for(int i=0; i<=m;i++)
	{
		table[i][0]=i;
		table[0][i]=i;
	}

	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++)
		{
			if(str1[i-1]==str2[j-1])
				table[i][j]=table[i-1][j-1];
			else
			{
				table[i][j]=std::min(table[i][j-1]+1, table[i-1][j]+1);
				table[i][j]=std::min(table[i][j], table[i-1][j-1]+1);
			}	
		}
		return table[m][n];
}

int main()
{
	std::string str1;
	std::string str2;
	std::cin>>str1>>str2;
	std::cout<<EditDistance(str1,str2);
	return 0;
}