


namespace RBtree
{

using namespace Tree;

class RBNode : public BinaryTreeNode
{
private:
  typedef enum { red,
                 black } color;
  color m_nColor;
};

class RBTree
{
private:
  void m_fLeftRotate(RBNode *);
  void m_fRightRotate(RBNode *);

public:
  RBNode *GrandParent(RBNode *);
  RBNode *Uncle(RBNode *);
};
}