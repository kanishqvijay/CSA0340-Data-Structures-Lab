#include <stdio.h>
#include <stdlib.h>

struct node{
    int hash;
    int occupied;
    int data;
};

struct hashmap{
    int h;
    int full;
    struct node* array;
}*HashMap;

void create(int h){
    HashMap = calloc(1,sizeof(struct hashmap));
    struct node* n = calloc(h,sizeof(struct node));
    HashMap->h = h;
    HashMap->full = 0;
    HashMap->array = n;
    for (int i = 0;i<h;i++){
        n->hash = i;
        n->occupied = 0;
        n->data = -1;
        n++;
    }
}

int insert(int hash_value,int value){
    HashMap->array[hash_value].data = value;
    HashMap->array[hash_value].occupied = 1;
    HashMap->full++;
}

int isFull(){
    return HashMap->full == HashMap->h;
}

int hashf(int value){
    return value%(HashMap->h);
}

void linear(int value){
    int hash_value = hashf(value);
    if (!HashMap->array[hash_value].occupied){
        insert(hash_value,value);
    } else if(!isFull()){
        linear(value+1);
    } else{
        printf("Hash Table has been filled, can't insert\n");
    }
}

void display(){
    struct node* n = HashMap->array;
    for (int i=0;i<HashMap->h;i++){
        printf("data:%d\n",n->data);
        printf("hash:%d\n",n->hash);
        printf("occupied:%d\n-----------\n",n->occupied);
        n++;
    }
}

int main()
{   int a[] = {100,23,43,56,78,13,12,9,4,1,7};    
    create(10);
    for(int i=0; i<11; i++){
        linear(a[i]);
    }
    display();
    return 0;
}
