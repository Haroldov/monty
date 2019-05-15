#ifndef __MONTY__
#define __MONTY__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
=======
/*Global Variables*/
extern int state; /*begins as stack*/

/*Prototypes*/
char **split(char *str, const char *delim);

>>>>>>> 5b638241cf790f973be6abc14758fe540f940067
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/*Prototypes*/
char **split(char *str, const char *delim);
void (*get_op(char *command))(stack_t **stack, unsigned int line_number);
void op_push(stack_t **stack, unsigned int line);
#endif
