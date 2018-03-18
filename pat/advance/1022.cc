#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <stdio.h>

using namespace std;

struct Book
{
    char id[8];
    char title[81];
    char author[81];
    vector<string> keys;
    char publisher[81];
    char year[5];
};

typedef struct Book Book;

bool comp(const Book &a, const Book &b)
{
    return strcmp(a.id, b.id) < 0;
}

struct Query
{
    int num;
    char word[81];
};

typedef struct Query Query;

vector<Book> books;

void find(Query &q, vector<string> &result)
{
}

int main()
{
    int bookNums;
    cin >> bookNums;
    books.resize(bookNums);
    getchar(); //very inmprtant
    for (int i = 0; i < bookNums; i++)
    {
        gets(books[i].id);
        gets(books[i].title);
        gets(books[i].author);
        do
        {
            char tmp[10];
            scanf("%s", tmp);
            books[i].keys.push_back(string(tmp));
        } while (getchar() != '\n');

        gets(books[i].publisher);
        gets(books[i].year);
    }

    sort(books.begin(), books.end(), comp);

    int query_num;
    cin >> query_num;

    vector<string> result;

    Query que;
    for (int i = 0; i < query_num; i++)
    {
        scanf("%d: ", &que.num);
        gets(que.word);

        printf("%d: %s\n", que.num, que.word);

        bool find = false;

        if (que.num == 1)
        {
            for (auto t : books)
                if (strcmp(q.word, t.title) == 0)
                    result.push_back(string(t.id));
        }
        else if (que.num == 2)
        {
            for (auto t : books)
                if (strcmp(q.word, t.author) == 0)
                    result.push_back(string(t.id));
        }
        else if (que.num == 3)
        {

            for (auto t : books)
            {
                for (auto key : t.keys)
                {
                    if (strcmp(key.c_str(), q.word) == 0)
                    {
                        result.push_back(string(t.id));
                        break;
                    }
                }
            }
        }
        else if (que.num == 4)
        {
            for (auto t : books)
                if (strcmp(q.word, t.publisher) == 0)
                    result.push_back(string(t.id));
        }
        else if (que.num == 5)
        {
            for (auto t : books)
                if (strcmp(q.word, t.year) == 0)
                    result.push_back(string(t.id));
        }

        if (!find)
        {
            cout << "Not Found\n";
            continue;
        }
    }

    return 0;
}