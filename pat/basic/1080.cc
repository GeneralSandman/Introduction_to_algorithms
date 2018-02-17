#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <map>
#include <algorithm>

using namespace std;

class Student
{
  public:
    string id;
    int prog;
    int middle;
    int end;
    int avg;

    Student(string id_ = "", int p = -1, int m = -1, int e = -1, int a = -1)
        : id(id_),
          prog(p),
          middle(m),
          end(e),
          avg(a)
    {
    }

    friend bool operator>(const Student &a, const Student &b)
    {
        if (a.avg > b.avg)
        {
            return true;
        }
        else if (a.avg == b.avg)
        {
            return a.id <= b.id;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    map<string, Student> db;

    int p, m, n;
    cin >> p >> m >> n;

    for (int i = 0; i < p; i++)
    {
        string id;
        int score;
        cin >> id >> score;
        db[id].id = id;
        db[id].prog = score;
    }
    for (int i = 0; i < m; i++)
    {
        string id;
        int score;
        cin >> id >> score;
        db[id].id = id;
        db[id].middle = score;
    }
    for (int i = 0; i < n; i++)
    {
        string id;
        int score;
        cin >> id >> score;
        db[id].id = id;
        db[id].end = score;
    }
    for (auto t : db)
    {
        if (t.second.middle > t.second.end)
        {
            t.second.avg = 0.4 * t.second.middle +
                           0.6 * t.second.end;
        }
        else
        {
            t.second.avg = t.second.end;
        }
    }

    vector<Student> r;
    for (auto t : db)
    {
        if (t.second.prog >= 200 && t.second.avg >= 60)
        {
            r.push_back(t.second);
        }
    }

    sort(r.begin(), r.end(), [](const Student &a, const Student &b) { return a > b; });

    for (auto t : r)
    {
        cout << t.id << " " << t.prog << " " << t.middle << " " << t.end << " " << t.avg << endl;
    }
    return 0;
}
