#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int findOptimalIndex(int pages[], int frames[], int frameCount, int startIndex) {
    int i, j;
    int optimalIndex = -1;
    int farthestIndex = startIndex;

    for (i = 0; i < frameCount; i++) {
        int frame = frames[i];
        int found = 0;

        for (j = startIndex; j < MAX_PAGES; j++) {
            if (pages[j] == frame) {
                found = 1;
                if (j > farthestIndex) {
                    farthestIndex = j;
                    optimalIndex = i;
                }
                break;
            }
        }

        if (!found) {
            optimalIndex = i;
            break;
        }
    }

    return optimalIndex;
}

int main() {
    int pages[MAX_PAGES];
    int frames[MAX_FRAMES];
    int pageFaults = 0;
    int pageHits = 0;
    int i, j;

    printf("Enter the sequence of page references (separated by spaces): ");
    for (i = 0; i < MAX_PAGES; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames with -1 indicating an empty frame
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    // Process each page reference
    for (i = 0; i < MAX_PAGES; i++) {
        int page = pages[i];
        int pageExists = 0;

        // Check if the page already exists in any frame
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                pageExists = 1;
                pageHits++;
                break;
            }
        }

        // Page fault: page is not present in any frame
        if (!pageExists) {
            int optimalIndex = findOptimalIndex(pages, frames, MAX_FRAMES, i + 1);
            frames[optimalIndex] = page;
            pageFaults++;

            // Print the current state of frames
            printf("\nPage Fault: [");
            for (j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1) {
                    printf(" - ");
                } else {
                    printf(" %d ", frames[j]);
                }
            }
            printf("]");
        }
    }

    printf("\n\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);

    return 0;
}

/*
Enter the sequence of page references (separated by spaces): 1 2 3 4 1 2 5 1 2 3 4 5

Page Fault: [ 1  -  - ]
Page Fault: [ 1  2  - ]
Page Fault: [ 1  2  3 ]
Page Fault: [ 4  2  3 ]
Page Fault: [ 4  1  3 ]
Page Hit: [ 4  1  3 ]
Page Hit: [ 4  1  3 ]
Page Fault: [ 4  1  5 ]
Page Hit: [ 4  1  5 ]
Page Hit: [ 4  1  5 ]
Page Hit: [ 4  1  5 ]
Page Hit: [ 4  1  5 ]
Page Hit: [ 4  1  5 ]
Page Hit: [ 4  1  5 ]

Total Page Faults: 5
Total Page Hits: 7
*/
