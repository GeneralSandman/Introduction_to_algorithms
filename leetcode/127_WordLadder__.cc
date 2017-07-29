#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<string> cur_level, next_level;
        wordList.push_back(endWord);
        cur_level.push_back(beginWord);
        int depth = 1;
        int len = beginWord.size();
        while (!cur_level.empty())
        {
            for (auto cur_word : cur_level)
            {
                if (cur_word == endWord)
                    return depth;
                for (int i = 0; i < len; i++)
                {
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        cur_word[i] = c;

                        auto p = find(wordList.begin(), wordList.end(), cur_word);
                        if (p != wordList.end())
                        {
                            next_level.push_back(cur_word);
                            wordList.erase(p);
                        }
                    }
                }
            }

            depth++;
            cur_level = next_level;
            next_level.erase(next_level.begin(), next_level.end());
        }

        return 0;
    }
};

int main()
{
    Solution a;
    string beginWord="hit";
    string endWord="cog";
    vector<string> wordList={"hot","dot","dog","lot","log","cog"};
    cout<<a.ladderLength(beginWord,endWord,wordList)<<endl;
    return 0;
}
