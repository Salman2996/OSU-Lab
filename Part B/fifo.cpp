#include <iostream>
using namespace std;
int main(){
	int pno, fno, j=0, available_page, count=0;
	cout<<"\nEnter the number of pages: ";
	cin>>pno;
	int page[pno];
	cout<<"\nEnter the pages:\n";
	for (int i = 0; i < pno; i++)
		cin>>page[i];
	cout<<"\nEnter the number of frames: ";
	cin>>fno;
	int frame[fno];
	for (int i = 0; i < fno; i++)
		frame[i] = -1;

	cout<<"\nPage\t\tFrame\n";
	for (int i = 0; i < pno; i++){
		cout<<page[i]<<"\t\t";
		available_page=0;
		for(int k = 0; k < fno; k++){
			if(frame[k]==page[i])
				available_page=1;
		}
		if(available_page==0){
			frame[j]=page[i];
			j=(j+1)%fno;
			count++;
			for (int k = 0; k < fno; k++)
				cout<<frame[k]<<"\t";
		}
		cout<<endl;
	}
	cout<<"\nNo. of page faults = "<<count;
	return 0;
}