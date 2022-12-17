#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef int TreeEntry;

typedef struct node{
    TreeEntry info;
    struct node *left;
    struct node *right;
}Node;

typedef Node* Tree;

void CreateTree(Tree *t);
int isTreeEmpty(Tree *t);
int isTreeFull(Tree *t);
int TreeSize(Tree *t);
int TreeHeight(Tree *t);
void InorderTraverse(Tree *t,void(*pf)(TreeEntry));
void PreorderTraverse(Tree *t,void(*pf)(TreeEntry));
void PostorderTraverse(Tree *t,void(*pf)(TreeEntry));
void InsertNode(Tree *t,TreeEntry info);
void Delete(Tree *t,TreeEntry k);
void ClearTree(Tree *t);
int Search(Tree *t,TreeEntry k);
int CountLeafs(Tree *t);
#endif // BST_H_INCLUDED
