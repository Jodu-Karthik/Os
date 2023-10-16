#include<bits/stdc++.h>
using namespace std;

struct process
{
	string id;
	int pri;
	int arrTime;
	int burstTime;
};

bool comp(process p1,process p2)
{
	return p1.pri<p2.pri;
}

void priority(vector<process> &v)
{
	int comp_time=0;
	for(auto i:v) 
	{
		if(i.arrTime<=comp_time and p[i])
	}
}

int main()
{
	int n;cin>>n;
	vector<process> v(n);
	for(auto &i:v) cin>>i.id>>i.pri>>i.arrTime>>i.burstTime;

	sort(v.begin(),v.end(),comp);
	// priority(v);
	
	for(auto i:v) cout<<i.id<<" "<<i.pri<<" "<<i.arrTime<<" "<<i.burstTime<<" "<<endl;
}