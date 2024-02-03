#include <stdio.h>

int main(void)
{
    // rotors
    const char letters[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int l = 26;
    const int rotor1[26] = {0, 21, 9, 14, 12, 16, 2, 20, 1, 3, 15, 13, 5, 17, 11, 24, 7, 23, 25, 4, 22, 8, 10, 18, 6, 19};
    const int rotor2[26] = {16, 17, 5, 8, 13, 21, 22, 1, 18, 14, 2, 10, 7, 0, 11, 6, 25, 20, 3, 24, 4, 9, 23, 12, 15, 19};
    const int rotor3[26] = {11, 16, 1, 7, 6, 5, 14, 20, 2, 12, 25, 8, 13, 10, 22, 3, 23, 9, 4, 17, 21, 15, 0, 24, 19, 18};
    const int rotor4[26] = {19, 8, 21, 23, 5, 17, 14, 3, 1, 0, 11, 16, 10, 20, 18, 7, 22, 12, 6, 24, 13, 2, 15, 25, 4, 9};
    const int rotor5[26] = {0, 22, 14, 2, 11, 1, 16, 18, 9, 12, 4, 3, 13, 5, 20, 25, 23, 19, 24, 21, 8, 7, 15, 17, 6, 10};
    
    // settings
    int offset1 = 3;
    int offset2 = 5;
    int offset3 = 2;

    // program
    const char message[] = "HELLOWORLD";
    char in_char = message[0];
    size_t n = sizeof(message)/sizeof(message[0]);
    int idx1 = 0;
    int idx2 = 0;
    int idx3 = 0;
    int idx4 = 0;
    for (int i=0; i<n; i++) {
        /* encoding */
        in_char = message[i];
        // find index of in_char in letters
        int found = 0;
        for (int j=0; j<l && found == 0; j++) {
            if (letters[j]==in_char) {
                found = 1;
                idx1 = j;
            }
        }
        // 'go through the rotors'
        idx2 = (rotor1[idx1]+offset1) % l;
        idx3 = (rotor2[idx2]+offset2) % l;
        idx4 = (rotor3[idx3]+offset3) % l;
        printf("%c", letters[idx4]);
        // rotate the rotors
        offset1++;
        if (i%26==25) {
            offset2++;
        }
    }
    printf("\n");
    return 0;
}