#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *left,*right;
    int bal;
}NODE;

NODE* create(NODE *bnode,int x){
    NODE *getnode;
    if(bnode==NULL){
        bnode=(NODE*) malloc(sizeof(NODE));
        bnode->info=x;
        bnode->left=bnode->right=NULL;
    }
    else if(x>bnode->info)
        bnode->right=create(bnode->right,x);
    else if(x<bnode->info)
        bnode->left=create(bnode->left,x);
    else{
        printf("Duplicate node\n");
        exit(0);
    }
    return(bnode);
}

void inorder(NODE *ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
        printf("%5d-->%d",ptr->info,ptr->bal);
        inorder(ptr->right);
    }
}

void postorder(NODE *ptr){
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%5d-->%d",ptr->info,ptr->bal);
    }
}

void preorder(NODE *ptr){
    if(ptr!=NULL){
        printf("%5d-->%d",ptr->info,ptr->bal);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

int max(int a,int b){
    return a>b?a:b;
}

int height(NODE *ptr){
    if(ptr==NULL)
        return 0;
    return 1+max(height(ptr->left),height(ptr->right));
}

void balance(NODE *ptr){
    if(ptr!=NULL){
        ptr->bal=height(ptr->left)-height(ptr->right);
        balance(ptr->left);
        balance(ptr->right);
    }
}

void main(){
    int n,x,ch,i;
    NODE *root;
    root=NULL;
    while(1){
        printf("\n-----------Menu-----------\n");
        printf(" 1.Insert\n 2.All traversals\n 3.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter node (do not enter duplicate nodes):\n");
            scanf("%d",&x);
            root=create(root,x);
            balance(root);
            break;
            case 2: printf("\nInorder traversal:\n");
            inorder(root);
            printf("\nPreorder traversal:\n");
            preorder(root);
            printf("\nPostorder traversal:\n");
            postorder(root);
            printf("\n\n*********************************************");
            break;
            case 3:
            exit(0);
        }
    }
}