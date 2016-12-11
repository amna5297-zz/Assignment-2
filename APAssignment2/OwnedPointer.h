#ifndef OWNEDPOINTER_H
#define	OWNEDPOINTER_H


class own_ptr{
public :
    own_ptr();
    ~own_ptr();
    own_ptr(own_ptr&);
    own_ptr(char*,int);

    char charAt(int) const;
    int length() const;
	void display();
    void smartCopy(char*,int);
    void smartCopy(own_ptr*);
    void revSmartCopy(char* newString);
    void reserve(int);
    void append(char);
	char* _strbuf;
    int _length;    								//declare reference count pointer

private:
  
};



#endif	/* OWNEDPOINTER_H */