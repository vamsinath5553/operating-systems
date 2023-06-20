#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void look(int tracks[], int numTracks, int headPos) {
    int totalHeadMovement = 0;      // Variable to keep track of total head movement

    printf("LOOK Disk Scheduling Algorithm\n");
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

    bool directionUp = true;    // Variable to keep track of the direction of movement

    // Perform LOOK disk scheduling
    while (true) {
        if (directionUp) {
            // Scan in the upward direction
            for (int i = currentPos + 1; i <= maxTrack; i++) {
                if (tracks[i] != -1) {
                    totalHeadMovement += abs(currentPos - tracks[i]);
                    currentPos = tracks[i];
                    printf("%d ", currentPos);
                    tracks[i] = -1;   // Mark the track as visited
                }
            }

            directionUp = false;   // Change the direction of movement
        } else {
            // Scan in the downward direction
            for (int i = currentPos - 1; i >= minTrack; i--) {
                if (tracks[i] != -1) {
                    totalHeadMovement += abs(currentPos - tracks[i]);
                    currentPos = tracks[i];
                    printf("%d ", currentPos);
                    tracks[i] = -1;   // Mark the track as visited
                }
            }

            directionUp = true;   // Change the direction of movement
        }

        bool allVisited = true;

        // Check if all tracks have been visited
        for (int i = 0; i < numTracks; i++) {
            if (tracks[i] != -1) {
                allVisited = false;
                break;
            }
        }

        if (allVisited) {
            break;
        }
    }

    printf("\n\nTotal Head Movement: %d\n", totalHeadMovement);
    printf("Average Head Movement: %.2f\n", (float) totalHeadMovement / numTracks);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int numTracks = 5;
    int headPos = 50;

    look(tracks, numTracks, headPos);

    return 0;
}

