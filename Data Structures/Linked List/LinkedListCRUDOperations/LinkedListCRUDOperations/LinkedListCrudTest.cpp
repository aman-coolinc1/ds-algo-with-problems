#include "gtest/gtest.h"
#include "LinkedListCRUDOperations.h"

using namespace std;

class LinkedListCRUDOperationsTest :public ::testing::Test {
public:
	virtual void SetUp() {
		root = nullptr;
	}
	virtual void TearDown() {
		ListNode *temp = root;
		while (root) {
			delete root;
			root = temp->next;
			temp = temp->next;
		}
	}

protected:
	ListNode* root;
};

TEST_F(LinkedListCRUDOperationsTest, add_node_to_front_of_existing_list) {
	root = add_node_to_front(root, create_node(1));
	root = add_node_to_front(root, create_node(2));
	EXPECT_EQ(root->data, 2);
}

TEST_F(LinkedListCRUDOperationsTest, add_node_after_given_empty_list) {
	ListNode* new_node = add_node_after(root, create_node(1));
	EXPECT_EQ(new_node->data,1);
}

TEST_F(LinkedListCRUDOperationsTest, add_node_after_given_node_in_list) {
	ListNode* new_node = add_node_after(root, create_node(1));
	ListNode* new_node_1 = add_node_after(new_node, create_node(2));
	EXPECT_NE(new_node_1, nullptr);
	EXPECT_EQ(new_node_1, new_node->next);
}

TEST_F(LinkedListCRUDOperationsTest, add_nullptr_after_given_node) {
	EXPECT_ANY_THROW(add_node_after(root, nullptr));
}