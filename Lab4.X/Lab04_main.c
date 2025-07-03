// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CMPE13 Support Library
#include "BOARD.h"



// User libraries
#include "rpn.h"

// **** Set macros and preprocessor directives ****
// The lab calls for 60 characters of user input
#define MAX_INPUT_LENGTH 60

int main() {
    BOARD_Init();

    //What follows is starter code.  You will need to modify it!

    char rpn_sentence[MAX_INPUT_LENGTH + 2];
    double result;
    int error;

    printf("Welcome to CRUZID'S RPN calculator.  Compiled on %s %s", __DATE__, __TIME__);
    while (1) {

        printf("Enter floats and + - / * in RPN format:\n");

        fgets(rpn_sentence, sizeof (rpn_sentence), stdin);
        

        error = RPN_Evaluate(rpn_sentence, &result);
        if (strlen(rpn_sentence) > MAX_INPUT_LENGTH) {
            printf("Error: TOO MANY CHARACTERS\n");
            while ( getchar() != '\n' );
        }
        if (error) {
            if (error == 1) {
                printf("Error: STACK OVERFLOW ERROR\n");
                while ( getchar() != '\n' );
            }
            else if (error == 2 || error == 5) {
                printf("Error: STACK UNDERFLOW ERROR or TOO FEW ITEMS ERROR\n");
            }
            else if (error == 3) {
                printf("Error: INVALID TOKEN ERROR\n");
            }
            else if (error == 4) {
                printf("Error: DIVIDE BY ZERO ERROR\n");
            }
            else if (error == 6) {
                printf("Error: TOO MANY ITEMS ERROR\n");
            }
        }
        else if (error == 0 && ) {
            printf("result = %f\n", result);
        }

    }

    while (1);
}
