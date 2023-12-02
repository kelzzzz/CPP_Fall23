#pragma once
#include "TreeNode.h"
class BinaryTree
{

public:
	BinaryTree(int root);
	TreeNode* root;
	int incrementingIdx = 0;
	TreeNode* createNode(int data);

	void recursivelyPrintTreePreorder(struct TreeNode* node);
	void recursivelySearchTree(struct TreeNode* node, int searchFor);
	void insertNodeIntoFirstAvailable(TreeNode* root, int data);
	int recursivelyFindMaximum(struct TreeNode* node);
	int recursivelyFindMinimum(struct TreeNode* node);
	void deleteNodeByData(struct TreeNode* node, int searchFor);
	void deleteNodeByIdx(struct TreeNode* node, int idx);
	TreeNode* popDeepestRightMostNode(TreeNode* root);
};

