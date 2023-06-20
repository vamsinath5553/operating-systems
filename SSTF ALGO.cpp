#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TRACKS 100

void sstf(int tracks[], int numTracks, int headPos) {
    int visited[MAX_TRACKS] = {0};  // Array to keep track of visited tracks
    int totalHeadMovement = 0;      // Variable to keep track of total head movement

    printf("SSTF Disk Scheduling Algorithm\n");
    printf("Track Positions: ");
    for (int i = 0; i < numTracks; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\n");

    int currentPos = headPos;   // Start at the head position

    printf("\nHead Movement:\n");
    printf("%d ", currentPos);

    // Perform SSTF disk scheduling
    for (int i = 0; i < numTracks - 1; i++) {
        int minDistance = __INT_MAX__;
        int nextPos = -1;

        // Find the next closest track
        for (int j = 0; j < numTracks; j++) {
            if (!visited[j]) {
                int distance = abs(currentPos - tracks[j]);
                if (distance < minDistance) {
                    minDistance = distance;
                    nextPos = j;
                }
            }
        }

        // Update the current position and total head movement
        currentPos = tracks[nextPos];
        totalHeadMovement += minDistance;

        visited[nextPos] = 1;   // Mark the track as visited

        printf("%d ", currentPos);
    }

    printf("\n\nTotal Head Movement: %d\n", totalHeadMovement);
    printf("Average Head Movement: %.2f\n", (float) totalHeadMovement / (numTracks - 1));
}

int main() {
    int tracks[MAX_TRACKS] = {55, 58, 60, 70, 18};
    int numTracks = 5;
    int headPos = 50;

    sstf(tracks, numTracks, headPos);

    return 0;
}

