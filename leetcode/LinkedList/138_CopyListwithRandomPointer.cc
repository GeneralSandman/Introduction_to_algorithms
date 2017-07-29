#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
  private:
    map<RandomListNode *, RandomListNode *> copyed;

  public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (!head)
            return nullptr;

        RandomListNode *newhead = new RandomListNode(head->label);
        copyed[head] = newhead;
        RandomListNode *tmp = head->next;
        RandomListNode *pre=newhead;
        while (tmp)
        {
            copyed[tmp] = new RandomListNode(tmp->label);
            pre->next=copyed[tmp];
            tmp = tmp->next;
            pre=pre->next;
        }

        RandomListNode *a = head;
        RandomListNode *b = newhead;
        while (a && b)
        {
            if (a->random)
                b->random = copyed[a->random];
            a = a->next;
            b = b->next;
        }

        return newhead;
    }
};

class Solution2
{
  public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (!head)
            return nullptr;
    }
};

class Solution3
{
  public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (!head)
            return nullptr;
    }
};

int main()
{
    Solution a;

    return 0;
}
