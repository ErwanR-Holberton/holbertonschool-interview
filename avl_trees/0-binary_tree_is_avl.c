#include "binary_trees.h"
#include "110-binary_tree_is_bst.c"
#include "14-binary_tree_balance.c"
/**
 * binary_tree_is_avl - check if tree is an avl tree
 * @tree: tree to check
 * Return: NOTHING
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (binary_tree_is_bst(tree) == 0)
		return (0);
	balance = binary_tree_balance(tree);
	if (balance < -1 || balance > 1)
		return (0);
	if (tree->left == NULL || tree->right == NULL)
		return (1);

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
