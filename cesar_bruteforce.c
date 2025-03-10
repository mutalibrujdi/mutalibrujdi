#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXN 1000
#define ALPHA_LENGTH 26

char *cesar_decipher(char *cipher, int key)
{
    int length = strlen(cipher);
    char *plaintext = (char *)malloc(sizeof(char) * (length + 1));

    for (int i = 0; i < length; i++)
    {
        if (cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            plaintext[i] = ((cipher[i] - 'a' - key + 26) % 26) + 'a';
        }
        else if (cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            plaintext[i] = ((cipher[i] - 'A' - key + 26) % 26) + 'A';
        }
        else if (cipher[i] >= '0' && cipher[i] <= '9')
        {
            plaintext[i] = ((cipher[i] - '0' - key + 10) % 10) + '0';
        }
        else
        {
            plaintext[i] = cipher[i];
        }
    }

    plaintext[length] = '\0';
    return plaintext;
}

int read_cipher(char *filename, char *cipher)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("The file does not exist");
        return EXIT_FAILURE;
    }
    if (fgets(cipher, MAXN, fp) == NULL)
    {
        printf("Error reading from file.");
        return EXIT_SUCCESS;
    }

    fclose(fp);
    return EXIT_SUCCESS;
}

void write_text(char *filename, char *text)
{
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "%s", text);
    fclose(fp);
}

int main()
{
    char cipher[MAXN];
    fgets(cipher, MAXN, stdin);
    for (int key = 0; key < ALPHA_LENGTH; key++)
    {
        char *plaintext = cesar_decipher(cipher, key);
        printf("key %d -> %s", key, plaintext);
        free(plaintext);
    }

    return EXIT_SUCCESS;
}
