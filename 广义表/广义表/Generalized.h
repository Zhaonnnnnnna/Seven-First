#pragma once;
#include<iostream>
using namespace std;
#include<assert.h>

enum Type
{
	HEAD,
	VALUE,
	SUB,
};

struct GeneralizedNode
{
	Type _type;                     //结点类型
	GeneralizedNode* _next;
	union
	{
		char _value;                //若为值类型结点，则存储值
		GeneralizedNode* _sublink;  
	};

	GeneralizedNode(Type type = HEAD,char value=0)
		:_type(type)
		, _next(NULL)
	{
		if (_type == VALUE)
		{
			_value = value;
		}
		else if (_type == SUB)
		{
			_sublink = NULL;
		}
	}
};

class Generalized
{
public:
	Generalized()
	    :_head(NULL)
	{}

	Generalized(const char* str)
		:_head(NULL)
	{
		_head = _CreateLized(str);   
	}

	Generalized(const Generalized& g)
	{
		_head = _Copy(g._head);
	}

	Generalized& operator=(const Generalized& g)
	{
		if (_head != g._head)
		{
			GeneralizedNode* cur = _head;
			_Destory(_head);
			_head = _Copy(g._head);
			return *this;
		}
	}

	~Generalized()
	{
		_Destory(_head);
	}
public:
	void Print()
	{
		_Print(_head);
		cout << endl;
	}
	size_t Size()
	{
		size_t count = _Size(_head);
		return count;
	}

	size_t Depth()
	{
		size_t dep = _Depth(_head);
		return dep;
	}

protected:
	//创建表
	GeneralizedNode* _CreateLized(const char*& str)//传参用引用是为了防止str在退出一层
	{                                              //递归时发生回退
		assert(str&&*str == '(');     //若当前str是不为‘（’，则传参错误
		str++;                       

		GeneralizedNode* head = new GeneralizedNode(HEAD);
		GeneralizedNode* cur = head;
		while (*str != '\0')
		{
			if (_Isvalue(*str))
			{
				GeneralizedNode* tmp = new GeneralizedNode(VALUE, *str);
				cur->_next = tmp;
				cur = cur->_next;
				str++;
				continue;
			}
			else if (*str == '(')   //遇到子表
			{
				GeneralizedNode* sub = new GeneralizedNode(SUB);
				cur->_next = sub;
				cur = cur->_next;
				sub->_sublink = _CreateLized(str);  //进入递归创建子表
				continue;
			}
			else if (*str == ')')  //一个表的结束
			{
				str++;
				return head;
			}
			else
			{
				str++;
				continue;
			}
			assert(false);  //强制判断程序是否出错
			return head;
		}
	}

	//判断当前值是否为有效值
	bool _Isvalue(const char c)
	{
		if ((c <= '9'&&c >= '0') || (c <= 'z'&&c >= 'a') || (c <= 'Z'&&c >= 'A'))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//拷贝一个表
	GeneralizedNode* _Copy(GeneralizedNode* head)
	{
		GeneralizedNode* Head = new GeneralizedNode(HEAD);
		//_head = Head;
		GeneralizedNode* cur = head->_next;
		GeneralizedNode* tmp = Head;
		while (cur)
		{
			if (cur->_type == VALUE)
			{
				tmp->_next = new GeneralizedNode(VALUE, cur->_value);
				cur = cur->_next;
				tmp = tmp->_next;
			}
			else if (cur->_type == SUB)
			{
				tmp->_next = new GeneralizedNode(SUB);
				//cur = cur->_next;
				tmp = tmp->_next;
				tmp->_sublink = _Copy(cur->_sublink);  //进入拷贝表的递归
				cur = cur->_next;
			}
		}
		return Head;
	}

	//打印表
	void _Print(GeneralizedNode* head)
	{
		GeneralizedNode* cur = head;
		while (cur)
		{
			if (cur->_type == HEAD)
			{
				cout << "(" << " ";
				cur = cur->_next;
				continue;
			}
			else if ((cur->_type == VALUE) && (cur->_next != NULL))
			{
				cout << cur->_value << " " << ",";
				cur = cur->_next;
				continue;
			}
			else if ((cur->_type == VALUE) && (cur->_next == NULL))//遇到一个表的最后一个节点
			{
				cout << cur->_value << " ";
				cur = cur->_next;
				continue;
			}
			else if (cur->_type == SUB)
			{
				_Print(cur->_sublink);                //进入打印表的递归
				cur = cur->_next;
				if (cur != NULL)      //说明此时的表并不是最外层的表，需要打印‘，’
				{
				   cout << ",";
				}	
				continue;
			}			
		}
		if (cur == NULL)
		{
			cout << ")";
			return;
		}
	}

	//销毁表
	void _Destory(GeneralizedNode* head)
	{
		GeneralizedNode* cur = head;
		while (cur)
		{
			if (cur->_type  == SUB)
			{
				_Destory(cur->_sublink);  //进入销毁表的递归
			}
			GeneralizedNode* del = cur;
			cur = cur->_next;
			delete del;
		}
		return;
	}

	//求表的大小
	size_t _Size(GeneralizedNode* head)
	{
		size_t count = 0;
		GeneralizedNode* cur = head;
		while (cur)
		{
			if (cur->_type == VALUE)
			{
				count++;
				cur = cur->_next;
				continue;
			}
			if (cur->_type == SUB)
			{
				count += _Size(cur->_sublink); //进入递归
				cur = cur->_next;
				continue;
			}
			cur = cur->_next;
		}
		return count;
	}

	//求表的深度
	size_t _Depth(GeneralizedNode* head)
	{
		assert(head);
		size_t dep = 1;
		size_t Dep = 0;
		GeneralizedNode* cur = head;
		while (cur)
		{	
			if (cur->_type == SUB)
			{
				dep += _DepthSUB(cur->_sublink); 
			}
			cur = cur->_next;
			if (Dep < dep)   //用Dep来保存最深的深度
			{
				Dep = dep;
				dep = 1;
			}
		}
		
		return Dep;
	}
	//求子表长度
	size_t _DepthSUB(GeneralizedNode* sub)
	{
		GeneralizedNode* cur = sub;
		size_t dep = 1;
		while (cur)
		{
			if (cur->_type == SUB)
			{
				dep = dep + _DepthSUB(cur->_sublink);
			}
			cur = cur->_next;
		}
		return dep;
	}

protected:
	GeneralizedNode* _head;
};