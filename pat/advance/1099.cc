#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

struct Node
{
    int val;
    int left;
    int right;
};
typedef struct Node Node;

Node tree[100];

void inorderDis(vector<Node *> &result, int index)
{
    if (tree[index].left != -1)
        inorderDis(result, tree[index].left);

    result.push_back(&tree[index]);

    if (tree[index].right != -1)
        inorderDis(result, tree[index].right);
}

void levelDis(vector<int> &result)
{
    int root = 0;
    queue<Node *> level;
    level.push(&tree[root]);

    while (!level.empty())
    {
        int size = level.size();

        for (int i = 0; i < size; i++)
        {
            Node *front = level.front();
            level.pop();
            result.push_back(front->val);

            if (front->left != -1)
                level.push(&tree[front->left]);
            if (front->right != -1)
                level.push(&tree[front->right]);
        }
    }
}

int main()
{
    memset(tree, -1, sizeof(tree));
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> tree[i].left >> tree[i].right;
    }

    vector<int> weight;
    for (int i = 0; i < num; i++)
    {
        int tmp;
        cin >> tmp;
        weight.push_back(tmp);
    }

    vector<Node *> inorder;
    inorderDis(inorder, 0);
    sort(weight.begin(), weight.end());

    for (int i = 0; i < num; i++)
        inorder[i]->val = weight[i];

    vector<int> result;
    levelDis(result);

    if (result.empty())
        return 0;

    cout << result[0];
    for (int i = 1; i < result.size(); i++)
        cout << " " << result[i];
    cout << endl;

    return 0;
}