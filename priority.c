#include<stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b = temp;

}

int main(){
    int n;
    printf("enter the total number of processes: ");
    scanf("%d",&n);
    int index[n],p[n],b[n];
    for(int i = 0; i<n ; i++){
        printf("enter the priority for process%d: ",i+1);
        scanf("%d",&p[i]);
        printf("enter the burst time: ");
        scanf("%d",&b[i]);
        index[i] = i+1;
    }
    for(int i = 0;i<n;i++){
        int a = p[i],m = i;
        for(int j = i;j<n;j++){
            if(p[j]>a){
                a = p[j];
                m = j;
            }
        }
        swap(&p[i],&p[m]);
        swap(&b[i],&b[m]);
        swap(&index[i],&index[m]);
    }
    int t = 0;
    printf("order of execution is: \n");
    for(int i = 0; i<n ; i++){
        printf("P%d is executed from %d to %d",i+1,t,t+b[i]);
        t = b[i];
    }
    printf("\n");
    printf("Process Id     Burst Time   Wait Time    TurnAround Time\n");
    int wait_time=0;
    for(int i = 0; i<n ; i++){
        printf("P%d          %d          %d          %d\n",index[i],b[i],wait_time,wait_time + b[i]);
        wait_time += b[i];
    }
    return 0;
}
