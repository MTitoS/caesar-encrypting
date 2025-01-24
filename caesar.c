#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>

int encodeWord (int originalKey, char text[30]);

int main (void) {
    int key = 0;
    char plainText[30];

    //Gets the key that will be used as a encoder.
    do {
        printf("Key: ");
        scanf("%d", &key);
    } while (key < 0);

    printf("Plain text: ");
    //%99[^\n] so the program doesn't think the whitespaces (from the spacebar) are the empty space that marks the final of a string.
    scanf( " %99[^\n]", plainText);

    encodeWord(key, plainText);
}

int encodeWord (int originalKey, char text[30]) {
    int newKey = originalKey % 26; //%26 because of the 26 words in the alphabet, so if the key is too big it converts to be more concise.
    char encodedText[30];

    printf("Encoded text: ");

    //Iterate through the whole text
    for (int i = 0; i < strlen(text); i++) {
        //isspace function from <ctype.h> to identify a whitespace. They are going to be printed as it should.
        if (isspace(text[i])) {
            printf(" ");
        //If is alphabetical (also <ctype.h> function)
        } else if (isalpha(text[i])) {
            //The base is, in other words, if the text[i] is a uppercase letter, the base is A, if not, it will be a.
            char base = isupper(text[i]) ? 'A' : 'a';
            //text[i] - base ('A' or 'a'), so we can work with a number from 0 to 25. Then it adds the key it need to be in. Example: item[i] (A) - base (A) = 65 - 65 = 0.
            //After the expression in parenthesis, it will certify that is in the baseline of 0 to 25 doing % 26, because the key can be something like 125.
            //Then it adds the base again so the text can go to the range of alphabet in ASCII (65 to 90 if is uppercase).  
            encodedText[i] = (text[i] - base + newKey) % 26 + base;
        } else {
                //If it isn't alphabetical, it will just print out as it already is.
                encodedText[i] = text[i];
        }

        //Prints char by char.
        printf("%c", encodedText[i]);
    }
}