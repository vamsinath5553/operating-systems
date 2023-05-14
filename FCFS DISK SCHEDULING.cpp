#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int head = 50; // start head position
    int movement = 0;

    printf("Sequence of tracks visited:\n%d", head);
    for (int i = 0; i < n; i++)
    {
        movement += abs(tracks[i] - head);
        head = tracks[i];
        printf(" -> %d", head);
    }

    printf("\nTotal head movement = %d\n", movement);
    printf("Average head movement = %.2f\n", (float)movement/n);

    return 0;
}
