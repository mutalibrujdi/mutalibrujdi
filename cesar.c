#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXN 1000

char *cezar_cipher(char *str, int key)
{
    int lenght = (strlen(str));
    char *cipher = (char *)malloc(sizeof(char) * (lenght + 1));
    for (int i = 0; i <= lenght; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            cipher[i] = ((str[i] - 'a') + key) % 26 + 'a';
        }
        else
        {
            cipher[i] = str[i];
        }
    }
    cipher[lenght] = '\0';
    return cipher;
}

int main()
{
    char str[MAXN];
    scanf("%s", str);

    int key;
    scanf("%d", &key);

    char *cipher = cezar_cipher(str, key);
    printf("%s", cipher);
    return EXIT_SUCCESS;
}
