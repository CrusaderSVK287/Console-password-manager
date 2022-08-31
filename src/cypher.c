#include "headers/cypher.h"

unsigned char* encrypt(char* password_to_encrypt) {
    if(password_to_encrypt == NULL) {
        return NULL;
    }

    //get the bits of the password
    int lenght = strlen(password_to_encrypt);
    int bits[lenght][8];
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < 8; j++) {
            bits[i][7-j] = password_to_encrypt[i] >> j & 1;
        }
    }
    //swap bits int the mb nibble
    for (int i = 0; i < lenght; i++) {
        int tmp = bits[i][0];
        bits[i][0]=bits[i][1];
        bits[i][1]=tmp;
        tmp = bits[i][2];
        bits[i][2]=bits[i][3];
        bits[i][3]=tmp;
    }
    unsigned char* result = calloc((lenght+1), sizeof(char));
    //XOR
    for (int i = 0; i < lenght; i++) {
        for (int j = 4; j < 8; j++) {
            bits[i][j] ^= bits[i][j-4];
        }
        int output = 0;
        for (int j = 7; j >= 0; j--) {
           output+=bits[i][7-j]*pow(2,j);
        }
        result[i]=output;
        result[i+1]='\0';
    }
    
    for (int i =0; i <lenght; i++) {
        printf("%x ",result[i]);
    }
    printf("\n");

    return result;
}

char* decrypt(unsigned char* password_to_decrypt) {
    if(password_to_decrypt == NULL) {
        return NULL;
    }
    int lenght = strlen((char*)password_to_decrypt);
    char * result = malloc((lenght+1)*sizeof(char));
    for (int i = 0; i < lenght; i++)
    {
        int bits[8];
        for (int j = 0; j < 8; j++) {
            bits[7-j] = password_to_decrypt[i] >> j & 1;
        }
        for (int j = 4; j < 8; j++) {
            bits[j] ^= bits[j-4];
        }
        int tmp = bits[0];
        bits[0]=bits[1];
        bits[1]=tmp;
        tmp = bits[2];
        bits[2]=bits[3];
        bits[3]=tmp;
        int output = 0;
        for (int j = 7; j >= 0; j--){
            output+=bits[7-j]*pow(2,j);
        }
        result[i]=output;
        result[i+1]='\0';
    }

    printf("%s\n",result);

    return result;
}