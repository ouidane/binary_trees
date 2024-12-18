#include "binary_trees.h"

/**
 * binary_tree_size - Computes the total number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree being measured.
 *
 * Return: Total node count, or 0 if the tree is empty.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}

	return (size);
}
