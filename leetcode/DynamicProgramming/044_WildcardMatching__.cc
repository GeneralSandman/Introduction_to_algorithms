#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;

class Solution1
{
  public:
    bool isMatch(string s, string p)
    {
        bool result = false;

        result = match(s, 0, p, 0);
        return result;
    }

  private:
    bool match(string &s, int a, string &p, int b)
    {
        if (a == s.size() && b == p.size())
            return true;
        if (a == s.size())
        {
            if (p[b] == '*')
                return match(s, a, p, b + 1);
            else
                return false;
        }

        if (b == p.size())
            return false;

        if (p[b] == '*')
        {
            return match(s, a + 1, p, b) || match(s, a + 1, p, b + 1) || match(s, a, p, b + 1);
        }
        else if (p[b] == '?')
        {
            return match(s, a + 1, p, b + 1);
        }
        else
        {
            if (p[b] != s[a])
                return false;

            return match(s, a + 1, p, b + 1);
        }
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        
    }
};

int main(){
    Solution a;
    
    return 0;
}


