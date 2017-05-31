#ifndef _NODE_H_
#define _NODE_H_

template <class KEY, class DATA>
class Node
{
protected:
	KEY k;
	DATA val;
	bool isuse;
public:
	KEY GetKey();
	DATA& GetData();
	void SetKey(KEY k_);
	void SetVal(DATA val_);
	Node() { isuse = false;
	k = KEY();
	val = DATA();
	}
	bool isUse()
	{
		return isuse;
	}
	void setUse(bool use)
	{
		isuse = use;
	}
};

template <class KEY, class DATA>
KEY Node<KEY, DATA>::GetKey(){return k;}

template <class KEY, class DATA>
DATA& Node<KEY, DATA>::GetData() { return val; }

template <class KEY, class DATA>
void Node<KEY, DATA>::SetKey(KEY k_){k = k_;}

template <class KEY, class DATA>
void Node<KEY, DATA>::SetVal(DATA val_){val = val_;}

#endif 