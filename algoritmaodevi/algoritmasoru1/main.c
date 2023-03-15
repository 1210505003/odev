#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void quickSort(int dizi[], int x, int y) {
    int i = x, j = y, temp;
    int pivot = dizi[(x + y) / 2];

    while (i <= j) {
        while (dizi[i] < pivot) {
            i++;
        }
        while (dizi[j] > pivot) {
            j--;
        }
        if (i <= j) {
            temp = dizi[i];
            dizi[i] = dizi[j];
            dizi[j] = temp;
            i++;
            j--;
        }
    }

    if (x < j) {
        quickSort(dizi, x, j);
    }
    if (i < y) {
        quickSort(dizi, i, y);
    }
}



int binarySearch(int dizi[], int x, int y, int key) {
    int ortanca;

    while (x <= y) {
        ortanca = (x+ y) / 2;

        if (dizi[ortanca] == key) {
            return ortanca;
        } else if (dizi[ortanca] < key) {
            x = ortanca + 1;
        } else {
            y = ortanca - 1;
        }
    }

    return -1;
}


int LinearArama(int dizi[]){
    int konum = 0,c;
    for (c = 1; c < 10000; c++){
    if (dizi[c] > dizi[konum]){
      konum = c;
    }
}
  return dizi[konum];
}


int main(){

	int dizi[10000];
    int i, max;
	clock_t baslangic, bitis;
    double linearSearchTime,binarySearchTime ;


    printf("Rastgele oluþturulmuþ sýralý sayýlar: ");
    for (i = 0; i < 10000; i++) {
        dizi[i] = rand() % 100000;
        printf("%d ", dizi[i]);
	}

	quickSort(dizi, 0, 9999);

	baslangic = clock();
      	printf("\n en buyuk sayi  %d.\n",LinearArama(dizi));
    bitis = clock();
    linearSearchTime = ((double) (bitis - baslangic)) /CLOCKS_PER_SEC;

    baslangic = clock();
      	max = dizi[binarySearch(dizi, 0, 9999, dizi[9999])];
      	printf("En buyuk sayi: %d \n", max);
    bitis = clock();
    binarySearchTime = ((double) (bitis - baslangic)) /CLOCKS_PER_SEC ;

    printf("binarySearch süresi: %f saniye\n", binarySearchTime);
    printf("LinearArama süresi: %f saniye\n", linearSearchTime);

return 0;
}
