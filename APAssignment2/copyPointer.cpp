#define _CRT_SECURE_NO_WARNINGS
#include "copyPointer.h"
#include <memory>
#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;
//default constructor

cpy_ptr::cpy_ptr() {
    this->_strbuf = 0;
    this->_length = 0;
    this->_refcount = new int (1);					//reference count pointer points to value 1

}
//destructor

cpy_ptr::~cpy_ptr() {
   this->_strbuf = NULL;
}

//copy a const cpy_ptr into this string

cpy_ptr::cpy_ptr(cpy_ptr& newString) {

	this->_strbuf = newString._strbuf;
    this->_length = newString.length();

    //copy the passed string into internal buffer
	
	this->_refcount = newString._refcount ;				//Store reference count value to the new pointer
    //this->smartCopy(newString._strbuf, _length);
	(*_refcount) ++ ;									//Increment the reference count value after new copy pointer declared
	cout<<"string:	"<<newString._strbuf<<"	ref_count	"<<*newString._refcount<<endl;
	cout<<"string copy:	"<<this->_strbuf<<"	ref_count	"<<*_refcount<<endl;
}

//copy a char* into your string

cpy_ptr::cpy_ptr(char* newString, int length) {
	
    _length = length;
    _strbuf = new char[length];
    _strbuf = newString;
	_refcount = new int (1);							//reference count pointer points to value 1
	cout<<"cpy_ptr		"<<newString<<"	ref_count	"<<*_refcount<<endl;

    //Should I delete the string passed by the user?
    //delete[] newString;

}

//make a smart copy of the cpy_ptr into the callee cpy_ptr

void cpy_ptr::smartCopy(cpy_ptr* newString) {
    int shorterLength = 0;
    (this->_length < newString->_length) ? shorterLength = this->_length : shorterLength = newString->_length;
    int it = 0;
    while (it < shorterLength) {
        *_strbuf++ = *(newString->_strbuf)++;
        it++;
    }
}

//make a smart copy of the char* into this string

void cpy_ptr::smartCopy(char* newString, int length) {
    //(this->_length == length)?:this->_length=length;
    this->_length = length;
    int it = 0;
    while (it < length) {
        *_strbuf++ = *newString++;
        it++;
    }
}
//make a smart copy of this string into the passed string

void cpy_ptr::revSmartCopy(char* newString) {
    int it = 0;
    while (it < _length) {
        newString[it] = _strbuf[it];
        it++;
    }
}

void cpy_ptr::reserve(int n) {
    if (_length < n) {
        int newlength = n; //max(_length*2,n);
        char* newbuf = new char[newlength];
        //copy contents of the stored string in the new buffer
        this->revSmartCopy(newbuf);

        //return stuff from the new buffer to the stored buffer
        delete[] this->_strbuf;
        this->_strbuf = newbuf;
        this->_length = newlength;
    }
}

//append a character at the end of this String, which has already made a reservation
//Main Assumption: the length has been allocated but not yet utilized and the 
//length counter has not been increased.

void cpy_ptr::append(char c) {
    //this->_strbuf[this->_length - 1] = c;
	

	char* ret = new char[this->_length+2];

	strcpy(ret, _strbuf);    
    ret[this->_length] = c;
    ret[this->_length+1] = '\0';

	_strbuf = ret;
	
}
//get length of the string

int cpy_ptr::length() const {
    return this->_length;
}

//get character at index if it is less than length

char cpy_ptr::charAt(int index) const {
    if (index < _length) {
        return _strbuf[index];
    } else {
        //throw new IndexOutOfBoundException();

    }
}

void cpy_ptr::display() {
	cout<<"String:	"<<_strbuf<<"	Reference Count:	"<<*_refcount<<endl;
}

