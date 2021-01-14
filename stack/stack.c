#ifndef STACK_H
#define STACK_H

#ifndef __cplusplus
    #include <stdbool.h>
#endif

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct stack_t stack_t;

struct stack_t {
    size_t size;
    size_t capacity;
    size_t top;
    int *elements;
};

#ifdef __cplusplus
extern "C" {
#endif
    //data is int
    stack_t *stack_new(int cap);
    //why void *
    void stack_delete(void *self);

    bool stack_is_empty(const stack_t *self);
    bool stack_peek(const stack_t *self);
    bool stack_push(stack_t *self,int data);
    int stack_pop(stack_t *self);

#ifdef __cplusplus
}
#endif


int stack_pop(stack_t *self)
{
    if (stack_is_empty(self))
        return false;
    printf("POP data %d \n",self->elements[self->top-1]);
    self->size--;
    self->top--;
    return true;
}

bool stack_push(stack_t *self,int data)
{
    if (self->size == self->capacity)
    {
        printf("Stack is full!\n");
        return false;
    }
    self->elements[self->top] = data;
    self->size++;
    self->top++;
    printf("data(%d) is push\n",data);
    return true;
}

bool stack_is_empty(const stack_t *self)
{
    //printf("stack_is_empty()\n");
    if (!self) {
        printf("NULL stack\n");
        return true;
    }
    if (self->size == 0)
        return true;

    return false;
}

bool stack_peek(const stack_t *self)
{
    if (stack_is_empty(self))
        return false;
    size_t top_data = self->elements[self->top-1];
    printf("Peek top data :%zu\n",top_data);
    return top_data;

}
stack_t *stack_new(int cap)
{
    printf("New stack !\n");
    stack_t *new_stack = malloc(sizeof(stack_t));
    if (!new_stack) 
    {
        printf("Null malloc()");
        return new_stack;
    }

    new_stack->size = 0;
    new_stack->top = 0;
    new_stack->capacity = cap;

    printf("Stack_new capacity :%zu\n", new_stack->capacity);

    new_stack->elements = malloc(sizeof(int *) *cap);
    if (!new_stack->elements) {
        printf("New stack elements null");
        stack_delete(new_stack);
        new_stack = NULL;
    }
    return new_stack;
}

void stack_delete(void *self)
{
    printf("Delete stack!!!!!\n");
    if (!self) {
        printf("Empty space\n");
        return;
    }

    if (((stack_t *)self)->elements)
    {
        printf("Free elment\n");
        free(((stack_t *)self)->elements);
    }
    else
        printf("elements address :%p \n",&((stack_t *)self)->elements);

    printf("Delete stack end\n");
    free(self);
}

int main(void)
{
    int total_count = 10;
    printf("Run Start\n");

    printf("New stack with %d \n",total_count);

    stack_t *new_s = stack_new(total_count);
    for(int i=0; i < total_count; i++)
    {
        printf("Push data %d \n",i);
        stack_push(new_s,i);
        stack_peek(new_s);
    }
    if (stack_is_empty(new_s))
        printf("It is empty\n");
    else
        printf("It is not empty\n");
    printf("======== start pop ==========\n");
    for(int i=0; i < total_count; i++)
    {
        stack_pop(new_s);
        stack_peek(new_s);
    }
 
    stack_delete(new_s);

}

#endif
