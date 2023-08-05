#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *turn, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	turn = tree->left;
	tmp = turn->right;
	turn->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = turn;
	turn->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->right == tree)
			tmp->right = turn;
		else
			tmp->left = turn;
	}

	return (turn);
}
