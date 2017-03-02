/*Given N jobs where every job is represented by following three elements of it.

Start Time
Finish Time
Profit or Value Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.*/

#include <iostream>
#include <algorithm>
using namespace std;

struct job
{
	int start_time;
	int finish_time;
	int profit;
};

job* createNewJob(int start_time, int finish_time, int profit)
{
	job* s=new job;
	s->start_time=start_time;
	s->finish_time=finish_time;
	s->profit=profit;
	return s;
}

bool jobComparater(job *s1, job *s2)
{
	return (s1->finish_time < s2->finish_time);
}

int WJS(job* s[], int n)
{
	sort(s,s+n,jobComparater);
	int table[n];
	for (int i = 0; i < n; ++i)
	{
		table[i]=s[i]->profit;
		//cout<<table[i]<<" ";		
	}
	for(int i=1; i<n; i++)
	{
		for(int j=i-1; j>=0; j--)
		{
			if(s[i]->start_time >= s[j]->finish_time)
			{
				table[i]+=s[j]->profit;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i)
		cout<<table[i]<<" ";
	cout<<endl;
	return max(table[n-1], table[n-2]);
}

int main()
{
	int n;
	cin>>n;
	job* s[n];
	int start_time,finish_time,profit;
	for (int i = 0; i < n; ++i)
	{
		cin>>start_time>>finish_time>>profit;
		s[i]=createNewJob(start_time,finish_time,profit);
	}
	cout<<WJS(s,n);
	return 0;
}
