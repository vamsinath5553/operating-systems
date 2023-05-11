#include<stdio.h>

int main()
{
    int n=3,m=3; // number of processes and resources
    int allocation[n][m], max[n][m], need[n][m], available[m], finish[n], deadlocked=0;

    // Allocation matrix input
    printf("Enter the Allocation Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }

    // Max matrix input
    printf("Enter the Max Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }

    // Available resources input
    printf("Enter the Available Resources:\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&available[i]);
    }

    // Deadlock detection algorithm implementation
    for(int k=0;k<n;k++)
    {
        finish[k]=0;
    }
    for(int count=0;count<n;count++)
    {
        int found=0;
        for(int i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                int j;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>available[j])
                    {
                        break;
                    }
                }
                if(j==m)
                {
                    for(int k=0;k<m;k++)
                    {
                        available[k]+=allocation[i][k];
                    }
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(found==0)
        {
            deadlocked=1;
            printf("The system is deadlocked. The deadlocked processes are: ");
            for(int i=0;i<n;i++)
            {
                if(finish[i]==0)
                {
                    printf("P%d ",i+1);
                }
            }
            printf("\n");
            break;
        }
    }
    if(deadlocked==0)
    {
        printf("The system is not deadlocked.\n");
    }

    return 0;
}
