#ifndef _ANTINUX_ATHENA_LIST_CORE_H_
#define _ANTINUX_ATHENA_LIST_CORE_H_

#include "Apollo/loop.hpp"

namespace Antinux{namespace Athena{
template <class ElementType>
class list_core {
public:
	struct Node {
		ElementType element;
		Node* Pre;
		Node* Next;
	};
protected:
	//Fast_operation
	/*
	Node* Insert_prediction_node;
	Node* Delete_prediction_node;
	Node* Query_prediction_node;
	unsigned long Insert_prediction_i;
	unsigned long Delete_prediction_i;
	unsigned long Query_prediction_i;
	*/
protected:
	Node* Header;
	unsigned long len;
public:
	list_core();
	virtual ~list_core();
public:
	list_core(list_core<ElementType>& src);
public:
	//basic_operation
	void Insert(ElementType& element, unsigned long position); // Insert at position (example: l = {2,3} l.insert(-1,0) -> l = {-1,2,3} )
	ElementType Query(unsigned long position);
	void Delete(unsigned long position);
	void Rewrite(ElementType& element, unsigned long position);
public:
	unsigned long length();
	void Clear();
public:
	//other-method of Insert();
	void Append(ElementType& element);
	void Push(ElementType& element);
public:
	//Fast_operation
	//field operation
	void Insert(ElementType* element, unsigned long begin_position, unsigned long num_of_element);
	void Append(ElementType* element, unsigned long num_of_element);
	void Push(ElementType* element,unsigned long num_of_element);
	//reference operation
	void Insert(ElementType&& element, unsigned long begin_position);
	void Append(ElementType&& element);
	void Push(ElementType&& element);
};


}}

#include "list-core.inl"
#endif



//you need to define operator = (value or lvalue ref) and constructor and destrctor