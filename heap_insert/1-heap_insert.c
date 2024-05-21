#include <stdlib.h>
#include <stdio.h>
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

/**
 * binary_tree_size - count all child nodes including the root
 * @tree: tree to loop through
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
/**
 * binary_tree_is_perfect - checks if tree is perfect
 *@tree: tree to check
 *
 *Return: 1 perfect 0 not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t size, i, j, sum = 0, pow;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	for (i = 0; i <= binary_tree_height(tree); i++)
	{
		for (j = 0, pow = 1; j < i; j++)
			pow *= 2;
		sum += pow;
	}
	if (sum == size)
		return (1);
	return (0);
}
/**
 * find_parent - finds parent for insert
 * @root: tree to check
 *
 *Return: null or node
 */
heap_t *find_parent(heap_t *root)
{
    if (root == NULL)
        return (NULL);
    if (root->left == NULL && root->right == NULL)
        return root;
    if (root->right == NULL)
        return root;
    int l = binary_tree_height(root->left);
    int r = binary_tree_height(root->right);

    if (l == r && binary_tree_is_perfect(root->right))
        return find_parent(root->left);
    if (l == r && !binary_tree_is_perfect(root->right))
        return find_parent(root->right);
    if (l != r && !binary_tree_is_perfect(root->left))
        return find_parent(root->left);
    return find_parent(root->right);

    printf("%d %d", l, r);
    return NULL;
}
/**
 * heap_insert - main
 * @root: root of the tree
 * @value: value of the node
 *
 *Return: 1 perfect 0 not
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *parent = find_parent(*root);
    heap_t *node, *current;
    int temp;

    node = binary_tree_node(parent, value);
    if (parent == NULL)
    {
        *root = node;
    }
    else
    {
        if (parent->left == NULL)
            parent->left = node;
        else
            parent->right = node;
    }
    current = node;

    while (current != NULL)
    {
        if (current->parent == NULL)
            break;
        if (current->n > current->parent->n)
        {
            temp = current->n;
            current->n = current->parent->n;
            current->parent->n = temp;
            current = current->parent;
        }
        else
            break;
    }

    return node;
}