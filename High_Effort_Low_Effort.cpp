#include <iostream> 
using namespace std;

int HELE(int *l, int *h, int n)
{
	int table[n+2],maxi;
	table[0]=0;
	table[1]=0;
	for (int i = 2; i<=n+1; ++i)
	{
		maxi=max(h[i-2]+table[i-2], l[i-2]+table[i-1]);
		table[i]=maxi; 
	}
	return table[n+1];
}

int main()
{
	int n;
	cin>>n;
	int l[n],h[n];
	for (int i = 0; i < n; ++i)
		cin>>l[i]>>h[i];
	cout<<HELE(l,h,n)<<endl;
	return 0;
}