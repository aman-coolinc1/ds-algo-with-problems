#pragma once
struct ListNode {
	int data;
	ListNode *next;

	ListNode(int data) :data(data), next(nullptr) {}
	ListNode(int data, ListNode* next) :data(data), next(next) {}
};

ListNode* create_node(int val);
ListNode* add_node_to_front(ListNode*, ListNode*);
ListNode* add_node_after(ListNode*, ListNode*);