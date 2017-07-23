#ifndef DICT_H
#define DICT_H
#include<string>
#include<cstring>
namespace dict{
	using namespace std;

    	template<typename K>
		unsigned int hashFunction(const K &key){
			std::hash<std::string> h;
			unsigned int n=h(key);
			return n;
		}

	template<typename K,typename V>    
		class DictEntry{
			public:
				K m_nKey;
				V m_nValue;
				DictEntry *m_pNext;
            public:
				DictEntry():m_pNext(nullptr){}
				~DictEntry(){m_pNext=nullptr;}
		};

	template<typename K,typename V>
		class DictTable{
			public:
				DictEntry<K,V> **m_pTable;
				size_t m_nSize;
				size_t m_nSizeMask;
				size_t m_nUsed;

				DictTable(size_t size=2);
				bool insertPair(const K&,const V&);
                V findPair(const K&);
				~DictTable();

            private:
            	unsigned int m_fGetIndex(const K&);
				DictEntry<K,V> * m_fGetEntry(const K &);
				DictEntry<K,V> * m_fFindEntry(const K &);


		};

	template<typename K>
		class DictFunctor{
			unsigned int m_fHashFunction(const K &);
			//dup,compare
		};

	template<typename K,typename V>    
		class Dict{
			public:
				DictFunctor<K> * m_pFunctor;

		};



	//........api.............//

	template<typename K,typename V>
		DictTable<K,V>::DictTable(size_t size){
			m_nSize=size;
			m_nSizeMask=size-1;
			m_nUsed=0;
			m_pTable=new DictEntry<K,V>* [size];
		}


	template<typename K,typename V>
		unsigned int DictTable<K,V>::m_fGetIndex(const K&k){
			unsigned int hash=hashFunction(k);
			unsigned int index=hash%m_nSize;
			return index;
		}


	template<typename K,typename V>
		DictEntry<K,V>* DictTable<K,V>::m_fFindEntry(const K &k){
			//if exists return a pointer,else return nullptr;
			unsigned int index=m_fGetIndex(k);
			if(m_pTable[index]==nullptr)
				return nullptr;

			DictEntry<K,V> *cur=m_pTable[index];
			while(cur){
				if(cur->m_nKey==k)
					return cur;
				else{
					cur=cur->m_pNext;
				}
			}

			return nullptr;

		}


	template<typename K,typename V>
		DictEntry<K,V>* DictTable<K,V>::m_fGetEntry(const K &k){
			DictEntry<K, V> *find=m_fFindEntry(k);
			if(find==nullptr){
                unsigned int index=m_fGetIndex(k);
				find=new DictEntry<K,V> ();
                find->m_nKey=k;
                find->m_pNext=m_pTable[index];
                m_pTable[index]=find;                
			}
			return find;
		}


	template<typename K,typename V>
		bool DictTable<K,V>::insertPair(const K&k,const V&v){
			DictEntry<K, V> *get=m_fGetEntry(k);
			get->m_nValue=v;
			return true;
		}

    template<typename K,typename V>
		auto DictTable<K,V>::findPair(const K&k) ->V{
            DictEntry<K, V> *find=m_fFindEntry(k);
            if(find==nullptr)
                return V();
            else if(find->m_nKey==k)
                return find->m_nValue;
        }


	template<typename K,typename V>
		DictTable<K,V>::~DictTable(){
			for(int i=0;i<m_nSize;i++)
			{
				if(m_pTable[i]){
					DictEntry<K,V> *cur=m_pTable[i],*pre=cur;
					while(cur){
						delete pre;
						pre=cur;
						cur=cur->m_pNext;
					}
				}
			}

			delete m_pTable;
			m_pTable=nullptr;
			m_nSize=0;
			m_nSizeMask=0;
			m_nUsed=0;
		}


}




#endif
