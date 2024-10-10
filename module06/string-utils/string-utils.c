#include "string-utils.h"

/* mystrncpy - determine the length of a fixed-size string */
char *mystrncpy(char *dest, char *src, int maxlen) {
    int i;

    for (i = 0; i < maxlen && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for ( ; i < maxlen; i++) {
        dest[i] = '\0';
    }

    return dest;
}


/* mystrnlen - determine the length of a fixed-size string */
int mystrnlen(char *s, int maxlen) {
    int count = 0;
    for (int i = 0; i < maxlen; i++) {
        if (s[i] == '\0') {
            break;
        }
        count++;
    }
    return count;
}

/* mystrcat - concatenate two strings */
char *mystrcat(char *dest, char *src) {
    int destLength = 0;
    int i = 0;
    while (dest[i] != '\0') {
        destLength++;
        i++;
    }
    

    for (i = 0; src[i] != '\0'; i++) {
        dest[destLength] = src[i];
        destLength++;
    }
    dest[destLength] = '\0';

    return dest;
}

/* mystrrev - reverse a string */
void strrev(char *s){
    int strLength = 0;
    int i = 0;
    while (s[i] != '\0') {
        strLength++;
        i++;
    }

    int position = strLength - 1; // position at end of string, then goes backwards
    for (i = 0; i < strLength / 2; i++) {
        char temp = s[i];
        s[i] = s[position];
        s[position] = temp;
        position--;
    }

}

/* mystrcmp - compare two strings */
int mystrcmp(char *s1, char *s2) {
    int i = 0;
    while ((s1[i] != '\0') && (s2[i] != '\0')) {
        if (s1[i] < s2[i]) {
            return -1;
        }
        else if (s1[i] > s2[i]) {
            return 1;
        }
        i++;
    }
    // check if one string is longer
    if (s1[i] != '\0') {
        return 1;
    } else if (s2[i] != '\0') {
        return -1;
    }

    return 0;
}

/* strpal - determine if a string is a palindrome */
int strpal(char *s) {
    int strLength = 0;
    int i = 0;
    while (s[i] != '\0') {
        strLength++;
        i++;
    }

    // Assume 1 is true, 0 is false
    int position = strLength - 1; // position at end of string, then goes backwards
    for (i = 0; i < strLength / 2; i++) {
        if (s[i] != s[position]) {
            return 0;
        }
        position--;
    }
    return 1;
}