#include<bits/stdc++.h>
using namespace std;

int timeQuantum=2;

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

		for(int i=0;i<n;i++)
		{
			if(p[i].arrTime<=min_time and p[i].burstTime>0)
			{
				int execution_time=(p[i].burstTime<=timeQuantum)?p[i].burstTime:timeQuantum;
				p[i].burstTime-=execution_time;
				min_time+=execution_time;
				if(p[i].burstTime==0)
				{
					p[i].compTime+=min_time;
					comp_proc++;
				}
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