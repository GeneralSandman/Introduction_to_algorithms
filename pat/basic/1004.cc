#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

struct Student
{
    string m_nName;
    string m_nId;
    unsigned char m_nScore;
    friend bool operator>(const struct Student &a, const struct Student &b)
    {
        return a.m_nScore >= b.m_nScore;
    }
};

int main()
{
    int size = 0;
    cin >> size;

    vector<Student> s(size);

    for (int i = 0; i < size; i++)
    {
        struct Student tmp;

        cin >> tmp.m_nName;
        cin >> tmp.m_nId;
        cin >> tmp.m_nScore;

        s.push_back(tmp);
    }

    sort(s.begin(),s.end(),[](const struct Student&a,const struct Student&b){return a>b;});

    cout<<s[0].m_nName<<s[0].m_nId<<endl;
    cout<<s[s.size()-1].m_nName<<s[s.size()-1].m_nId<<endl;
    return 0;
}
