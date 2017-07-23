#include"dict.h"
#include<iostream>
#include<string>
using namespace std;
using namespace dict;
int main(){
    DictTable<string,string> table;
    table.insertPair("lizhenhu","lizhenhu");
    // cout<<table.findPair("lizhenhu")<<endl;
    // cout<<table.findPair("li")<<endl;

    			unsigned int hash=hashFunction("lizhenhu");
			unsigned int index=hash%2;

            cout<<hash<<endl<<index<<endl;


    return 0;
}