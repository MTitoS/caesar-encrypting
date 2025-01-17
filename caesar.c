#include <stdio.h>
#include <string.h>
#include <string.h>

int main (void) {
    int key = 0;

    do {
        printf("Key: ");
        scanf("%d", &key);
    } while (key < 0);
}