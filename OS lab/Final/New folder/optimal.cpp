#include <stdio.h>

int main() {
    int pageCount = 20; 
    int pages[20] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int frameCount = 4; 
    int frames[4] = {-1, -1, -1, -1};
    int lastUsed[4] = {0, 0, 0, 0};

    int pageFaults = 0; 
    int pageHits = 0; 
    int time = 0; 


    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];
        int hit = 0; 

     
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                hit = 1;
                lastUsed[j] = time; 
                break; 
            }
        }

        if (hit == 1) {
            pageHits++; 
        } else {
            
            pageFaults++; 

           
            int emptyFound = 0;
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {
                    frames[j] = page; 
                    lastUsed[j] = time;
                    emptyFound = 1;
                    break; 
                }
            }

          
            if (emptyFound == 0) {
                
                int lruIndex = 0;
                for (int j = 1; j < frameCount; j++) {
                    if (lastUsed[j] < lastUsed[lruIndex]) {
                        lruIndex = j;
                    }
                }

             
                frames[lruIndex] = page;
                lastUsed[lruIndex] = time; 
            }
        }

        time++; 
    }

    printf("Number of page hits: %d\n", pageHits);
    printf("Number of page faults: %d\n", pageFaults);

    return 0;
}