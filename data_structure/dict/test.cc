#include"dict.h"
#include<iostream>
#include<string>
using namespace std;
using namespace dict;
int main(){

    {

    DictTable<string,string> table;
    table.insertPair("li","lizhenhu");
    cout<<table.findPair("li")<<endl;
    cout<<table["li"]<<endl;
    cout<<endl;

    table.insertPair("li","qqq");
    cout<<table.findPair("li")<<endl;
    cout<<table["li"]<<endl;

    for(int i=0;i<10;i++)
        table.insertPair(to_string(i),to_string(i));
    
    cout<<"used "<<table.m_nUsed<<endl;

    for(int i=0;i<10;i++)
        cout<<table[to_string(i)]<<endl;

    }



    return 0;
}