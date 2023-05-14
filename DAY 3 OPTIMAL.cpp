#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

int find_longest_future(int pages[], int n, int frame[], int m, int current_index) {
    int max_future_index = -1;
    int max_future_distance = -1;

    for (int i = 0; i < m; i++) {
        int future_distance = -1;
        for (int j = current_index; j < n; j++) {
            if (pages[j] == frame[i]) {
                future_distance = j - current_index;
                break;
            }
        }
        if (future_distance == -1) {
            return i;
        }
        if (future_distance > max_future_distance) {
            max_future_index = i;
            max_future_distance = future_distance;
        }
    }

    return max_future_index;
}

int main() {
    int num_frames = 3;
    int page_refs[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int num_page_refs = sizeof(page_refs) / sizeof(page_refs[0]);
    int page_faults = 0;

    int frames[MAX_FRAMES];
    int num_frames_used = 0;

    for (int i = 0; i < num_page_refs; i++) {
        int page = page_refs[i];
        int page_found = 0;
        for (int j = 0; j < num_frames_used; j++) {
            if (frames[j] == page) {
                page_found = 1;
                break;
            }
        }
        if (!page_found) {
            if (num_frames_used < num_frames) {
                frames[num_frames_used] = page;
                num_frames_used++;
            }
            else {
                int index_to_replace = find_longest_future(page_refs, num_page_refs, frames, num_frames, i);
                frames[index_to_replace] = page;
            }
            page_faults++;
        }
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}
