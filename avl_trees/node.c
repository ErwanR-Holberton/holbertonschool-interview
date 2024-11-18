#include "binary_trees.h"

/**
 * *binary_tree_node - creates a binary tree node
 *
 * @parent: Pointer to the tree to add a node in
 * @value: value of the node to create
 *
 * Return: pointer to the created node or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
