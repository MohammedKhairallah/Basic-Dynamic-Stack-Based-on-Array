/* 
 * File:   StackArrayDS.h
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on December 27, 2023, 8:01 PM
 */
#include "StackArrayDS.h"

static uint8_t StackIsEmpty (Stack_t* stack_obj);
static uint8_t StackIsFull (Stack_t* stack_obj);

 /**
 * @brief Creates a new stack with the specified maximum size.
 *
 * This function dynamically allocates memory for a new stack object with the given maximum size,
 * initializes its attributes, and returns a pointer to the newly created stack.
 * It also updates the status of the operation in ret_status.
 *
 * @param maxSize Maximum number of elements that the created stack can hold.
 * @param ret_status Pointer to a StackStatus_t variable to store the status of the operation.
 *                   It will be updated based on the success or failure of the stack creation.
 *
 * @return Stack_t* Returns a pointer to the newly created stack on success.
 *                  Returns NULL if the stack creation fails or if ret_status is a NULL pointer.
 */
Stack_t* CreateStack (uint32_t maxSize, StackStatus_t *ret_status){
    Stack_t *my_stack = NULL;
    /* Check for NULL pointers in the input parameters */
    if(NULL == ret_status){ 
        *ret_status = STACK_NULL_POINTER; /* NULL pointer passed to the function */
        my_stack = NULL;
    }
    else{
        /* Allocate the stack in the heap */
        my_stack = (Stack_t *)malloc(sizeof(Stack_t));
        if(NULL == my_stack){
            *ret_status = STACK_NOK; /* Stack not created successfully */
        }
        else{
            my_stack->StackTop = -1;          /* Initialize the stack pointer to -1 (empty stack) */
            my_stack->ElementCount = 0;       /* Initialize the element counter to 0 (empty stack) */
            my_stack->StackMaxSize = maxSize; /* Initialize the maximum number of elements in the stack */
            /* Allocate memory for the stack array (elements) */
            my_stack->StackArray = (void **)calloc(my_stack->StackMaxSize, sizeof(void *));
            if(!(my_stack->StackArray)){
                free(my_stack);  /* Free the stack object as the Array not created successfully */
                my_stack = NULL; /* Array not created successfully */
                *ret_status = STACK_NOK; /* Stack not created successfully */
            }
            else{
                *ret_status = STACK_OK; /* Stack created successfully */
            }
        }
    }
    return my_stack;
}

 /**
 * @brief Destroys the provided stack object and releases its memory.
 *
 * This function deallocates memory for the provided stack object and its associated array of elements,
 * effectively destroying the stack. It updates the status of the operation in ret_status.
 *
 * @param stack_obj Pointer to the stack object (Stack_t) to be destroyed.
 * @param ret_status Pointer to a StackStatus_t variable to store the status of the operation.
 *                   It will be updated based on the success or failure of the stack destruction.
 *
 * @return Stack_t* Returns NULL after successfully destroying the stack.
 *                  Returns the original stack_obj pointer if any NULL pointer is passed.
 */
Stack_t* DestroyStack (Stack_t* stack_obj, StackStatus_t *ret_status){
    Stack_t *my_stack = stack_obj;
    /* Check for NULL pointers in the input parameters */
    if((NULL == stack_obj)||(NULL == ret_status)){
        *ret_status = STACK_NULL_POINTER; /* NULL pointer passed to the function */
    }
    else{
        /* Free the memory for the array object and the stack object */
        free(stack_obj->StackArray); /* Release the Array object */
        free(stack_obj); /* Release the stack object */
        *ret_status = STACK_OK;
        my_stack = NULL;
    }
    return my_stack;
}

 /**
 * @brief Pushes an item onto the top of the given stack.
 *
 * This function pushes an item onto the top of the provided stack object and
 * updates the status of the operation in StackStatus.
 *
 * @param stack_obj Pointer to the stack object (Stack_t) onto which the item will be pushed.
 * @param itemPtr Pointer to the item to be pushed onto the stack.
 *
 * @return StackStatus_t Returns a status code indicating the success or failure of the push operation:
 *         - STACK_OK if the item is successfully pushed onto the stack.
 *         - STACK_FULL if the stack is full (reached its maximum capacity), preventing stack overflow.
 *         - STACK_NULL_POINTER if either stack_obj or itemPtr is a NULL pointer.
 *         - STACK_NOK if any other failure occurs during the push operation.
 */
StackStatus_t PushStack (Stack_t* stack_obj, void* itemPtr){
    StackStatus_t StackStatus = STACK_NOK;
    /* Check for NULL pointers in the input parameters */
    if((NULL == stack_obj)||(NULL == itemPtr)){
        StackStatus = STACK_NULL_POINTER; /* NULL pointer passed to the function */
    }
    else{
        /* Check if the stack is full */
        if(StackIsFull(stack_obj)){
            StackStatus = STACK_FULL; /* Stack is full, prevent stack overflow */
        }
        else{
            (stack_obj->StackTop)++; /* Points to the next element in the stack */
            stack_obj->StackArray[stack_obj->StackTop] = itemPtr;
            (stack_obj->ElementCount)++; /* Increment the number of elements in the stack */
            StackStatus = STACK_OK; /* Item successfully pushed onto the stack */
        }
    }
    return StackStatus;
}

 /**
 * @brief Pops the top element from the given stack.
 *
 * This function removes and retrieves the top element from the provided stack object and
 * updates the status of the operation in ret_status.
 *
 * @param stack_obj Pointer to the stack object (Stack_t) from which the top element will be popped.
 * @param ret_status Pointer to a StackStatus_t variable to store the status of the operation.
 *                   It will be updated based on the success or failure of the pop operation.
 *
 * @return void* Returns a pointer to the popped element from the stack.
 *               If the stack is empty or if any NULL pointer is passed, it returns NULL.
 */
void* PopStack (Stack_t* stack_obj, StackStatus_t *ret_status){
    void *dataPtrOut = NULL;
    /* Check for NULL pointers in the input parameters */
    if((NULL == stack_obj)||(NULL == ret_status)){
        *ret_status = STACK_NULL_POINTER; /* NULL pointer passed to the function */
    }
    else{
        /* Check if the stack is empty */
        if(StackIsEmpty(stack_obj)){
            *ret_status = STACK_EMPTY; /* Stack is empty, prevent stack underflow */
        }
        else{
            /* Retrieve the top element from the stack */
            dataPtrOut = stack_obj->StackArray[stack_obj->StackTop];
            (stack_obj->StackTop)--; /* Points to the next element in the stack */
            (stack_obj->ElementCount)--; /* Decrement the number of elements in the stack */
            *ret_status = STACK_OK;
        }
    }
    return dataPtrOut;
}

 /**
 * @brief Retrieves the top element of the given stack.
 *
 * This function retrieves the top element (most recently added) from the provided stack object and
 * returns a pointer to that element. It also updates the status of the operation in ret_status.
 *
 * @param stack_obj Pointer to the stack object (Stack_t) from which the top element will be retrieved.
 * @param ret_status Pointer to a StackStatus_t variable to store the status of the operation.
 *                   It will be updated based on the success or failure of the operation.
 *
 * @return void* Returns a pointer to the top element of the stack.
 *               If the stack is empty or if any NULL pointer is passed, it returns NULL.
 */
void* StackTop (Stack_t* stack_obj, StackStatus_t *ret_status){
    void *dataPtrOut = NULL;
    /* Check for NULL pointers in the input parameters */
    if((NULL == stack_obj)||(NULL == ret_status)){
        *ret_status = STACK_NULL_POINTER; /* NULL pointer passed to the function */
    }
    else{
        /* Check if the stack is empty */
        if(StackIsEmpty(stack_obj)){
            *ret_status = STACK_EMPTY; /* Stack is empty, prevent stack underflow */
        }
        else{
            /* Copy the top element to the user */
            dataPtrOut = stack_obj->StackArray[stack_obj->StackTop];
            *ret_status = STACK_OK;
        }
    }
    return dataPtrOut;
}

 /**
 * @brief Checks the count of elements in the given stack and updates the count in stack_count.
 *
 * This function determines the count of elements present in the provided stack and
 * updates the count in the memory location pointed by stack_count parameter.
 *
 * @param stack_obj Pointer to the stack object (Stack_t) whose count needs to be checked.
 * @param stack_count Pointer to a uint32_t variable where the count of elements will be stored.
 *
 * @return StackStatus_t Enum status indicating the success or failure of the stack count operation:
 *         - STACK_OK if the operation is successful and the count is retrieved.
 *         - STACK_EMPTY if the provided stack is empty (contains no elements), and the count is set to 0.
 *         - STACK_NULL_POINTER if either stack_obj or stack_count is a NULL pointer.
 */
StackStatus_t StackCount (Stack_t* stack_obj, uint32_t *stack_count){
    StackStatus_t StackStatus = STACK_NOK;
    /* Check for NULL pointers in the input parameters */
    if((NULL == stack_obj)||(NULL == stack_count)){
        StackStatus = STACK_NULL_POINTER; /* NULL pointer passed to the function */
    }
    else{
        /* Check if the stack is empty */
        if(StackIsEmpty(stack_obj)){
            StackStatus = STACK_EMPTY; /* Stack is empty, prevent stack underflow */
            *stack_count = 0; /* Set the count to 0 for an empty stack */
        }
        else{
            /* Update the stack_count with the number of elements in the stack */
            *stack_count = stack_obj->ElementCount;
            StackStatus = STACK_OK;  /* Stack operation performed successfully  */
        }
    }
    return StackStatus;
}
/**
 * @brief Checks whether the given stack is empty.
 *
 * This function examines the provided stack object and determines whether it contains any elements.
 *
 * @param stack_obj Pointer to the stack object (Stack_t) to be checked for emptiness.
 *
 * @return uint8_t Returns 1 if the stack is empty; otherwise, returns 0.
 */
static uint8_t StackIsEmpty (Stack_t* stack_obj){
    return ((stack_obj->ElementCount) == 0);
}
/**
 * @brief Checks whether the given stack is full.
 *
 * This function examines the provided stack object and determines whether it has reached its maximum capacity.
 *
 * @param stack_obj Pointer to the stack object (Stack_t) to be checked for fullness.
 *
 * @return uint8_t Returns 1 if the stack is full; otherwise, returns 0.
 */
static uint8_t StackIsFull (Stack_t* stack_obj){
    return ((stack_obj->ElementCount) == (stack_obj->StackMaxSize));
}