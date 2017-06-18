#ifndef _ANTINUX_ATHENA_LIST_H_
#define _ANTINUX_ATHENA_LIST_H_
#include "list-core.hpp"

namespace Antinux{namespace Athena{
	
template <class ElementType>
class list :public list_core<ElementType>{
private:
	//Array function
	bool updated;
	ElementType* hide_array_ptr;
public:
	list();
	~list();
public:
	list(list<ElementType>& src);
public:
	void operator = (list<ElementType>& src);
public:
	//Array function
	ElementType* Array();
	void load(ElementType* base, unsigned long num_of_element);
	unsigned long Alloc(unsigned long num_of_element);
public:
	ElementType& operator [] (unsigned long position);
};

}}




#include "list.inl"

#endif