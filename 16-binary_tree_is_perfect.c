#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the binary tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}

/**
 * depth - Returns the number of edges between a given node and the root
 * of the tree it belongs to.
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The number of edges between the node and the tree root.
 */
size_t depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	while (tree != NULL)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}

/**
 * get_leaf - Finds a leaf node in the tree.
 *
 * @tree: root node of the tree
 *
 * @return: a leaf node
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	if (tree->left)
		return get_leaf(tree->left);
	return get_leaf(tree->right);
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 * @tree: Pointer to the root node of the tree.
 * @leaf_depth: The depth of one leaf in the tree.
 * @level: The level of the current node.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * is_leaf - Checks if a node is a leaf node in a binary tree.
 * @node: The node to check.
 *
 * @return: 1 if node is a leaf node, 0 otherwise.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}
