#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node* node, int data)
{
    if (node == NULL)
        return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

struct node* search(struct node *node, int value)
{
    if (node == NULL)
        return NULL;
    if (value == node->data)
        return node;
    else if (value < node->data)
        return search(node->left, value);
    return search(node->right, value);
}

void display_preorder(struct node *node)
{
    if (node)
    {
        printf("%d ", node->data);
        display_preorder(node->left);
        display_preorder(node->right);
    }
}

void display_inorder(struct node *node)
{
    if (node)
    {
        display_inorder(node->left);
        printf("%d ", node->data);
        display_inorder(node->right);
    }
}

void display_postorder(struct node *node)
{
    if (node)
    {
        display_postorder(node->left);
        display_postorder(node->right);
        printf("%d ", node->data);
    }
}

struct node *minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        // 1 or 0 child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // 2 children
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void deleteTree(struct node *node)
{
    if (node)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        free(node);
    }
}

int main(){
    struct node* root = NULL;
    printf("1.Insert\n");
    printf("2.Search\n");
    printf("3.Delete a node\n");
    printf("4.Delete tree\n");
    printf("5.PreOrder Traversal\n");
    printf("6.InOrder Traversal\n");
    printf("7.PostOrder Traversal");
    int choice, ele;
    while(1){
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter item to insert: ");
                scanf("%d", &ele);
                root = insert(root, ele);
                break;
            case 2:
                printf("\nEnter item to search: ");
                scanf("%d", &ele);
                if(search(root, ele) == NULL)
                    printf("Not Found");
                else
                    printf("Found");
                break;
            case 3:
                printf("\nEnter item to delete: ");
                scanf("%d", &ele);
                root = deleteNode(root, ele);
                break;
            case 4:
                deleteTree(root);
                break;
            case 5:
                printf("\n");
                display_preorder(root);
                printf("\n");
                break;
            case 6:
                printf("\n");
                display_inorder(root);
                printf("\n");
                break;
            case 7:
                printf("\n");
                display_postorder(root);
                printf("\n"); 
                break;
        }
    }
}