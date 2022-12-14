#include <bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	int count;
	struct node *left, *right;
};

struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	temp->count = 2;
	return temp;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		int n = root->count;
		string s;
		if (n == 1){
			s = "red";
		}
		else if (n == 2)
			s = "black";
		else
			s = "Black";
		cout << root->key << "("
			 << s << ") ";
		inorder(root->left);
		inorder(root->right);
	}
}

struct node *insert(struct node *node, int key)
{
	if (node == NULL)
		return newNode(key);

	if (key == node->key)
	{
		(node->count)++;
		return node;
	}

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	return node;
}

struct node *minValueNode(struct node *node)
{
	struct node *current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

struct node *deleteNode(struct node *root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else
	{
		if (root->count > 1)
		{
			(root->count)--;
			return root;
		}

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

		struct node *temp = minValueNode(root->right);

		root->key = temp->key;
		root->count = temp->count;

		temp->count = 0;

		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

int main()
{
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


	cout << "Preorder traversal of the given tree "<< endl;
	inorder(root);

	// cout << "\nDelete 20\n";
	// root = deleteNode(root, 20);
	// cout << "Preorder traversal of the modified tree \n";
	// inorder(root);

	// cout << "\nDelete 12\n";
	// root = deleteNode(root, 12);
	// cout << "Preorder traversal of the modified tree \n";
	// inorder(root);

	// cout << "\nDelete 9\n";
	// root = deleteNode(root, 9);
	// cout << "Preorder traversal of the modified tree \n";
	// inorder(root);

	return 0;
}