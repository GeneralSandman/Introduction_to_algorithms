#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

int getHeight(Node *node)
{
    if (node == nullptr)
        return 0;
    return max(getHeight(node->right), getHeight(node->left)) + 1;
}

Node *leftRotate(Node *node)
{
    Node *tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    return tmp;
}

Node *rightRotate(Node *node)
{
    Node *tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    return tmp;
}

Node *insert(Node *root, int data)
{
    if (root == nullptr)
    {
        root = new Node;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
        if (getHeight(root->left) - getHeight(root->right) == 2)
        {
            if (getHeight(root->left->left) - getHeight(root->left->right) == 1)
            {
                root = rightRotate(root);
            }
            else
            {
                root->left = leftRotate(root->left);
                root = rightRotate(root);
            }
        }
    }
    else
    {
        root->right = insert(root->right, data);
        if (getHeight(root->right) - getHeight(root->left) == 2)
        {
            if (getHeight(root->right->right) - getHeight(root->right->left) == 1)
            {
                root = leftRotate(root);
            }
            else
            {
                root->right = rightRotate(root->right);
                root = leftRotate(root);
            }
        }
    }

    return root;
}

Node *root = nullptr;

bool complete;
bool last;

int main()
{

    complete = true;
    last = false;

    int size;
    cin >> size;

    int tmp;
    for (int i = 0; i < size; i++)
    {
        cin >> tmp;
        root = insert(root, tmp);
    }

    int maxHeight = getHeight(root);

    int curLevel = 0;
    bool flag = true;

    queue<Node *> level;
    vector<int> result;
    level.push(root);

    while (!level.empty())
    {
        int size = level.size();
        if (curLevel + 1 != maxHeight && size != pow(2, curLevel))
            flag = false;

        for (int i = 0; i < size; i++)
        {
            Node *front = level.front();
            result.push_back(front->data);
            if (front->left)
                level.push(front->left);
            if (front->right)
                level.push(front->right);
            level.pop();

            if (!front->left && front->right)
                complete = false;

            if (last && (front->left || front->right))
                complete = false;

            if (!front->left || !front->right)
                last = true;
        }

        curLevel++;
    }

    if (result.size() >= 1)
    {
        cout << result[0];
        for (int i = 1; i < result.size(); i++)
        {
            cout << " " << result[i];
        }
        cout << endl;

        if (complete)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
    {
        cout << endl
             << "NO\n";
    }

    return 0;
}