#ifndef COWREFERENCECOUNTING_H
#define	COWREFERENCECOUNTING_H

class COW_refCount{
public :
    COW_refCount();
    ~COW_refCount();
    COW_refCount(const COW_refCount&);
    COW_refCount(char*,int);

    char charAt(int) const;
    int length() const;
    void smartCopy(char*,int);
    void smartCopy(COW_refCount*);
    void revSmartCopy(char* newString);
    void reserve(int);
    void append(char);
    int _refcount;
private:
    char* _strbuf;
    int _length;
    
};

#endif	/* COWREFERENCECOUNTING_H */

