#include<iostream>
#include"tree.h"
using namespace std;

int chose_mod(void)
{
	cout << "\n\t\tPlease chose mod of queue!!!\n";
	cout << "\t1)insert\t\t2)preorder\n"
		<< "\t3)inorder\t4)postorder\n"
		<< "\t5)breathfirst\t6)quit the system\n" << endl << endl;
	int m;
	cin >> m;
	return m;
}


//深度优先遍历
void Tree::preorder(TreeNode * pTree)
{
	if (pTree != nullptr) {
		visit(pTree);
		preorder(pTree->left_);
		preorder(pTree->right_);
	}
}

void Tree::inorder(TreeNode *pTree)
{
	if (pTree != nullptr) {
		inorder(pTree->left_);
		visit(pTree);
		inorder(pTree->right_);
	}
}

void Tree::postorder(TreeNode *pTree)
{
	if (pTree != nullptr) {
		postorder(pTree->left_);
		postorder(pTree->right_);
		visit(pTree);
	}
}

int * Tree::search(TreeNode *pTree, const int value) const
{
	while (pTree != nullptr) {

		if (value == pTree->value_)
			return &(pTree->value_);
		else if (value < pTree->value_)
			pTree = pTree->left_;
		else
			pTree = pTree->right_;
	}

	return nullptr;

}
Tree::~Tree()
{
	delete_tree(root);
	cout << "delete tree successfully!!!\n";
}

void Tree::delete_tree(TreeNode * pTree)
{

	if (pTree->left_ == nullptr && pTree->right_ == nullptr)
		delete pTree;

	else if(pTree->left_!=nullptr) 
		delete_tree(pTree->left_);
	else if(pTree->right_!=nullptr)
		delete_tree(pTree->right_);

		
}
//广度优先遍历
void Tree::breathfirst()
{
	TreeQueue<TreeNode *>TreeQueue1;

	TreeNode *p = root;
	if (p != nullptr)
	{
		TreeQueue1.enqueue(p);
		while (TreeQueue1.size() != 0) {
			p = TreeQueue1.dequeue();//key
			visit(p);
			if (p->left_ != 0)
				TreeQueue1.enqueue(p->left_);
			if (p->right_ != 0)
				TreeQueue1.enqueue(p->right_);
		}

	}


}

void Tree::insert(const int & value)
{
	TreeNode *p = root, *prev = nullptr;

	while (p != nullptr) {
		prev = p;
		if (value < p->value_)
			p = p->left_;
		else
			p = p->right_;
	}

	if (root == nullptr)
		root = new TreeNode(value);
	else if (value < prev->value_)
		prev->left_ = new TreeNode(value);
	else
		prev->right_ = new TreeNode(value);
}

void Tree::delete_by_merging(TreeNode * node)
{
	TreeNode * tmp = node;
	if (node != nullptr) {

		if (node->right_ != nullptr)
			node = node->left_;
		else if (node->left_ != nullptr)
			node = node->right_;
		else {
			tmp = node->left_;
			while (tmp->right_ != nullptr) {
				tmp = tmp->right_;
			}

			tmp->right_ = node->right_;
			tmp = node;
			node = node->left_;
		}
	}

	delete tmp;
}

void Tree::find_delete_by_merging(const int &value)
{
	TreeNode *node = root, *prev = nullptr;
	while (node != nullptr) {
		if (node->value_ == value)
			break;
		prev = node;
		if (value < node->value_)
			node = node->left_;
		else
			node = node->right_;
	}

	if (node != nullptr && node->value_ == value) {

		if (node == root)
			delete_by_merging(root);

		else if (prev->left_ == node)
			delete_by_merging(prev->left_);

		else if (prev->right_ == node)
			delete_by_merging(prev->right_);
	}
	else if (!(node->value_ == value))
		cout << "the value " << value << " is not in the tree!!!\n";

	else if (root == nullptr)
		cout << "the tree is empty!!!\n";


}


void Tree::insert_more()
{
	cout << "please input the number of value:\n";
	int number;
	int tmp;
	cin >> number;
	cout << "please input " << number << " value:";
	for (int i = 0; i < number; i++)
	{
		cin >> tmp;
		insert(tmp);
	}

}