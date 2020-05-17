#include <iostream>
#include <string>
#include<stack>
#include "BST.h"

BST::BST() { root = NULL; }

BST::node *BST::CreateLeaf(unsigned long long key, std::string text) {
	node *n = new node;
	n->key = key;
	n->text = text;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void BST::AddLeaf(unsigned long long key, std::string text) {
	AddLeafPrivate(key, text, root);
}

void BST::AddLeafPrivate(unsigned long long key, std::string text, node *Ptr) {
	if (root == NULL) {
		root = CreateLeaf(key, text);
	}
	else if (key < Ptr->key) {
		if (Ptr->left != NULL) {
			AddLeafPrivate(key, text, Ptr->left);
		}
		else {
			Ptr->left = CreateLeaf(key, text);
		}
	}
	else if (key > Ptr->key) {
		if (Ptr->right != NULL) {
			AddLeafPrivate(key, text, Ptr->right);
		}
		else {
			Ptr->right = CreateLeaf(key, text);
		}
	}
	else {
		std::cout << "The key " << key << " has already been added." << std::endl;
	}
}

void BST::PrintInOrder() {
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node *Ptr) {
	if (root != NULL) {
		if (Ptr->right != NULL) {
			PrintInOrderPrivate(Ptr->right);
		}
		std::cout << Ptr->text << std::endl;

		if (Ptr->left != NULL) {
			PrintInOrderPrivate(Ptr->left);
		}
	}
	else {
		std::cout << "The tree is empty." << std::endl;
	}
}

void BST::PrintPreOrder() {
	PrintPreOrderPrivate(root);
}

void BST::PrintPreOrderPrivate(node *Ptr) {
	if (root != NULL) {
		std::stack<node*> stack;
		stack.push(Ptr);
		while (!stack.empty())
		{
			node *curr = stack.top();
			std::cout << curr->text << std::endl;
			stack.pop();

			if (curr->right)
			{
				stack.push(curr->right);
			}
			if (curr->left)
			{
				stack.push(curr->left);
			}
		}
	}
}