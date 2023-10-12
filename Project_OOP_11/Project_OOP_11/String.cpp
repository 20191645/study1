#include "String.h"

String::String() {
	str = NULL;
	len = 0;
}

String::String(const char* mystr) {
	len = strlen(mystr) + 1;
	str = new char[len];
	strcpy(str, mystr);
}

String::String(const String& ref) {
	len = ref.len;
	str = new char[len];
	strcpy(str, ref.str);
}

String& String::operator=(const String& ref) {
	if (str != NULL)
		delete[] str;
	len = ref.len;
	str = new char[ref.len];
	strcpy(str, ref.str);

	return *this;
}

String String::operator+(const String& ref) {
	char* tempstr = new char[len + ref.len - 1];
	strcpy(tempstr, str);
	strcat(tempstr, ref.str);

	String temp(tempstr);
	delete[] tempstr;

	return temp;
}

String& String::operator+=(const String& ref) {
	len += ref.len - 1;
	char* tempstr = new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, ref.str);

	if (str != NULL)
		delete[] str;
	str = tempstr;

	return *this;
}

bool String::operator==(const String& ref) {
	//return strcmp(str, ref.str) ? false : true;

	if (strcmp(str, ref.str))
		return false;
	else
		return true;
}

String::~String() {
	if (str != NULL)
		delete[] str;
}

ostream& operator<<(ostream& os, const String& mystr) {
	os << mystr.str;
	return os;
}

istream& operator>>(istream& is, String& mystr) {
	char temp[100];
	is >> temp;
	mystr = String(temp);
	return is;
}