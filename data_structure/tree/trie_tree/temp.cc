#include <iostream>
#include<cstring>
using namespace std;

/* trie的节点类型 */
template <int Size> //Size为字符表的大小
struct trie_node 
{
    bool terminable; //当前节点是否可以作为字符串的结尾
    int node; //子节点的个数
    trie_node *child[Size]; //指向子节点指针

    /* 构造函数 */
    trie_node() : terminable(false), node(0) { memset(child, 0, sizeof(child)); }
};

/* trie */
template <int Size, typename Index> //Size为字符表的大小，Index为字符表的哈希函数
class trie 
{
public:
    /* 定义类型别名 */
    typedef trie_node<Size> node_type;
    typedef trie_node<Size>* link_type;
    template <typename Iterator>
    bool erase(Iterator begin, Iterator end) 
    {
        bool result; //用于存放搜索结果
        erase_node(begin, end, root, result);
        return result;
    }

private:

    /* 边搜索边删除冗余节点，返回值用于向其父节点声明是否该删除该节点 */
    template <typename Iterator>
    bool erase_node(Iterator begin, Iterator end, node_type &cur, bool &result) 
    {
        if (begin == end) //当到达字符串结尾：递归的终止条件
        { 
            result = cur.terminable; //如果当前节点可以作为终止字符，那么结果为真
            cur.terminable = false;  //设置该节点为不可作为终止字符，即删除该字符串
            return cur.node == 0;    //若该节点为树叶，那么通知其父节点删除它
        }
        //当无法匹配当前字符时，将结果设为假并返回假，即通知其父节点不要删除它
        if (cur.child[index[*begin]] == 0) return result = false; 
        //判断是否应该删除该子节点
        else if (erase_node((++begin)--, end, *(cur.child[index[*begin]]), result)) 
        { 
            delete cur.child[index[*begin]]; //删除该子节点
            cur.child[index[*begin]] = 0; //子节点数减一
            //若当前节点为树叶，那么通知其父节点删除它
            if (--cur.node == 0 && cur.terminable == false) return true; 
        }
        return false; //其他情况都返回假
    }

    /* 根节点 */
    node_type root;

    /* 将字符转换为索引的转换表或函数对象 */
    Index index;
};