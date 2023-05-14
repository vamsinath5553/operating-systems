#include <stdio.h>

int main()
{
    int mem_size[] = {300, 600, 350, 200, 750, 125};
    int n = sizeof(mem_size) / sizeof(mem_size[0]);
    int process_size[] = {115, 500, 358, 200, 375};
    int m = sizeof(process_size) / sizeof(process_size[0]);
    int allocation[m];

    for (int i = 0; i < m; i++)
    {
        int best_index = -1;
        for (int j = 0; j < n; j++)
        {
            if (mem_size[j] >= process_size[i])
            {
                if (best_index == -1)
                    best_index = j;
                else if (mem_size[j] < mem_size[best_index])
                    best_index = j;
            }
        }
        if (best_index != -1)
        {
            allocation[i] = best_index;
            mem_size[best_index] -= process_size[i];
        }
        else
            allocation[i] = -1;
    }

    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d\t\t%d\t\t", i+1, process_size[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i]+1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
