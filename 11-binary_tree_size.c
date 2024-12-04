#include "binary_trees.h"

/**
 * calculate_binary_tree_size - Computes the total number of nodes
 * in a binary tree.
 * @tree: Pointer to the root node of the tree being measured.
 *
 * Return: Total node count, or 0 if the tree is empty.
 */
size_t calculate_binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return 0;

	return 1 + calculate_binary_tree_size(tree->left) + calculate_binary_tree_size(tree->right);
}