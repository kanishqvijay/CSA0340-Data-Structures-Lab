#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
	char data;
	struct node* next;
};

struct stack{
	int top;
	struct node* head;
}*Stack;

void create(){
    Stack = calloc(1,sizeof(struct stack));
    struct node* n = calloc(1,sizeof(struct node));
    n->data = '\0';
    n->next = NULL;
    Stack->top = -1;
    Stack->head = n;
}
void push(char c){
	struct node* n = calloc(1,sizeof(struct node));
	n->data = c;
	n->next = Stack->head;
	Stack->head = n;
	Stack->top++;
}

void pop(){
	if (Stack->head->data == '\0'){
		return;
	}
	struct node* n = Stack->head;
	Stack->head = Stack->head->next;
	Stack->top--;
	free(n);
}

char peek(){
	return Stack->head->data;
}

int priority(char c){   
    switch (c){   
	    case '+':   
	    case '-':   
	        return 1;   
	  
	    case '*':   
	    case '/':   
	        return 2;   
	  
	    case '^':   
	        return 3;   
    }   
    return -1;  
}

void main(){
    create();
	char a[] = "a+(b*c+d)/e";
	for (int i = 0; a[i]; i++){
		if(isalnum(a[i])){
			printf("%c",a[i]);
		} else if(a[i] == '('){
			push(a[i]);
		} else if (a[i] == ')'){
			while (peek() != '('){
				printf("%c",peek());
				pop();
			}
			pop();
		} else if(priority(a[i]) > priority(peek())){
			push(a[i]);
		} else if (priority(a[i]) <= priority(peek())){
			printf("%c",peek());
			pop();
			push(a[i]);
		} 
	}
	while (Stack->top != -1){
		printf("%c",peek());
		pop();
	}
	
}
