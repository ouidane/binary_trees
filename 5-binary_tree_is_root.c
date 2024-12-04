#include "binary_trees.h"

/**
 * binary_tree_is_root - Determines if a node is the root of a binary tree.
 * @node: Pointer to the node to evaluate.
 *
 * Return: 1 if the node is the root (has no parent), 0 otherwise.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
