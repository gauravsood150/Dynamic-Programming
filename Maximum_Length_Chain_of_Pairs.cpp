#include <iostream>
#include <algorithm>
using namespace std;

class chain
{
public:
	int slength;
	int flength;
	int difference;
	chain(){}
	void get(int sl, int fl)
	{
		slength=sl;
		flength=fl;
		difference=fl-sl;
	}
};

bool chainComparator(chain c1, chain c2)
{
	return c1.flength <c2.flength;
}

int MLCP(chain *c, int n)
{
	sort(c,c+n,chainComparator);
	int table[n];
	for (int i = 0; i < n; ++i)
	{
		table[i]=c[i].difference;
	}
	for(int i=1; i<n; i++)
		for(int j=i-1; j>=0; j--)
			if(c[i].slength>=c[j].flength)
			{
				table[i] += table[j];
				break;
			}
			// for (int i = 0; i < n; ++i) cout<<table[i]<<" ";
			// 	cout<<endl;
	return max(table[n-1], table[n-2]);

}

int main()
{
	int n;
	cin>>n;
	chain c[n];
	int slength,flength;
	for (int i = 0; i < n; ++i)
	{
		cin>>slength>>flength;
		c[i].get(slength,flength);
	}

	cout<<MLCP(c,n);
}