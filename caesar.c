#include <stdio.h>
#include <string.h>
#include <string.h>

int encodeWord (int key, char text[30]);

int main (void) {
    int key = 0;
    char plainText[30];

    do {
        printf("Key: ");
        scanf("%d", &key);
    } while (key < 0);

    printf("Plain text: ");
    scanf("%29s", plainText);

    encodeWord(key, plainText);
}

int encodeWord (int key, char text[30]) {
    printf("Plain text: %d\nKey: %d", text[0], key);

    int temp = text - "0";
    temp += key;

    //Preciso transformar em string novamente
    
    //printf("%s", temp[0]);
}