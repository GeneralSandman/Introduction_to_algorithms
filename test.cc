#include <iostream>
#include <string>

using namespace std;
#include <vector>
#include <climits>

class Solution
{
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> result;
        if (input.empty())
            return result;
        if (input.size() < k)
            return result;

        result.reserve(k);
        Heap = new int[k];
        for (int i = 0; i < k; i++)
            *(Heap + i) = INT_MAX;
        n = k;
        for (auto t : input)
        {
            insert(t);
        }

        for (int i=0;i<k;i++)
            cout<<*(Heap+i)<<" ";
        cout << endl;

        for (int i = k; i >0; i--)
            result.insert(result.begin(), popMax(i));

        delete[] Heap;
        Heap = nullptr;
        return result;
    }

  private:
    int *Heap;
    int n;
    void insert(int num)
    {
        if (num < *Heap)
        {
            *Heap = num;
            adjust(n);
        }
    }

    void adjust(int end)
    {
        int i = 0;
        int son = 2 * i + 1;

        while (son < end)
        {
            if (son + 1 < end)
            {
                if (*(Heap + son + 1) > *(Heap + son))
                    son++;
            }
            if (*(Heap + i) >= *(Heap + son))
                break;
            swap(*(Heap + i), *(Heap + son));
            i = son;
            son = 2 * i + 1;
        }
    }
    int popMax(int end)
    {
        int res = *Heap;
        swap(*Heap, *(Heap + end - 1));
        adjust(end - 1);
        return res;
    }
};

int main()
{
    class Solution s;
    vector<int> result;
    vector<int> nums = {4, 5, 1, 6, 2, 7, 3, 8};
    result = s.GetLeastNumbers_Solution(nums, 4);

    for (auto t : result)
        cout << t << endl;

    return 0;
}
