#include <stdio.h>

int main () {
    char x[1];
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    printf("Enter letter: ");
    scanf("%s", x);


    printf("\nYour selections were: %s %d", x, n);    

    return 0;
}
