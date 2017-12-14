#include <stdio.h>

int n, fib, t;
int wybor = 1;

void liczenie(int *n, int fib);

int main() {

    do{

        liczenie(&n, fib);

            printf("Czy chcesz liczyc kolejna liczbe?? 1 - Tak / 0 - Nie\n");
            scanf("%d", &wybor);
    }
    while(wybor == 1);

    return 0;
}

    void liczenie(int *n, int fib) {
    printf("Podaj wartosc calkowita dla ktorej mam obliczyc ciag \nn = ");
    scanf(" %d", n);

    if ((*n) <= 2) {
            printf("Wynik = 1\n");
        } else if ((*n>2)) {
        fib = (*n) - 2 + (*n) - 1;
        printf("Ciag Fibonacciego dla liczby %d jest liczba %d\n", (*n), fib);
    }
}
