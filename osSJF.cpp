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
	int waitingTime;
};


void findComp(vector<process> &p)
{
	int n=p.size();
	int min_time=0;
	int comp_pro=0;
	while(comp_pro<n)
	{
		int high_burstTime=INT_MAX;
		int select_pro=-1;
		for(auto i=0;i<n;i++)
		{
			if(p[i].arrTime<=min_time and p[i].burstTime<high_burstTime and p[i].burstTime>0)
			{
				high_burstTime=p[i].burstTime;
				select_pro=i;
			}
		}
		if(select_pro==-1) min_time++;
		else
		{
			min_time+=p[select_pro].burstTime;
			p[select_pro].compTime=min_time;
			comp_pro++;
			p[select_pro].burstTime=0;
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
	for(auto &i:p) cin>>i.id>>i.arrTime>>i.burstTime;

	for(auto &i:p) i.tempBurstTime=i.burstTime;

	// sort(p.begin(),p.end(),comp); since checking till n in the above no need to sort

	findComp(p);
	findTurnAroundTime(p);
	findWaitTime(p);

	cout<<"ID At Bt Ct TAT Wt"<<endl;
	for(auto i:p) cout<<i.id<<"  "<<i.arrTime<<"  "<<i.tempBurstTime<<"  "<<i.compTime<<" "<<i.turnAroundTime<<"  "<<i.waitingTime<<endl;
}





// #include<bits/stdc++.h>
// using namespace std;

// struct process
// {
// 	int id;
// 	int at;
// 	int burstTime;
// 	int ct;
// 	int tat;
// 	int wt;
// };

// bool comp(process a,process b)
// {
// 	return a.at<b.at;
// }

// void sjf(vector<process> &pro,int n)
// {
// 	sort(pro.begin(),pro.end(),comp);
// }

// int main()
// {
// 	int n;cin>>n;
// 	vector<process> v(n);
// 	for(int i=0;i<n;i++) cin>>v[i].id>>v[i].at>>v[i].burstTime;

// 	sjf(v,n);
		
// 	for(auto i:v) cout<<i.id<<" "<<i.at<<" "<<i.burstTime<<" "<<endl;
	
// }