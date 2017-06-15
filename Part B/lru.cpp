#include <iostream>
using namespace std;
int main(){
	int pno, fno, j=0, count=0, flag1, flag2, index;
	cout<<"\nEnter the number of pages: ";
	cin>>pno;
	int page[pno];
	cout<<"\nEnter the pages:\n";
	for (int i = 0; i < pno; i++)
		cin>>page[i];
	cout<<"\nEnter the number of frames: ";
	cin>>fno;
	int frame[fno], fs[fno];
	for (int i = 0; i < fno; i++)
		frame[i] = -1;

	for (int j = 0; j < pno; j++){
		flag1=0;
		flag2=0;
		for (int i = 0; i < fno; i++){
			if(frame[i]==page[j]){
				flag1=1;
				flag2=1;
				break;
			}
		}
		if(flag1==0){
			for (int i = 0; i < fno; i++){
				if(frame[i]==-1){
					frame[i]=page[j];
					flag2=1;
					break;
				}
			}
		}
		if(flag2==0){
			for (int i = 0; i < fno; i++)
				fs[i]=0;
			for (int k = j-1, l = 1; l <= fno-1; l++, k--){
				for (int i = 0; i < fno; i++){
					if(frame[i]==page[k])
						fs[i]=l;
				}
			}
			for (int i = 0; i < fno; i++){
				if(fs[i]==0)
					index=i;
			}
			frame[index]=page[j];
			count++;
		}
		for (int i = 0; i < fno; i++)
			cout<<"\t"<<frame[i];
		cout<<endl;
	}
	cout<<"\nNo. of page faults = "<<(count+fno)<<endl;
	return 0;
}