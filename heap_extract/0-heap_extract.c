#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * binary_tree_height - function that goes through the tree and mesure height
 * @tree: tree to loop through
 *
 * Return: nothing
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int height = 0, height2 = 0;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree->left);
	height2 = binary_tree_height(tree->right);

	if (height > height2)
		return (height + 1);
	else
		return (height2 + 1);
}

/**
 * heap_extract - remove node root an keep the tree perfect
 * @root: root of the tree
 *
 * Return: value to return
 */
int heap_extract(heap_t **root)
{
    int left = 0, right = 0;
    heap_t *l, *r, *node;

    if (root == NULL)
        return 0;

    if ((*root)->left == NULL && (*root)->right == NULL)
    {
        if ((*root)->parent != NULL)
        {
            if ((*root)->parent->left == (*root))
                (*root)->parent->left = NULL;
            if ((*root)->parent->right == (*root))
                (*root)->parent->right = NULL;
            (*root)->parent = NULL;
        }
        right = (*root)->n;
        free(*root);
        return (right);
    }

	left = binary_tree_height((*root)->left);
	right = binary_tree_height((*root)->right);

    l = (*root)->left;
    r = (*root)->right;

    if (left > right)
        node = l;
    else
        node = r;

    left = node->n;
    node->n = (*root)->n;
    (*root)->n = left;

    return (heap_extract(&node));
}