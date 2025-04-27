#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_score(string word);

int main(void)
{
    // prompts the user for two words
    string word1 = get_string("Player1: ");
    string word2 = get_string("Player2: ");

    // calculates the score
    int score1 = get_score(word1);
    int score2 = get_score(word2);

    // prints the result
    if (score1 > score2)
        printf("Player1 wins!\n");
    else if (score2 > score1)
        printf("Player2 wins!\n");
    else
        printf("Tie!\n");
}

int get_score(string word)
{
    // Scrabble-like points: index 0 = A/a, 1 = B/b, ..., 25 = Z/z
    int points[] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
        5, 1, 3, 1, 1, 3,10, 1, 1, 1,
        1, 4, 4, 8, 4,10
    };

    int score = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            char lower = tolower(word[i]);
            score += points[lower - 'a'];
        }
    }
    return score;
}
