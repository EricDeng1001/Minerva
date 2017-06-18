#define MF(return_type) template<unsigned long size> return_type string<size>::
#define __init__(para) template<unsigned long size> string<size>::string(para)
#define __des__() template<unsigned long size> string<size>::~string()

namespace Antinux{namespace Athena{

__init__(){
	content = new char[size + 1];
	content[size] = 0; 
	len = 0;
}

__init__(const char* str){
	content = new char[size];
	unsigned long i = 0;
	while(i < size && *(str + i)){
		content[i] = str[i];
		i++;
	}
	len = i;
	while(i < size){
		content[i] = 0;
		i++;
	}
}

__init__(char* str){
	content = new char[size];
	unsigned long i = 0;
	while(i < size && *(str + i)){
		content[i] = str[i];
		i++;
	}
	len = i;
	while(i < size){
		content[i] = 0;
		i++;
	}
}

__init__(string<size>& str){
	content = new char[size];
	unsigned long i = 0;
	while(str.content[i]){
		content[i] = str.content[i];
		i++;
	}
	len = i;
	while(i < size){
		content[i] = 0;
		i++;
	}
}

__des__(){
	delete [] content;
}

MF(void) operator = (string<size>& str){
	unsigned long i = 0;
	while(str.content[i]){
		content[i] = str.content[i];
		i++;
	}
	len = i;
	while(i < size){
		content[i] = 0;
		i++;
	}
}

MF(void) Append(const char* str){
	unsigned long i = 0;
	while((i + len < size) && str[i]){
		content[i + len] = str[i];
		i++;
	}
}

MF(void) Append(char* str){
	unsigned long i = 0;
	while((i + len < size) && str[i]){
		content[i + len] = str[i];
		i++;
	}
}

MF(void) RTrim(unsigned long length){
	loop(length){
		content[len - i] = 0;
	}
	len -= length;
}

MF(char*) ConvertToC(){
	return content;
}

MF(unsigned long) Hash(){
	unsigned long hs = 0;  
	char* str = content;
    while(*str) {
        hs = (hs + (*str << 4) + (*str++ >> 4)) * 11;
    }
    return hs;
}

MF(bool) operator == (string<size>& another){
	if(another.len != len){
		return false;
	}
	else{
		loop(len){
			if(content[i] != another.content[i])
				return false;
		}
		return true;
	}
}

MF(void) operator = (const char* str){
	unsigned long i = 0;
	while(str[i]){
		content[i] = str[i];
		i++;
	}
	len = i;
	while(i < size){
		content[i] = 0;
		i++;
	}
}

MF(void) operator = (char* str){
	unsigned long i = 0;
	while(str[i]){
		content[i] = str[i];
		i++;
	}
	len = i;
	while(i < size){
		content[i] = 0;
		i++;
	}
}

}}