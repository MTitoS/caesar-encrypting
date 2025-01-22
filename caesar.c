#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>

int encodeWord (int originalKey, char text[30]);

int main (void) {
    int key = 0;
    char plainText[30];

    do {
        printf("Key: ");
        scanf("%d", &key);
    } while (key < 0);

    printf("Plain text: ");
    scanf( " %99[^\n]", plainText);

    encodeWord(key, plainText);
}

int encodeWord (int originalKey, char text[30]) {
    int newKey = originalKey % 26;
    char encodedText[30];

    printf("Encoded text: ");

    for (int i = 0; i < strlen(text); i++) {
        if (isspace(text[i])) {
            printf(" ");
        } else if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            encodedText[i] = (text[i] - base + newKey) % 26 + base;
        } else {
                encodedText[i] = text[i];
        }

        printf("%c", encodedText[i]);
    }
}