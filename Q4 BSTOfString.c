// C program to demonstrate delete operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
	char *key; 
	struct node *left, *right; 
}; 

// A utility function to create a new BST node 
struct node *newNode(char item[10]) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%s  ",root->key); 
		inorder(root->right); 
	} 
} 

/* A utility function to insert a new node with given key in BST */
struct node *insert(struct node* node, char key[10]) 
{ 
    int i=0,j=0,k=0;
	/* If the tree is empty, return a new node */
	if (node == NULL) 
    return newNode(key); 

	/* Otherwise, recur down the tree */
	    r1:
        if(key[i]<node->key[i])
        {
            k=1; 
        }
        else if(key[i]>node->key[i])
        {
            k=2;
        }
        else
        {
            i++;
            goto r1;
        }
        
    
    switch(k)
    {
        case 1: node->left = insert(node->left, key); 
        break;
        case 2: node->right = insert(node->right, key);   
        break;
        default: printf("\nInvalid Press\n");      
    }
    
    
	/* return the (unchanged) node pointer */
	return node; 
} 


// Driver Program to test above functions 
int main() 
{ 
	/* Let us create following BST 
			50 
		/	 \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 */
	struct node *root = NULL; 
	root = insert(root,"arthi"); 
	root = insert(root,"christy"); 
	root = insert(root,"dorothy"); 
	root = insert(root,"fraser"); 
	root = insert(root,"eliza");
	root = insert(root,"david"); 

	
	inorder(root);  //Sorting or Inorder Traversal

	return 0; 
} 
