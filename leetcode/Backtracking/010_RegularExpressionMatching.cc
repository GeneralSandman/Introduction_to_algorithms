#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        bool result = false;
        result = match(s, 0, p, 0);
        return result;
    }

  private:
    bool match(string &s, int b1, string &p, int b2)
    {
        if (b1 == s.size() && b2 == p.size())
            return true;
        if (b1 == s.size())
        {
            if ((p.size() - b2) % 2 != 0)
            {
                return false;
            }
            for (int i = b2 + 1; i < p.size(); i += 2)
            {
                if (p[i] != '*')
                {
                    return false;
                }
            }

            return true;
        }

        if (b2 == p.size())
            return false;
        if (p.size() - b2 > 1 && p[b2 + 1] == '*')
        {
            if (p[b2] == '.' || p[b2] == s[b1])
            {
                return match(s, b1 + 1, p, b2) || match(s, b1, p, b2 + 2);
            }
            else
                return match(s, b1, p, b2 + 2);
        }
        else
        {
            if (p[b2] == s[b1] || p[b2]=='.')
                return match(s, b1 + 1, p, b2 + 1);
            else
                return false;
        }
    }
};

int main()
{
    Solution a;
    string s;
    string p;
    cin >> s;
    cin >> p;
    if (a.isMatch(s, p))
    {
        cout << "successfully\n";
    }
    else
        cout << "failed\n";

    return 0;
}
