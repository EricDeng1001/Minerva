#define MF(return_type) template<class ElementType> return_type list_core<ElementType>::
#define __init__(para) template<class ElementType> list_core<ElementType>::list_core(para)
#define __des__() template<class ElementType> list_core<ElementType>::~list_core()

namespace Antinux{namespace Athena{
__init__(){
	Header = new Node;
	Header->Next = Header;
	Header->Pre = Header;
	//an extension need consider
	ElementType tmp;
	Header->element = tmp;
	//--------
	len = 0;
	//fast_operation
	
}

__init__(list_core<ElementType>& src){
	Header = new Node;
	Header->Next = Header;
	Header->Pre = Header;
	loop(src.len){
		Append(src.Query(i));
	}
	len = src.len;
	//fast_operation	
}

__des__(){
	Node* tmp;
	Node* left;
	left = Header->Pre;
	tmp = Header->Next;
	until(tmp == Header) {
		delete tmp->Pre;
		tmp = tmp->Next;
	}
	delete left;
}

MF(void) Insert(ElementType& element, unsigned long position){
	Node* tmp;
	Node* New;
	tmp = Header->Next;
	loop(position) {
		tmp = tmp->Next;
	}
	New = new Node;
	New->element = element;
	New->Next = tmp;
	New->Pre = tmp->Pre;
	tmp->Pre->Next = New;
	tmp->Pre = New;
	len++;
}

MF(void) Insert(ElementType&& element, unsigned long position){
	Node* tmp;
	Node* New;
	tmp = Header->Next;
	loop(position) {
		tmp = tmp->Next;
	}
	New = new Node;
	New->element = element;
	New->Next = tmp;
	New->Pre = tmp->Pre;
	tmp->Pre->Next = New;
	tmp->Pre = New;
	len++;
}

MF(void) Insert(ElementType* element, unsigned long begin_position, unsigned long num_of_element){
	Node* tmp;
	Node* New;
	tmp = Header->Next;
	loop(begin_position) {
		tmp = tmp->Next;
	}
	loop(num_of_element) {
		New = new Node;
		New->element = element[i];
		New->Next = tmp;
		New->Pre = tmp->Pre;
		tmp->Pre->Next = New;
		tmp->Pre = New;
	}
	len += num_of_element;
}

MF(void) Append(ElementType& element){
	Node* New = new Node;
	New->element = element;
	New->Pre = Header->Pre;
	New->Next = Header;
	Header->Pre->Next = New;
	Header->Pre = New;
	len++;
}

MF(void) Append(ElementType&& element){
	Node* New = new Node;
	New->element = element;
	New->Pre = Header->Pre;
	New->Next = Header;
	Header->Pre->Next = New;
	Header->Pre = New;
	len++;
}

MF(void) Append(ElementType* element, unsigned long num_of_element){
	Node* New;
	loop(num_of_element) {
		New = new Node;
		New->element = element[i];
		New->Pre = Header->Pre;
		New->Next = Header;
		Header->Pre->Next = New;
		Header->Pre = New;
	}
	len += num_of_element;
}

MF(void) Push(ElementType& element){
	Node* New = new Node;
	New->element = element;
	New->Pre = Header;
	New->Next = Header->Next;
	Header->Next->Pre = New;
	Header->Next = New;
	len++;
}

MF(void) Push(ElementType&& element){
	Node* New = new Node;
	New->element = element;
	New->Pre = Header;
	New->Next = Header->Next;
	Header->Next->Pre = New;
	Header->Next = New;
	len++;
}

MF(void) Push(ElementType* element, unsigned long num_of_element){
	Node* New;
	loop(num_of_element) {
		New = new Node;
		New->element = element[i];
		New->Pre = Header;
		New->Next = Header->Next;
		Header->Next->Pre = New;
		Header->Next = New;
	}
	len += num_of_element;
}

MF(ElementType) Query(unsigned long position){
	Node* tmp;
	tmp = Header->Next;
	loop(position) {
		tmp = tmp->Next;
	}
	return tmp->element;
}

MF(void) Delete(unsigned long position){
	Node* tmp;
	tmp = Header->Next;
	loop(position) {
		tmp = tmp->Next;
	}
	tmp->Next->Pre = tmp->Pre;
	tmp->Pre->Next = tmp->Next;
	delete tmp;
	len--;
}

MF(void) Rewrite(ElementType& element, unsigned long position){
	Node* tmp;
	tmp = Header->Next;
	loop(position) {
		tmp = tmp->Next;
	}
	tmp->element = element;
}

MF(unsigned long) length(){
	return this->len;
}

MF(void) Clear(){
	Node* tmp = Header->Next;
	Node* f;
	until(tmp == Header) {
		f = tmp->Next;
		delete tmp;
		tmp = f;
	}
	Header->Next = Header->Pre = Header;
	len = 0;
}








}}





#undef MF
#undef __init__
#undef __des__