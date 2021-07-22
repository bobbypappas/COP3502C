#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD_SIZE 13
#define BADWORD_SIZE 21

//function definitions
int factorial(int n);
int dupeCount(char word[WORD_SIZE]);
void changePosition(char *index1, char *index2);
int anagram(char word[WORD_SIZE], char badWord[BADWORD_SIZE][WORD_SIZE], int startIndex, int endIndex, int badCount);


//global variable to track # of bad words
int count = 0;

int main()
{
    char word[WORD_SIZE];
    char badWord[BADWORD_SIZE][WORD_SIZE];
    int i, permutations, finalCount, badCount;

    scanf("%s", word);
    scanf("%d", &badCount);

    for (i = 0; i < badCount; i++)
        scanf("%s", &badWord[i][0]);

    //used to find number of bad words
    anagram(word, badWord, 0, strlen(word)-1, badCount);

    //calculates total permutations
    permutations = factorial(strlen(word));

    //derives the final number of total unique permutations - bad words
    finalCount = (permutations / dupeCount(word)) - count;

    printf("%d", finalCount);

    return 0;
}

//calculates duplicate # of anagrams
int dupeCount(char word[WORD_SIZE])
{
    int i, j;
    int b = 1;
    int freq [26] = {0};

    //storing duplicate letters in array
    for (i = 0; i < strlen(word); i++)
        freq[(word[i] - 'a')]++;

    //calculates excess permutations
    for (j = 0; j < 26; j++)
    {
        if (freq[j] > 1)
        {
            b *= factorial (freq[j]);
        }
    }
    return b;
}

//changes position of two indexes
void changePosition(char *index1, char *index2)
{

    char tempVar;

    tempVar = *index1;

    *index1 = *index2;

    *index2 = tempVar;
}

//recursive solution to find # of bad words in relation to the string
int anagram(char word[WORD_SIZE], char badWord[BADWORD_SIZE][WORD_SIZE], int startIndex, int endIndex, int badCount)
{
    int i, toggle = 0;
    char * result;

    //base case to find number of bad words
    if (startIndex == endIndex)
    {
        for (i = 0; i < badCount; i++)
        {
            result = strstr(word, &badWord[i][0]);

            if (result)
            {
                toggle = 1;
            }
        }

        if (toggle == 1)
            count++;
    }

    //loop used to visit all permutations of string
    for (i = startIndex; i < strlen(word); i++)
    {
        changePosition(word+startIndex, word+i);
        anagram(word, badWord, startIndex+1, endIndex, badCount);
        changePosition(word+startIndex, word+i);
    }
    return count;

}

//calculates factorial of given int
int factorial(int n)
{
    int result = 1;

    for (int i = 1; i <= n; i++)
        result *= i;

   return result;
}
