#include <iostream>
using namespace std;
int main(){
	int process, resource, k=0, count=0, temp=0;
	cout<<"\nEnter the number of processes: ";
	cin>>process;
	cout<<"\nEnter the number of resources: ";
	cin>>resource;
	int available[resource], max[process][resource], allocation[process][resource], need[process][resource], completed[process];
	for (int i = 0; i < process; i++)
		completed[i]=0;
	
	cout<<"\nEnter the number of instances of each resource:\n";
	for (int i = 0; i < resource; i++)
		cin>>available[i];

	cout<<"\nEnter the max matrix:\n";
	for (int i = 0; i < process; i++){
		cout<<"\nProcess "<<i<<": ";
		for (int j = 0; j < resource; j++)
			cin>>max[i][j];
	}

	cout<<"\nEnter the allocation matrix:\n";
	for (int i = 0; i < process; i++){
		cout<<"\nProcess "<<i<<": ";
		for (int j = 0; j < resource; j++){
			cin>>allocation[i][j];
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}

	cout<<"\nSafe Sequence is:\n";
	while (count != process){
		temp=count;
		for (int i = 0; i < process; i++){
			for (int j = 0; j < resource; j++){
				if(need[i][j]<=available[j])
					k++;
			}
			if(k==resource && completed[i]==0 ){
				cout<<"P"<<i<<"\t";
				completed[i]=1;
				for (int j = 0; j < resource; j++)
					available[j]+=allocation[i][j];
				count++;
			}
			k=0;
		}
		if(count==temp){
			cout<<"\nDEADLOCK!!!";
			break;
		}
	}
	return 0;
}