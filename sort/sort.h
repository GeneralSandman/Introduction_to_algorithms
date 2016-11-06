#ifndef SORT_H
#define SORT_H
#include<iostream>
#include<vector>
using namespace std;

class SelectionSort{
    public:
    void sort(vector<int> & nums){
        for(int i=0;i<nums.size()-1;i++){
            int min=i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[min])
                    min=j;
            }

            swap(nums[i],nums[min]);
        }
        cout<<"SelectionSort:";
        for(auto t:nums)
            cout<<t<<" ";
        cout<<endl;
    }
};

class InsertionSort{
public:
    void sort(vector<int> & nums){
        for(int i=1;i<nums.size();i++){
            int tmp=nums[i];
            int j=i-1;
            for(;j>=0&&nums[j]>tmp;j--){
                nums[j+1]=nums[j];
            }

            nums[j+1]=tmp;
        }
        cout<<"InsertSort:";
        for(auto t:nums)
            cout<<t<<" ";
        cout<<endl;
    }
};

class BinarySearshInsertionSort{
public:
    void sort(vector<int> & nums){
        
    }
};

class QuitSort{


};

class MergeSort{
    public:
    void sort(vector<int> & nums){
        m_fSort(nums,0,nums.size()-1);
        cout<<"MergeSort:";
        for(auto t:nums)
            cout<<t<<" ";
        cout<<endl;
    }

    private:

    void m_fSort(vector<int> & nums,int begin,int end){
        if(begin>=end)
            return;
        
        int middle=(begin+end)/2;
        m_fSort(nums,begin,middle);
        m_fSort(nums,middle+1,end);

        int begin1=begin;
        int end1=middle;
        int begin2=middle+1;
        int end2=end;

        int k=begin;

        while(begin1<=end1 && begin2<=end2)
            nums[k++]=nums[begin1]>nums[begin2]?nums[begin2++]:nums[begin1++];
        while(begin1<=end1)
            nums[k++]=nums[begin1++];
        while(begin2<=end2)
            nums[k++]=nums[begin2++];
        


    }

};

class HeapSort{
    void sort(vector<int> & nums){


        for(auto t:nums)
            cout<<t<<" ";
        cout<<endl;
    }
};

class RadixSort{

};

class STLStableSort{

};

class STLSort{

};

class MSBSort{

};

class ShellSort{

};

class ShakerSort{

};

class HeashSort{

};

#endif