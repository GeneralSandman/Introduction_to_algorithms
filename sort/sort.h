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
    public:
    void sort(vector<int> & nums){
                 


        cout<<"QuikeSort:";
        for(auto t:nums)
            cout<<t<<" ";
        cout<<endl;
    }

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
    public:
    void sort(vector<int> & nums){
        
        m_fSort(nums,0,nums.size()-1);     
        cout<<"HeapSort:";
        for(auto t:nums)
            cout<<t<<" ";
        cout<<endl;
    }

    private:

    void m_fSort(vector<int> & nums,int begin,int end){
        int parent=begin;
        int son=parent*2+1;

        while(son<=nums.size()-1){
            if(son+1<=nums.size()-1&&nums[son+1]>nums[son]) 
                son++;
            if(nums[son]>nums[parent])
                return;
            else{
                swap(nums[son],nums[parent]);
                parent=son;
                son=parent*2+1;
            }
        }
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

class BubbleSort{
    public:
    void sort(vector<int> & nums){
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[j-1])
                    swap(nums[j],nums[j-1]);
            }
        }

        cout<<"BubbleSort:";
        for(auto t:nums)
            cout<<t<<" ";
        cout<<endl;
    }
};

class ShakerSort{
    public:
    void sort(vector<int> & nums){
        int begin=0;
        int end=nums.size()-1;
        while(begin<end){
            for(int i=begin;i<end;i++)
                if(nums[i]>nums[i+1])
                    swap(nums[i],nums[i+1]);
            end--;

            for(int i=end;i>begin;i--)
                if(nums[i]<nums[i-1])
                    swap(nums[i],nums[i-1]);
            begin++;
        }
        cout<<"ShakerSort:";
        for(auto t:nums)
            cout<<t<<" ";
        cout<<endl;
    }
};

class HeashSort{

};

#endif