#ifndef _ANTINUX_ATHENA_STRING_H_
#define _ANTINUX_ATHENA_STRING_H_

#include "Apollo/loop.hpp"
#include "list.hpp"
namespace Antinux{namespace Athena{

template<unsigned long size>
class string{
protected:
	char* content;
	unsigned long len;
public:
	string();
	~string();
public:
	string(const char* str);
	string(char* str);
	string(string<size>& str);
public:
	void operator = (string<size>& src);
public:
	void Append(const char* str);
	void Append(char* str);
public:
	void RTrim(unsigned long length = 1);
public:
	char* ConvertToC();
public:
	unsigned long Hash();
public:
	bool operator == (string<size>& another);
	void operator = (const char* str);
	void operator = (char* str);
};

}}

#include "string.inl"

#endif