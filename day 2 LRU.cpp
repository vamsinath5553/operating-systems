#include <stdio.h>

int main() {
    int n, i, j, k, page_faults = 0, m, flag;
    printf("Enter the number of page frames: ");
    scanf("%d", &n);

    int page_frames[n], pages[m];

    printf("Enter the number of pages: ");
    scanf("%d", &m);

    printf("Enter the page reference sequence: ");
    for(i = 0; i < m; i++) {
        scanf("%d", &pages[i]);
    }

    for(i = 0; i < n; i++) {
        page_frames[i] = -1;
    }

    for(i = 0; i < m; i++) {
        flag = 0;
        for(j = 0; j < n; j++) {
            if(page_frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            for(j = 0; j < n; j++) {
                int lru = m;
                for(k = i - 1; k >= 0; k--) {
                    if(page_frames[j] == pages[k]) {
                        lru = k;
                        break;
                    }
                }

                if(lru < m) {
                    page_frames[j] = pages[i];
                    page_faults++;
                    break;
                }
            }
        }

        printf("\n%d: ", pages[i]);
        for(j = 0; j < n; j++) {
            printf("%d\t", page_frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", page_faults);

    return 0;
}
