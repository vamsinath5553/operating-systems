#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, head, i, total_movement = 0;

    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    int queue[n];

    printf("Enter the track positions: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // FCFS disk scheduling algorithm
    for (i = 0; i < n; i++) {
        total_movement += abs(head - queue[i]);
        head = queue[i];
    }

    printf("Total head movement: %d\n", total_movement);
    printf("Average head movement: %.2f\n", (float) total_movement / n);

    return 0;
}
