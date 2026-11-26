#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char *wordList[] = {
        "hello", "computer", "programming", "school",
        "keyboard", "science", "technology", "learning",
        "future", "internet", "language", "student",
        "creative", "knowledge", "digital", "software",
        "function", "variable", "network", "design",
        "apple", "beautiful", "success", "practice",
        "window", "garden", "freedom", "education"
    };

    char target[500] = "";
    char typed[500];

    int totalWords = 10;
    int totalAvailable = sizeof(wordList) / sizeof(wordList[0]);

    int i, correct = 0;
    int typedWords = 0;
    int targetLength, typedLength;
    int maxLength;

    double seconds, wpm, accuracy;

    time_t start, end;

    srand((unsigned int)time(NULL));

    printf("\n====================================\n");
    printf("       RANDOM TYPING SPEED TEST\n");
    printf("====================================\n");

    printf("\nType these random words:\n\n");

    for(i = 0; i < totalWords; i++)
    {
        int randomIndex = rand() % totalAvailable;

        strcat(target, wordList[randomIndex]);
        strcat(target, " ");
    }

    target[strlen(target) - 1] = '\0';

    printf("%s\n", target);

    printf("\nStart typing:\n");

    start = time(NULL);

    fgets(typed, sizeof(typed), stdin);

    end = time(NULL);

    typed[strcspn(typed, "\n")] = '\0';

    seconds = difftime(end, start);

    targetLength = strlen(target);
    typedLength = strlen(typed);

    for(i = 0; i < typedLength; i++)
    {
        if(typed[i] != ' ' &&
           (i == 0 || typed[i - 1] == ' '))
        {
            typedWords++;
        }
    }

    maxLength = targetLength > typedLength ?
                targetLength : typedLength;

    for(i = 0; i < targetLength && i < typedLength; i++)
    {
        if(target[i] == typed[i])
        {
            correct++;
        }
    }

    if(seconds <= 0)
        seconds = 1;

    wpm = (typedWords * 60.0) / seconds;

    if(maxLength == 0)
        accuracy = 0;
    else
        accuracy = (correct * 100.0) / maxLength;

    printf("\n====================================\n");
    printf("             YOUR RESULTS\n");
    printf("====================================\n");

    printf("\nTime Taken : %.0f seconds", seconds);
    printf("\nWords Typed : %d", typedWords);
    printf("\nTyping Speed : %.2f WPM", wpm);
    printf("\nAccuracy : %.2f%%", accuracy);

    if(accuracy >= 90)
        printf("\nPerformance : EXCELLENT!");
    else if(accuracy >= 70)
        printf("\nPerformance : GOOD!");
    else
        printf("\nPerformance : KEEP PRACTICING!");

    printf("\n====================================\n");

    return 0;
}
