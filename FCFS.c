/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void main()
{
    int p;
    printf("Enter no of processes:");
    scanf("%d",&p);
    char ch[p];
    int AT[p],BT[p],CT[p],TAT[p],i,WT[p],s1,s2,s3;
    printf("Enter Process name as Caps from A-Z\n");
    printf("Enter details of processes:\n");
    printf("Pid\tAT\tBT\n");
    for(i=0;i<p;i++)
    {
        scanf("%c\t%d\t%d\n",&ch[i],&AT[i],&BT[i]);
    }
    for(i=0;i<p;i++)
    {
        if(i==0)
        {
            s1=AT[i]+BT[i];
            s2=s1-AT[i];
            s3=s2-BT[i];
            CT[i]=s1;
            TAT[i]=s2;
            WT[i]=s3;
            continue;
        }
        s1=CT[i-1]+BT[i];
        s2=s1-AT[i];
        s3=s2-BT[i];
        CT[i]=s1;
        TAT[i]=s2;
        WT[i]=s3;
    }
    printf("Process details:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<p;i++)
    {
        printf("%c\t%d\t%d\t%d\t%d\t%d\t%d\n",ch[i],AT[i],BT[i],CT[i],TAT[i],WT[i],WT[i]);
    }
    printf("Gantt chart:\n");
    printf("Process\tStart time\tEnd time\n");
    for(i=0;i<p;i++)
    {
        if(i==0)
        {
            if(AT[i]!=0)
            {
                printf("L\t0\t%d\n",AT[i]);
            }
            else
            {
                printf("%c\t%d\t%d\n",ch[i],AT[i],CT[i]);
            }
            continue;
        }
        else
        {
            if(CT[i-1]<AT[i])
            {
                printf("L\t%d\t%d\n",CT[i-1],AT[i]);
            }
            else
            {
                printf("%c\t%d\t%d\n",ch[i],CT[i-1],CT[i]);
            }
        }
    }
}

