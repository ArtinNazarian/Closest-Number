#ifndef ClosestNumber_h
#define ClosestNumber_h

#include <fstream>
#include <iostream>
#include <math.h>
#include <climits>

using namespace std;

struct Node
{
	Node *left;
	Node *right;
	int info;
};

class BST
{
public:
	BST()
	{
		root = nullptr;
	}

	void Insert(int x)
	{
		InsertPrivate(root, x);
	}

	void print()
	{
		printPrivate(root);
	}

	bool search(int target)
	{
		bool found;
		found = find(root, target);
		return found;
	}

	int closestNode(int x)
	{
		int minDiff;
		minDiff =closestPrivate(root, x);
		return minDiff;
	}
private:
	void InsertPrivate(Node *&tree, int num)
	{
		if (tree == nullptr)
		{
			tree = new Node;
			tree->right = nullptr;
			tree->left = nullptr;
			tree->info = num;
		}
		else if (num < tree->info)
			InsertPrivate(tree->left, num);
		else if (num > tree->info)
			InsertPrivate(tree->right, num);
	}

	void printPrivate(Node *tree)
	{
		if (tree != nullptr)
		{
			printPrivate(tree->left);
			cout << tree->info <<" ";
			printPrivate(tree->right);
		}
	}

	bool find(Node *tree, int &num)
	{
		Node *parentPtr = nullptr;
		bool found = false;
		while (tree !=nullptr && !found)
		{
			if (num < tree->info)
			{
				parentPtr = tree;
				tree = tree->left;
			}
			else if (num > tree->info)
			{
				parentPtr = tree;
				tree = tree->right;
			}
			else
				found = tree;
		}
		return found;
	}
	int closestPrivate(Node *tree, int num)
	{
		int closest = 0;
		Node *parentPtr = nullptr;
		bool found = false;
		int minDiff= INT_MAX;
		int distance;
		while (tree!=nullptr)
		{
			distance= distance = abs(tree->info - num);
			if (distance < minDiff)
			{
				minDiff = distance;
				closest = tree->info;
			}

			if (distance == 0)
				break;
			if (num < tree->info)
			{
				parentPtr = tree;
				tree = tree->left;
			}
			else if (num > tree->info)
			{
				parentPtr = tree;
				tree = tree->right;
			}
				
		}
		return closest;
	}


	Node *root;
};

#endif // !ClosestNumber_h