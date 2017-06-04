#ifndef _HT_H_
#define _HT_H_

#include "node.h"
#include <iostream>
#include <string>
#include <fstream>

template <class KEY, class DATA>
class Table
{
protected:
	int size; 
	int count;
	int p; 
	Node<KEY,DATA>* mas; 
	int Hash(KEY K);
public:
Table(int size_ = 1,int p_ =11); 
Table(Table& ht);
~Table();
DATA& operator[](KEY k_);
Table& operator=(Table& ht);
void Add(DATA val_,KEY k_);
void Del(KEY k_);
void resize(int newSize);
void saveInFile(std::string name)
{
	std::ofstream fout(name);
	for(int i=0;i<size;i++)
	{
		if (mas[i].isUse() == false)
			continue;
		fout << mas[i].GetKey() << std::endl << mas[i].GetData() << std::endl;
	} 
	fout.close();
}
};

template <class KEY, class DATA>
Table<KEY, DATA>::Table(int size_, int p_)
{
	size = size_;
	count = 0;
	p = p_;
	mas = new Node<KEY,DATA>[size];
}

template <class KEY, class DATA>
Table<KEY, DATA>::Table(Table& ht)
{
	size=ht.size;
	count=ht.count;
	p=ht.p;
	mas=new Node<KEY,DATA>[ht.size];
	for(int i=0; i<ht.size;++i)
		mas[i]=ht.mas[i];

}

template <class KEY, class DATA>
Table<KEY, DATA>::~Table()
{
	delete[] mas;
	size=0;
	count=0;
}

template <class KEY, class DATA>
int Table<KEY, DATA>:: Hash(KEY K)
{
	return ((int)K*17)% size;

}
template <class KEY, class DATA>
DATA& Table<KEY, DATA>::operator[](KEY K)
{
	int index=Hash(K);
	int HashIndex=index;
	do
	{
		if (mas[index].isUse() == false)
			break;
	if(mas[index].GetKey()==K)
		return mas[index].GetData();
	else
		index= (index + p) % size;
	} while (index != HashIndex);
	throw 5;
}

template<class KEY, class DATA>
Table<KEY,DATA> & Table<KEY, DATA>::operator=(Table & ht)
{
	size = ht.size;
	count = ht.count;
	p = ht.p;
	mas = new Node[ht.size];
	for (int i = 0; i<ht.size; ++i)
		mas[i] = ht.mas[i];
}

template <class KEY, class DATA>
void Table<KEY, DATA>::Add(DATA val_, KEY k_)
{
	int index=Hash(k_);
	int HashIndex=index;
	do
	{

	if(mas[index].isUse() ==false || mas[index].GetKey() == k_)
	{
		mas[index].SetKey(k_);
		mas[index].SetVal(val_);
		mas[index].setUse(true);
		return;

	}
	else
		index= (index+p)%size;
	} while (index != HashIndex);
	throw 22;
}

template<class KEY, class DATA>
void Table<KEY, DATA>::Del(KEY k_)
{
	int index = Hash(k_);
	int HashIndex = index;
	do
	{
		if (mas[index].isUse() == false)
			break;
		if (mas[index].GetKey() == k_)
		{
			mas[index].setUse(false);
			return;
	    }
		else
			index = (index + p) % size;
	} while (index != HashIndex);

}

template<class KEY, class DATA>
void Table<KEY, DATA>::resize(int newSize)
{
	LinkedList<Node<KEY, DATA>>*tmp = mas;
	if (count > newSize)
		throw 112;
	mas = new LinkedList<Node<KEY, DATA>>[newSize];
	count = 0;
	int oldSize = size;
	size = newSize;
	for (int i = 0; i < oldSize; i++)
	{
		for (size_t x = 0; x<tmp[i].size(); x++)
			Add(tmp[i].get(x).GetData(), tmp[i].get(x).GetKey());
	}
	delete[] tmp;
}

#endif