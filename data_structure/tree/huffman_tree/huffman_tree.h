

namespace Huffman
{
using namespace std;

class Node
{
private:
  char m_nChar;
  int m_nFrequency;

public:
  Node(char Char, int Frequency) : m_nChar(Char), m_nFrequency(Frequency) {}
  ~Node(){};
};

class Code
{
private:
  char m_nChar;
  vector<int> m_nCode;

public:
  Code(char Char, vector<int> &Code) : m_nChar(Char), m_nCode(Code) {}
  ~Code(){};
};

class HuffmanNode
{
private:
  char m_nChar;
  int m_nFrequency;
  HuffmanNode *m_pParent;
  HuffmanNode *m_pLeft;
  HuffmanNode *m_pRight;

public:
  HuffmanNode(const Node &);
  HuffmanNode(HuffmanNode &, HuffmanNode &);
  ~HuffmanNode(){};
};

class HuffmanTree
{
private:
  bool m_fCompare(HuffmanNode *, HuffmanNode *);
  priority_queue<HuffmanNode, vector<HuffmanNode>, decltype(m_fCompare)> m_nQueue;
  HuffmanNode *m_pRoot;

public:
  HuffmanTree(vector<Node> &);
  //continue
  void GenerateCode(HuffmanNode *, vector<int> &);
  ~HuffmanTree();
};
}