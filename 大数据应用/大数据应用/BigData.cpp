#include"BigData.h"

BigData:: BigData(INT64 value)
          :_value(value)
{
	int count = 0;
	INT64 tmp = _value;
	while (tmp)
	{
		count++;
		tmp /= 10;
	}

	int size = count + 1;
	_str.resize(size);
	if (_value > 0)
	{
		_str[0] = '+';
		tmp = _value;
	}
	else
	{
		_str[0] = '-';
		tmp = -_value;
	}

	
	char cRet = 0;
	while (tmp)
	{
		cRet = tmp % 10 + '0';
		tmp /= 10;
		_str[count--] = cRet;
	}
}

BigData::BigData(const char* a)
{
	assert(a);
	char cSymbol = a[0];

	if (a[0] <= '9'&&a[0] >= '0')
	{
		cSymbol = '+';
	}
	else if (a[0] == '+' || a[0] == '-')
	{
		a++;
	}
	else
	{
		_value = VALUE;
		return;
	}

	while (*a == '0')
	{
		a++;
	}

	_str.resize(strlen(a) + 1);
	_str[0] = cSymbol;

	int iCount = 1;
	_value = 0;
	while (*a >= '0'&& *a <= '9')
	{
		_str[iCount++] = *a;
		_value = _value * 10 + *a - '0';
		a++;
	}

	if (cSymbol == '-')
	{
		_value = 0 - _value;
	}

	_str.resize(iCount);
}

bool BigData::IsINT64Overflow()const //const修饰this
{
	string tmp("+9223372036854775807‬");
	
	if (_str[0] == '-')
	{
		tmp = "-9223372036854775808‬";
		        // -4444444444222222
	}
	tmp.resize(20);
	if (_str.size() < tmp.size() )
	{
		return false;
	}				   
	
	else if (_str.size() == tmp.size())
	{
			if ((strcmp((char*)_str.c_str() + 1, (char*)tmp.c_str() + 1) <= 0))
			{
				return false;
	     	}		
	}
	else
	{
		return true;
	}
}

ostream& operator<<(ostream& os, const BigData& bigData)
{
	if (bigData._str == "")
	{
		os << bigData._value;
	}
	if (!bigData.IsINT64Overflow())
	{
		os << bigData._value;
	}
	else
	{
		char* pData = (char*)bigData._str.c_str();//
		if (bigData._str[0] == '+')
		{
			pData++;
			os << pData;
		}
		else
		{
			os << pData;
		}
	}
	return os;
}


BigData BigData::operator+(const BigData& bigData)
{
	//两个数都没有溢出
	if (!IsINT64Overflow() && !bigData.IsINT64Overflow())
	{
		if (_str[0] != bigData._str[0])
		{
			return (_value + bigData._value);
		}
		//两个数正负相同并且相加不会溢出
		else
		{
			//10 3 8 7<8  6
			//-10 -7 -5 -5>-7 -3
			if (_str[0] == bigData._str[0])
			{
				if ((_str[0] == '+'&&MAX - _value >= bigData._value) ||
					(_str[0] == '-'&&MIN - _value <= bigData._value))
				{
					return _value + bigData._value;
				}
			}
		}
	}

	//至少有一个数溢出或者相加结果溢出
	if (_str[0] == bigData._str[0])
	{
		return BigData((char*)ADD(_str, bigData._str).c_str());
	}

	return BigData((char*)SUB(_str, bigData._str).c_str());
}

string BigData::ADD(string left, string right)
{
	int Lsize = left.size();
	int Rsize = right.size();

	if (Lsize < Rsize)
	{
		swap(left, right);
		swap(Lsize, Rsize);
	}

	string strRet;
	strRet.resize(Lsize + 1,'0');
	strRet[0] = left[0];

	//逐位相加
	char cstep = 0;
	for (int iIdx = 1; iIdx < Lsize; iIdx++)
	{
		char cRet = left[Lsize - iIdx] - '0' + cstep;
		if (iIdx < Rsize)
		{
			cRet += right[Rsize - iIdx] - '0';
		}

		strRet[Lsize - iIdx + 1] = cRet % 10 + '0';
		cstep = cRet / 10;
	}

	strRet[1] = cstep + '0';

	return strRet;
}


BigData BigData::operator-(const BigData& bigData)
{
	//两个数都没有溢出
	if (!IsINT64Overflow() && !bigData.IsINT64Overflow())
	{
		//同号相减不会溢出
		if (_str[0] == bigData._str[0])
		{
			return (_value - bigData._value);
		}
		//异号相减结果不会溢出
		else if ((_str[0] == '+'&&MIN + _value <= bigData._value) ||
			(_str[0] == '-'&&MAX + _value >= bigData._value))
		{
			return (_value - bigData._value);
		}
	}

	string strRet;
	//至少有一个溢出或者相减结果会溢出
	if (_str[0] != bigData._str[0])
	{
		return ((char *)ADD(_str, bigData._str).c_str());
	}
	return ((char *)SUB(_str, bigData._str).c_str());

}

string BigData::SUB(string left, string right)
{
	char* pleft = (char *)left.c_str();
	char* pright = (char *)right.c_str();

	int Lsize = left.size();
	int Rsize = right.size();

	string strRet;
	strRet.resize(Lsize);

	if (Lsize == Rsize)
	{
		if ((strcmp(pleft, pright) >= 0 && left[0] == '+') ||
			(strcmp(pleft, pright) < 0 && left[0] == '-'))
		{
			strRet[0] = '+';
		}
		else
		{
			strRet[0] = '-';
		}
	}

	if (Lsize < Rsize)
	{
		if (left[0] == '-')
		{
			strRet[0] = '+';
		}
		else
		{
			strRet[0] = '-';
		}
		swap(left, right);
		swap(Lsize, Rsize);
		strRet.resize(Lsize);
	}

	//逐位相减
	for (int iIdx = 1; iIdx <= Lsize; iIdx++)
	{
		char cRet = left[Lsize - iIdx] - '0';
		if (iIdx <= Rsize)
		{
			cRet -= right[Rsize - iIdx] - '0';
		}
		if (cRet < 0)
		{
			cRet += 10;
			left[Lsize - iIdx - 1] -= 1;
		}
		strRet[Lsize - iIdx] = cRet + '0';
	}

	return strRet;
}

BigData BigData::operator*(const BigData& bigData)
{
	//两个数都没有溢出
	if (!IsINT64Overflow() && !bigData.IsINT64Overflow())
	{
		//同号相乘不会溢出
		if (_str[0] == bigData._str[0])
		{
			if ((_str[0] == '+'&&MAX / _value >= bigData._value) ||
				(_str[0] == '-'&&MAX / _value <= bigData._value))
			{
				return (_value * bigData._value);
			}
		}

		//异号相乘不会溢出
		else
		{
			if ((_str[0] == '-'&&MIN / _value >= bigData._value) ||
				(_str[0] == '+'&&MIN / _value <= bigData._value))
			{
				return (_value * bigData._value);
			}
		}
	}

	//至少有一个溢出或者相乘结果溢出
	return ((char *)MUL(_str, bigData._str).c_str());
}


void MulAdd(string& tmp, int RIdx)
{
	string str;
	int size = tmp.size();
	str.resize(size + RIdx - 1, '0');
	int Tsize = size + RIdx - 1;

	for (int iIdx = 0; iIdx < size; iIdx++)
	{
		str[Tsize - 1 - RIdx + 1 - iIdx] = tmp[size - iIdx - 1];
	}

	tmp = str;
}

string BigData::MUL(string left, string right)
{
	int Lsize = left.size();
	int Rsize = right.size();
	if (Lsize < Rsize)
	{
		swap(left, right);
		swap(Lsize, Rsize);
	}

	string strRet;
	strRet.resize(Lsize + Rsize - 1, '0');

	if (left[0] == right[0])
	{
		strRet[0] = '+';
	}
	else
	{
		strRet[0] = '-';
	}

	//逐位相乘
	char cstep = 0;
	string tmp;
	tmp.resize(Lsize + 1, '0');
	string Inistring(tmp);
	//999999999999999
	// 9 9
	for (int RIdx = 1; RIdx < Rsize; RIdx++)
	{
		for (int LIdx = 1; LIdx < Lsize; LIdx++)
		{
			char cRet = right[Rsize - RIdx] - '0';
			cRet *= left[Lsize - LIdx] - '0';

			cRet += cstep;
			if (cRet>10)
			{
				cstep = cRet / 10;
				cRet = cRet % 10;
			}
			tmp[Lsize - LIdx + 1] = cRet % 10 + '0';
		}
		tmp[1] = cstep + '0';
		tmp[0] = '+';
	  cstep = 0;
	  
	  MulAdd(tmp, RIdx);   //统一向前移了一位
	  strRet = ADD(tmp, strRet);//相加结果保存在strRet中
	  tmp = Inistring;
	}
		
	return strRet;
}

BigData BigData::operator/(const BigData& bigData)
{
	assert(bigData._value != 0);
	BigData b("0");
	
	//被除数为零
	if (_value == 0)
	{
		return b;
	}


	if (!IsINT64Overflow() && !bigData.IsINT64Overflow())
	{
		return (_value / bigData._value);
	}
	
	if (_str.size() < bigData._str.size())
	{
		return b;
	}
	else if (_str.size() == bigData._str.size())
	{
		if (strcmp((char*)_str.c_str() + 1, (char*)bigData._str.c_str() + 1) < 0)
		{
			return b;
		}
		else if (strcmp((char*)_str.c_str() + 1, (char*)bigData._str.c_str() + 1) == 0)
		{
			if (_str[0] == bigData._str[0])
			{
				return 1;
			}
			else
				return -1;
		}
		else
		{
			return ((char*)DIV(_str, bigData._str).c_str());
		}

	}
	else
        return ((char*)DIV(_str, bigData._str).c_str());
}

bool BigData::IsLessThanDiv(string& tmp, string& pRight)
{
	char* pR = (char*)pRight.c_str();
	char* pT = (char*)tmp.c_str();

	while (pT[0] == '0')
	{
		pT++;
	}

	string S(pT);

	if (S.size() > pRight.size())
	{
		return false;
	}
	else
	{
		if (S. size() == pRight.size())
		{
			if (strcmp(pT, pR) < 0)
			{
				return true;
			}
			return false;
		}
	}
	return true;
}

int BigData::DivSub(string& tmp, string& pRight)
{
	int count = 0;
	char cRet = 0;
	while (!IsLessThanDiv(tmp,pRight))
	{
		count++;
		tmp = SUB(tmp, pRight);	
	}

	return count;
}


string BigData::DIV(string left, string right)
{
	int Lsize = left.size();
	int Rsize = right.size();

	string strRet;
	strRet.resize(1);

	if (left[0] != right[0])
	{
		strRet[0] = '-';
	}
	else
		strRet[0] = '+';

	string pLeft = (char*)left.c_str() + 1;
	string pRight = (char*)right.c_str() + 1;
	string tmp;
	tmp.resize(Rsize - 1, '0'); 
	int iIdx = 0;
	for (iIdx = 0; iIdx < Rsize-1; iIdx++)
	{
		tmp[iIdx] = pLeft[iIdx];
	}


	//判断除数是否小于当前被除数，若小于，则再取一位
	int index = 0;
	int count = 0;
	while (iIdx < pLeft.size())
	{
		//不能减
		if (IsLessThanDiv(tmp, pRight))
		{
			tmp.append(1, pLeft[iIdx++]);
		}

		//确定商
		count = DivSub(tmp, pRight);

		char c = count + '0';
		strRet.append(1, c);
	}
	
	return strRet;
}
