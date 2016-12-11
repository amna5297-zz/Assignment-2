#ifndef COWREFCOUNT_H
#define	COWREFCOUNT_H


class cow_ref{
public :
    cow_ref();
    ~cow_ref();
    cow_ref(cow_ref&);
    cow_ref(char*,int);

    char charAt(int) const;
    int length() const;
	void display();
    void smartCopy(char*,int);
    void smartCopy(cow_ref*);
    void revSmartCopy(char* newString);
    void reserve(int);
    void append(char);
    int* _refcount;										//declare reference count pointer

private:
    char* _strbuf;
    int _length;    
};



#endif	/* COWREFCOUNT_H */