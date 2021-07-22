#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD_SIZE 100
int main()
{
    int loop,i , number, j, key, isVowel = 0;
    char word[WORD_SIZE + 1];
    char finalWord;
    scanf("%d", &loop);
    for (i = 0; i < loop; i++)
    {
        scanf("%s", word);
        isVowel = 0;
        key = 13;
        for (j = 0; j < strlen(word); j++)
        {

            if(isVowel == 1)
                key = 14;
            else key = 13;
            if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i'|| word[j] == 'o'|| word[j] == 'u')
            {
                isVowel = 1;
            }
            else isVowel = 0;
            number = word[j] - 'a';
            finalWord = ((key + number) %26) + 'a';
            printf("%c", finalWord);

        }
        printf("\n");

    }

    return 0;
}


