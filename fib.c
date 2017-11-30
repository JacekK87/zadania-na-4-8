#include <stdio.h>

int main() {
    int n;
    int fn,f1=n-2, f2=n-1;
    int wynik;


    printf("Podaj wartosc calkowita dla ktorej mam obliczyc ciag \nn = ");
    scanf(" %d", &n);

    if (n <= 2) {
        printf("Wynik = 1\n");
    } else {
        int fn= (f1 + f2);

        printf("%d elementem ciagu Fibonacciego jest %d\n",n,fn);
    }
    return fn = f1 + f2;
}
