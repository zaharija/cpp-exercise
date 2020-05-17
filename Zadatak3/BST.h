#pragma once
#include "IConsolePrintable.h"
class BST : virtual public IConsolePrintable
{
private:
	struct node {
		unsigned long long key;
		std::string text;
		node *left;
		node *right;
	};
	node *root;
	void AddLeafPrivate(unsigned long long key, std::string text, node *Ptr);
	void PrintInOrderPrivate(node *Ptr);
	void PrintPreOrderPrivate(node *Ptr);

public:
	BST();
	node *CreateLeaf(unsigned long long key, std::string text);
	void AddLeaf(unsigned long long key, std::string text);
	void PrintInOrder() override;
	void PrintPreOrder() override;
};

