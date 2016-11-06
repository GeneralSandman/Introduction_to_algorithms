#include<iostream>
#include"sort.h"
#include<vector>

using namespace std;

int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(9);
    nums.push_back(8);
    nums.push_back(7);

    SelectionSort select;
    InsertionSort insert;
    MergeSort merge;

    select.sort(nums);
    insert.sort(nums);
    merge.sort(nums);
    

    return 0;
}