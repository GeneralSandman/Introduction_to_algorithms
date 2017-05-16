#include<iostream>
#include"head.h"

using namespace std;

void Priority_queue_Test(void){

vector<int> res;
res.push_back(2);
res.push_back(5);
res.push_back(6);
res.push_back(3);
res.push_back(6);
res.push_back(7);
res.push_back(9);
res.push_back(0);
res.push_back(10);
res.push_back(11);

priority_queue::Priority_queue queue(res);
cout<<queue.Max();
queue.RemoveMax();
cout<<queue.Max();
queue.Insert(12);
cout<<queue.Max();
queue.Insert(10);
cout<<queue.Max();

}


int main(){
	Priority_queue_Test();

	return 0;

}
