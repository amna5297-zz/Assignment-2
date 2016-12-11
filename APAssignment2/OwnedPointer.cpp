#define _CRT_SECURE_NO_WARNINGS
#include "OwnedPointer.h"
#include <memory>
#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;
//default constructor

own_ptr::own_ptr() {
    this->_strbuf = 0;
    this->_length = 0;
}
//destructor

own_ptr::~own_ptr() {
   this->_strbuf = NULL;
}

//copy a const own_ptr into this string

own_ptr::own_ptr(own_ptr& newString) {

	this->_strbuf = newString._strbuf;
    this->_length = newString.length();

    //copy the passed string into internal buffer
	newString._strbuf = NULL;
	newString._length = 0;
	cout<<"ownership transfered"<<endl;
	
	//cout<<"string:	"<<newString._strbuf<<endl;
	cout<<"string copy:	"<<this->_strbuf<<endl;
}

//copy a char* into your string

own_ptr::own_ptr(char* newString, int length) {
	
    _length = length;
    _strbuf = new char[length];
    _strbuf = newString;
	
	cout<<"own_ptr		"<<newString<<"	ref_count	"<<endl;

    //Should I delete the string passed by the user?
    //delete[] newString;

}

//make a smart copy of the own_ptr into the callee own_ptr

void own_ptr::smartCopy(own_ptr* newString) {
    int shorterLength = 0;
    (this->_length < newString->_length) ? shorterLength = this->_length : shorterLength = newString->_length;
    int it = 0;
    while (it < shorterLength) {
        *_strbuf++ = *(newString->_strbuf)++;
        it++;
    }
}

//make a smart copy of the char* into this string

void own_ptr::smartCopy(char* newString, int length) {
    //(this->_length == length)?:this->_length=length;
    this->_length = length;
    int it = 0;
    while (it < length) {
        *_strbuf++ = *newString++;
        it++;
    }
}
//make a smart copy of this string into the passed string

void own_ptr::revSmartCopy(char* newString) {
    int it = 0;
    while (it < _length) {
        newString[it] = _strbuf[it];
        it++;
    }
}

void own_ptr::reserve(int n) {
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

void own_ptr::append(char c) {
    //this->_strbuf[this->_length - 1] = c;
	

	char* ret = new char[this->_length+2];

	strcpy(ret, _strbuf);    
    ret[this->_length] = c;
    ret[this->_length+1] = '\0';

	_strbuf = ret;
	
}
//get length of the string

int own_ptr::length() const {
    return this->_length;
}

//get character at index if it is less than length

char own_ptr::charAt(int index) const {
    if (index < _length) {
        return _strbuf[index];
    } else {
        //throw new IndexOutOfBoundException();

    }
}

void own_ptr::display() {
	if(_strbuf != NULL){
		cout<<"String:	"<<_strbuf<<endl;
	}
	else{
		cout<<"NULL"<<endl;
	}
}

