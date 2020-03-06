/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : Tam Yi Ki <your name>
 * Student ID    : 1155126127 <your student ID>
 * Class/Section : ENGG1110 D <your class/section>
 * Date          : 02/11/2018<date>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Macros */
#define MAX_GRID 10
#define MAX_WORDLIST 8
#define MAX_WORD 11
#define MAX_FILENAME 260


/* NO global variables are allowed */


/* Read the letter grid from console into the 2D array parameter letterGird
 Return the size of the letter grid */
int readLetterGridFromConsole(char letterGrid[MAX_GRID][MAX_GRID]) {
    int row, col;
    int gridSize;
    
    printf("Enter the size of the letter grid:\n");
    scanf("%d", &gridSize);
    printf("Enter the letter grid:\n");
    for(row = 0; row < gridSize; row++) {
        for(col = 0; col < gridSize; col++) {
            /* In scanf(), use " %c" instead of "%c" to read the first non-whitespace character,
             so that the newline character at the end of the previous line can be ignored */
            scanf(" %c", &letterGrid[row][col]);
        }
    }
    return gridSize;
}


/* Read the word list from console into the 2D array parameter wordList
 Return the number of words */
int readWordListFromConsole(char wordList[MAX_WORDLIST][MAX_WORD]) {
    int i;
    int listSize;
    
    printf("Enter the size of the word list:\n");
    scanf("%d", &listSize);
    printf("Enter the word list:\n");
    for(i = 0; i < listSize; i++) {
        /* no & before wordList[i] since wordList[i] already represents the memory address */
        scanf("%s", wordList[i]);
    }
    
    return listSize;
}


/* Read the letter grid from file into the 2D array parameter letterGird
 Return
 the size of the letter grid if successful
 -1 if there is any file reading error */
int readLetterGridFromFile(char letterGrid[MAX_GRID][MAX_GRID]) {
    FILE *fptr;
    int num;
    int row, col;
    char fileName[MAX_FILENAME];
    
    
    printf("Enter filename of the letter grid:\n");
    scanf("%s", fileName);
    fptr = fopen(fileName, "r");
    
    if (fptr == NULL) {
        printf("Error in reading the letter grid file. Program terminates.\n");
        return -1;
    }
    
    fscanf(fptr, "%d", &num);
    
    for(row = 0; row < num; row++) {
        for(col = 0; col < num; col++) {
            fscanf(fptr, " %c", &letterGrid[row][col]);
        }
    }
    fclose(fptr);
    return num;
    /* TODO: Complete the function, you can refer to readLetterGridFromConsole() for reference */
}


/* Read the word list from file into the 2D array parameter wordList
 Return
 the number of words if successful
 -1 if there is any file reading error */
int readWordListFromFile(char wordList[MAX_WORDLIST][MAX_WORD]) {
    printf("Enter filename of the word list:\n");
    FILE*fptr;
    int i;
    int listSize;
    char fileName[MAX_FILENAME];
    
    scanf("%s", fileName);
    fptr = fopen(fileName, "r");
    
    if (fptr == NULL) {
        printf("Error in reading the word list file. Program terminates.\n");
        return -1;
    }
    
    fscanf(fptr, "%d", &listSize);
    
    for(i = 0; i < listSize; i++) {
        fscanf(fptr, "%s", wordList[i]);
    }
    
    fclose(fptr);
    return listSize;
    
    /* TODO: Complete the function, you can refer to readWordListFromConsole() for reference */
    
    
}


/* Display the letter grid, assume gridSize <= 10 */
void printLetterGrid(char letterGrid[MAX_GRID][MAX_GRID], int gridSize) {
    int row, col;
    int i;
    
    /* For debugging */
    if(gridSize < 2 || gridSize > MAX_GRID) {
        printf("DEBUG: gridSize is %d but not between 2 and %d\n", gridSize, MAX_GRID);
        printf("Program terminates.\n");
        exit(1);
    }
    
    printf("### %d x %d Letter Grid ###\n", gridSize, gridSize);
    
    printf("  +");
    for(i = 0; i < gridSize; i++) {
        printf(" %d", i);
    }
    printf("\n");
    
    for(i = 0; i < gridSize + 2; i++) {
        printf("+ ");
    }
    printf("\n");
    
    for(row = 0; row < gridSize; row++) {
        printf("%d +", row);
        for(col = 2; col < gridSize + 2; col++) {
            printf(" %c", letterGrid[row][col - 2]);
        }
        printf("\n");
    }
    
    /* TODO: Print the letter grid */
    
    
}


/* Display the word list stored in wordList of size listSize with the matching status for each word */
void printWordList(char wordList[MAX_WORDLIST][MAX_WORD], int listSize, int matchingStatus[MAX_WORDLIST]) {
    int i, check;
    char inputWord[MAX_WORD];
    int N;
    N = (int) strlen(inputWord);
    
    /* For debugging */
    if(listSize < 1 || listSize > MAX_WORDLIST) {
        printf("DEBUG: listSize is %d but not between 1 and %d\n", listSize, MAX_WORDLIST);
        printf("Program terminates.\n");
        exit(1);
    }
    
    
    printf("### Word List of Size %d ###\n", listSize);
    for(i = 0; i < listSize; i++) {
        if (matchingStatus[i] == 0) {
            printf("[ ] %s\n", wordList[i]);
        }
        if (matchingStatus[i] == 1) {
            printf("[X] %s\n", wordList[i]);
        }
    }
    
    
    
    /* TODO: Print the word list with matching status */
    
    
}


/* Check whether the input word is in the word list and whether it is matched before
 Return
 the index of the input word in the word list (i.e., a value between 0 and listSize - 1) if the input word is in the word list and has not been matched before
 listSize if the input word is in the word list but has been matched already
 -1 if the input word is not in the word list */
int checkWordList(char wordList[MAX_WORDLIST][MAX_WORD], int listSize, int matchingStatus[MAX_WORDLIST], char inputWord[MAX_WORD]) {
    int N, i, check=0;
    N = (int) strlen(inputWord);
    
    printf("Enter the word:\n");
    
    scanf("%s", inputWord);
    
    for (i = 0; i < listSize; i++) {
        if (strcmp(inputWord, wordList[i]) == 0) {
            if (matchingStatus[i] == 0) {
                check = 1;
                return i;
            }
            
            else if (matchingStatus[i] == 1) {
                check = 1;
                return listSize;
            }
        }
    }
    
    if (check == 0) {
        return -1;
    }
    
    /* TODO: Complete the function */
    
}


/* Check whether the input word is in the letter grid in the specified row, column, and direction
 Return
 1 if the input word is in the letter grid in the specified row, column, and direction
 0 if the input word cannot be found in the letter grid in the specified row, column, and direction
 -1 if the search of the input word exceeds the boundary of the letter grid
 This function should not print anything, except debugging messages (if any) */
int checkLetterGrid(char letterGrid[MAX_GRID][MAX_GRID], int gridSize, char inputWord[MAX_WORD], int matchRow, int matchCol, int matchDirection) {
    int N, i, count=0;
    N = (int) strlen(inputWord);
    
    if (matchDirection == 1) {
        if (((matchRow + (N - 1)) >= gridSize) || ((matchCol - (N - 1)) >= gridSize)) {
            return -1;
        }
        for (i = 0; i < N; i++) {
            if (letterGrid[matchRow + i][matchCol - i] == inputWord[i]) {
                count++;
            }
        }
        if (count == N) {
            return 1;
        }
        else return 0;
    }
    
    if (matchDirection == 2) {
        if ((matchRow + (N - 1)) >= gridSize) {
            return -1;
        }
        for (i = 0; i < N; i++) {
            if (letterGrid[matchRow + i][matchCol] == inputWord[i]) {
                count++;
            }
        }
        if (count == N) {
            return 1;
        }
        else return 0;
    }
    
    if (matchDirection == 3) {
        if (((matchRow + (N - 1)) >= gridSize) || ((matchCol + (N - 1)) >= gridSize)) {
            return -1;
        }
        for (i = 0; i < N; i++) {
            if (letterGrid[matchRow + i][matchCol + i] == inputWord[i]) {
                count++;
            }
        }
        if (count == N) {
            return 1;
        }
        else return 0;
    }
    
    if (matchDirection == 4) {
        if ((matchCol - (N - 1)) >= gridSize) {
            return -1;
        }
        for (i = 0; i < N; i++) {
            if (letterGrid[matchRow][matchCol - i] == inputWord[i]) {
                count++;
            }
        }
        if (count == N) {
            return 1;
        }
        else return 0;
    }
    
    if (matchDirection == 6) {
        if ((matchCol + (N - 1)) >= gridSize) {
            return -1;
        }
        for (i = 0; i < N; i++) {
            if (letterGrid[matchRow][matchCol + i] == inputWord[i]) {
                count++;
            }
        }
        if (count == N) {
            return 1;
        }
        else return 0;
    }
    
    if (matchDirection == 7) {
        if (((matchCol - (N - 1)) >= gridSize) || ((matchRow - (N - 1)) >= gridSize)) {
            return -1;
        }
        for (i = 0; i < N; i++) {
            if (letterGrid[matchRow - i][matchCol - i] == inputWord[i]) {
                count++;
            }
        }
        if (count == N) {
            return 1;
        }
        else return 0;
    }
    
    if (matchDirection == 8) {
        if ((matchRow - (N - 1)) >= gridSize) {
            return -1;
        }
        for (i = 0; i < N; i++) {
            if (letterGrid[matchRow - i][matchCol] == inputWord[i]) {
                count++;
            }
        }
        if (count == N) {
            return 1;
        }
        else return 0;
    }
    
    if (matchDirection == 9) {
        if (((matchCol + (N - 1)) >= gridSize) || ((matchRow - (N - 1)) >= gridSize)) {
            return -1;
        }
        for (i = 0; i < N; i++) {
            if (letterGrid[matchRow - i][matchCol + i] == inputWord[i]) {
                count++;
            }
        }
        if (count == N) {
            return 1;
        }
        else return 0;
    }
    
    /* TODO: Complete the function */
    
    
}


/* Display the secret table */
void printSecretTable(char letterGrid[MAX_GRID][MAX_GRID], int gridSize, char inputWord[MAX_WORD], int matchRow, int matchCol, int matchDirection, char wordList[MAX_WORDLIST][MAX_WORD], int listSize) {
    int i;
    printf("### Secret Table ###\n");
    
    for (i = 0; i < listSize; i++) {
        for (matchRow = 0; matchRow < gridSize; matchRow++) {
            for (matchCol = 2; matchCol < (gridSize + 2); matchCol++) {
                for (matchDirection = 1; matchDirection <= 9; matchDirection++) {
                    if (matchDirection == 5) {
                        continue;
                    }
                    if (checkLetterGrid(letterGrid, gridSize, wordList[i], matchRow, matchCol-2, matchDirection) == 1) {
                        printf("%s: R%d C%d D%d\n", wordList[i], matchRow, matchCol-2, matchDirection);
                    }
                }
            }
        }
    }
    
    /* TODO: Complete the function */
    
}

/* The main() function */
int main()
{
    char letterGrid[MAX_GRID][MAX_GRID];
    char wordList[MAX_WORDLIST][MAX_WORD];
    int matchingStatus[MAX_WORDLIST];     /* Each element should be either 0 (not matched) or 1 (matched) */
    char a;
    int matchRow;
    int matchCol;
    int matchDirection;
    char inputWord[MAX_WORD];
    int i=0;
    int N;
    N = (int) strlen(inputWord);
    int endGame=1;
    int gridSize;
    int listSize;
    /* TODO: Complete the main() function by invoking the functions declared above */
    
    /* Ask the user whether to read the data from file */
    printf("Read data from file [Y/N]?\n");
    scanf("%c", &a);
    
    /* Read the letter grid and the word list from file or console */
    if (a == 'N') {
        gridSize = readLetterGridFromConsole(letterGrid);
        listSize = readWordListFromConsole(wordList);
    }
    if (a == 'Y') {
        gridSize = readLetterGridFromFile(letterGrid);
        listSize = readWordListFromFile(wordList);
    }
    
    for (i = 0; i < listSize; i++) {
        matchingStatus[i] = 0;
    }
    
    /* Initialize all elements in the matchingStatus array to 0 */
    while (1) {
        endGame = 1;
        for (i = 0; i < listSize; i++) {
            if (matchingStatus[i] == 0){
                endGame = 0;
                break;
            }
        }
        
        if (endGame == 1) {
            printWordList(wordList, listSize, matchingStatus);
            printf("You have finished the puzzle.\nCongratulations!\n");
            break;
        }
        
        printLetterGrid(letterGrid, gridSize);
        printWordList(wordList, listSize, matchingStatus);
        
        int index = checkWordList(wordList, listSize, matchingStatus, inputWord);
        if (strcmp(inputWord, "SECTBL") == 0) {
            printSecretTable(letterGrid, gridSize, inputWord, matchRow, matchCol, matchDirection, wordList, listSize);
            int index = checkWordList(wordList, listSize, matchingStatus, inputWord);
        }
        
        if (index == listSize) {
            printf("The input word has already been matched before.\n");
            printf("\n");
            continue;
        }
        
        if (index == -1) {
            printf("The input word is not in the word list.\n");
            printf("\n");
            continue;
        }
    
        printf("Enter the row number, the column number, and the direction (1-4 or 6-9):\n");
        scanf("%d%d%d", &matchRow, &matchCol, &matchDirection);
        
        if (checkLetterGrid(letterGrid, gridSize, inputWord, matchRow, matchCol, matchDirection) == 1) {
            printf("The word is found!\n");
            printf("\n");
            matchingStatus[index] = 1;
        }
        if (checkLetterGrid(letterGrid, gridSize, inputWord, matchRow, matchCol, matchDirection) == 0) {
            printf("The input word cannot be found in the given location.\n");
            printf("\n");
        }
        if (checkLetterGrid(letterGrid, gridSize, inputWord, matchRow, matchCol, matchDirection) == -1) {
            printf("The search exceeds the boundary of the letter grid.\n");
            printf("\n");
        }
        
        
    }
    
    
    /* FOR TESTING: Uncomment the following two statements to print the letter grid and the word list
     You can move them elsewhere after testing
     Please make sure the five arguments are initialized properly */
    
    /* Read the user input repeatedly until the puzzle finishes */
    
    return 0;
}

