#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<queue>
using namespace std;

int chose_mod(void);
template<class T>
class TreeQueue :public queue<T>{
public:
	T dequeue() {
		T tmp = front();
		queue<T>::pop();
		return tmp;
	}
	void enqueue(const T & value) { queue<T>::push(value); }
};

class TreeNode {
	friend class Tree;
private:
	int value_;
	TreeNode * left_;
	TreeNode * right_;
public:
	TreeNode() { left_ = right_ = nullptr; }
	TreeNode(const int & value, TreeNode * left=nullptr, TreeNode * right=nullptr) {
		left_ = left;
		right_ = right;
		value_ = value;
	}
};
 
class Tree {
protected:
	TreeNode * root;

	void preorder(TreeNode *);//深度优先遍历
	void inorder(TreeNode *);
	void postorder(TreeNode *);

	int * search(TreeNode *, const int value)const;

	virtual void visit(TreeNode * pTree) { cout << pTree->value_ << " "; }
public:
	Tree() { root = 0; }
	~Tree();
	void delete_tree(TreeNode *);
	bool isEmpty(){return root == nullptr;}
	void preordder() { preorder(root); }
	void inorder() { inorder(root); }
	void postorder() { postorder(root); }

	int * search(const int & value)const {return search(root, value);}

	void breathfirst();//广度优先遍历
	void insert(const int &);
	void delete_by_merging(TreeNode *);
	void find_delete_by_merging(const int &);

	void insert_more();
};






#endif