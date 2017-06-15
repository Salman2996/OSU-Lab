#include<iostream>
using namespace std;

int mutex=1,full=0,empty,x=0;

int wait(int s){
	return --s;
}

int signal(int s){
	return ++s;
}

void producer(){
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x++;
	cout<<"\nItem "<<x<<" produced";
	mutex=signal(mutex);
}

void consumer(){
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	cout<<"\nItem "<<x<<" consumed";
	x--;
	mutex=signal(mutex);
}

int main(){
	cout<<"\nEnter buffer size: ";
	cin>>empty;
	int choice;
	while(1){
		cout<<"\nEnter choice:\n1.Producer\n2.Consumer\n3.Exit\n";
		cin>>choice;
		switch(choice){
			case 1:
				if(mutex==1 && empty!=0)
					producer();
				else
					cout<<"\nBuffer is full!!!";
				break;
			case 2:
				if(mutex==1 && full!=0)
					consumer();
				else
					cout<<"\nBuffer is empty!!!";
				break;
			case 3:
				exit(0);
				break;
			default:
				cout<<"\nCheck your input!";
		}
	}
	return 0;
}
