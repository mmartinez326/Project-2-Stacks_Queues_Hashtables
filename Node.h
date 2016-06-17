#ifndef NODE_H
#define NODE_H

// Node contains key info used in preserving the contents of the hash table after resizing

static int num = 0;
template <class Key, class Value> class Node
{
private:
    Value data;
	Key dataKey;

    Node* next;
    int ID;

    template<class key, class value> friend class SLinkedList;
	template<class key, class value> friend class Hash_Table;

public:
    Node() :data(0), next(0), dataKey(0)
	{
        ID = 0;
        this->ID = ++num;
    }

    Node(const Value& data, const Key& dataKey) :next(0)
	{
        this->data = data;
		this->dataKey = dataKey;
        this->ID = ++num;
    }

    Node(const Value& data, const Key& dataKey, Node * next)
	{
        this->data = data;
		this->dataKey = dataKey;
        this->next = next;
        this->ID = ++num;
    }

};

#endif