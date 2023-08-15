/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  :AKash yadav
Student ID#:172566218
Email      :ayadav35@myseneca.ca
Section    :NII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"core.h"
#include"clinic.h"
//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void) {
    char space = ' ';
    int number;

    do {
        scanf("%d%c", &number, &space);

        if (space != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (space != '\n');

    return number;
}


int inputIntPositive(void) {
    char space = ' ';
    int num;

    do {
        scanf("%d%c", &num, &space);

        if (space != '\n') {
            clearInputBuffer();
            printf("Error! Input a number: ");
        }

        if (num <= 0) {
            printf("ERROR! Value must be > 0: ");
        }
    } while (num <= 0);

    return num;
}



int inputIntRange(int lower_limit, int  Upper_limit) {
    int num = lower_limit - 1;
    do {
        num = inputInt();
    } while ((num<lower_limit || num>Upper_limit) && printf("ERROR! Value must be between %d and %d inclusive: ", lower_limit, Upper_limit));

    return num;
}

char inputCharOption(const char* cString)
{
    char num = '\0';
    char newline = '\0';
    int i = 0;
    int j = 0;
    for (j = 1; cString[j]; j++)
        ;
    int integer = 1;
    do
    {
        scanf("%c%c", &num, &newline);

        if (newline == '\n')
        {
            for (i = 0; i < j && integer; i++)
                if (cString[i] == num)
                    integer = 0;
        }

    } while (integer && printf("ERROR: Character must be one of [%s]: ", cString));

    return num;
}
void inputCString(char* Cstring, int min, int max)
{
    char length[100] = { '\0' };
    int flag = 0;
    int i = 0;
    int j = 0;
    do
    {
        scanf("%99[^\n]%*c", length);
        for (i = 1; length[i]; i++)
            ;
        if (min == max)
        {
            if (i == min)
            {
                for (j = 0; length[j]; Cstring[j] = length[j], j++)
                    ;
                Cstring[j] = '\0';
                flag = 1;
            }
        }
        else
        {
            if (i >= min && i <= max)
            {
                for (j = 0; length[j]; Cstring[j] = length[j], j++)
                    ;
                Cstring[j] = '\0';
                flag = 1;
            }
        }
        if (!flag)
        {
            if (min == max)
            {
                printf("ERROR: String length must be exactly %d chars: ", min);
            }
            else if (min == 0 || i > max)
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }
        }

    } while (!flag);
}

void displayFormattedPhone(const char arr[])
{
    int i = 0, size = 0, check = 0;
    if (arr == NULL)
    {
        printf("(___)___-____");
        return;
    }
    while (arr[i] != '\0')
    {
        size++;
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            check = 1;
        }
        else
        {
            printf("(___)___-____");
            return;
        }
        i++;
    }
    if (size != 10)
    {
        printf("(___)___-____");
    }
    else if (size == 10 && check == 1)
    {
        i = 0;
        while (arr[i] != '\0')
        {
            if (i == 0)
            {
                printf("(%c", arr[i]);
            }
            else if (i == 3)
            {
                printf(")%c", arr[i]);
            }
            else if (i == 6)
            {
                printf("-%c", arr[i]);
            }
            else
                printf("%c", arr[i]);
            i++;
        }
    }
}


