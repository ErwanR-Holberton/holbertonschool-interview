#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

void avl_right(int left, int right, binary_tree_t *parent, int *array
																	, int size);

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


/**
 * *avl_left - create AVL tree
 *
 * @left: index left
 * @right: idex right
 * @parent: parent node
 * @array: values to put in the tree
 * @size: does not matter
 *
 */
void avl_left(int left, int right, binary_tree_t *parent, int *array, int size)
{
	int center = (right - left) / 2 + left;

	if (center == 0)
		parent->left = binary_tree_node(parent, array[center]);
	if (center == left)
		return;

	parent->left = binary_tree_node(parent, array[center]);
	if (!parent->left)
		return;
	avl_left(left, center, parent->left, array, size);
	avl_right(center, right, parent->left, array, size);
}
/**
 * *avl_right - create AVL tree
 *
 * @left: index left
 * @right: idex right
 * @parent: parent node
 * @array: values to put in the tree
 * @size: does not matter
 *
 */
void avl_right(int left, int right, binary_tree_t *parent, int *array
																	, int size)
{
	int center = (right - left) / 2 + left;

	if (center == left)
		return;
	parent->right = binary_tree_node(parent, array[center]);

	if (!parent->right)
		return;
	avl_left(left, center, parent->right, array, size);
	avl_right(center, right, parent->right, array, size);
}

/**
 * *sorted_array_to_avl - create AVL tree
 *
 * @array: values to put in the tree
 * @size: does not matter
 *
 * Return: the tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int center = size / 2;
	avl_t *tree;

	if (!array)
		return NULL;

	tree = binary_tree_node(NULL, array[center]);
	if (!tree)
		return NULL;

	avl_left(0, center, tree, array, size);
	avl_right(center, size, tree, array, size);
	return (tree);
}
