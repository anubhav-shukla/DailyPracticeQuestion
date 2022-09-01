#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

struct Node* newnode(int data)
{
	struct Node* node = new (struct Node);
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

int countNode = 0;

void preOrder(Node* node, int mx)
{
	// Base case
	if (node == NULL)
	{
		return;
	}
	if (node->data >= mx)
	{
		countNode++;
		mx = max(node->data, mx);
	}

	preOrder(node->left, mx);

	preOrder(node->right, mx);
}

int main()
{
	struct Node* root = newnode(5);

	/*
			5
		/ \
		3	 10
		/ \ /
	20 21 1
*/

	root->left = newnode(3);
	root->right = newnode(10);

	root->left->left = newnode(20);
	root->left->right = newnode(21);

	root->right->left = newnode(1);

	preOrder(root, INT_MIN);

	cout << countNode;
}

