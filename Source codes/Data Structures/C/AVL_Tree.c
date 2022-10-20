#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};
//int max(int a, int b);

int ht(struct Node *N)
{
	if (N == NULL)
	return 0;
	return 1+max(ht(N->left), ht(N->right));
}


int max(int a, int b)
{
	return (a > b)? a : b;
}

//Insertion of Root node
struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 0; 
	return(node);
}

//Function for Right Rotation
struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;
	
	x->right = y;
	y->left = T2;
	
	y->height = ht(y);
	x->height = ht(x);
	
	return x;
}

//Function for Left Rotation
struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;
	
	y->left = x;
	x->right = T2;

	x->height = ht(x);
	y->height = ht(y);
	
	return y;
}

//Function to obtain Balancing Factor
int getBalancingFactor(struct Node *N)
{
	if (N == NULL)
		return 0;
	return ht(N->left) - ht(N->right);
}

//Insertion of New node
struct Node* insert(struct Node* node, int key)
{	
	if (node == NULL)
	{
		node = newNode(key);
		 printf("Element inserted\n");
		return node;
	}

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else 
		return node;
	
	node->height = ht(node);
	
	int balance = getBalancingFactor(node);
	
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
	
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);
	
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	 
	return node;
}

//Function to obtain Minimum Value Node
struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;
 
    
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

//Deletion of Node
struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;
    if ( key < root->key )
        root->left = deleteNode(root->left, key);
    else if( key > root->key )
        root->right = deleteNode(root->right, key);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
             *root = *temp; 
                            
            free(temp);
            printf("Element deleted\n");
        }
        else
        {
            struct Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == NULL)
      return root;
    root->height = ht(root);
    int balance = getBalancingFactor(root);
    if (balance > 1 && getBalancingFactor(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalancingFactor(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalancingFactor(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalancingFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

//Inorder Trav
void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

//Preorder Trav
void preorder(struct Node* root)
{
    if (root != NULL)
    {
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

//Postorder Trav
void postorder(struct Node* root)
{
    if (root!= NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
    }
}
int main()
{
 struct Node *root = NULL;
    int ch,x,n;
    printf("***   MENU   ***\n\n1. Insertion\n2. Deletion\n3. Display (Preorder, Inorder and Postorder)\n4. Exit\n");
    printf("--Enter the prefered choice--\n");
    scanf("%d",&ch);
    while(ch !=0)
    {        
        switch(ch)
        {
            case 1:
            	printf("!!In case1. Enter the node\n");
                   scanf("%d",&n);
                   root=insert(root,n);
                   break;
            case 2:
			       printf("!!In case2. Enter the node\n");
                    scanf("%d", &n);
                    root=deleteNode(root, n);
                    break;

            case 3:
            	    printf("!!In case3\n");
                    printf("Preorder: ");
                    preorder(root);
                    printf("\n");
                    printf("Inorder: ");
                    inorder(root);
                    printf("\n");
                    printf("Postorder: ");
                    postorder(root);
                    printf("\n");
                    break;
            
            case 4:
                   printf("EXIT\n");
            	   exit(0);
            	   break;
            default:
                printf("\nPLEASE ENTER VALID CHOICE\n");
        }
        printf("--Enter the prefered choice--\n");
        scanf("%d",&ch);
    }
}