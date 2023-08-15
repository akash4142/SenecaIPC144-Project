#pragma once
/*
*****************************************************************************
                        Assignment 1 - Milestone 1
Full Name  :akash yadav
Student ID#:172566218
Email      :ayadav35@myseneca.ca
Section    :NII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/#include <stdio.h>

void clearInputBuffer(void);
void suspend(void);

int inputInt(void);
int inputIntPositive(void);
int inputIntRange(int lower_limit, int  Upper_limit);
char inputCharOption(const char valid_char[]);
void inputCString(char* Cstring, int min_char, int max_char);
void displayFormattedPhone(const char* arr);