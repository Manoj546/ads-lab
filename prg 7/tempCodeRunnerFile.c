// C++ program to implement basic operations
// (search, insert and delete) on a BST that
// handles duplicates by storing count with
// every node
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	int count;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	temp->count = 1;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->key << "("
			<< root->count << ") ";
		inorder(root->right);
	}
}

/* A utility function to insert a new
node with given key in BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	// If key already exists in BST,
	// increment count and return
	if (key == node->key)
	{
	(node->count)++;
		return node;
	}

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree, return
the node with minimum key value found in that
tree. Note that the entire tree does not need
to be searched. */
struct node * minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

/* Given a binary search tree and a key,
this function deletes a given key and
returns root of modified tree */
struct node* deleteNode(struct node* root,
								int key)
{
	// base case
	if (root == NULL) return root;

	// If the key to be deleted is smaller than the
	// root's key, then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater than
	// the root's key, then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key
	else
	{
		// If key is present more than once,
		// simply decrement count and return
		if (root->count > 1)
		{
			(root->count)--;
			return root;
		}

		// ElSE, delete the node

		// node with only one child or no child
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

		// node with two children: Get the inorder
		// successor (smallest in the right subtree)
		struct node* temp = minValueNode(root->right);

		// Copy the inorder successor's
		// content to this node
		root->key = temp->key;
		root->count = temp->count;
	
		// To ensure successor gets deleted by
		// deleteNode call, set count to 0.
		temp->count = 0;

		// Delete the inorder successor
		root->right = deleteNode(root->right,
								temp->key);
	}
	return root;
}

// Driver Code
int main()
{
	/* Let us create following BST
			12(3)
		/	 \
	10(2)	 20(1)
	/ \
	9(1) 11(1) */
	struct node *root = NULL;
	root = insert(root, 10);
	root = insert(root, 18);
	root = insert(root, 7);
	root = insert(root, 15);
	root = insert(root, 16);
	root = insert(root, 30);
	root = insert(root, 25);
	root = insert(root, 40);
	root = insert(root, 60);

	cout << "Inorder traversal of the given tree "
		<< endl;
	inorder(root);

	cout << "\nDelete 20\n";
	root = deleteNode(root, 20);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 12\n" ;
	root = deleteNode(root, 12);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 9\n";
	root = deleteNode(root, 9);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	return 0;
}

// This code is contributed by Akanksha Rai
