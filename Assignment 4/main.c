#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(char alphabet[], char word1[], char word2[]);

int main()
{
    //get new alphabet
    int i = 0;
    char alphabet [26];

    for (i = 0; i < 26; i++)
        scanf("%c ", &alphabet[i]);

   //get total number of words
    int numWords = 0;

    scanf("%d", &numWords);

    //get words and add to array
    char words [numWords][100];

    for (i = 0; i < numWords; i++)
        scanf("%s", words[i]);

    //swapping function
    int j = 0;
    char* tmp = (char*) malloc(sizeof(char) * 100);

    for (i = 0; i < numWords; i++)
    {
        for (j = i+1; j < numWords; j++)
        {
            //if true, swap
            if(compareStrings(alphabet, words[i], words[j]))
            {
                strcpy(tmp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], tmp);
            }
        }
    }

    for (int i = 0; i < numWords; i++)
    {
        printf("%s\n", words[i]);
    }

    //freeing memory
    free(tmp);
    return 0;
}

//returns "1" (true) if swapping is needed, else "0" (false) if swapping is not needed
int compareStrings(char alphabet[], char word1[], char word2[])
{
    int i, j, length;

    //setting length equal to longest string length
    if (strlen(word1) > strlen(word2))
        length = strlen(word1);
    else
        length = strlen(word2);

    for (i = 0; i < length; i++)
    {
        //compares strings to alphabet
        for (j = 0; j < 26; j++)
        {
           if (word1[i] == word2[i])
                continue;
           else if (word1[i] == alphabet[j] && word2[i] != alphabet[j])
                return 0;
           else if (word1[i] != alphabet[j] && word2[i] == alphabet[j])
                return 1;

        }
    }
    return 0;

}
