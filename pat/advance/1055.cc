#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Person
{
    char name[8];
    int age;
    int worth;
};

typedef struct Person Person;

struct Query
{
    int size;
    int begin;
    int end;
};

typedef struct Query Query;

bool comp(const Person &a, const Person &b)
{
    if (a.worth == b.worth)
    {
        if (a.age == b.age)
        {
            return strcmp(a.name, b.name);
        }
        else
        {
            return a.age < b.age;
        }
    }
    else
    {
        return a.worth > b.worth;
    }
}

int main()
{
    int num, query;
    cin >> num >> query;

    vector<Person> persons;
    persons.reserve(num);

    for (int i = 0; i < num; i++)
    {
        char name[8];
        int age, worth;

        scanf("%s %d %d", name, &age, &worth);
        persons.push_back((Person){name, age, worth});
    }

    vector<Query> querys;
    querys.reserve(query);
    for (int i = 0; i < query; i++)
    {
        int s, b, e;
        scanf("%d %d %d", &s, &b, &e);
        querys.push_back((Query){s, b, e});
    }
    sort(persons.begin(), persons.end(), comp);

    for (int i = 0; i < query; i++)
    {
        cout << "Case #" << i + 1 << ":\n";
        int count = 0;
        for (auto t : persons)
        {
            if (querys[i].begin <= t.age && t.age <= querys[i].end)
            {
                count++;
                cout << t.name << " " << t.age << " " << t.worth << endl;
                if (count >= querys[i].size)
                    break;
            }
        }

        if (count == 0)
            cout << "Node\n";
    }

    return 0;
}