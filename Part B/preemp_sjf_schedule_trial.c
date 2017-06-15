#include <stdio.h>
 
int main() {
	int at[10], bt[10], temp[10], g1[10],g2[10],k=0;
	int i, smallest, count = 0, time, n;
	double totalwait = 0, totaltat = 0, end;
	float avgwait, avgtat;

    printf("\nEnter the Total Number of Processes: ");
	scanf("%d", &n); 
	printf("\nEnter arrival time and burst time of the processes:\n");
	for(i = 0; i < n; i++){
		printf("\nProcess %d:",i+1);
		printf("\nArrival Time: ");
		scanf("%d", &at[i]);
		printf("\nBurst Time: ");
		scanf("%d", &bt[i]); 
		temp[i] = bt[i];
	}

	bt[9] = 9999;  
	printf("\n\nProcess\t|\tTurnaround time\t|\tWait time\n");
	int s1=-1;
	int s2=-1;
	
	for(time = 0; count != n; time++){
		smallest = 9;
		
		for(i = 0; i < n; i++){
			if(at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0){
				if(s2==-1)
					s1=i,s2=0;
				smallest = i;
			}
		}
		
		bt[smallest]--;
		if(smallest!=s1){
			g1[k]=s1+1;
			g2[k++]=time;
		}
		
		if(bt[smallest] == 0){
			count++;
			end = time + 1;
			totalwait += end - at[smallest] - temp[smallest];
			totaltat += end - at[smallest];
			printf("P[%d]\t|\t%f\t|\t%f\n", smallest+1, end-at[smallest], end-at[smallest]-temp[smallest]);
		}
		
		s1=smallest;
	}
	
	g1[k]=s1+1;
	g2[k++]=time;
	avgwait = totalwait / n; 
	avgtat = totaltat / n;
	
	printf("\nAverage Waiting Time: %lf", avgwait);
	printf("\nAverage Turnaround Time: %lf", avgtat);
	printf("\nGantt Chart:\n");
	for(i=0;i<k;i++)
		printf("|\t%d\t",g1[i]);
	printf("|\n0");
	for(i=0;i<k;i++)
		printf("\t\t%d",g2[i]);
	printf("\n");
	return 0;
}