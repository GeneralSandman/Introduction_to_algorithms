#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  public:
    vector<string> readBinaryWatch(int num)
    {
        vector<int> hour{1, 2, 4, 8};
        vector<int> mintu{1, 2, 4, 8, 16, 32};
        vector<string> result;
        generate(result,hour,mintu,0,num);

    }


  private:
  void generate(vector<string> &result,vector<int> & h,vector<int> & m,int n1,int n2){

  }

    string int2str(int number, int hour)
    {
    }
};

1 2 4 8 1 2 4 8 16 32