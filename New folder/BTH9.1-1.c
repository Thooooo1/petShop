//bt9.a.1
#include <stdio.h>

void ADJUST(int K[], int i, int n) {
    int KEY = K[i];
    int j = 2 * i;
    while (j <= n) {
        if ((j < n) && (K[j] < K[j+1]))
            j++;
        if (KEY >= K[j])
            break;
        K[j/2] = K[j];
        j *= 2;
    }
    K[j/2] = KEY;
}

void HeapSort(int K[], int n) {
    int i;
    for (i = n/2; i >= 1; i--)
        ADJUST(K, i, n);
    for (i = n; i >= 2; i--) {
        int tmp = K[1];
        K[1] = K[i];
        K[i] = tmp;
        ADJUST(K, 1, i-1);
    }
}

