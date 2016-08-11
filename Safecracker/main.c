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
    
    printf("%s, please enter your guess.\n\n", name);
    int guess[4];
    int numberOfGuessScanned = 0;
    while (numberOfGuessScanned != 4) {
        fpurge(stdin);
        numberOfGuessScanned = scanf("%d", guess);
    }
    printf("%s, your guess is %d-%d-%d-%d.\n\n", name, guess[0], guess[1], guess[2], guess[3]);
    
    printf("%s, the safe combination is %d-%d-%d-%d.\n\n", name, safeCombo[0], safeCombo[1], safeCombo[2], safeCombo[3]);
    
    // if (guess[0] == safeCombo[0]){
    // printf("You guessed the first number correctly!\n\n");
    
    
    return 0;
}


