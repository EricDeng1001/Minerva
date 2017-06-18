#define MF(return_type) template<class ElementType> return_type stack<ElementType>::
#define __init__(para) template<class ElementType> stack<ElementType>::stack(para)
#define __des__() template<class ElementType> stack<ElementType>::~stack()

namespace Antinux{namespace Athena{

__init__():stack_core<ElementType>(){

}

__init__(stack<ElementType>& src):stack_core<ElementType>(src){

}

__des__(){

}

MF(void) operator = (stack<ElementType>& src){
	stack_core<ElementType>::operator=(src);
}

}}

#undef MF
#undef __init__
#undef __des__