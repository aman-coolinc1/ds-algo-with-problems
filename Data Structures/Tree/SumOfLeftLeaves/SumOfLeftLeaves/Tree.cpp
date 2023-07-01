#include "Tree.h"

void sumHelper(TreeNode* root, TreeNode* prev, int& sum) {
	if (!root)	return;
	if (prev && prev->left == root && !root->left && !root->right) {
		sum += root->val;
		return;
	}
	sumHelper(root->left, root, sum);
	sumHelper(root->right, root, sum);
}

int sumOfLeftLeaves(TreeNode* root) {
	int sum{ 0 };
	TreeNode *prev = nullptr;
	sumHelper(root, prev, sum);
	return sum;
}