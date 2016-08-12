//
//  main.c
//  Safecracker
//
//  Created by Dan Esrey on 2016/10/08.
//  Copyright © 2016 Dan Esrey. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getUserName(char name[], char *prompt);
void functionThatUsesName(char[]);
void evaluateGuess(char[]);
int guess[4];
int safeCombo[4];
int error = 5;

int main(int argc, const char * argv[]){
    
    printf("Safecracker!\n\n");
    
    /*printf("What is your name?\n\n");
    fpurge(stdin);*/
    
    char name[100] = "\0";
    int numberOfItemsScanned = 0;
    while (numberOfItemsScanned !=1) {
        numberOfItemsScanned = getUserName(name, "what is your name?\n\n");
    }
    
    printf("\nHello, %s! Let's play Safecracker!\n\n", name);
    
    printf("%s, you need to crack the safe. There are four digits in the combination, and each digit has a possible value from zero to three. (Hint: It's possible the combination may contain a number more than once.)\n\n", name);
    
    functionThatUsesName(name);
    evaluateGuess(name);
    
    return 0;
}
int getUserName(char name[], char *prompt) {
    int numberOfItemsScanned = 0;
    while (numberOfItemsScanned != 1) {
        fpurge(stdin);
        printf("%s", prompt);
        numberOfItemsScanned = scanf("%[^\n]s", name);
    }
    return numberOfItemsScanned;
}
void functionThatUsesName(char name[]){
    printf("%s, please enter the first digit of your guess.\n\n", name);
    fpurge(stdin);
    int guess[4] = {-1, -1, -1, -1};
    int error = 5;
    while (guess[0] < 0 || guess[0] > 3) {
        fpurge(stdin);
        error = scanf("%d", &guess[0]);
        if (error != 1 || guess[0] < 0 || guess[0] > 3) {
            printf("%s, you need to choose a number from 0 to 3.\n\n", name);
        }
    }
    printf("%s, please enter the second digit of your guess.\n\n", name);
    while (guess[1] < 0 || guess[1] > 3) {
        fpurge(stdin);
        error = scanf("%d", &guess[1]);
        if (error != 1 || guess[1] < 0 || guess[1] > 3) {
            printf("%s, you need to choose a number from 0 to 3.\n\n", name);
        }
    }
    printf("%s, please enter the third digit of your guess.\n\n", name);
    while (guess[2] < 0 || guess[2] > 3) {
        fpurge(stdin);
        error = scanf("%d", &guess[2]);
        if (error != 1 || guess[2] < 0 || guess[2] > 3) {
            printf("%s, you need to choose a number from 0 to 3.\n\n", name);
        }
    }
    printf("%s, please enter the fourth and final digit of your guess.\n\n", name);
    while (guess[3] < 0 || guess[3] > 3) {
        fpurge(stdin);
        error = scanf("%d", &guess[3]);
        if (error != 1 || guess[3] < 0 || guess[3] > 3) {
            printf("%s, you need to choose a number from 0 to 3.\n\n", name);
        }
    }
    printf("%s, your guess is %d-%d-%d-%d.\n\n", name, guess[0], guess[1], guess[2], guess[3]);
}
void evaluateGuess(char name[]){
    int numberCorrect = 0;
    int safeCombo[4] = {
        arc4random_uniform(4),
        arc4random_uniform(4),
        arc4random_uniform(4),
        arc4random_uniform(4)
    };
    if (guess[0] == safeCombo[0] && guess[1] == safeCombo[1] && guess[2] == safeCombo[2] && guess[3] == safeCombo[3] ) {
        printf("%s, the safe combination is %d-%d-%d-%d.\n\n", name, safeCombo[0], safeCombo[1], safeCombo[2], safeCombo[3]);
        printf("%s, you guessed the code correctly! Great job!\n\n", name);
    } else {
        if (guess[0] == safeCombo[0]){
            printf("%s, you guessed the first number correctly!\n\n", name);
            numberCorrect = numberCorrect + 1;
        }
        if (guess[1] == safeCombo[1]){
            printf("%s, you guessed the second number correctly!\n\n", name);
            numberCorrect = numberCorrect + 1;
        }
        if (guess[2] == safeCombo[2]){
            printf("%s, you guessed the third number correctly!\n\n", name);
            numberCorrect = numberCorrect + 1;
        }
        if (guess[3] == safeCombo[3]){
            printf("%s, you guessed the fourth number correctly!\n\n", name);
            numberCorrect = numberCorrect + 1;
        }
        if (numberCorrect > 0) {
            printf("Congratulations, %s, you guessed %d correct!\n\nBased on what you know now, would you like to try again? (1=Y/2=N)\n\n", name, numberCorrect);
        } else {
            printf("Wow, %s! You did not guess even one number correctly! What a bad guess you made!\n\nWould you like to try again? (1=Y/2=N)\n\n", name);
        }
        int keepPlaying = 9;
        fpurge(stdin);
        while (keepPlaying < 1 || keepPlaying >= 3) {
            error = scanf("%d", &keepPlaying);
            if (error != 1 || keepPlaying < 1 || keepPlaying >= 3 ) {
                printf("Please enter 1 or 2: \n\n");
            }
        }
        if (keepPlaying == 1) {
            functionThatUsesName(name);
        }
    }
}

