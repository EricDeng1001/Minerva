namespace Antinux{namespace Athena{
template <> 
unsigned long HashTable_core<char*>::Hash(char* str){
	unsigned long hs = 0;  
    while(*str) {
        hs = (hs + (*str << 4) + (*str++ >> 4)) * 11;
    }  
    return hs % TableSize;
}

template <> 
typename HashTable_core<char*>::Position HashTable_core<char*>::Find(char* Key){
	HashTable<char*>::Position tmp;
    unsigned long position = Hash(Key);
    tmp.Index_of_HashTable = position;
    unsigned long len = lists[position].length();
    loop(len){
            if(!strcmp(lists[position].Query(i),Key)){
                Finded = tmp.Exist = true;
                tmp.Index_of_list = i;
                return tmp;
            }
    }
    tmp.Index_of_list = 0;
    Finded = tmp.Exist = false;
    return tmp;
}

template <> 
unsigned long HashTable_core<const char*>::Hash(const char* str){
	unsigned long hs = 0;  
    while(*str) {
        hs = (hs + (*str << 4) + (*str++ >> 4)) * 11;
    }  
    return hs % TableSize;
}

template <> 
typename HashTable_core<const char*>::Position HashTable_core<const char*>::Find(const char* Key){
	HashTable<char*>::Position tmp;
    unsigned long position = Hash(Key);
    tmp.Index_of_HashTable = position;
    unsigned long len = lists[position].length();
    loop(len){
            if(!strcmp(lists[position].Query(i),Key)){
                Finded = tmp.Exist = true;
                tmp.Index_of_list = i;
                return tmp;
            }
    }
    tmp.Index_of_list = 0;
    Finded = tmp.Exist = false;
    return tmp;
}

template <> 
unsigned long HashTable_core<string>::Hash(string str){  
    return str.Hash() % TableSize;
}



}}