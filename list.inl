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

MF(unsigned long) Alloc(unsigned long num_of_element)
{
	typename list_core<ElementType>::Node* New;
	unsigned ret = list_core<ElementType>::len;
	loop(num_of_element) {
		New = new typename list_core<ElementType>::Node;
		New->Pre = list_core<ElementType>::Header->Pre;
		New->Next = list_core<ElementType>::Header;
		list_core<ElementType>::Header->Pre->Next = New;
		list_core<ElementType>::Header->Pre = New;
	}
	list_core<ElementType>::len += num_of_element;
	updated = true;
	return ret;
}

MF(ElementType*) Array()
{
	if (updated) {
		updated = false;
		delete [] hide_array_ptr;
		hide_array_ptr = new ElementType[list_core<ElementType>::len];
		typename list_core<ElementType>::Node* tmp = list_core<ElementType>::Header->Next;
		loop(list_core<ElementType>::len) {
			hide_array_ptr[i] = tmp->element;
			tmp = tmp->Next;
		}
	}
	return hide_array_ptr;
}

MF(void) load(ElementType* base, unsigned long num_of_element)
{
	list_core<ElementType>::Clear();
	list_core<ElementType>::Append(base, num_of_element);
	updated = true;
}

MF(ElementType&) operator [] (unsigned long position)
{
	typename list_core<ElementType>::Node* tmp;
	tmp = list_core<ElementType>::Header->Next;
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