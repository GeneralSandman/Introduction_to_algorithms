#include<iostream>
#include<vector>
#include"sort.h"
using namespace std;

class SelectionSort{
    void sort(vector<int> & nums){
        for(int i=0;i<nums.size()-1;i++){
            int min=i;
            for(int j=0;j<nums.size();j++){
                if(nums[j]<nums[min])
                    min=j;
            }

            swap(nums[i],nums[min]);
        }

        for(auto t:nums)
            cout<<t<<" "
        cout<<endl;
    }
}

class InsertSort{

}

class QuitSort{


}

class MergeSort{


}

class HeapSort{

}

class HeashSort{

}
