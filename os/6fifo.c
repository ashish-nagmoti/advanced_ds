#include <stdio.h>

int main() {
    int page_reference_stream[] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
    int num_pages = sizeof(page_reference_stream) / sizeof(page_reference_stream[0]);
    int num_frames = 5;
    int frames[num_frames];
    int page_faults = 0;

    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1; // Initialize frames as empty
    }

    int frame_index = 0; // Index to track the oldest page in the frames

    printf("Page Reference\tPage Frames\n");

    for (int i = 0; i < num_pages; i++) {
        int page = page_reference_stream[i];
        int page_found = 0;

        // Check if the page is already in the frames
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == page) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            frames[frame_index] = page; // Replace the oldest page with the new page
            frame_index = (frame_index + 1) % num_frames; // Update the index for the next oldest page
            page_faults++;
        }

        printf("%d\t\t\t", page);
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] != -1) {
                printf("%d\t", frames[j]);
            } else {
                printf("-\t");
            }
        }
        if (page_found)
        {
            printf("hit\t");
        }
        else
        {
            printf("miss\t");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Total Hits: %d\n", num_pages - page_faults);

    return 0;
}