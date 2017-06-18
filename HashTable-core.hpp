#ifndef _ANTINUX_ATHENA_HASHTABLE_CORE_H_
#define _ANTINUX_ATHENA_HASHTABLE_CORE_H_

#include "Apollo/loop.hpp"
#include "list-core.hpp"

namespace Antinux{namespace Athena{


template <class ElementType>
class HashTable_core{
public:
	typedef struct {
		unsigned long Index_of_HashTable;
		unsigned long Index_of_list;
		bool Exist;
	}Position;
private:
	list_core<ElementType>* lists;
	unsigned long TableSize;
	bool Finded;
private:
	unsigned long Hash(ElementType Key);
public:
	HashTable_core(unsigned long TableSize = 10007);
	~HashTable_core();
public:
	void Insert(ElementType Key);
	Position Find(ElementType Key);
	void Delete(ElementType Key);
	ElementType Query(Position p);
public:
	bool NoFind();
};




}}




#include "HashTable-core.inl"

#endif