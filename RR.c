#include<stdio.h>
#include<conio.h>
int main(){
    int i,NOP,quant,sum = 0,y,count = 0,wt=0,tat=0,at[10],bt[10],temp[10];
    float awt,att;
    printf("enter the number of processes: ");
    scanf("%d",&NOP);
    y = NOP;
    for(i = 0 ; i<NOP;i++){
        printf("Enter the burst time and the arrival time for the process[%d]\n",i+1);
        printf("enter the arrival time");
        scanf("%d",&at[i]);
        printf("enter the burst time");
        scanf("%d",&bt[i]);
        temp[i]=bt[i];
    }
    printf("enter the time quantum: ");
    scanf("%d",&quant);
    printf("process no \t\t\t burst time \t\t\t wait time \t\t\t turn around time\n");
    for(sum = 0, i = 0;y!=0;){
        if(temp[i]<=quant && temp[i]>0){
            sum = sum +  temp[i];
            temp[i]=0;
            count = 1;
        }

        else if(temp[i]>0){
            temp[i] = temp[i]-quant;
            sum = sum + quant;
        }
        if(temp[i]==0 && count==1){
            y--;
            printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1,bt[i],sum-at[i]-bt[i],sum-at[i]);
            tat = tat + sum-at[i]-bt[i];
            wt = wt + sum-at[i];
            count = 0;
        }
        if(i == NOP-1){
            i = 0;
        }
        else if(at[i+1]<=sum){
            i++;
        }
        else{
            i=0;
        }
    }
    awt = wt/NOP;
    att = tat/NOP;
    printf("The average Wait time is: %f\n",awt);
    printf("the average turn around time is: %f",att);
    getch();
