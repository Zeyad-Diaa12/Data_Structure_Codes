#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void CreateTree(Tree *t){
    *t=NULL;
}

int isTreeEmpty(Tree *t){
    return !*t;
}

int isTreeFull(Tree *t){
    return 0;
}

int TreeSize(Tree *t){
    if(!*t){
        return 0;
    }
    return(1+TreeSize(&(*t)->left)+TreeSize(&(*t)->right));
}

int TreeHeight(Tree *t){
    if(!*t){
        return 0;
    }
    int left = TreeHeight(&(*t)->left);
    int right = TreeHeight(&(*t)->right);
    return (left>right)?left+1:right+1;
}

void InorderTraverse(Tree *t,void(*pf)(TreeEntry)){
    if(*t){
        InorderTraverse(&(*t)->left,pf);
        (*pf)((*t)->info);
        InorderTraverse(&(*t)->right,pf);
    }
}

void PreorderTraverse(Tree *t,void(*pf)(TreeEntry)){
    if(*t){
        (*pf)((*t)->info);
        PreorderTraverse(&(*t)->left,pf);
        PreorderTraverse(&(*t)->right,pf);
    }
}

void PostorderTraverse(Tree *t,void(*pf)(TreeEntry)){
    if(*t){
        PostorderTraverse(&(*t)->left,pf);
        PostorderTraverse(&(*t)->right,pf);
        (*pf)((*t)->info);
    }
}

void InsertNode(Tree *t,TreeEntry info){
    Node *pn = (Node*)malloc(sizeof(Node));
    pn->info=info;
    pn->left=NULL;
    pn->right=NULL;

    if(!*t){
        *t=pn;
    }
    else{
       Node *curr,*prev;
       curr=*t;
       while(curr){
            prev=curr;
            if(info>curr->info){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
       }
       if(info>prev->info){
            prev->right=pn;
       }
       else{
            prev->left=pn;
       }
    }
}

void Delete(Tree *t,TreeEntry k){
   int found=0;
   Node *curr=*t;
   Node *prev=NULL;

   while(curr && !(found=(k==curr->info))){
      prev=curr;
      if(k<curr->info){
        curr=curr->left;
      }
      else{
        curr=curr->right;
      }
    }

    if(found){
        if(!prev){
            DeleteNode(t);
        }
        else if(k<prev->left){
            DeleteNode(&prev->left);
        }
        else{
            DeleteNode(&prev->right);
        }
    }

}

void DeleteNode(Tree *t){
    Node *curr=*t;
    if(!curr->left){
        *t=curr->right;
    }
    else if(!curr->right){
        *t=curr->left;
    }
    else{
        curr=curr->left;
        Node *prev=NULL;
        while(curr->right){
            prev=curr;
            curr=curr->right;
        }
        (*t)->info = curr->info;
        if(prev){
            prev->right=curr->left;
        }
        else{
            (*t)->left = curr->left;
        }
    }
    free(curr);
}

void ClearTree(Tree *t){
    if(*t){
       ClearTree(&(*t)->left);
       ClearTree(&(*t)->right);
       free(*t);
       *t=NULL;
    }
}

int Search(Tree *t,TreeEntry k){
    int found=0;
    Node *pn;
    pn=*t;
    while(pn && !(found = (k==pn->info))){
        if(k>pn->info){
            pn=pn->right;
        }
        else{
            pn=pn->left;
        }
    }
    return found;
}

int CountLeafs(Tree *t){
    if(!*t){
        return 0;
    }
    if((*t)->left == NULL && (*t)->right == NULL){
        return 1;
    }
    return CountLeafs(&(*t)->left)+CountLeafs(&(*t)->right);
}
