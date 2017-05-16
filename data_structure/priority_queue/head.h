#ifndef PQUEUE_H
#define PQUEUE_H
#include<iostream>
#include<vector>
#include<climits>
namespace priority_queue{
	using namespace std;
	class Priority_queue{
		//this class default is max priority queue,
		//we have to change the class
		//after the change ,the construct function of this class have to accept the lamda
		private:
			vector<int> m_nVector;
			void m_fFloat(int );
			void m_fSink(int );
			void m_fSwap(int ,int );
			//bool m_fCompare();
		public:
			Priority_queue(vector<int> &);
			Priority_queue();
			~Priority_queue();
			int Size();
			int Max();
			void RemoveMax();
			void Insert(const int & a);
			void PrintVector(void);
	};

}
#endif
