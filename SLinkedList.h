#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <cassert>
using namespace std;

template<class Key, class Value> class SLinkedList
{
private:
    Node<Key, Value> * head;
    int sz;

	template<class key, class value> friend class Hash_Table;

public:
    SLinkedList() :head(nullptr), sz(0)
	{}

    bool isEmpty() const
	{
        return head == nullptr;
    }

	int Size() const { return sz; };

	~SLinkedList()
	{
		// clear();
	}

	// Accessors -----------------------------------------------------------------
	Node<Key, Value>* GetHead() const { return head; };

	Value getHeadValue()
	{
		return head->data;
	}

	// Mutators -----------------------------------------------------------------
    void insert(const Value& data, const Key& dataKey)
	{
        Node<Key, Value> *tmp_node = new Node<Key, Value>(data, dataKey);
        Node<Key, Value> *ptr = head;
        
		if (ptr == nullptr)
		{
            head = tmp_node;
            sz++;
        }
        
		else
		{
            while(ptr->next != nullptr)
			{
                ptr = ptr->next;
            }
            
			ptr->next = tmp_node;
            sz++;
        }
        // SLinkedList::printLst();
    }

    void insertBefore(const Value& data, const Key& dataKey, int pos)
	{
        if(pos<=1)
		{
            Node<Key, Value> *newNode = new Node<Key, Value>(data, dataKey, head);
            head = newNode;
            sz++;
			SLinkedList::printLst();
        }
        else if(pos > sz)
		{
            SLinkedList::insert(data, dataKey);
        }
        else
		{
            int p =1;
            Node<Key, Value> *newNode = new Node<Key, Value>(data, dataKey);
            Node<Key, Value> *ptr = head;
            while(p!=pos -1)
			{
                ptr = ptr->next;
                p++;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
            SLinkedList::printLst();
        }
    }

    void del(const Value& data)
	{
        Node<Key, Value> *ptr = head;
        Node<Key, Value> *prev = head;
        while(ptr!=nullptr)
		{
            if(ptr->data==data)
			{
                if(ptr==head) head = ptr->next;
                else
				{
                    prev->next=ptr->next;
                    cout << ptr->ID << endl;
                    ptr = prev;
                }
            }
            prev = ptr;
            ptr = ptr->next;

        }
        SLinkedList::printLst();
    }

    void printLst() const
	{
        Node<Key, Value> *ptr = head;
		int counter = 0;

        while(ptr != nullptr)
		{
            cout << /*"Node[" << counter++ << "]=" <<*/ ptr->data << " --> ";
            ptr = ptr->next;
        }

        cout << "[NULL]" << endl;
    }

    void clear()
	{
        Node<Key, Value> *ptr = head;
        Node<Key, Value> *prev = head;
        while(ptr!=nullptr)
		{
            ptr = ptr->next;
            delete prev;
            prev = ptr;
        }
        head = nullptr;
    }
};

#endif