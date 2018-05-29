
#ifndef __STRING_H__
#define __STRING_H__
#include "BankingCommonDec1.h"
class String
{
private:
	int len;
	char* str;
public:
	String();
	String(const char* S);
	String(const String& S);
	~String();
	String& operator+= (const String& S);
	String& operator= (const String& S);
	bool operator==(const String& S);
	String& operator+(const String& S);

	friend ostream& operator<<(ostream& os, const String& S);
	friend istream& operator>>(istream& is, String& S);
};
#endif __STRING_H__