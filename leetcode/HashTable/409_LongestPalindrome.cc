#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int longestPalindrome(string s)
    {
        if (s.size() <= 1)
            return s.size();
        
        int odd = 0;
        int number = 1;
        sort(s.begin(), s.end());
        char pre = s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == pre)
            {
                number++;
            }
            else
            {
                if (number % 2)
                    odd++;
                number = 1;
            }
            pre = s[i];
        }
        if(number%2)
            odd++;
        cout<<odd<<"-";
        return s.size()-odd+(odd?1:0);
    }
};

int main()
{
    Solution a;
    string s = "abccccdd";
    string s2 = "abbcdde";
    cout << a.longestPalindrome(s) << endl;  //2
    cout << a.longestPalindrome(s2) << endl; //3
    return 0;
}
