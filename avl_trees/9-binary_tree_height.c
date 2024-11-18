#include "binary_trees.h"
/**
 * binary_tree_height - function that goes through the tree and mesure height
 *@tree: tree to loop through
 *
 *Return: nothing
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int height = 0, height2 = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	if (tree->left != NULL)
		height = binary_tree_height(tree->left);
	if (tree->right != NULL)
		height2 = binary_tree_height(tree->right);

	if (height > height2)
		return (height + 1);
	else
		return (height2 + 1);
}
