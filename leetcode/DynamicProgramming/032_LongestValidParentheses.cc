#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <stack>

using namespace std;

class Solution1
{
  public:
    int longestValidParentheses(string s)
    {
        stack<int> res;
        res.push(-1);

        int ma = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int t = res.top();

            if (t != -1 && s[t] == '(' && s[i] == ')')
            {
                res.pop();
                int tmp = i - res.top();
                ma = max(tmp, ma);
            }
            else
            {
                res.push(i);
            }
        }

        return ma;
    }
};

class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        stack<int> res;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                res.push(i);

            else
            {
                if (!res.empty())
                {
                    if (s[res.top()] == '(')
                        res.pop();
                    else
                        res.push(i);
                }
                else

                    res.push(i);
            }
        }

        int result = 0;
        if (res.empty())
            return s.size();

        int end = s.size();
        int begin = 0;

        while (!res.empty())
        {
            begin = res.top();

            result = max(result, end - begin - 1);
            end = begin;
            res.pop();
        }
        result = max(result, end - 0);

        return result;
    }
};

int main()
{
    Solution a;
    cout << a.longestValidParentheses(")(") << endl;
    cout << a.longestValidParentheses("())") << endl;
    cout << a.longestValidParentheses(")()())()()(") << endl;
    cout << a.longestValidParentheses("()(()(()()(()()()") << endl;
    cout << a.longestValidParentheses("()(()") << endl;
    cout << a.longestValidParentheses("(") << endl;
    cout << a.longestValidParentheses("()(())") << endl;
    // result=6

    return 0;
}

// ()(()
// ()(()(()()(()()()