#ifndef _ANTINUX_ATHENA_STACK_CORE_H_
#define _ANTINUX_ATHENA_STACK_CORE_H_

#include "Apollo/loop.hpp"
#include "list-core.hpp"

namespace Antinux{namespace Athena{

template<class ElementType>
class stack_core{
protected:
	list_core<ElementType>* core;
	unsigned long length;
public:
	stack_core();
	virtual ~stack_core();
public:
	stack_core(stack_core<ElementType>& src);
public:
	void operator = (stack_core<ElementType>& src);
public:
	void Pop();
	ElementType PopOut();
	void Push(ElementType& Value);
	void Push(ElementType&& Value);
	bool Empty();
};


}}



#include "stack-core.inl"

#endif

