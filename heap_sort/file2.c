/**
 * iParent - Calculate the parent index
 * @i: Current index
 *
 * Return: Index of the parent
 */
int iParent(int i)
{
	return ((i - 1) / 2);
}

/**
 * iLeftChild - Calculate the left child index
 * @i: Current index
 *
 * Return: Index of the left child
 */
int iLeftChild(int i)
{
	return (2 * i + 1);
}
