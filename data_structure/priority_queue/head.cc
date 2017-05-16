#include<iostream>
#include<vector>
#include<climits>
#include"head.h"
namespace priority_queue{

	void Priority_queue::m_fFloat(int i){
		int index=i;
		while(index>1){
			int parent=index/2;
			if(m_nVector[index]<=m_nVector[parent])
				break;
			m_fSwap(index,parent);
			index=parent;
		}
	}

	void Priority_queue::m_fSink(int i){
		int index=i;
		while(2*index<=m_nVector.size()-1){
			int left_child=2*index;
			int max_child=left_child;
			int right_child=2*index+1;
			if(right_child<=m_nVector.size()-1 && m_nVector[right_child]>m_nVector[left_child] )
				max_child=right_child;

			if(m_nVector[index]<m_nVector[max_child])
			{
				m_fSwap(index,max_child);
				index=max_child;
			}else
				break;
		}
	}

	void Priority_queue::m_fSwap(int index,int parent){
		int tmp=m_nVector[index];
		m_nVector[index]=m_nVector[parent];
		m_nVector[parent]=tmp;
	}


	Priority_queue::Priority_queue(){
		m_nVector.push_back(INT_MIN);
	}

	Priority_queue::Priority_queue(vector<int> & number){
		m_nVector.push_back(INT_MIN);
		for(auto t:number)
			Insert(t);

	}


	Priority_queue::~Priority_queue(){

	}

	void Priority_queue::Insert(const int & value){
		cout<<"insert value:"<<value<<endl;
		m_nVector.push_back(value);
		m_fFloat(m_nVector.size()-1);
	}

	int Priority_queue::Size(){
		return m_nVector.size()-1;
	}

	int Priority_queue::Max(){
		if(m_nVector.size()==1){
			cout<<"priority queue is empty\n";
			return INT_MIN;
		}
		return m_nVector[1];
	}

	void Priority_queue::RemoveMax(){
		if(m_nVector.size()==1)
			return ;
		cout<<"remove value:"<<m_nVector[1]<<endl;
		m_nVector[1]=*(m_nVector.end()-1);
		m_nVector.erase(m_nVector.end()-1);
		if(m_nVector.size()>1)
			m_fSink(1);
	}

	void Priority_queue::PrintVector(void){
		for(int i=1;i<m_nVector.size();i++)
			cout<<m_nVector[i]<<" ";
		cout<<endl;
	}


}
