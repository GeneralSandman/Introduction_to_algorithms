#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<string> readBinaryWatch(int num)
  {
    vector<int> hour{1, 2, 4, 8};
    vector<int> mintu{1, 2, 4, 8, 16, 32};
    vector<string> result;
    generate(result, hour, mintu, 0, num);
    return result;
  }

private:
  void generate(vector<string> &result, vector<int> &h, vector<int> &m, int n1, int n2)
  {
  }
};

int main()
{
  Solution a;
  vector<string> result;
  result = a.readBinaryWatch(5);
  for (auto t : result)
    cout << t << endl;

  return 0;
}
