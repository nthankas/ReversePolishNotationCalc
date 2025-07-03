// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CMPE13 Support Library
#include "BOARD.h"



// User libraries
#include "rpn.h"

int main()
{
    BOARD_Init();
    int error;
    int passed = 0;

    printf("\n###### Beginning CRUZID's rpn test harness: ####\n\n");

    //What follows is starter code.  You will need to modify it!
    
    char test0[] = "1 1 +";
    double result0;
    double expected0 = 2;
    printf("Testing RPN_Evaluate with \"%s\"... \n ", test0);
    error = RPN_Evaluate(test0, &result0);
    if (error) {
        printf("   Failed, RPN_Evaluate produced an error\n");
    } else if (result0 != expected0) {
        printf("   Failed, expected = %f , result = %f\n", expected0, result0);
    } else {
        printf("   Success!\n");
        passed += 1;
    }
    
    char test1[] = "1 4 + 6 4 - * 8 /";
    double result1;
    double expected1 = 1.25;
    printf("Testing RPN_Evaluate with \"%s\"... \n ", test1);
    error = RPN_Evaluate(test1, &result1);
    if (error) {
        printf("   Failed, RPN_Evaluate produced an error\n");
    } else if (result1 != expected1) {
        printf("   Failed, expected = %f , result = %f\n", expected1, result1);
    } else {
        printf("   Success!\n");
        passed += 1;
    }
    
    char test2[] = "3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 *";
    double result2;
    printf("Testing RPN_Evaluate with \"%s\"... \n ", test2);
    error = RPN_Evaluate(test2, &result2);
    if (error == 1) {
        printf("   Success, RPN_Evaluate expected an error and received the Stack Overflow error.\n");
        passed += 1;
    }
    else {
        printf("   Failed, expected error.\n");
    }
    
    char test4[] = "- - 3";
    double result4;
    printf("Testing RPN_Evaluate with \"%s\"... \n ", test4);
    error = RPN_Evaluate(test4, &result4);
    if (error == 2 || error == 5) {
        printf("   Success, RPN_Evaluate expected an error and received the Too Few Items or Stack Underflow error.\n");
        passed += 1;
    }
    else {
        printf("   Failed, expected error.\n");
    }
    
    char test7[] = "1 4 / 3 X";
    double result7;
    printf("Testing RPN_Evaluate with \"%s\"... \n ", test7);
    error = RPN_Evaluate(test7, &result7);
    if (error == 3) {
        printf("   Success, RPN_Evaluate expected an error and received the Invalid Token error.\n");
        passed += 1;
    }
    else {
        printf("   Failed, expected error.\n");
    }
    
    char test8[] = "1 4 / 4 * 0 /";
    double result8;
    printf("Testing RPN_Evaluate with \"%s\"... \n ", test8);
    error = RPN_Evaluate(test8, &result8);
    if (error == 4) {
        printf("   Success, RPN_Evaluate expected an error and received the Division by Zero error.\n");
        passed += 1;
    }
    else {
        printf("   Failed, expected error.\n");
    }
    
    char test3[] = "1 4 5 3 4 5 23323 4343 21 492494 2323 13132 4923282 1212 3131323 121 212212 2499812";
    double result3;
    printf("Testing RPN_Evaluate with \"%s\"... \n ", test3);
    error = RPN_Evaluate(test3, &result3);
    if (error == 6) {
        printf("   Success, RPN_Evaluate expected an error and received the Too Many Items error.\n");
        passed += 1;
    }
    else {
        printf("   Failed, expected error.\n");
    }
    
    char test5[] = "5 6 - 3 * 5 +";
    double result5;
    double expected5 = 2;
    printf("Testing RPN_Evaluate with \"%s\"... \n ", test5);
    error = RPN_Evaluate(test5, &result5);
    if (error) {
        printf("   Failed, RPN_Evaluate produced an error\n");
    } else if (result5 != expected5) {
        printf("   Failed, expected = %f , result = %f\n", expected5, result5);
    } else {
        printf("   Success!\n");
        passed += 1;
    }
    
    char test6[] = "5 6 - 3 * 5 + 9 * 10 /";
    double result6;
    double expected6 = 1.8;
    printf("Testing RPN_Evaluate with \"%s\"... \n ", test6);
    error = RPN_Evaluate(test6, &result6);
    if (error) {
        printf("   Failed, RPN_Evaluate produced an error\n");
    } else if (result6 != expected6) {
        printf("   Failed, expected = %f , result = %f\n", expected6, result6);
    } else {
        printf("   Success!\n");
        passed += 1;
    }

    printf("Testing ProcessBackspaces:\n");
    char test_pb1[] = "123\b34";
    ProcessBackspaces(test_pb1);
    printf("result    : %s\n", test_pb1);
    printf("should be : 1234\n");
    
    printf("RPM_Evaluate Tests passed: %i / 9\n", passed);
    printf("ProcessBackspaces Tests passed: 0 / 1\n");
    BOARD_End();
    while (1);
}


