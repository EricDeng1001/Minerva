#define MF(return_type) template<class ElementType> return_type list<ElementType>::
#define __init__(para) template<class ElementType> list<ElementType>::list(para)
#define __des__() template<class ElementType> list<ElementType>::~list()

namespace Antinux{namespace Athena{

__init__(){
	updated = false;
	hide_array_ptr = nullptr;
}

__des__(){
	delete [] hide_array_ptr;
}

MF(ElementType) Alloc(unsigned long num_of_element)
{
	Node* New;
	unsigned ret = len;
	loop(num_of_element) {
		New = new Node;
		New->Pre = Header->Pre;
		New->Next = Header;
		Header->Pre->Next = New;
		Header->Pre = New;
	}
	len += num_of_element;
	updated = true;
	return ret;
}

MF(ElementType*) Array()
{
	if (updated) {
		updated = false;
		delete [] hide_array_ptr;
		hide_array_ptr = new T[len];
		Node* tmp = Header->Next;
		loop(len) {
			hide_array_ptr[i] = tmp->element;
			tmp = tmp->Next;
		}
	}
	return hide_array_ptr;
}

MF(void) load(ElementType* base, unsigned long num_of_element)
{
	Clear();
	Append(base, num_of_element);
	updated = true;
}

MF(ElementType&) operator [] (unsigned long position)
{
	= Node* tmp;
	tmp = Header->Next;
	loop(position) {
		tmp = tmp->Next;
	}
	updated = true;
	return tmp->element;
}










}}





#undef MF
#undef __init__
#undef __des__