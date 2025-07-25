#include <stdio.h>

int n = 5;
int w[10] = {3, 3, 2, 5, 1}; 
int p[10] = {10, 15, 10, 12, 8};
int W = 10; 

int main() {
    int cur_w;
    float tot_v = 0;
    int i, maxi;
    int used[10];

    for (i = 0; i < n; ++i)
        used[i] = 0;

    cur_w = W;

    while (cur_w > 0) {
        maxi = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) &&
                (maxi == -1 || (float)w[i]/w[i] > (float)p[maxi]/w[maxi]))
                maxi = i;

        used[maxi] = 1;
        cur_w -= w[maxi];
        tot_v += p[maxi];

        if (cur_w >= 0)
            printf("Added object %d (%d, %d) completely in the bag. Space left: %d.\n",
                maxi + 1, p[maxi], w[maxi], cur_w);
        else {
            printf("Added %d%% (%d, %d) of object %d in the bag.\n",
                (int)((1 + (float)cur_w / w[maxi]) * 100), p[maxi], w[maxi], maxi + 1);
           
            tot_v -= p[maxi];
            tot_v += (1 + (float)cur_w / w[maxi]) * p[maxi];
        }
    }

    printf("Filled the bag with objects worth %.2f.\n", tot_v);
    return 0;
}