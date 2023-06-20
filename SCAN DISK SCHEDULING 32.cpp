#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TRACKS 100

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void scan(int tracks[], int n, int head) {
    int totalHeadMovement = 0;

    // Sort the tracks in ascending order
    qsort(tracks, n, sizeof(int), compare);

    // Find the position of the head in the sorted tracks
    int headPos = 0;
    for (int i = 0; i < n; i++) {
        if (tracks[i] > head) {
            headPos = i;
            break;
        }
    }

    // Move the head from the current position to the last track (max track)
    for (int i = headPos; i < n; i++) {
        printf("%d -> ", tracks[i]);
        totalHeadMovement += abs(tracks[i] - head);
        head = tracks[i];
    }

    // Move the head from the last track to the first track (min track)
    printf("%d -> ", tracks[n - 1]);
    totalHeadMovement += abs(tracks[n - 1] - head);
    head = tracks[n - 1];

    // Move the head from the first track to the track just before the head position
    for (int i = n - 2; i >= 0; i--) {
        printf("%d -> ", tracks[i]);
        totalHeadMovement += abs(tracks[i] - head);
        head = tracks[i];
    }

    printf("End\n");

    float avgHeadMovement = (float)totalHeadMovement / n;
    printf("Average Head Movement: %.2f\n", avgHeadMovement);
}

int main() {
    int tracks[MAX_TRACKS] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int n = 9;
    int head = 100;

    printf("SCAN Disk Scheduling Algorithm\n");
    printf("Track Positions: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\n");
    printf("Initial Head Position: %d\n", head);
    printf("Head Movement Sequence: ");

    scan(tracks, n, head);

    return 0;
}

