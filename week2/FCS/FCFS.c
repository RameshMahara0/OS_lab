#include<stdio.h>
int main(){
int i,n;
printf("Enter number of processor:\t");
scanf("%d",&n);
int at[n],bt[n],wt[n],tat[n],rt[n],ct[n];
for(i=0;i<n;i++){
    printf("Processor:%d\n",i+1);
    printf("Arrival time:");
    scanf("%d",&at[i]);
    printf("Brust Time");
    scanf("%d",&bt[i]);
}
    ct[0]=at[0]+bt[0];
    tat[0]=ct[0]-at[0];
    wt[0]=tat[0]-bt[0];
    rt[0]=wt[0];
    for(i=0;i<n;i++){
        if(ct[i-1]<at[i])
            ct[i]=at[i]+bt[i];
        else
            ct[i]=ct[i-1]+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        rt[i]=wt[i];
    }
    printf("Process\tAT\tBT\tCT\tWT\tTAT\tRT\n");
    float total_wt=0,total_tat=0,total_rt=0;
    for(i=0;i<n;i++){
        printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],wt[i],tat[i],rt[i]);
        total_wt+=wt[i];
        total_tat+=tat[i];
        total_rt+=rt[i];
    }
    printf("\nAverage Wt:%.2f",total_wt/n);
    printf("\nAverage TAT:%.2f",total_tat/n);
    printf("\nAverage RT:%.2f",total_rt/n);
    return 0;

}
