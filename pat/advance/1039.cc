#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

void find(const vector<vector<string>> &coures,
          const string &stu, vector<int> &res)
{
    for (int i = 0; i < coures.size(); i++)
    {
        for (auto t : coures[i])
        {
            if (t == stu)
            {
                res.push_back(i);
                break;
            }
        }
    }
}

int main()
{
    int stuNum, couNum;
    cin >> stuNum >> couNum;

    vector<vector<string>> coures(couNum);

    for (int i = 0; i < couNum; i++)
    {
        int num, size;
        cin >> num >> size;

        string tmp;
        for (int j = 0; j < size; j++)
        {
            cin >> tmp;
            coures[num-1].push_back(tmp);
        }
    }

    vector<string> query;
    query.reserve(stuNum);
    string tmp;
    for (int i = 0; i < stuNum; i++)
    {
        cin >> tmp;
        query.push_back(tmp);
    }

    vector<vector<int>> result;
    vector<int> res;
    for (auto t : query)
    {
        res.clear();
        find(coures, t, res);
        result.push_back(res);
    }

    for (int i = 0; i < stuNum; i++)
    {
        cout << query[i] << " " << result[i].size();
        for (auto t : result[i])
            cout << " " << t+1;
        cout<<endl;
    }

    return 0;
}