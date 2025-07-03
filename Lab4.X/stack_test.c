// **** Include libraries here ****
// Standard libraries
#include <stdio.h>

//CMPE13 Support Library
#include "BOARD.h"


// User libraries
#include "stack.h"

int main()
{
    BOARD_Init();

    printf("\n###### Beginning CRUZID's stack test harness: ####\n\n");

    //What follows is starter code.  You will need to modify it!
    int passed = 0;
    
    struct Stack stack = {};
    
    printf("Does StackPush() properly return an error?\n");
    int a = StackPush(&stack, 10.1);
    if (a == STANDARD_ERROR) {
        printf("passed\n");
        passed += 1;
    }
    else {
        printf("failed\n");
    }
    
    printf("Does StackInit() set the currentItemIndex appropriately?\n");
    StackInit(&stack);
    if (stack.currentItemIndex == -1) {
        printf("passed\n");
        passed += 1;
    } else {
        printf("failed\n");
    }
    printf("Does StackPush() add the double specified appropriately?\n");
    StackPush(&stack, 10.1);
    if (stack.currentItemIndex == 0 && stack.stackItems[stack.currentItemIndex] == 10.1) {
        printf("passed\n");
        passed += 1;
    }
    else {
        printf("failed\n");
    }
    
    printf("Does StackIsEmpty() properly evaluate the Stack and whether it's empty?\n");
    if(!(StackIsEmpty(&stack))) {
        printf("passed\n");
        passed += 1;
    }
    else {
        printf("failed\n");
    } 
    
    printf("Does StackIsFull() properly evaluate the Stack and whether it's full or not?\n");
    if(!(StackIsFull(&stack))) {
        printf("passed\n");
        passed += 1;
    }
    else {
        printf("failed\n");
    } 
    
    printf("Does StackGetSize() properly evaluate the Stack size?\n");
    if(StackGetSize(&stack) == 1) {
        printf("passed\n");
        passed += 1;
    }
    else {
        printf("failed\n");
    } 
    
    printf("Does StackPop() remove the top element appropriately?\n");
    double y = 0;
    StackPop(&stack, &y);
    if (stack.currentItemIndex == -1 && y == 10.1) {
        printf("passed\n");
        passed += 1;
    }
    else {
        printf("failed\n");
    }
    
    printf("Does StackIsEmpty() properly evaluate the Stack and whether it's empty?\n");
    if(StackIsEmpty(&stack)) {
        printf("passed\n");
        passed += 1;
    }
    else {
        printf("failed\n");
    }
    
    printf("Does StackPop() correctly return an error?\n");
    double z = 0;
    int b = StackPop(&stack, &z);
    if (b == STANDARD_ERROR) {
        printf("passed\n");
        passed += 1;
    }
    else {
        printf("failed\n");
    }
    
    printf("Does StackPush() add the double specified appropriately?\n");
    StackPush(&stack, 234243.1);
    if (stack.currentItemIndex == 0 && stack.stackItems[stack.currentItemIndex] == 234243.1) {
        printf("passed\n");
        passed += 1;
    }
    else {
        printf("failed\n");
    }
    
    printf("Does StackPush() add the double specified appropriately?\n");
    StackPush(&stack, -234243.1);
    if (stack.currentItemIndex == 1 && stack.stackItems[stack.currentItemIndex] == -234243.1) {
        printf("passed\n");
        passed += 1;
    }
    else {
        printf("failed\n");
    }
    
    printf("Does StackIsFull() properly evaluate the Stack and whether it's full or not?\n");
    if(!(StackIsFull(&stack))) {
        printf("passed\n");
        passed += 1;
    }
    else {
        printf("failed\n");
    } 
    
    printf("Does StackGetSize() properly evaluate the Stack size?\n");
    if(StackGetSize(&stack) == 2) {
        printf("passed\n");
        passed += 1;
    }
    else {
        printf("failed\n");
    } 
    
    
    
    
    printf("Tests passed: %i / 13", passed);
    BOARD_End();
    //test stackInit:
    while (1);
    return 0;
}


