#include "binary_trees.h"
#include "9-binary_tree_height.c"
/**
 * binary_tree_balance - calculate the balance of the tree
 *@tree: tree to loop through
 *Return: balance
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left;
	int height_right;

	if (tree == NULL)
		return (0);
	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	if (tree->left != NULL)
		height_left++;
	if (tree->right != NULL)
		height_right++;

	return (height_left - height_right);
}
