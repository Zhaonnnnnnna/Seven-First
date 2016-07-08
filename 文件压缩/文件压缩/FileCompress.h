#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning (disable:4996)

#pragma once

#include"HuffmanTree.h"
#include<string>
#include<stdio.h>
#include<stdlib.h>


typedef unsigned long longType;

struct CharInfo
{
	unsigned char _ch; //字符
	longType _count;    //字符出现的次数
	string _code;      //字符对应的编码
	
	CharInfo(longType count = 0)
		:_count(count)
	{}

	CharInfo operator+(const CharInfo& infos) const
	{
		return CharInfo(this->_count + infos._count);
	}

	/*bool operator<(const CharInfo& infos) const
	{
		if (this->_count < infos._count)
			return true;
		else
			return false;
	}*/

	bool operator != (const CharInfo& infos) const
	{														   
		if (_count != infos._count)
			return true;
		else
			return false;
	}

	bool operator <= (const CharInfo& infos) const
	{
		if (_count <= infos._count)
			return true;
		else
			return false;
	}

};



template<class T>
class FileCompress
{
public:
	FileCompress()
	{
		int i = 0;
		for (i = 0; i < 256; i++)
		{
			_infos[i]._ch = (unsigned char)i;
			_infos[i]._count = 0;
		}
	}

	void GetHuffmanCode(HuffmanTreeNode<CharInfo>* root, string code)
	{
		if (root == NULL)
			return;

		if (root->_left == NULL&&root->_right == NULL)
		{
			_infos[root->_weight._ch]._code = code;
			//root->_weight._code = code;
		}
		else
		{
			GetHuffmanCode(root->_left, code + '0');
			GetHuffmanCode(root->_right, code + '1');
		}
	}

	void Compress(string filename)
	{
		FILE* fRead = NULL;
		fRead = fopen((filename).c_str(), "rb");
		assert(fRead);

		//统计文件中字符出现的次数
		unsigned char ch = fgetc(fRead);
		while (!feof(fRead))
		{
			_infos[ch]._count++;
			ch = fgetc(fRead);
		}

		//生成HuffmanTree
		CharInfo invalid;
		HuffmanTree<CharInfo> tree(_infos, 256, invalid);

		//生成HuffmanCode
		string code;
		GetHuffmanCode(tree.GetRoot(), code);

		//把对应的字符的编码压缩并放进压缩文件
		FILE* fWrite = fopen((filename + ".Huffman").c_str(), "wb");
		//FILE* fWrite = fopen("Huffman.txt", "wb");
		assert(fWrite);

		fseek(fRead, 0, SEEK_SET);
		ch = fgetc(fRead);

		unsigned char c = 0;
		int index = 0;
		char num = 0;
		while (!feof(fRead))
		{
			int size = _infos[(unsigned char)ch]._code.size();
			for (int i = 0; i < size; i++)
			{
				if (index == 7)
				{
					c = c | _infos[ch]._code[i] - '0';
					fputc(c, fWrite);
					index = 0;
					c = 0;
					continue;
				}

				num = _infos[ch]._code[i] - '0';
				c = c | (num << (7 - index));
				num = 0;
				index++;
			}
			ch = fgetc(fRead);
		}

		//最后一个可能不够八位，也要放进去
		fputc(c, fWrite);

		//写配置文件
		FILE* fconfig = fopen("config.txt", "wb");
		assert(fconfig);
		for (int i = 0; i < 256; i++)
		{
			if (_infos[i]._count != 0)
			{
				fputc(_infos[i]._ch, fconfig);
				fputc(',', fconfig);
				char buf[100];
				char *str = _itoa(_infos[i]._count, buf, 10);
				fputs(str, fconfig);
				fputc('\n', fconfig);
			}
		}

		fclose(fRead);
		fclose(fconfig);
		fclose(fWrite);
	}

	bool GetLine(FILE* fconfig, string& str)
	{
		unsigned char ch = fgetc(fconfig);

		if (feof(fconfig))
			return false;
		else
		{
			if (ch == '\n')
			{
				str += ch;
				ch = fgetc(fconfig);
			}

			while (ch != '\n')
			{
				str += ch;
				ch = fgetc(fconfig);
			}
			return true;
		}
		
	}

	void UnCompress(const string filename)
	{
		//读配置文件重新生成HuffmanTree
		FILE* fconfig = fopen("config.txt", "rb");
		assert(fconfig);

		string str;
		while (GetLine(fconfig, str))
		{
			char* _str = (char*)str.c_str();
		    _infos[(unsigned char)(*_str)]._count =atoi(_str + 2);
			str.clear();
		}

		//生成HuffmanTree
		CharInfo invalid ;
		HuffmanTree<CharInfo> tree(_infos, 256, invalid);

		//生成HuffmanCode
		string code;
		GetHuffmanCode(tree.GetRoot(), code);


		FILE* fWrite = fopen((filename + ".UnHuffman") .c_str(), "wb");
		//FILE* fWrite = fopen("UnHuffman.txt", "wb");
		assert(fWrite);

		//FILE* fRead = fopen((filename + ".Huffman").c_str(), "r");
		FILE* fRead = fopen(filename.c_str() , "rb");
		assert(fRead);

		HuffmanTreeNode<CharInfo>* cur = tree.GetRoot();
		HuffmanTreeNode<CharInfo>* root = tree.GetRoot();

		unsigned char ch;
		ch = getc(fRead); 
		char tmp = 0;
		int index = 7;
		int Sum = tree.GetRoot()->_weight._count;
		while (!feof(fRead) && Sum != 0)
		{
			while ((index + 1) && (Sum != 0))
			{
				//拿到压缩文件的字符的第一位
				tmp = 1 << index;
				if (ch&tmp)
					tmp = 1;
				else
					tmp = 0;

				//拿位找字符
				if (tmp)
					cur = root->_right;
				else
					cur = root->_left;

				if (cur->_left != NULL&&cur->_right != NULL)
					root = cur;

				if (cur->_left == NULL&&cur->_right == NULL)
				{
					if (_infos[cur->_weight._ch]._count != 0)
					{
						//找到编码对应的字符并放进解压文件里
						fputc(_infos[cur->_weight._ch]._ch, fWrite);
						_infos[cur->_weight._ch]._count--;
						Sum--;
						root = tree.GetRoot();
					}
				}

				index--;
			}

			ch = getc(fRead);
			index = 7;
			tmp = 0;
		}

		fclose(fconfig);
		fclose(fWrite);
	}


protected:
	CharInfo _infos[256];
};