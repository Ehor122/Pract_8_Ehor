#include <stdio.h>
#include <string.h>

// Function for calculating the factorial
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    char word[15]; // The maximum word length is 14 + 1 for a null character
    printf("Enter the word: ");
    scanf("%s", word);

    int length = strlen(word);

    // Array for counting the frequency of each letter
    int frequency[26] = {0};
    for (int i = 0; i < length; i++) {
        frequency[word[i] - 'A']++;
    }

    // Calculating the factorial of the word length
    unsigned long long result = factorial(length);

    // Division by the factorial of the frequencies of repeated letters
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 1) {
            result /= factorial(frequency[i]);
        }
    }

    printf("Number of possible anagrams: %llu\n", result);

    return 0;
}
