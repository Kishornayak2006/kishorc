# include<stdio.h>
int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,totalT=0,pos,temp;
    float avg_wt,avg_tat;
    printf("\n enter the number of process");
    scanf("%d",&n);
     printf("\n enter the burst time of process\n :");
    for(i=0;i<n;i++)
    {
        printf("P%d ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
 }
    for(i=0;i<n;i++)
 {
    pos=i;
    for(j=i+1;j<n;j++)
    {
        if(bt[j]<bt[pos])
        pos=j;
    }
    temp=bt[i];
    bt[i]=bt[pos];
    bt[pos]=temp;
    temp=p[i];
    p[i]=p[pos];
    p[pos]=temp;
    wt[i]+=bt[j];
    totalT+=wt[i];
 }
 avg_wt=(float)totalT/n;
 printf("\nProcess Burst Time\tWaiting Time\tTurn around Time");
     for(i=0;i<n;i++)                                         
{
    tat[i]=bt[i]+wt[i];
    totalT+=tat[i];
    printf("\np%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);

}
avg_tat=(float)totalT/n;
printf("\n\n Average waiting time=%f",avg_wt);
printf("\n\n Average turnaround time=%f",avg_tat);
}

