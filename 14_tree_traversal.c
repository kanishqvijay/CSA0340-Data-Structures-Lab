#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

void inorder(struct node* root) {
  if (root == NULL) return;
  inorder(root->left);
  printf("%d ->", root->data);
  inorder(root->right);
}

void preorder(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(struct node* root) {
  if (root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ->", root->data);
}

struct node* create(int value) {
  struct node* n = calloc(1,sizeof(struct node));
  n->data = value;
  n->left = NULL;
  n->right = NULL;

  return n;
}

struct node* insertLeft(struct node* root, int value) {
  root->left = create(value);
  return root->left;
}

struct node* insertRight(struct node* root, int value) {
  root->right = create(value);
  return root->right;
}

int main() {
  struct node* root = create(1);
  insertLeft(root, 12);
  insertRight(root, 9);
  insertLeft(root->left, 5);
  insertRight(root->left, 6);
  printf("Inorder traversal \n");
  inorder(root);
  printf("\nPreorder traversal \n");
  preorder(root);
  printf("\nPostorder traversal \n");
  postorder(root);
}
