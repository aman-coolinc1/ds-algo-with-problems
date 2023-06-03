#include "gtest/gtest.h"
#include "LinkedListCRUDOperations.h"

TEST(LinkedListCRUDOperations, create_new_node) {
	ListNode* root = create_node(10);
	EXPECT_EQ(root->data, 10);
}

TEST(LinkedListCRUDOperations, add_node_to_front) {
	ListNode *root = create_node(10);
	root = add_node_to_front(root, create_node(20));
}