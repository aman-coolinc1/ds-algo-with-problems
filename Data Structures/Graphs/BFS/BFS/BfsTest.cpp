#include <gtest/gtest.h>
#include "Bfs.h"

using vector2D = std::vector<std::vector<int>>;
TEST(BFSTest, EmptyTree) {
	TreeNode *root = nullptr;
	vector2D levelOrderTraversal = bfs(root);
	EXPECT_EQ(levelOrderTraversal.size(), 0);
}

class BfsTestWithRoot : public ::testing::Test {
public:
	virtual void SetUp() {
		root = new TreeNode(0);
	}
	TreeNode *root;
};

void checkBfsOutput(const vector2D &expectedlevelOrderTraversal, const vector2D &levelOrderTraversal) {
	EXPECT_EQ(levelOrderTraversal.size(), expectedlevelOrderTraversal.size());
	for (size_t i = 0; i < expectedlevelOrderTraversal.size(); i++)
		for (size_t j = 0; j < expectedlevelOrderTraversal[i].size(); j++)
			EXPECT_EQ(expectedlevelOrderTraversal[i][j], levelOrderTraversal[i][j]);
}

TEST_F(BfsTestWithRoot, level1Tree) {
	vector2D expectedlevelOrderTraversal = { {0} };
	vector2D levelOrderTraversal = bfs(root);
	checkBfsOutput(expectedlevelOrderTraversal, levelOrderTraversal);
}

TEST_F(BfsTestWithRoot, level2TreeWithLeftChild) {
	root->left = new TreeNode(1);
	vector2D expectedlevelOrderTraversal = { {0},{1} };
	vector2D levelOrderTraversal = bfs(root);
	checkBfsOutput(expectedlevelOrderTraversal, levelOrderTraversal);
}

TEST_F(BfsTestWithRoot, level2TreeWithRightChild) {
	root->right = new TreeNode(1);
	vector2D expectedlevelOrderTraversal = { {0},{1} };
	vector2D levelOrderTraversal = bfs(root);
	checkBfsOutput(expectedlevelOrderTraversal, levelOrderTraversal);
}

TEST_F(BfsTestWithRoot, level3TreeWithleftChild) {
	root->left = new TreeNode(1);
	root->left->left = new TreeNode(2);
	vector2D expectedlevelOrderTraversal = { {0},{1},{2} };
	vector2D levelOrderTraversal = bfs(root);
	checkBfsOutput(expectedlevelOrderTraversal, levelOrderTraversal);
}

TEST_F(BfsTestWithRoot, level3TreeWithRightChild) {
	root->right = new TreeNode(1);
	root->right->right = new TreeNode(2);
	vector2D expectedlevelOrderTraversal = { {0},{1},{2} };
	vector2D levelOrderTraversal = bfs(root);
	checkBfsOutput(expectedlevelOrderTraversal, levelOrderTraversal);
}

TEST_F(BfsTestWithRoot, level3TreeWithLeftRightChild) {
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	vector2D expectedlevelOrderTraversal = { {0},{1,2},{3,4} };
	vector2D levelOrderTraversal = bfs(root);
	checkBfsOutput(expectedlevelOrderTraversal, levelOrderTraversal);
}

