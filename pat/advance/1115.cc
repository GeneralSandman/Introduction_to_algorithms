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

void insert(Node *&root, int val)
{
    if (root == nullptr)
    {
        root = new Node;
        root->val = val;
        root->left = nullptr;
        root->right = nullptr;
        // cout << "new Node " << val << endl;
    }
    else
    {
        if (root->val < val)
        {
            insert(root->right, val);
        }
        else
        {
            insert(root->left, val);
        }
    }
}

void levelOrder(Node *root, vector<int> &result)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        result.push_back(size);
        // cout << size << endl;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
}

int main()
{
    int nums;
    cin >> nums;

    Node *root = nullptr;
    for (int i = 0; i < nums; i++)
    {
        int tmp;
        cin >> tmp;
        insert(root, tmp);
    }

    vector<int> result;
    levelOrder(root, result);

    int index = result.size() - 1;
    int all = 0;

    if (index >= 0)
    {
        cout << result[index] << " + ";
        all += result[index];
    }
    else
    {
        cout << "0 + ";
    }

    index--;

    if (index >= 0)
    {
        cout << result[index] << " = ";
        all += result[index];
    }
    else
    {
        cout << "0 = ";
    }

    cout << all;

    return 0;
}