#include <stdio.h>

int main() {
    int P[11] = {0};

    P[10] = 9;
    P[9] = 3;
    P[3] = 1;

    int cur = 10;

    while(1) {
        printf("%d ", cur);

        if(cur == 1)
            break;

        cur = P[cur];
    }

    return 0;
}
