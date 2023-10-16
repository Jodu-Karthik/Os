#include<bits/stdc++.h>
using namespace std;

struct process
{		
	int id;
	int arr_time;
	int burst_time;
};

void fcfs(vector<process> &pro)
{
	int tot_time=0;

	for(process &p:pro)
	{
		if(p.arr_time>tot_time) tot_time=p.arr_time;
		tot_time+=p.burst_time;
		cout<<"process"<<p.id<<": "<<tot_time<<endl;
	}
	cout<<"Total Time: "<<tot_time<<endl;
}


int main()
{
	int n;cin>>n;
	vector<process> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i].id>>v[i].arr_time>>v[i].burst_time;

	cout<<"First Come First Serve: \n\n";
	fcfs(v);

	return 0;
}