#include <stdio.h>
#include <stdlib.h>
int nodeCount = 0;
typedef struct node *nodeptr;

struct node
{
    int data;
    nodeptr left;
    nodeptr right;
};

nodeptr createNode()
{
    nodeptr temp = (nodeptr)malloc(sizeof(struct node));
    return temp;
}

nodeptr createTree()
{
    int n;
    printf("Enter a no: ");
    scanf("%d", &n);
    if (n == -1)
        return NULL;
    nodeptr temp = createNode();
    temp->data = n;
    printf("Left child of %d:\n", n);
    temp->left = createTree();
    printf("Right child of %d:\n", n);
    temp->right = createTree();
    return temp;
}

int count_Nodes(nodeptr root){
    nodeCount++;
    if (!root)
    {
        return 0;
    }
    return (1 + count_Nodes(root->left) + count_Nodes(root->right));
}

void main()
{
    nodeptr root = createTree();
    printf("Number of Nodes: %d\n", count_Nodes(root));
    printf("Operation Count: %d", nodeCount);
}
