#ifndef COPYPOINTER_H
#define	COPYPOINTER_H


class cpy_ptr{
public :
    cpy_ptr();
    ~cpy_ptr();
    cpy_ptr(cpy_ptr&);
    cpy_ptr(char*,int);

    char charAt(int) const;
    int length() const;
	void display();
    void smartCopy(char*,int);
    void smartCopy(cpy_ptr*);
    void revSmartCopy(char* newString);
    void reserve(int);
    void append(char);
    int* _refcount;										//declare reference count pointer

private:
    char* _strbuf;
    int _length;    
};



#endif	/* COPYPOINTER_H */