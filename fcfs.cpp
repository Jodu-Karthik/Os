#include<bits/stdc++.h>
using namespace std;

struct process
{
	int id;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
};

bool comp(process a,process b)
{
	return a.at < b.at;
}

void findCt(vector<process> &v,int n)
{
	v[0].ct=v[0].at+v[0].bt;
	for(int i=1;i<n;i++) v[i].ct=v[i-1].ct+v[i].bt;
}

void ftat(vector<process> &v,int n)
{
	for(auto &i:v) i.tat=i.ct-i.at;
}

void fwt(vector<process> &v,int n)
{
	for(auto &i:v) i.wt=i.tat-i.bt;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);

		freopen("output.txt", "w", stdout);
	#endif
	
	int n;cin>>n;
	vector<process> p(n);

	for(auto &i:p) cin>>i.id>>i.at>>i.bt;

	for(auto i:p) cout<<i.id<<" "<<i.at<<" "<<i.bt<<endl;

	cout<<endl;
	sort(p.begin(),p.end(),comp);

	// for(auto &i:p)
 	// cout<<i.id<<" "<<i.at<<" "<<i.bt<<endl;

	findCt(p,n);
	ftat(p,n);
	fwt(p,n);

	cout<<endl;
	cout<<"id\t"<<"at\t"<<"bt\t"<<"ct\t"<<"tat\t"<<"wt\t"<<endl;
	for(auto &i:p) cout<<i.id<<"\t"<<i.at<<"\t"<<i.bt<<"\t"<<i.ct<<"\t"<<i.tat<<"\t"<<i.wt<<endl;

	int awt=0,atat=0;
	cout<<endl;
	for(auto &i:p)
	{
		awt+=i.wt;
		atat+=i.tat;
	}
	cout<<"Average TurnAroundTime: "<<awt/n<<endl;
	cout<<"Average WaitingTime: "<<atat/n<<endl;
}
