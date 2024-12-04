#include "binary_trees.h"

/**
 * Measured the height of a binary tree, i.e. the number of nodes along
 * the longest path from the root node down to the farthest leaf node.
 * @tree: The root node of the tree to measure.
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef = 0, rig = 0;

		lef = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		rig = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		return ((lef > rig) ? lef : rig);
	}

	return (0);
}
