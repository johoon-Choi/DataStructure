#include <stdio.h>
#include <malloc.h>

typedef int E;

typedef struct Node {
	E data;
	struct Node* parent;
	struct Node* left_child;
	struct Node* right_child;
} Node;

Node* makeNode(const E Data) {
	Node* ret = (Node*)malloc(sizeof(Node));
	ret->data = Data;
	ret->parent = ret->left_child = ret->right_child = NULL;
	return ret;
}

void insertNode(Node* parentNode, Node* curNode, const E Data) {
	if (curNode != NULL) {
		if (Data <= curNode->data) {
			insertNode(curNode, curNode->left_child, Data);
		}
		else { // curNode->data < Data
			insertNode(curNode, curNode->right_child, Data);
		}
	}
	else {
		curNode = makeNode(Data);
		curNode->parent = parentNode;
		curNode->left_child = curNode->right_child = NULL;
		if (Data <= curNode->parent->data) curNode->parent->left_child = curNode;
		else curNode->parent->right_child = curNode;
	}
}

void find(Node* curNode, const E tar) {
	if (curNode != NULL) {
		if (tar < curNode->data)
			find(curNode->left_child, tar);
		else if (curNode->data < tar)
			find(curNode->right_child, tar);
		else {
			printf(" Found target value!\n");
			return;
		}
	}
	else printf(" There is no target value\n");
}

Node* root;

int main() {
	root = makeNode(5);
	insertNode(NULL, root, 7);
	find(root, 7);
	//printf("%d\n", root->right_child->data);
	//printf("%p\n", root->left_child);
	//printf("%p\n", root->right_child->left_child);
}

/*
	* 이미 존재하는 값이 입력 될 경우 -> left child
*/
