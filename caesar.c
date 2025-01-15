#include <stdio.h>
#include <string.h>

int main (void) {
    int key = 0;

    do {
        printf("Key:\n");
        scanf("%d",key);
    } while (key < 0);

    printf("%d", key);
}