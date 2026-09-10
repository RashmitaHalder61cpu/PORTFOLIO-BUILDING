#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

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

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== LINE EDITOR =====\n");
        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Display Document\n");
        printf("4. Exit\n");

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
                printf("Exiting editor...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}