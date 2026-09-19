#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;


/* INSERT LINE */
void insertLine()
{
    int lineNumber;

    printf("Enter line number: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount + 1)
    {
        printf("Invalid line number!\n");
        return;
    }

    if (lineCount >= MAX_LINES)
    {
        printf("Document is full!\n");
        return;
    }

    for (int i = lineCount; i >= lineNumber; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    printf("Enter text: ");
    fgets(lines[lineNumber - 1], MAX_LENGTH, stdin);

    lines[lineNumber - 1][strcspn(lines[lineNumber - 1], "\n")] = '\0';

    lineCount++;

    printf("Line inserted successfully!\n");
}


/* DELETE LINE */
void deleteLine()
{
    int lineNumber;

    printf("Enter line number to delete: ");
    scanf("%d", &lineNumber);

    if (lineNumber < 1 || lineNumber > lineCount)
    {
        printf("Invalid line number!\n");
        return;
    }

    for (int i = lineNumber - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully!\n");
}


/* DISPLAY DOCUMENT */
void displayDocument()
{
    if (lineCount == 0)
    {
        printf("Document is empty!\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d. %s\n", i + 1, lines[i]);
    }
}


/* SEARCH - BONUS */
void searchWord()
{
    char word[MAX_LENGTH];
    int found = 0;

    getchar();

    printf("Enter word or phrase to search: ");
    fgets(word, MAX_LENGTH, stdin);

    word[strcspn(word, "\n")] = '\0';

    for (int i = 0; i < lineCount; i++)
    {
        if (strstr(lines[i], word) != NULL)
        {
            printf("Found in line %d: %s\n", i + 1, lines[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Word or phrase not found!\n");
    }
}


/* FIND AND REPLACE - BONUS */
void findAndReplace()
{
    int lineNumber;
    char oldWord[MAX_LENGTH];
    char newWord[MAX_LENGTH];
    char temp[MAX_LENGTH];

    printf("Enter line number: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount)
    {
        printf("Invalid line number!\n");
        return;
    }

    printf("Enter word to replace: ");
    fgets(oldWord, MAX_LENGTH, stdin);
    oldWord[strcspn(oldWord, "\n")] = '\0';

    printf("Enter new word: ");
    fgets(newWord, MAX_LENGTH, stdin);
    newWord[strcspn(newWord, "\n")] = '\0';

    char *position = strstr(lines[lineNumber - 1], oldWord);

    if (position == NULL)
    {
        printf("Word not found in this line!\n");
        return;
    }

    int before = position - lines[lineNumber - 1];

    strncpy(temp, lines[lineNumber - 1], before);
    temp[before] = '\0';

    strcat(temp, newWord);
    strcat(temp, position + strlen(oldWord));

    if (strlen(temp) >= MAX_LENGTH)
    {
        printf("Replacement is too long!\n");
        return;
    }

    strcpy(lines[lineNumber - 1], temp);

    printf("Replacement successful!\n");
}


/* LINE COUNT AND WORD COUNT - BONUS */
void statistics()
{
    int wordCount = 0;

    for (int i = 0; i < lineCount; i++)
    {
        int inWord = 0;

        for (int j = 0; lines[i][j] != '\0'; j++)
        {
            if (lines[i][j] != ' ' &&
                lines[i][j] != '\t' &&
                lines[i][j] != '\n')
            {
                if (!inWord)
                {
                    wordCount++;
                    inWord = 1;
                }
            }
            else
            {
                inWord = 0;
            }
        }
    }

    printf("\n----- DOCUMENT STATISTICS -----\n");
    printf("Number of lines : %d\n", lineCount);
    printf("Number of words : %d\n", wordCount);
}


/* SAVE FILE */
void saveFile()
{
    char filename[100];
    FILE *file;

    getchar();

    printf("Enter filename: ");
    fgets(filename, 100, stdin);

    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Unable to save file!\n");
        return;
    }

    for (int i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("File saved successfully!\n");
}


/* LOAD FILE */
void loadFile()
{
    char filename[100];
    FILE *file;

    getchar();

    printf("Enter filename: ");
    fgets(filename, 100, stdin);

    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    lineCount = 0;

    while (lineCount < MAX_LINES &&
           fgets(lines[lineCount], MAX_LENGTH, file) != NULL)
    {
        lines[lineCount][strcspn(lines[lineCount], "\n")] = '\0';
        lineCount++;
    }

    fclose(file);

    printf("File loaded successfully!\n");
}


/* MAIN */
int main()
{
    int choice;

    while (1)
    {
        printf("\n========== LINE EDITOR ==========\n");

        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Display Document\n");
        printf("4. Search\n");
        printf("5. Find and Replace\n");
        printf("6. Line/Word Count\n");
        printf("7. Save File\n");
        printf("8. Load File\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertLine();
                break;

            case 2:
                deleteLine();
                break;

            case 3:
                displayDocument();
                break;

            case 4:
                searchWord();
                break;

            case 5:
                findAndReplace();
                break;

            case 6:
                statistics();
                break;

            case 7:
                saveFile();
                break;

            case 8:
                loadFile();
                break;

            case 9:
                printf("Exiting editor...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}