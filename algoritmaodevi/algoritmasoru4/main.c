#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//soru4
void quick_sort(int[], int, int);
void selection_sort(int[], int);

int main() {
    int i, n = 10000;
    int dizi1[n], dizi2[n];
    clock_t basla, bitis;
    double quick_sort_time, selection_sort_time;


    srand(time(NULL));
    for (i = 0; i < n; i++) {
        dizi1[i] = rand() % 100000;
        dizi2[i] = dizi1[i];
    }

    basla = clock();
    quick_sort(dizi1, 0, n - 1);
    bitis= clock();
    quick_sort_time = ((double) (bitis - basla)) /CLOCKS_PER_SEC;

    basla = clock();
    selection_sort(dizi2, n);
    bitis = clock();
    selection_sort_time = ((double) (bitis - basla))/CLOCKS_PER_SEC ;

    printf("Quick sort ile sýralanmýþ dizi: ");
    for (i = 0; i < n; i++) {
        printf("%d ", dizi1[i]);
    }
    printf("\nSelection sort ile sýralanmýþ dizi: ");
    for (i = 0; i < n; i++) {
        printf("%d ", dizi2[i]);
    }
    printf("\n\n");


    printf("Quick sort süresi: %f saniye\n", quick_sort_time);
    printf("Selection sort(bruteforce)süresi: %f saniye\n", selection_sort_time);

    return 0;
}

void quick_sort(int dizi[], int x, int y) {
    if (x < y) {
        int pivot = dizi[y];
        int i = x - 1, j, temp;
        for (j = x; j < y; j++) {
            if (dizi[j] < pivot) {
                i++;
                temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }
        }
        temp = dizi[i + 1];
        dizi[i + 1] = dizi[y];
        dizi[y] = temp;

        quick_sort(dizi, x, i);
        quick_sort(dizi, i + 2, y);
    }
}

void selection_sort(int dizi[], int n) {
    int i, j, min_index, temp;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (dizi[j] < dizi[min_index]) {
                min_index = j;
            }
        }
        temp = dizi[i];
        dizi[i] = dizi[min_index];
        dizi[min_index] = temp;
}
}
