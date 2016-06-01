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
	Type _type;                     //�������
	GeneralizedNode* _next;
	union
	{
		char _value;                //��Ϊֵ���ͽ�㣬��洢ֵ
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
	//������
	GeneralizedNode* _CreateLized(const char*& str)//������������Ϊ�˷�ֹstr���˳�һ��
	{                                              //�ݹ�ʱ��������
		assert(str&&*str == '(');     //����ǰstr�ǲ�Ϊ���������򴫲δ���
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
			else if (*str == '(')   //�����ӱ�
			{
				GeneralizedNode* sub = new GeneralizedNode(SUB);
				cur->_next = sub;
				cur = cur->_next;
				sub->_sublink = _CreateLized(str);  //����ݹ鴴���ӱ�
				continue;
			}
			else if (*str == ')')  //һ����Ľ���
			{
				str++;
				return head;
			}
			else
			{
				str++;
				continue;
			}
			assert(false);  //ǿ���жϳ����Ƿ����
			return head;
		}
	}

	//�жϵ�ǰֵ�Ƿ�Ϊ��Чֵ
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

	//����һ����
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
				tmp->_sublink = _Copy(cur->_sublink);  //���뿽����ĵݹ�
				cur = cur->_next;
			}
		}
		return Head;
	}

	//��ӡ��
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
			else if ((cur->_type == VALUE) && (cur->_next == NULL))//����һ��������һ���ڵ�
			{
				cout << cur->_value << " ";
				cur = cur->_next;
				continue;
			}
			else if (cur->_type == SUB)
			{
				_Print(cur->_sublink);                //�����ӡ��ĵݹ�
				cur = cur->_next;
				if (cur != NULL)      //˵����ʱ�ı����������ı���Ҫ��ӡ������
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

	//���ٱ�
	void _Destory(GeneralizedNode* head)
	{
		GeneralizedNode* cur = head;
		while (cur)
		{
			if (cur->_type  == SUB)
			{
				_Destory(cur->_sublink);  //�������ٱ�ĵݹ�
			}
			GeneralizedNode* del = cur;
			cur = cur->_next;
			delete del;
		}
		return;
	}

	//���Ĵ�С
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
				count += _Size(cur->_sublink); //����ݹ�
				cur = cur->_next;
				continue;
			}
			cur = cur->_next;
		}
		return count;
	}

	//�������
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
			if (Dep < dep)   //��Dep��������������
			{
				Dep = dep;
				dep = 1;
			}
		}
		
		return Dep;
	}
	//���ӱ���
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