#include <gtest/gtest.h>
#include "Tree.h"

class SumOfLeftLeavesTest : public ::testing::Test {
public:
	virtual void SetUp() {
		root = new TreeNode(1);
	}
	TreeNode *root;
};

TEST_F(SumOfLeftLeavesTest, OnlyOneNode) {
	EXPECT_EQ(0,sumOfLeftLeaves(root));
}

TEST_F(SumOfLeftLeavesTest, rootNodeWithLeftLeaf) {
	root->left = new TreeNode(2);
	EXPECT_EQ(2, sumOfLeftLeaves(root));
}

TEST_F(SumOfLeftLeavesTest, rootNodeWithLeftLeftLeaf) {
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	EXPECT_EQ(3, sumOfLeftLeaves(root));
}

TEST_F(SumOfLeftLeavesTest, rootNodeWithLeftRightLeftLeaf) {
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(3);
	root->left->right->left = new TreeNode(4);
	EXPECT_EQ(4, sumOfLeftLeaves(root));
}

TEST_F(SumOfLeftLeavesTest, rootNodeWithRightRightLeftLeaf) {
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(3);
	root->right->right->left = new TreeNode(4);
	EXPECT_EQ(4, sumOfLeftLeaves(root));
}

TEST_F(SumOfLeftLeavesTest, rootNodeWithRightRightRightLeaf) {
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(3);
	root->right->right->right = new TreeNode(4);
	EXPECT_EQ(0, sumOfLeftLeaves(root));
}