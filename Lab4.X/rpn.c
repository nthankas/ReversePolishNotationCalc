#include "stack.h"
#include "rpn.h"
// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>

int RPN_Evaluate(char * rpn_string, double * result) {
    struct Stack stack2 = {};
    StackInit(&stack2);
    char * token = strtok(rpn_string, " ");
    while (token != NULL) {
        if ((atof(token) != 0) || (*token == '0')) {
            if (StackIsFull(&stack2)) {
                return RPN_ERROR_STACK_OVERFLOW;
            }
            StackPush(&stack2, atof(token));
        }
        else {
            double x;
            double y;
            if ((*token != '+') && (*token != '-') && (*token != '/') && (*token != '*')) {
                return RPN_ERROR_INVALID_TOKEN;
            }
            if (StackGetSize(&stack2) < 2) {
                return RPN_ERROR_STACK_UNDERFLOW;
            }
            StackPop(&stack2, &y);
            StackPop(&stack2, &x);
            if (*token == '+') {
                double z = x + y;
                if (StackIsFull(&stack2)) {
                    return RPN_ERROR_STACK_OVERFLOW;
                }
                StackPush(&stack2, z);
            }
            else if (*token == '-') {
                double z = x - y;
                if (StackIsFull(&stack2)) {
                    return RPN_ERROR_STACK_OVERFLOW;
                }
                StackPush(&stack2, z);
            }
            else if (*token == '/') {
                if (y == 0) {
                    return RPN_ERROR_DIVIDE_BY_ZERO;
                }
                else {
                    double z = x / y;
                    if (StackIsFull(&stack2)) {
                        return RPN_ERROR_STACK_OVERFLOW;
                    }
                    StackPush(&stack2, z);
                }
            }
            else if (*token == '*') {
                double z = x * y;
                if (StackIsFull(&stack2)) {
                    return RPN_ERROR_STACK_OVERFLOW;
                }
                StackPush(&stack2, z);
            }
            
        }
        token = strtok(NULL, " ");
    }
    if (StackGetSize(&stack2) > 1) {
        return RPN_ERROR_TOO_MANY_ITEMS_REMAIN;
    }
    else if (StackGetSize(&stack2) < 1) {
        return RPN_ERROR_TOO_FEW_ITEMS_REMAIN;
    }
    else {
        *result = stack2.stackItems[stack2.currentItemIndex];
        return RPN_NO_ERROR;
    }
}

int ProcessBackspaces(char *rpn_sentence) {
//    char newString = '';
//    char * token2 = strtok(rpn_sentence, '/b';
    return 1;
    
}