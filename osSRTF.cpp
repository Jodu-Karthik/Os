#include<bits/stdc++.h>
using namespace std;

struct process
{
	string id;
	int arrTime;
	int burstTime;
	int tempBurstTime;
	int compTime;
	int turnAroundTime;
	int waitTime;
};

bool comparator(process p1,process p2)
{
	return p1.arrTime < p2.arrTime;
}

bool comparator2(process p1,process p2)
{
	return p1.id<p2.id;
}

void findCompTime(int n,vector<process> &p)
{
	int min_time=0;
	int comp_proc=0;
	while(comp_proc<n)
	{
		int select_pro=-1;
		int min_burst_time=INT_MAX;

		for(int i=0;i<n;i++)
		{
			if(p[i].arrTime<=min_time and p[i].burstTime<min_burst_time and p[i].burstTime>0)
			{
				min_burst_time=p[i].burstTime;
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
				comp_proc++;
				p[select_pro].compTime=min_time;
			}
		}
	}
}

void findTat(int n,vector<process> &p)
{
	for(auto &i:p) i.turnAroundTime=i.compTime-i.arrTime; 
}

void findWt(int n,vector<process> &p)
{
	for(auto &i:p) i.waitTime=i.turnAroundTime-i.tempBurstTime;
}

int main()
{
	int n;cin>>n;
	vector<process> p(n);
	for(auto &i:p) cin>>i.id>>i.arrTime>>i.burstTime;

	for(auto &i:p) i.tempBurstTime=i.burstTime;
	sort(p.begin(),p.end(),comparator);

	findCompTime(n,p);
	sort(p.begin(),p.end(),comparator2);

	findTat(n,p);

	findWt(n,p);
	cout<<"ID\tAt\tBt\tCt\tTAT\tWt"<<endl;
	for(auto i:p) cout<<i.id<<"\t"<<i.arrTime<<"\t"<<i.tempBurstTime<<"\t"<<i.compTime<<"\t"<<i.turnAroundTime<<"\t"<<i.waitTime<<endl;
	cout<<endl;

	int total_turnaround_time=0;
	int total_waiting_time=0;
	for(auto &i:p) 
	{
		total_turnaround_time+=i.turnAroundTime;
		total_waiting_time+=i.waitTime;
	}
	cout<<"AvgTurnAroundTime: "<<total_turnaround_time/n<<endl;
	cout<<"AvgWaitingTime: "<<total_waiting_time/n;
}