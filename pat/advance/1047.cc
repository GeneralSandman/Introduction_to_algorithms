#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int stuNum = 0;
    int couNum = 0;
    cin >> stuNum >> couNum;

    vector<vector<string> > courses(couNum);

    for (int i = 0; i < stuNum; i++)
    {
        string name;
        cin >> name;

        int size;
        cin >> size;

        for (int j = 0; j < size; j++)
        {
            int cou;
            cin >> cou;
            courses[cou-1].push_back(name);
        }
    }

    for (int i = 0; i < courses.size(); i++)
    {
        sort(courses[i].begin(), courses[i].end());
        cout << i+1 << " " << courses.size() << endl;
        for (auto t : courses[i])
            cout << t << endl;
    }

    return 0;
}