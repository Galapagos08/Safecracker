//
//  main.c
//  Safecracker
//
//  Created by Dan Esrey on 2016/10/08.
//  Copyright © 2016 Dan Esrey. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


char userName[100] = {'\0'};


int main(int argc, const char * argv[]){
    
    printf("Safecracker!\n\n");
    
    printf("What is your name?\n\n");
    fpurge(stdin);
    char name[100] = "\0";
    int numberOfItemsScanned = 0;
    numberOfItemsScanned = scanf("%[^\n]s", name);
    
    printf("\nHello, %s! Let's play Safecracker!\n\n", name);
    
    int safeCombo[4] = {
        arc4random_uniform(4),
        arc4random_uniform(4),
        arc4random_uniform(4),
        arc4random_uniform(4)
    };
    
    printf("%s, you need to crack the safe. There are four digits in the combination, and each digit has a possible value from zero to three. (Hint: It's possible the combination may contain a number more than once.)\n\n", name);
    
    printf("%s, please enter the first digit of your guess.\n\n", name);
    int guess[4];
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
    
    printf("%s, the safe combination is %d-%d-%d-%d.\n\n", name, safeCombo[0], safeCombo[1], safeCombo[2], safeCombo[3]); {
        if (guess[0] == safeCombo[0] && guess[1] == safeCombo[1] && guess[2] == safeCombo[2] && guess[3] == safeCombo[3] ) {
            printf("%s, you guessed the code correctly! Great job!\n\n", name);
        } else {
            if (guess[0] == safeCombo[0]){
                printf("You guessed the first number correctly!\n\n");
            }
            if (guess[1] == safeCombo[1]){
                printf("You guessed the second number correctly!\n\n");
            }
            if (guess[2] == safeCombo[2]){
                printf("You guessed the third number correctly!\n\n");
            }
            if (guess[3] == safeCombo[3]){
                printf("You guessed the fourth number correctly!\n\n");
            }
        }
    }
    return 0;
}


