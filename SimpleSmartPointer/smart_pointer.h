#ifndef SMART_POINTER_H
#define SMART_POINTER_H

#include <String>

///reference counter class
class RC
{
private:
    int counter;
public:
    int addRef()
    {
        return ++counter;
    }
    int releaseRef()
    {
        return --counter;
    }
};

/// SSPointer - simple smart pointer
template <class T>
class SSPointer
{
private:
    T*  pointer;
    /// reference counter
    RC* reference;
public:
    SSPointer(T *_ptr): pointer{_ptr}, reference(new RC) { reference->addRef(); }
    SSPointer(): pointer{NULL}, reference(new RC) { reference->addRef();}
    T& operator *() {return *pointer;}
    T* operator->(){return pointer;}
    ~SSPointer()
    {
        if(reference->releaseRef() == 0)
        {
            delete pointer;
            delete reference;
        }
    }
    SSPointer<T>& operator = (const SSPointer<T>& sp_in)
    {
        if(this == &sp_in)
            return this;

        ///decrement reference counter before new assignment
        if(reference->releaseRef() == 0)
        {
            delete pointer;
            delete reference;
        }

        pointer   = sp_in.pointer;
        reference = sp_in.reference;
        /// add new linked object, so increase counter
        reference->addRef();

        return *this;
    }
    /// make prefix increment. just for fun.
    SSPointer<T>& operator ++()
    {
        reference->addRef();
        return *this;
    }
    /// make postfix increment. the same reason as for prefix =)
    SSPointer<T> operator ++(int)
    {
        SSPointer<T> tmp = *this;
        ++(*this);
        return tmp;
    }
};

///
template <>
class StringSmartPointer <std::string>
{
private:
    std::string m_string;
public:
    StringSmartPointer(std::string _str): m_string(str)
    {
        if(m_string == NULL)
        {
            m_string = new std::string;
        }
    }
};



#endif // SMART_POINTER_H

