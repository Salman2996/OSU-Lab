#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int n;
	cout<<"\nEnter the number of processes: ";
	cin>>n;
	char p[n][n], temp[n][n];
	int wt[n],bt[n],pri[n],tat[n];
	int t1,t2;
	int totalwait=0, totaltat=0, burstsum=0;
	float avgwait, avgtat;
	cout<<"\nEnter the name, burst time and priority of the processes:\n";
	for(int i=0;i<n;i++){
		cout<<"\n\nName: ";
		cin>>p[i];
		cout<<"\nBurst time: ";
		cin>>bt[i];
		cout<<"\nPriority: ";
		cin>>pri[i];
	}
	
	//bubble sort the priority
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(pri[i]>pri[j]){
				//swap priority
				t1=pri[i];
				pri[i]=pri[j];
				pri[j]=t1;
				//swap burst time
				t2=bt[i];
				bt[i]=bt[j];
				bt[j]=t2;
				//swap names
				strcpy(temp[i],p[i]);
				strcpy(p[i],p[j]);
				strcpy(p[j],temp[i]);
			}
		}
	}
	
	wt[0]=0;
	for(int i=0;i<n;i++){
		wt[i+1]=wt[i]+bt[i];
		tat[i]=wt[i]+bt[i];
		totalwait+=wt[i];
		totaltat+=tat[i];
		burstsum+=bt[i];
	}
	avgwait=(float)totalwait/n;
	avgtat=(float)totaltat/n;
	cout<<"\nAverage wait time: "<<avgwait;
	cout<<"\nAverage turnaround time: "<<avgtat;
	cout<<"\nGantt Chart:\n";
	for(int i=0;i<n;i++)
		cout<<"|\t"<<p[i]<<"\t";
	cout<<"|"<<endl;
	for(int i=0;i<n;i++)
		cout<<wt[i]<<"\t\t";
	cout<<burstsum;
	return 0;
}
