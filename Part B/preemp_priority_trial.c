#include <stdio.h>

int main(){
	int i,j,n,time,totalwait=0,totaltat=0,smallest, g1[10],g2[10];
	int at[10],bt[10],pt[10],rt[10],remain; //rt = remaining Time
    printf("Enter no of Processes : ");
	scanf("%d",&n);
	remain=n;
	for(i=0;i<n;i++){
		printf("Enter arrival time, burst time and priority for process p%d :",i+1);
		scanf("%d%d%d",&at[i],&bt[i],&pt[i]);
		rt[i]=bt[i];
	}
	
	pt[9]=11;
	int k=0;
	printf("\n\nProcess\t|\tTurnaround time\t|\tWait time\n");
	int s1=-1;
	int s2=-1;
	
	for(time=0;remain!=0;time++){
		smallest=9;
		
		for(i=0;i<n;i++){
			if(at[i]<=time && pt[i]<pt[smallest] && rt[i]>0){
				if(s2==-1)
					s1=i,s2=0;
				smallest=i;
			}
		}
		
		rt[smallest]--;
		if(smallest!=s1){
			g1[k]=s1+1;
			g2[k++]=time;
		}
		
		if(rt[smallest]==0){
			remain--;
			printf("P[%d]\t|\t%d\t|\t%d\n", smallest+1, time+1-at[smallest], time+1-at[smallest]-bt[smallest]);
			totalwait+=time+1-at[smallest]-bt[smallest];
			totaltat+=time+1-at[smallest];
		}
		
		s1=smallest;
	}
	
	g1[k]=s1+1;
	g2[k++]=time;
	
	printf("\nAverage wait time = %f", totalwait*1.0/n);
	printf("\nAverage turnaround time = %f",totaltat*1.0/n);
	printf("\nGantt Chart:\n");
	for(i=0;i<k;i++)
		printf("|\t%d\t",g1[i]);
	printf("|\n0");
	for(i=0;i<k;i++)
		printf("\t\t%d",g2[i]);
	printf("\n");
	return 0;
}
