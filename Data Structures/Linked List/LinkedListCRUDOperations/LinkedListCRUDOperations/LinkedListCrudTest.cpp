#include "gtest/gtest.h"
#include "LinkedListCRUDOperations.h"

TEST(LinkedListCRUDOperations, create_new_node) {
	ListNode* root = create_node(10);
	EXPECT_EQ(root->data, 10);
}