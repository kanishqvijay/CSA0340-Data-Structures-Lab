#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
}*queue;

void create(){
    queue = calloc(1,sizeof(struct node));
    queue->data = -1;
    queue->next = NULL;
}

void enqueue(int d){
    if (queue->data == -1 && queue->next == NULL){
        queue->data = d;
        return;
    }
    struct node* n = calloc(1,sizeof(struct node));
    n->data = d;
    n->next = queue;
    queue = n;
}

int dequeue(){
    struct node* n = queue;
    if(queue->next == NULL && queue->data != -1){
        int d = queue->data;
        queue->data = -1;
        return d;
    }
    while(n->next->next!=NULL){
        n = n->next;
    }
    struct node* temp = n->next;
    int d = n->next->data;
    n->next = n->next->next;
    free(temp);
    return d;
}

void display(){
    struct node* n = queue;
    while(n->next!=NULL){
        printf("%d=>",n->data);
        n = n->next;
    }
    printf("%d\n",n->data);
}

int main(){
    int d;
    create();
    for (int i = 0; i<5;i++){
        enqueue(i);
    }
    for (int i = 0; i<5;i++){
        display();
        d = dequeue();
        printf("dequeue:%d\n",d);
    }
    printf("dequeue:%d\n",dequeue());
    display();
    return 0;
}
