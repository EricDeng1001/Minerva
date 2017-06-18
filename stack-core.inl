#define MF(return_type) template<class ElementType> return_type stack_core<ElementType>::
#define __init__(para) template<class ElementType> stack_core<ElementType>::stack_core(para)
#define __des__() template<class ElementType> stack_core<ElementType>::~stack_core()

namespace Antinux{namespace Athena{

__init__(){
	core = new list_core<ElementType>;
}

__init__(stack_core<ElementType>& src){
	core = new list_core<ElementType>(*src.core);
}

__des__(){
	delete core;
}

MF(void) operator = (stack_core<ElementType>& src){
	*core = *src.core;
}
MF(void) Pop(){
	if(core->length() > 0){
		core->Delete(0);
	}
}

MF(ElementType) PopOut(){
	ElementType tmp;
	if(core->length() > 0){
		tmp = core->Query(0);
		core->Delete(0);
		return tmp;
	}
}

MF(void) Push(ElementType& value){
	core->Push(value);
}

MF(void) Push(ElementType&& value){
	core->Push(value);
}

MF(bool) Empty(){
	return core->length() == 0;
}  

}}

#undef MF
#undef __init__
#undef __des__