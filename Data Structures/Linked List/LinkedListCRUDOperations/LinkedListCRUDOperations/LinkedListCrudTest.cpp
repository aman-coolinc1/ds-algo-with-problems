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

TEST_F(LinkedListCRUDOperationsTest, add_node_after_last_node_in_list) {
	ListNode* new_node = add_node_after(root, create_node(1));
	ListNode* new_node_1 = add_node_after(new_node, create_node(2));
	EXPECT_NE(new_node_1, nullptr);
	EXPECT_EQ(new_node_1, new_node->next);
}

TEST_F(LinkedListCRUDOperationsTest, add_nullptr_after_given_node) {
	EXPECT_ANY_THROW(add_node_after(root, nullptr));
}

TEST_F(LinkedListCRUDOperationsTest, add_node_after_given_node_in_middle_of_list) {
	ListNode* new_node_1 = add_node_after(root, create_node(1));
	ListNode* new_node_2 = add_node_after(new_node_1, create_node(2));
	ListNode* new_node_3 = add_node_after(new_node_2, create_node(3));
	ListNode* new_node_4 = add_node_after(new_node_1, create_node(4));
	EXPECT_NE(new_node_4, nullptr);
	EXPECT_EQ(new_node_4, new_node_1->next);
	EXPECT_EQ(new_node_4->next, new_node_2);
}

class LinkedListSearchOperationsTest : public LinkedListCRUDOperationsTest {
public:
	virtual void SetUp() {
		LinkedListCRUDOperationsTest::SetUp();
		root = add_node_after(root, create_node(1));
		add_node_after(root, create_node(2));
		add_node_after(root, create_node(3));
		add_node_after(root, create_node(4));
	}
	virtual void TearDown() {
		LinkedListCRUDOperationsTest::TearDown();
	}
};

TEST_F(LinkedListSearchOperationsTest, search_for_a_value_in_list) {
	ListNode* found_value = find_value_in_list(root,1);
	EXPECT_EQ(found_value->data, 1);
	found_value = find_value_in_list(root, 3);
	EXPECT_EQ(found_value->data, 3);
	found_value = find_value_in_list(root, 2);
	EXPECT_EQ(found_value->data, 2);
}

TEST_F(LinkedListSearchOperationsTest, search_for_non_existent_value_in_list) {
	ListNode* found_value = find_value_in_list(root, 6);
	EXPECT_EQ(found_value, nullptr);
}

TEST_F(LinkedListCRUDOperationsTest, search_for_value_in_empty_list) {
	ListNode* found_value = find_value_in_list(root, 6);
	EXPECT_EQ(found_value, nullptr);
}

TEST_F(LinkedListCRUDOperationsTest, delete_node_in_front) {
	ListNode* new_node = add_node_after(root, create_node(1));
	ListNode* new_node_1 = add_node_after(new_node, create_node(2));
	ListNode* root = delete_node_after(nullptr, 1);
	EXPECT_EQ(root->data, 2);
}
