#include <iostream>

using namespace std;

struct ListNode {
	int data;
	ListNode *next;

	ListNode(int data) :data(data), next(nullptr) {}
	ListNode(int data, ListNode* next) :data(data), next(next) {}
};

void printList(ListNode* root) {
	if (!root) {
		cout << "List is empty" << endl;
		return;
	}
	cout << "List: " << endl;
	ListNode* cur = root;
	while (cur->next) {
		cout << cur->data << "->";
		cur = cur->next;
	}
	cout << cur->data;
	cout << endl;
}

ListNode* insertInFront(ListNode* root, int data) {
	ListNode *newNode = new ListNode(data);
	if (root != nullptr) {
		newNode->next = root;
	}
	return newNode;
}

int main() {
	ListNode *root = nullptr;
	root = insertInFront(root, 1);
	root = insertInFront(root, 2);
	root = insertInFront(root, 3);
	printList(root);
	return 0;
}