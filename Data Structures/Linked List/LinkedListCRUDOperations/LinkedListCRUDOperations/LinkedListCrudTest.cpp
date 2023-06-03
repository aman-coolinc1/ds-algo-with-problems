#include "gtest/gtest.h"
#include "LinkedListCRUDOperations.h"

TEST(LinkedListCRUDOperations, create_new_node) {
	ListNode* root = create_node(0);
	EXPECT_EQ(root->data, 0);
}

TEST(LinkedListCRUDOperations, add_node_to_front) {
	ListNode *root = create_node(0);
	root = add_node_to_front(root, create_node(1));
	EXPECT_EQ(root->data, 1);
}