#include <stdio.h>

int main() {
    int pageC = 15;
    int pages[15] = {4, 2, 3, 1, 2, 3, 4, 7, 5, 2, 1, 0, 7, 3, 2};
    int frameC = 4;
    int frames[4] = {-1, -1, -1, -1};

    int pageF = 0;
    int pageH = 0;

    for (int i = 0; i < pageC; i++) {
        int page = pages[i];
        int hit = 0;

        for (int j = 0; j < frameC; j++) {
            if (frames[j] == page) {
                hit = 1;
                break;
            }
        }

        if (hit == 1) {
            pageH++;
        } else {
            pageF++;

            int emptyF = 0;
            for (int j = 0; j < frameC; j++) {
                if (frames[j] == -1) {
                    frames[j] = page;
                    emptyF = 1;
                    break;
                }
            }

            if (emptyF == 0) {
                int farthest = -1;
                int replaceIndex = 0;

                for (int j = 0; j < frameC; j++) {
                    int k;
                    for (k = i + 1; k < pageC; k++) {
                        if (frames[j] == pages[k]) {
                            if (k > farthest) {
                                farthest = k;
                                replaceIndex = j;
                            }
                            break;
                        }
                    }
                    if (k == pageC) {
                        replaceIndex = j;
                        break;
                    }
                }

                frames[replaceIndex] = page;
            }
        }
    }

    printf("Number of page hits: %d\n", pageH);
    printf("Number of page faults: %d\n", pageF);

    return 0;
}