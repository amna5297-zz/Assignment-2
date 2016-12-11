/* 
 * File:   main.cpp
 *
 * Created on February 16, 2016, 9:51 PM
 */

#include <cstdlib>
#include <iostream>
#include <string.h>
#include <cstring>
#include "StringBuffer.h"
#include "String.h"
#include "copyPointer.h"
#include "OwnedPointer.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

//    //create a smart string
////    String ss;
//    //create a smart string with const char*
//    char* hello = "hello";
//    
//    
//    
//    String ss2(hello,5);
//    std::cout<<"ss2 length = "<<ss2.length()<<std::endl;
//    cout<<hello<<endl;
//    //multiple references
//    String ss(ss2);
//    cout<<hello<<endl;
//    //output statements
//    std::cout<<"ss length = "<<ss.length()<<std::endl;
//    std::cout<<"new ss charAt 0 = "<<ss.charAt(0)<<std::endl;
//    
//    //append a character
//    ss2.append('w');
//    
//    //cout<<hello<<endl;
//    //hello = "bye";
//    
//    std::cout<<"new ss length = "<<ss.length()<<std::endl;
//    std::cout<<"new ss2 length = "<<ss2.length()<<std::endl;
    
	/****************		COPY POINTER		*******************************/

	cout<<"\n\ncpy_ptr<a>"<<endl;
	cpy_ptr a("Hello",5);

	cout<<"\n\ncpy_ptr<b>"<<endl;
	cpy_ptr b(a);

	cout<<"\n\ncpy_ptr<c>"<<endl;
	cpy_ptr c(a);

	cout<<"cpy_ptr<b>	"<<*b._refcount;

	char n = 'a';
	a.append(n);

	//	Display pointers //
	cout<<endl<<endl;
	a.display();
	b.display();
	c.display();


	/****************		OWNED POINTER		*******************************/

	cout<<"\n		OWNED POINTER"<<endl;
	
	//cout<<"own_ptr o('Own',3);"<<endl;
	own_ptr o("Own",3);
	own_ptr k (o);
	cout<<"After Ownership transfered:	own_ptr o('Own',3);"<<endl;
	cout<<"o.display();		";
	o.display();
	cout<<"k.display();		";
	k.display();


	/******************		COW with reference Counting		*******************/














	/******************		COW with reference Linking		*******************/




	int exit;
	cin>>exit;

    return 0;
}

