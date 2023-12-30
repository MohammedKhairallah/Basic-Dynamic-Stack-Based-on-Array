/* 
 * File:   Application.c
 * Author: Mohammed Khairallah
 *
 * Created on December 27, 2023, 8:01 PM
 */

#include "Application.h"

int main(){
    StackStatus_t Stack1_Status = STACK_NOK;

    printf("Enter number of stack 1 elements : ");
    scanf("%i", &Stack1_Size);

    Stack1 = CreateStack(Stack1_Size, &Stack1_Status);
    printf("Stack1_Status = %i\n", Stack1_Status);

    if(Stack1){
        printf("Stack 1 created \n");

        printf("==========PushStack===========\n");
        Stack1_Status = PushStack(Stack1, &data_1);
        printf("Stack1_Status = %i\n", Stack1_Status);

        printf("==========PushStack===========\n");
        Stack1_Status = PushStack(Stack1, &data_2);
        printf("Stack1_Status = %i\n", Stack1_Status);

        printf("==========PushStack===========\n");
        Stack1_Status = PushStack(Stack1, &data_3);
        printf("Stack1_Status = %i\n", Stack1_Status);

        printf("==========StackCount===========\n");
        Stack1_Status = StackCount(Stack1, &Stack1_Count);
        printf("Stack1_Status = %i\n", Stack1_Status);
        printf("Stack1_Count = %i\n", Stack1_Count);

        printf("==========StackTop===========\n");
        retval = StackTop(Stack1, &Stack1_Status);
        printf("Stack1_Status = %i\n", Stack1_Status);
        printf("retval = %c\n", *((uint8_t *)retval));

        printf("==========PopStack===========\n");
        retval = PopStack(Stack1, &Stack1_Status);
        printf("Stack1_Status = %i\n", Stack1_Status);
        printf("retval = %c\n", *((uint8_t *)retval));

        printf("==========StackCount===========\n");
        Stack1_Status = StackCount(Stack1, &Stack1_Count);
        printf("Stack1_Status = %i\n", Stack1_Status);
        printf("Stack1_Count = %i\n", Stack1_Count);

        printf("==========StackTop===========\n");
        retval = StackTop(Stack1, &Stack1_Status);
        printf("Stack1_Status = %i\n", Stack1_Status);
        printf("retval = %0.3f\n", *((float32_t *)retval));

        printf("==========DestroyStack===========\n");
        Stack1 = DestroyStack(Stack1, &Stack1_Status);
        printf("Stack1_Status = %i\n", Stack1_Status);

        if(!Stack1){
            printf("Stack 1 Destroyed \n");
        }
        else{}
    }
    else{ 
        printf("Stack1_Status = %i\n", Stack1_Status);
    }

    return 0;
}
