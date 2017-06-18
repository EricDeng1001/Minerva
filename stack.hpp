#ifndef _ANTINUX_ATHENA_STACK_H_
#define _ANTINUX_ATHENA_STACK_H_

#include "stack-core.hpp"

namespace Antinux{namespace Athena{

template<class ElementType>
class stack:public stack_core<ElementType>{
public:
	stack();
	~stack();
public:
	stack(stack<ElementType>& src);
public:
	void operator = (stack<ElementType>& src);
};


}}





#include "stack.inl"

#endif