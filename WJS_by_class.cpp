#include <iostream>
#include <algorithm>
using namespace std;

class job
{
public:
	int start_time;
	int finish_time;
	int profit;
	job(){};
	void get(int start_time, int finish_time, int profit)
	{
		this->start_time=start_time;
		this->finish_time=finish_time;
		this->profit=profit;
	}
};


bool jobComparater(job s1, job s2)
{
	return (s1.finish_time < s2.finish_time);
}

int WJS(job *s, int n)
{
	sort(s,s+n,jobComparater);
	// for(int i=0; i<n; i++)
	// 	cout<<s[i].finish_time<<" ";
	int table[n];

	for (int i = 0; i < n; ++i)
		table[i]=s[i].profit;

	for(int i=1; i<n; i++)
	{
		for(int j=i-1; j>=0; j--)
		{
			if(s[i].start_time >= s[j].finish_time)
			{
				table[i]=table[i] +s[j].profit;
				break;
			}
		}
	}
	return max(table[n-1], table[n-2]);
}

int main()
{
	int n;
	cin>>n;
	job s[n];
	int start_time,finish_time,profit;

	for (int i = 0; i < n; ++i)
	{
		cin>>start_time>>finish_time>>profit;
		s[i].get(start_time,finish_time,profit);
	}
	
	cout<<WJS(s,n);
	return 0;
}