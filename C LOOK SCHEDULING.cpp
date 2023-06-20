#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void clook(int tracks[], int numTracks, int headPos) {
    int totalHeadMovement = 0;      // Variable to keep track of total head movement

    printf("CLOOK Disk Scheduling Algorithm\n");
    printf("Track Positions: ");
    for (int i = 0; i < numTracks; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\n");

    int currentPos = headPos;   // Start at the head position

    printf("\nHead Movement:\n");
    printf("%d ", currentPos);

    // Find the maximum track position
    int maxTrack = tracks[0];
    for (int i = 1; i < numTracks; i++) {
        if (tracks[i] > maxTrack) {
            maxTrack = tracks[i];
        }
    }

    // Find the minimum track position
    int minTrack = tracks[0];
    for (int i = 1; i < numTracks; i++) {
        if (tracks[i] < minTrack) {
            minTrack = tracks[i];
        }
    }

    // Sort the track positions in ascending order
    for (int i = 0; i < numTracks - 1; i++) {
        for (int j = 0; j < numTracks - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    // Find the index of the current position
    int currentIndex = 0;
    for (int i = 0; i < numTracks; i++) {
        if (tracks[i] >= currentPos) {
            currentIndex = i;
            break;
        }
    }

    // Perform CLOOK disk scheduling
    for (int i = currentIndex; i < numTracks; i++) {
        totalHeadMovement += abs(currentPos - tracks[i]);
        currentPos = tracks[i];
        printf("%d ", currentPos);
    }

    if (currentIndex != 0) {
        totalHeadMovement += abs(currentPos - tracks[0]);
        currentPos = tracks[0];
        printf("%d ", currentPos);
    }

    printf("\n\nTotal Head Movement: %d\n", totalHeadMovement);
    printf("Average Head Movement: %.2f\n", (float) totalHeadMovement / numTracks);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int numTracks = 5;
    int headPos = 50;

    clook(tracks, numTracks, headPos);

    return 0;
}
