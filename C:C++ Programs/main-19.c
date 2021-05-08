//first come  first server
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void accept(n);
void display(n);
void fcfs(n);
struct process
{
   char pc[10];
       int at,bt,tat,wt;
}s[10],temp;
void main()
{
   int i,n,j,temp1,temp2,tot_tat=0,tot_wt=0,avg_wt=0,avg_tat=0,t_wt,t_tat;
   temp1=0;
   temp2=0;
   t_wt=0;
   t_tat=0;
   printf("\n Enter the no of processes u want to schedule");
   scanf("%d",&n);
  
   accept(n);
   printf("\n processess are:");
   printf("\n process\tarrival time\tburst time\twaiting time\tturn around time");
   display(n);
    
   printf("\n After sorting");
   for(i=0;i<n;i++)
   {
       for(j=i+1;j<n;j++)
       {
           if(s[i].at>s[j].at)
           {
               temp=s[i];
               s[i]=s[j];
               s[j]=temp;
           }
       }
   }
   display(n);
   fcfs(n);
   printf("\n After the calculation");
   display(n);
   for(i=0;i<n;i++)
   {
       t_wt=t_wt+s[i].wt;
       t_tat=t_tat+s[i].tat;
   }
   avg_wt=t_wt/n;
   avg_tat=t_tat/n;
   printf("\n Average waiting time is %d",avg_wt);
   printf("\n Average Turn around time is %d",avg_tat);
}
void accept(int n)
{
       int i;
       for(i=0;i<n;i++)
   {
       scanf("%s",&s[i].pc);
       scanf("%d",&s[i].at);
       scanf("%d",&s[i].bt);
   }
}
void display(int n)
{
       int i;
       for(i=0;i<n;i++)
       {
               printf("\n%s\t\t%d\t\t%d\t\t%d\t\t%d",s[i].pc,s[i].at,s[i].bt,s[i].wt,s[i].tat);
       }
}
void fcfs(int n)
{
       int i,j,temp1,temp2,tot_tat=0,tot_wt=0,avg_wt=0,avg_tat=0,t_wt,t_tat;
   temp1=0;
   temp2=0;
   t_wt=0;
   t_tat=0;
   temp1=s[0].at;
   s[0].wt=0;
   s[0].tat=s[0].bt;
       for(i=0;i<n;i++)
   {
      
       temp1=temp1+s[i].bt;
       s[i].tat=temp1-s[i].at;
       s[i].wt=s[i].tat-s[i].bt;
       tot_wt=tot_wt+s[i].wt;
       tot_tat=tot_wt+s[i].tat;
          
           if(i<(n-1) && temp1<s[i+1].at)
           printf("\n IDLE");
           temp1=s[i+1].at;
      
   }
   printf("%d",temp2);
   for(i=0;i<n;i++)
   {
       temp2=temp2+s[i].bt;
       printf("<-%s->%d",s[i].pc,temp2);
   }
}
