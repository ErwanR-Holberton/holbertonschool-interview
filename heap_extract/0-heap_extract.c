#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * swap - Swaps the values of two heap nodes.
 * @a: First node.
 * @b: Second node.
 */
void swap(heap_t *a, heap_t *b)
{
	int temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
 * findLastNode - Finds the last node in a heap (level-order).
 * @root: Root of the tree.
 *
 * Return: Pointer to the last node.
 */
heap_t *findLastNode(heap_t *root)
{
	heap_t *queue[100], *lastNode = NULL, *current;
	int front = 0, rear = 0;

	if (!root)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		current = queue[front++];
		lastNode = current;

		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}
	return (lastNode);
}

/**
 * heapifyDown - Restores max-heap property by sifting down a node.
 * @node: Node to heapify down from.
 */
void heapifyDown(heap_t *node)
{
	heap_t *largest = node;

	if (!node)
		return;

	if (node->left && node->left->n > largest->n)
		largest = node->left;

	if (node->right && node->right->n > largest->n)
		largest = node->right;

	if (largest != node)
	{
		swap(node, largest);
		heapifyDown(largest);
	}
}

/**
 * heap_extract - Extracts the root node of a max binary heap.
 * @root: Double pointer to the root of the heap.
 *
 * Return: Value of the extracted node, or 0 if failed.
 */
int heap_extract(heap_t **root)
{
	int maxValue;
	heap_t *lastNode;

	if (!(*root))
		return (0);

	lastNode = findLastNode(*root);
	if (!lastNode)
		return (0);

	maxValue = (*root)->n;

	if (*root == lastNode)
	{
		free(*root);
		*root = NULL;
		return (maxValue);
	}

	(*root)->n = lastNode->n;

	if (lastNode->parent->left == lastNode)
		lastNode->parent->left = NULL;
	else
		lastNode->parent->right = NULL;

	free(lastNode);

	heapifyDown(*root);
	return (maxValue);
}
