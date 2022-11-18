#include "binary_trees.h"

/**
 * recursive_succ - A function that sets a minimum
 * value into the right subtree of the node to be deleted
 * @node: node to find the successor before deleted
 * Return: the minimum value of the subtree
 */
int recursive_succ(bst_t *node)
{
	int l_val = 0;

	if (node == NULL)
	{
		return (0);
	}

	l_val = recursive_succ(node->left);
	if (l_val == 0)
	{
		return (node->n);
	}
	return (l_val);

}

/**
 * assignment - A function to get the successor and change the value
 * with the current node
 * @root: node to check
 * Return: value of node found
 */
int assignment(bst_t *root)
{
	int node_value = 0;

	node_value = recursive_succ(root->right);
	root->n = node_value;
	return (node_value);
}

/**
 * remove_node - A function that looks for a node to delete and do
 * connections for each node after deletion
 * @root: Node to delete
 *
 * Return: value of node to delete or 0
 */
int remove_node(bst_t *root)
{
	if (root->left && root->right)
	{
		return (assignment(root));
	}
	else if ((!root->left && root->right) || (root->left && !root->right))
	{
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		else
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
	}
	else
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
	}
	free(root);
	return (0);
}

/**
 * bst_remove - A function that removes a node from a Binary Search Tree
 * @root: is a pointer to the root node of the tree where you
 * will remove a node
 * @value: is the value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int val = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		val = remove_node(root);
		if (val != 0)
			bst_remove(root->right, val);
	}
	else
		return (NULL);
	return (root);
}
