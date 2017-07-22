#ifndef DICT_H
#define DICT_H
#include<string>
namespace dict{
        using namespace std;

    template<typename K,typename V>    
    class DictEntry{
        public:
            K m_nKey;
            V m_nValue;
            DictEntry *m_pNext;
    };

    template<typename K,typename V>
    class DictTable{
        public:
            DictEntry<K,V> **m_pTable;
            size_t m_nSize;
            size_t m_nSizeMask;
            size_t m_nUsed;
    };

    class DictFunctor{
        unsigned int m_fHashFunction(const string &);
        //dup,compare
    };

    template<typename K,typename V>    
    class Dict{
        public:
            DictFunctor * m_pFunctor;
    };
}

#endif