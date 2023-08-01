#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
}*head;

void create(int d){
	head = calloc(1,sizeof(struct node));
	head->data = d;
	head->next = NULL;
}

struct node* get_index(int i){
	struct node* n = head;
	int in = 0;
	while (n->next != NULL && i!=0){
		n = n->next;
		in++;
		if (in == i){
			break;
		}
	}
	return n;
}
void insert(int d,int i){
	struct node* n = calloc(1,sizeof(struct node));
	n->data = d;
	if (i<=0){
		n->next = head;
		head = n;
	} else{
		struct node* pos = get_index(i-1);
		n->next = pos->next;
		pos->next = n;
	}
}

void del(int i){
	if (i<=0){
		struct node* pos = get_index(i+1);
		struct node* temp = head;
		head = pos;
		free(temp);
	} else{
		struct node* pos = get_index(i);
		struct node* pos2 = get_index(i-1);
		pos2->next = pos->next;
		free(pos);
	}
}

void display(){
	struct node* n = head;
	while (n->next != NULL){
		printf("%d-->",n->data);
		n = n->next;
	}
	printf("%d\n",n->data);
}

void main(){
	create(3);
	display();
	insert(5,1);
	display();
	del(1);
	display();
	insert(20,5);
	display();
	insert(6,1);
	display();
}


