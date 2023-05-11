#include <stdio.h>

#define MAX_FRAMES 3

int main() {
    int pages[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int n = sizeof(pages) / sizeof(int);
    int frames[MAX_FRAMES];
    int page_faults = 0;
    int next_frame = 0;
    int i, j, k;
    int found;

    // Initialize frames to -1 to indicate empty
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    // Loop through pages
    for (i = 0; i < n; i++) {
        found = 0;

        // Check if page is already in a frame
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If page is not in a frame, replace the oldest page
        if (!found) {
            frames[next_frame] = pages[i];
            next_frame = (next_frame + 1) % MAX_FRAMES;
            page_faults++;
        }

        // Print current frame contents
        printf("Current frames: ");
        for (k = 0; k < MAX_FRAMES; k++) {
            if (frames[k] == -1) {
                printf("-");
            } else {
                printf("%d", frames[k]);
            }
            if (k < MAX_FRAMES - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", page_faults);

    return 0;
}
