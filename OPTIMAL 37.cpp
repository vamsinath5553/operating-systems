#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_PAGE_FRAMES 10

int optimal(int pageFrames[], int numFrames, int pageReferences[], int numReferences) {
    int pageFaults = 0;

    for (int i = 0; i < numReferences; i++) {
        int currentPage = pageReferences[i];
        bool pageFound = false;

        for (int j = 0; j < numFrames; j++) {
            if (pageFrames[j] == currentPage) {
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            int maxDistance = -1;
            int replaceIndex = -1;

            for (int j = 0; j < numFrames; j++) {
                int nextIndex = i + 1;
                int distance = 0;

                while (nextIndex < numReferences) {
                    if (pageFrames[j] == pageReferences[nextIndex]) {
                        break;
                    }
                    distance++;
                    nextIndex++;
                }

                if (distance > maxDistance) {
                    maxDistance = distance;
                    replaceIndex = j;
                }
            }

            pageFrames[replaceIndex] = currentPage;
            pageFaults++;
        }
    }

    return pageFaults;
}

int main() {
    int pageFrames[MAX_PAGE_FRAMES] = {0};
    int numFrames = 3;
    int pageReferences[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int numReferences = 8;

    int pageFaults = optimal(pageFrames, numFrames, pageReferences, numReferences);

    printf("Optimal Page Replacement Algorithm\n");
    printf("Page Reference Sequence: ");
    for (int i = 0; i < numReferences; i++) {
        printf("%d ", pageReferences[i]);
    }
    printf("\n");
    printf("Number of Page Faults: %d\n", pageFaults);

    return 0;
}

