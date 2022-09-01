#include "headers/cypher.h"

const int OFFSET_TABLE[128] = 
{ 1,  16, 9,  4,  8,  4,  7,  18, 1,  13, 13, 3,  8,  6,  4,  16, 1,  10, 7,  16,
  11, 14, 10, 4,  19, 14, 7,  11, 15, 2,  4,  9,  20, 5,  4,  6,  8,  16, 12, 19,
  2,  10, 18, 11, 12, 18, 10, 14, 12, 15, 7,  19, 9,  9,  18, 15, 10, 9,  5,  11,
  14, 3,  16, 14, 10, 10, 18, 2,  10, 10, 7,  11, 13, 18, 15, 6,  4,  17, 8,  18,
  8,  12, 9,  4,  16, 11, 17, 7,  10, 10, 16, 16, 12, 4,  4,  1,  16, 15, 12, 11,
  19, 20, 17, 16, 10, 1,  14, 3,  4,  18, 1,  9,  10, 14, 18, 13, 4,  3,  16, 14,
  14, 4,  8,  11, 16, 15, 11, 2};


unsigned char* encrypt(char* password_to_encrypt) {
    if(password_to_encrypt == NULL) {
        return NULL;
    }

    string_reverse(password_to_encrypt);
    int lenght = strlen(password_to_encrypt);

    int offset_table_index = 0;
    for (size_t i = 0; i < lenght; i++) {
        offset_table_index += KEY[offset_table_index % KEY_LENGHT];
        password_to_encrypt[i] += KEY[i % KEY_LENGHT] % OFFSET_TABLE[offset_table_index % 127];
    }

    //get the bits of the password
    int bits[lenght][8];
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < 8; j++) {
            bits[i][7-j] = password_to_encrypt[i] >> j & 1;
        }
    }
    //swap bits int the ms nibble
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

    int offset_table_index = 0;
    for (size_t i = 0; i < lenght; i++) {
        offset_table_index += KEY[offset_table_index % KEY_LENGHT];
        result[i] -= KEY[i % KEY_LENGHT] % OFFSET_TABLE[offset_table_index % 127];
    }

    string_reverse(result);
    return result;
}