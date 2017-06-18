#define MF(return_type) template<class ElementType> return_type HashTable_core<ElementType>::
#define __init__(para) template<class ElementType> HashTable_core<ElementType>::HashTable_core(para)
#define __des__() template<class ElementType> HashTable_core<ElementType>::~HashTable_core()

namespace Antinux{namespace Athena{

__init__(unsigned long TableSize){
	lists = new list<elementType>[TableSize];
	this->TableSize = TableSize;
}

__des__(){
	delete [] lists;
}


MF(unsigned long) Hash(elementType Key){
	unsigned long hs;  
	hs = (unsigned long)Key;
    return hs % TableSize;  
}

MF(void) Insert(elementType Key){
	unsigned long position = Hash(Key);
	if(Find(Key).Exist){
		return;
	}
	lists[position].Push(Key);
}

MF(typename HashTable<elementType>::Position) Find(elementType Key){
	typename  HashTable<elementType>::Position tmp;
	unsigned long position = Hash(Key);
	tmp.Index_of_HashTable = position;
	unsigned long i = 0;
	unsigned long len = lists[position].length();
	while(i < len){
		if(lists[position].Query(i) == Key){
			Finded = tmp.Exist = true;
			tmp.Index_of_list = i;
			return tmp;
		}
		i++;
	}
	tmp.Index_of_list = 0;
	Finded = tmp.Exist = false;
	return tmp;
}

MF(void) Delete(elementType Key){
	typename HashTable<elementType>::Position tmp;
	tmp = Find(Key);
	if(tmp.Exist){
		lists[tmp.Index_of_HashTable].Delete(tmp.Index_of_list);
	}
}

MF(elementType) Query(typename HashTable<elementType>::Position p){
	return lists[p.Index_of_HashTable][p.Index_of_list];
} 

MF(bool) NoFind(){
	return Finded == false;
}


}}

#include "Hash-specify-for-string.inl"
#undef MF
#undef __des__
#undef __init__