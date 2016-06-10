#pragma once;
#include<iostream>
#include<malloc.h>
#include<stdio.h>

template<class T>
class AutoPtr
{
	//friend ostream& operator<< <T>(ostream& os, const AutoPtr<T>& ap);
public:
	AutoPtr(T* ptr)
		:_ptr(ptr)
		, owner(true)
	{}
	~AutoPtr()
	{
		if (owner)
		{
			delete _ptr;
		}
	}
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
		, owner(true)
	{
		ap._ptr = NULL;
		ap.owner = false;
	}
public:
	AutoPtr<T>& operator=(const AutoPtr<T>& ap)
	{
		if (this != ap)
		{
			delete _ptr;
			_ptr = ap._ptr;
			ap._ptr = NULL;
			return _ptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
public:
	T* GetPtr()
	{
		return _ptr;
	}

private:
	T* _ptr;
	bool owner;
};
//template<class T>
//ostream& operator<< <T>(ostream& os, const AutoPtr<T>& ap)
//{
//	os << *(ap._ptr) << endl;
//	return os;
//}
class A
{

public:
	int _a;
};




template<class T, class Del = Delete<T>>
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _pcount(new int(1))
	{}
	SharedPtr(T* ptr, Del del)
		:_ptr(ptr)
		, _pcount(new int(1))
		, _del(del)
	{}
	~SharedPtr()
	{
		_Release();
	}
	SharedPtr(SharedPtr<T, Del>& sp)
	{
		_ptr = sp._ptr;
		_pcount = sp._pcount;
		(*_pcount)++;
	}
public:
	SharedPtr<T, Del>& operator=(const SharedPtr<T, Del>& sp)
	{
		if (_ptr != sp._ptr)
		{
			_Release();
			_ptr = sp._ptr;
			_pcount = sp._pcount;
			(*_pcount)++;
		}
		return *this;
	}

	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	long UseCount()
	{

		return *(_pcount);
	}
	T* GetPtr()
	{
		return _ptr;
	}

private:
	T* _ptr;
	int* _pcount;
	Del _del;

	void _Release()
	{
		if (--(*_pcount) == 0)
		{
			_del(_ptr);
			delete(_pcount);
		}
	}
};

template<class T>
struct Free
{
	void operator()(void* ptr)
	{
		cout << "free" << endl;
		free(ptr);
		ptr = NULL;
	}
};

template<class T>
struct Delete
{
	void operator()(T* ptr)
	{
		cout << "Del" << endl;
		delete(ptr);
		ptr = NULL;
	}
};

template<class T>
struct Fclose
{
	void operator()(void* ptr)
	{
		cout << "Fclose" << endl;
		fclose((FILE*)ptr);
	}
};


template<class T>
class ScopedPtr
{
public:
	ScopedPtr(T* ptr)
		:_ptr(ptr)
	{}
	~ScopedPtr()
	{
		if (_ptr != NULL)
		{
			delete _ptr;
		}
	}
protected:
	ScopedPtr(const ScopedPtr<T>& sp);
	ScopedPtr<T>& operator=(ScopedPtr<T>& sp);
public:
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};

template<class T>
class ScopedArr
{
public:
	ScopedArr(T* arr)
		:_arr(arr)
	{}
	~ScopedArr()
	{
		if (_arr != NULL)
		{
			delete[] _arr;
		}
	}
protected:
	ScopedArr(const ScopedArr<T>& sp);
	ScopedArr<T>& operator=(const ScopedArr<T>& sp);
public:
	T& operator[](int index)
	{
		return _arr[index];
	}
private:
	T* _arr;
};

template<class T>
class SharedArr
{
public:
	SharedArr(T* arr)
		:_arr(arr)
		, _pcount(new long(1))
	{}
	~SharedArr()
	{
		if (--(*_pcount) == 0)
		{
			delete[] _arr;
			delete _pcount;
		}
	}
	SharedArr(SharedArr<T>& sp)
	{
		_arr = sp._arr;
		_pcount = sp._pcount;
		(*_pcount)++;
	}
public:
	SharedArr<T>& operator=(SharedArr<T>& sp)
	{
		if (_arr != sp._arr)
		{
			if (--(*_pcount) == 0)
			{
				delete[] _arr;
				delete _pcount;
			}
			_arr = sp._arr;
			_pcount = sp._pcount;
			(*_pcount)++;
		}
		return *this;
	}
	T& operator[](int index)
	{
		return _arr[index];
	}
	long UseCount()
	{

		return *(_pcount);
	}
	T* GetPtr()
	{
		return _arr;
	}
private:
	T* _arr;
	long* _pcount;
};

