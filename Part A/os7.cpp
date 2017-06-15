#include<iostream>
#include<string>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
using namespace std;
int x=2;
int main()
{
	string s="";
	int i=20;
	pid_t pID=fork();
	
	if(pID==0)
	{
		s="Child process";
		x++;
		i++;
	}
	else if(pID<0)
	{
		cerr<<"\nFailed to fork!\n";
		exit(0);
	}
	else
		s="Parent process";
	
	cout<<"\n"<<s;
	cout<<"\nGlobal variable: "<<x;
	cout<<"\nLocal variable: "<<i<<endl;
	return 0;
}
