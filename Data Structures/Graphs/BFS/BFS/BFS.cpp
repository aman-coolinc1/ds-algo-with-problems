#include <iostream>
#include <queue>
#include "Bfs.h"

std::vector<std::vector<int>> bfs(TreeNode* root) {
	std::vector<std::vector<int>> levelOrderTraversal;
	if (root == nullptr)
		return levelOrderTraversal;
	std::queue<std::pair<TreeNode*,int>> bfsQ;
	int curLevel = 0;
	std::vector<int> curLevelTraversal;
	bfsQ.push(std::make_pair(root,0));
	while (!bfsQ.empty()) {
		std::pair<TreeNode*,int> front = bfsQ.front();
		bfsQ.pop();
		if (front.second != curLevel) {
			curLevel = front.second;
			levelOrderTraversal.push_back(curLevelTraversal);
			curLevelTraversal.clear();
		}
		curLevelTraversal.push_back(front.first->val);
		if (front.first->left)bfsQ.push(std::make_pair(front.first->left, front.second + 1));
		if (front.first->right)bfsQ.push(std::make_pair(front.first->right, front.second + 1));
	}
	levelOrderTraversal.push_back(curLevelTraversal);
	return levelOrderTraversal;
}
