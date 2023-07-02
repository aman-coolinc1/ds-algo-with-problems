#include <gtest/gtest.h>
#include "Tree.h"

class HeightOfTreeTest : public ::testing::Test {
public:
	virtual void SetUp() {
		root = new TreeNode(1);
	}
	TreeNode* root;
};

TEST_F(HeightOfTreeTest, nullRoot) {
	EXPECT_EQ(0, maxDepth(nullptr));
}

TEST_F(HeightOfTreeTest, notNullRoot) {
	EXPECT_EQ(1, maxDepth(root));
}

TEST_F(HeightOfTreeTest, leftChild) {
	root->left = new TreeNode(2);
	EXPECT_EQ(2, maxDepth(root));
}

TEST_F(HeightOfTreeTest, rightChild) {
	root->right = new TreeNode(2);
	EXPECT_EQ(2, maxDepth(root));
}

TEST_F(HeightOfTreeTest, leftrightChild) {
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(3);
	EXPECT_EQ(3, maxDepth(root));
}

TEST_F(HeightOfTreeTest, rightleftChild) {
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	EXPECT_EQ(3, maxDepth(root));
}

TEST_F(HeightOfTreeTest, rightleftAndleftrightleftChild) {
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	root->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->left->right->left = new TreeNode(6);
	EXPECT_EQ(4, maxDepth(root));
}
