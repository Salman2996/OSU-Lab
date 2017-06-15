#include <iostream>
using namespace std;

struct process{
	int id,bt,wt,tat,sTime;
};

int main(){
	int n,i,count,quantum,temp,totalServiceTime=0;
	cout<<"\nEnter the number of processes: ";
	cin>>n;
	process p[n];
	cout<<"\nEnter burst time of the processes:\n"; 
	for(i=0;i<n;i++){
		p[i].id=i+1;
		cout<<"\nProcess "<<i+1<<": ";
		cin>>p[i].bt;
		p[i].wt=0;
		p[i].sTime=p[i].bt;
	}
	cout<<"\nEnter the time quantum: ";
	cin>>quantum;
	while(true){
		count=0;
		for(i=0;i<n;i++){
			temp=quantum;
			if(p[i].sTime==0){
				count++;
				continue;
			}
			if(p[i].sTime>=quantum)
				p[i].sTime-=quantum;
			else{
				temp=p[i].sTime;
				p[i].sTime=0;
			}
			totalServiceTime+=temp;
			p[i].tat=totalServiceTime;
		}
		if(count==n)
			break;
	}
	for(i=0;i<n;i++)
		p[i].wt=p[i].tat-p[i].bt;
	float avgtat=0.0,avgwait=0.0;
	for(i=0;i<n;i++){
		avgtat+=p[i].tat;
		avgwait+=p[i].wt;
	}
	avgtat/=n;
	avgwait/=n;
	cout<<"\nProcess\tBurst\tWait\tTime\tsTime\n";
	for(i=0;i<n;i++)
		cout<<p[i].id<<"\t"<<p[i].bt<<"\t"<<p[i].wt<<"\t"<<p[i].tat<<"\t"<<p[i].sTime<<endl;
	cout<<"\nAverage wait time: "<<avgwait;
	cout<<"\nAverage turnaround time:"<<avgtat;
	cout<<"\nTotalServiceTime: "<<totalServiceTime;
	return 0;
}
