#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


namespace Huffman{
class HuffmanNode{
private:
	int m_nValue;
	HuffmanNode * m_pLeft;
	HuffmanNode * m_pRight;
public:
	HuffmanNode(int value);
	~HuffmanNode();
}


class Node{
private:
	char m_nChar;
	int m_nFrequent;
public:
	Node(char Char,Frequent):m_nChar(Char),m_nFrequent(Frequent){}
	~Node();
}


class HuffmanTree{
friend class HuffmanNode;
friend class Node;
private:
	HuffmanNode * m_pRoot;
	queue<Node> m_nPriorityQueue;
	bool m_fCompare(HuffmanNode *,HuffmanNode*);
	void m_fConstruct();
public:
	HuffmanTree(vector<Node> &);
	
	~HuffmanTree();
}

}


namespace HuffmanTree{

	HuffmanTree::HuffmanTree(vector<Node> & source){
		for(int i=0;i<source.size();i++){
			m_nPriorityQueue.push_back();
		}	
	
	}

	bool HuffmanTree::m_fCompare(HuffmanNode * node1,HuffmanNode * node2){
		return node1->m_nValue<node2->m_nValue;
	}

}







void HuffmanTest(void){

	vector<Node> inode;
	inode.push_back(Node('a',4));
	inode.push_back(Node('e',4));
	inode.push_back(Node('f',3));
	inode.push_back(Node('h',2));
	inode.push_back(Node('i',2));
	inode.push_back(Node('m',2));
	inode.push_back(Node('n',2));
	inode.push_back(Node('s',2));
	inode.push_back(Node('t',2));
	inode.push_back(Node('l',1));
	inode.push_back(Node('o',1));
	inode.push_back(Node('p',1));
	inode.push_back(Node('r',1));
	inode.push_back(Node('u',1));
	inode.push_back(Node('x',1));
	inode.push_back(Node(' ',7));

	HuffmanTree htree(inode);
	cout<<"the huffman code is:\n";
	htree.PrintCode();
}




int main(){

	HuffmanTest();

	return 0;

}
