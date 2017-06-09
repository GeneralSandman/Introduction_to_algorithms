#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        if (n == 0)
            return result;
        gen(result, n);
        sort(result.begin(),result.end());
        auto p=unique(result.begin(),result.end());
        result.erase(p,result.end());
        return result;
    }

  private:
    void gen(vector<string> &result, int n)
    {
        if (n == 1)
        {
            string tmp = "()";
            result.push_back(tmp);
            return;
        }
        gen(result, n - 1);

        vector<string> res = result;
        result.erase(res.begin(), res.end());

        for (auto t : res)
        {

            for (int i = 0; i < t.size(); i++)
            {
                string tmp;
                for (int j = 0; j < i; j++)
                    tmp += t[j];
                tmp += "()";
                for (int j = i; j < t.size(); j++)
                    tmp += t[j];
                result.push_back(tmp);
            }
        }
    }
};

int main()
{
    Solution a;
    int n;
    cin >> n;
    vector<string> result = a.generateParenthesis(n);
    for (auto t : result)
        cout << t << endl;
    return 0;
}
