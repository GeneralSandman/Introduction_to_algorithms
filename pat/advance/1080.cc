#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef struct Student
{
    int id;
    int ge;
    int gi;
    int all;

    bool getSchool;
} Student;

typedef struct School
{
    int lastRank;
    int maxSize;
    int size;
} School;

bool comp(const Student &a, const Student &b)
{
    if (a.all == b.all)
    {
        return a.ge > b.ge;
    }
    else
    {
        return a.all > b.all;
    }
}

int main()
{
    int stuNums, schoolNums, choNums;
    cin >> stuNums >> schoolNums >> choNums;

    vector<Student> students(stuNums);
    vector<int> tmp(choNums, 0);
    vector<vector<int>> choies(stuNums, tmp);

    vector<School> schools(schoolNums);
    for (int i = 0; i < schoolNums; i++)
    {
        cin >> schools[i].maxSize;
    }

    for (int i = 0; i < stuNums; i++)
    {
        cin >> students[i].ge >> students[i].gi;
        students[i].all = students[i].ge + students[i].gi;
        for (int j = 0; j < choNums; j++)
        {
            cin >> choies[i][j];
        }
    }

    sort(students.begin(), students.end(), comp);

    

    vector<vector<int>> result(schoolNums);

    for (int i = 0; i < schoolNums; i++)
    {
    }

    for (int i = 0; i < result.size(); i++)
    {
        if (!result[i].empty())
            cout << result[i][0];
        for (int j = 1; j < result[i].size(); j++)
            cout << " " << result[i][j];
        cout << endl;
    }

    return 0;
}