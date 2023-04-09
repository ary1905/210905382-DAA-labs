#include <stdio.h>
#include <string.h>

int bruteForce(char base[], char match_text[]) {
    int n = strlen(base);
    int m = strlen(match_text);
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (base[i + j] != match_text[j]) {
                break;
            }
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}
int main() {
    char sent[100];
    char sub[100];
    printf("Enter the base text: ");
    scanf("%s", sent);
    printf("Enter the text you want to match: ");
    scanf("%s", sub);
    int position = bruteForce(sent, sub);
    if (position == -1) {
        printf("Pattern not found\n");
    } else {
        printf("Pattern found at index %d\n", position);
    }
    return 0;
}