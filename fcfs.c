#include<stdio.h>
int main(){
    int pid[15];
    int bt[15];
    int n;
    printf("enter the number of processes");
    scanf("%d",&n);
    printf("enter the pid pf each process:\n");
    for(int i =0;i<n;i++){
        scanf("%d",&pid[i]);
    }
    printf("enter the bt pf each process:\n");
    for(int i =0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    int i,wt[15];
    wt[0] = 0;
    for(i = 1;i<n;i++){
        wt[i]=bt[i-1]+wt[i-1];
    }
    float tat=0.0;
    float twt = 0.0;
    printf("Process ID      Burst Time      Wait Time       Turn Around Time\n");
    for(int i = 0;i<n;i++){
        printf("%d\t\t",pid[i]);
        printf("%d\t\t",bt[i]);
        printf("%d\t\t",wt[i]);
        printf("%d\t\t",bt[i]+wt[i]);
        printf("\n");

        twt += wt[i];
        tat = bt[i]+wt[i];
    }
    float awt,att;
    awt = twt/n;
    att = tat/n;
    printf("The average wait time is: %f\n",awt);
    printf("The average Turn Aroud Time is: %f\n",att);

}
