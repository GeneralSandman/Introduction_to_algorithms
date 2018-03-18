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
    bool black;
    Node *left;
    Node *right;
} Node;

int preorder[30];

Node *create(int begin, int end)
{
    if (begin > end)
        return nullptr;

    Node *node = new Node;
    node->val = abs(preorder[begin]);
    node->black = preorder[begin] > 0 ? true : false;

    // cout << "new node " << node->val;
    // if (node->black)
    //     cout << "  black\n";
    // else
    //     cout << "  red\n";

    int middle = begin + 1;

    while (middle <= end && abs(preorder[middle]) < abs(preorder[begin]))
        middle++;

    node->left = create(begin + 1, middle - 1);
    node->right = create(middle, end);

    return node;
}

void deleteTree(Node *node)
{
    if (node == nullptr)
        return;

    if (node->left)
        deleteTree(node->left);
    if (node->right)
        deleteTree(node->right);

    // cout << "delete node " << node->val << endl;
    delete node;
}

bool dfs(Node *root, int blackNum, int &maxBlackNum)
{
    if (root == nullptr)
    {
        if (maxBlackNum == 0)
        {
            // cout << "curNum:" << blackNum << "max:" << maxBlackNum << endl;
            maxBlackNum = max(maxBlackNum, blackNum);
            return true;
        }
        else
        {
            // cout << "curNum:" << blackNum << "max:" << maxBlackNum << endl;
            return maxBlackNum == blackNum;
        }
    }

    if (root->black)
    {
        blackNum++;
    }
    else
    {
        //red
        if ((root->left != nullptr && !root->left->black) ||
            (root->right != nullptr && !root->right->black))
        {
            // cout << root->val << "is red have red sons\n";
            // if (root->left)
            //     cout << root->left->val << " ";
            // if (root->right)
            //     cout << root->right->val;
            // cout << endl;
            return false;
        }
    }

    return dfs(root->left, blackNum, maxBlackNum) &&
           dfs(root->right, blackNum, maxBlackNum);
}

bool test(Node *root)
{
    if (root == nullptr)
        return false;
    if (!root->black)
        return false;

    int blackNum = 0;
    int maxBlackNum = 0;
    return dfs(root, blackNum, maxBlackNum);
}

int main()
{

    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        memset(preorder, 0, sizeof(preorder));

        int size;
        cin >> size;
        for (int j = 0; j < size; j++)
            cin >> preorder[j];

        Node *root = create(0, size - 1);
        if (test(root))
            cout << "Yes\n";
        else
            cout << "No\n";
        deleteTree(root);
    }

    return 0;
}