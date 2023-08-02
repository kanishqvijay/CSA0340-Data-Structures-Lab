#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* create(){
	struct node* stack = calloc(1,sizeof(struct node)); 
	stack->data = NULL;
	stack->next = NULL;
	return stack;
}

struct node* push(struct node* stack,int d){
	if (stack->data == NULL){
		stack->data = d;
		return stack;
	}
	struct node* n = calloc(1,sizeof(struct node));
	n->data = d;
	n->next = stack;
	return n;
}

struct node* pop(struct node* stack){
	if (stack->data==NULL){
		printf("Stack is Empty, Stack underflow");
		return stack;
	}
	struct node* n = stack->next;
	free(stack);
	return n;
}

void display(struct node* stack){
	while (stack->next != NULL){
		printf("%d=",stack->data);
		stack = stack->next;
	}
	printf("%d\n",stack->data);
}
void main(){
	struct node* stack = create();
	stack = push(stack,4);
	display(stack);
	stack = push(stack,5);
	display(stack);
	stack = pop(stack);
	display(stack);
	stack = push(stack,2);
	display(stack);
	
	
}