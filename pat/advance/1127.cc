#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef struct Node
{
    int val;
    Node *left;
    Node *right;
} Node;

int inorder[30];
int postorder[30];

Node *create(int begin1, int end1, int begin2, int end2)
{
    if (begin1 > end1 || begin2 > end2)
        return nullptr;

    Node *node = new Node;
    node->val = postorder[end2];

    int middle = begin1;
    while (inorder[middle] != postorder[end2])
        middle++;

    int left_size = middle - begin1;
    int right_size = end1 - middle;

    node->left = create(begin1, middle - 1,
                        begin2, begin2 + left_size - 1);
    node->right = create(middle + 1, end1,
                         begin2 + left_size, end2 - 1);
}

void levelOrder(Node *node, vector<vector<int>> &result, int level)
{
    if (node == nullptr)
        return;

    if (level > result.size())
    {
        result.push_back(vector<int>());
    }
    result[level - 1].push_back(node->val);
    levelOrder(node->left, result, level + 1);
    levelOrder(node->right, result, level + 1);
}

void deleteTree(Node *node, int &count)
{

    if (node == nullptr)
        return;

    if (node->left)
        deleteTree(node->left, count);
    if (node->right)
        deleteTree(node->right, count);

    delete node;
    count++;
}

int main()
{
    int count = 0;
    int nums;
    cin >> nums;

    for (int i = 0; i < nums; i++)
        cin >> inorder[i];
    for (int i = 0; i < nums; i++)
        cin >> postorder[i];

    Node *root = create(0, nums - 1, 0, nums - 1);

    vector<vector<int>> result;
    vector<int> res;
    levelOrder(root, result, 1);
    // cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
    {
        // for (auto t : result[i])
        //     cout << t << " ";
        // cout << endl;
        if (i % 2 == 0)
            copy(result[i].rbegin(), result[i].rend(), back_inserter(res));
        else
            copy(result[i].begin(), result[i].end(), back_inserter(res));
    }

    if (res.empty())
        return 0;
    cout << res[0];
    for (int i = 1; i < res.size(); i++)
        cout << " " << res[i];
    // cout << endl;
    deleteTree(root, count);
    return 0;
}