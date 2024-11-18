#include "binary_trees.h"

/**
 * check_left - check if left nodes are inferior to ancestor
 * @tree: tree to test
 * @value: value of the ancestor node
 * Return: 1 BST 0 not
 */
int check_left(binary_tree_t *tree, int value)
{
	if (tree == NULL)
		return (1);

	if (value <= tree->n)
		return (0);

	return (check_left(tree->left, value) && check_left(tree->right, value));
}
/**
 * check_right - check if right nodes are inferior to ancestor
 * @tree: tree to test
 * @value: value of the ancestor node
 * Return: 1 BST 0 not
 */
int check_right(binary_tree_t *tree, int value)
{
	if (tree == NULL)
		return (1);

	if (value >= tree->n)
		return (0);

	return (check_right(tree->left, value) && check_right(tree->right, value));
}
/**
 * binary_tree_is_bst - test if tree is BST
 * @tree: tree to test
 * Return: 1 BST 0 not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		if (check_left(tree->left, tree->n) == 0)
			return (0);

	if (tree->right != NULL)
		if (check_right(tree->right, tree->n) == 0)
			return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_bst(tree->left) && binary_tree_is_bst(tree->right));

	if (tree->left != NULL)
		return (binary_tree_is_bst(tree->left));
	if (tree->right != NULL)
		return (binary_tree_is_bst(tree->right));
	return (1);
}
