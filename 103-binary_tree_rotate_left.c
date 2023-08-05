#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *turn, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	turn = tree->right;
	tmp = turn->left;
	turn->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = turn;
	turn->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = turn;
		else
			tmp->right = turn;
	}

	return (turn);
}
