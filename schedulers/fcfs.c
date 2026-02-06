#include <stdio.h>
#include <stdlib.h>
void sort(int pid[],int at[],int bt[],int n) 
{
    for (int i=0;i<n-1;i++) 
	{
        for (int j=i+1;j<n;j++) 
		{
            if (at[i]>at[j]) 
			{
                int t;
                t = at[i];at[i]=at[j];at[j]=t;
                t = bt[i];bt[i]=bt[j];bt[j]=t;
                t = pid[i];pid[i]=pid[j];pid[j]=t;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
    for (int i = 0; i < n; i++) 
	{
        pid[i] = i+1;
        printf("Enter Arrival Time and Burst Time for P%d: ", pid[i]);
        scanf("%d %d",&at[i],&bt[i]);
    }
    sort(pid, at, bt, n);
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < at[i])
            time = at[i];
        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}