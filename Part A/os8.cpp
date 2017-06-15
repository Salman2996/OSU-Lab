#include<iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
using namespace std;
int main()
{
	pid_t pID=fork();
	
	if(pID==0)
	{
		cout<<"\nChild process:";
		cout<<"\nProcess ID: "<<getpid();
		cout<<"\nParent Process ID: "<<getppid();
		//_exit(0);
	}
	else if(pID<0)
	{
		cerr<<"\nFailed to fork!\n";
		exit(0);
	}
	else
	{
		wait(NULL);
		cout<<"\n\nParent process:";
		cout<<"\nProcess ID: "<<getpid();
		cout<<"\nChild Process ID: "<<pID<<endl;
	}
	return 0;
}
