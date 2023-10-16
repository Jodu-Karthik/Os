#include<bits/stdc++.h>
using namespace std;

struct process
{
	string id;
	int priority;
	int arrTime;
	int burstTime;
	int tempBurstTime;
	int compTime;
	int turnAroundTime;
	int waitingTime;
};


void findComp(vector<process> &p)
{
	int n=p.size();
	int remaining_pro=n;
	int min_time=0;
	while(remaining_pro>0)
	{
		int select_pro=-1;
		int high_pri=INT_MAX;
		for(auto i=0;i<n;i++)
		{
			if(p[i].arrTime<=min_time and p[i].priority< high_pri and p[i].burstTime>0)
			{
				high_pri=p[i].priority;
				select_pro=i;
			}
		}
		if(select_pro==-1) min_time++;
		else 
		{
			p[select_pro].burstTime--;
			min_time++;
			if(p[select_pro].burstTime==0)
			{
				remaining_pro--;
				p[select_pro].compTime=min_time;
			}
		}
	}
}

void findTurnAroundTime(vector<process> &p)
{
	for(auto &i:p) i.turnAroundTime=i.compTime-i.arrTime;
}

void findWaitTime(vector<process> &p)
{
	for(auto &i:p)  i.waitingTime=i.turnAroundTime-i.tempBurstTime;
}

int main()
{
	int n;cin>>n;
	vector<process> p(n);
	for(auto &i:p) cin>>i.id>>i.priority>>i.arrTime>>i.burstTime;

	for(auto &i:p) i.tempBurstTime=i.burstTime;

	// sort(p.begin(),p.end(),comp); since checking till n in the above no need to sort

	findComp(p);
	findTurnAroundTime(p);
	findWaitTime(p);

	cout<<"ID Pri At Bt Ct TAT Wt"<<endl;
	for(auto i:p) cout<<i.id<<"  "<<i.priority<<"  "<<i.arrTime<<"  "<<i.tempBurstTime<<"  "<<i.compTime<<" "<<i.turnAroundTime<<"  "<<i.waitingTime<<endl;
}