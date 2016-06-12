#include <iostream>
#include <string>
#include <typeinfo>
#include "SLinkedList.h"

template<class Key, class Value> class Hash_Table
{
private:
	// Contains the total number of values in the entire hash table
	int numElements;

	// Contains the number of buckets
	int arraySize;
	double loadFactor;

	// Contains array of buckets to hold data
	SLinkedList<Value>* bucket;

	// The hash function --> note that this one is basic.
	int GetHashValue(const Key &key)
	{
		return (int)key % arraySize;
	}


public:
	// Initialize the hash table with a certain number of buckets
	Hash_Table(int n = 13) : arraySize(n)
	{
		bucket = new SLinkedList<Value>[n];
	}

	~Hash_Table() {};

	// Inserts an element at the position specified by key
	void insert (const Key &key, const Value & val) 
	{
		bucket[(int)key % arraySize].insert(val);
	}

	const SLinkedList<Value>& search(const Key &key)
	{
		// Determine what hash function to use
		int hashValue = GetHashValue(key);

		// How would one go about using strings as keys...?

		return bucket[hashValue];
	}

	void erase(const Key &key) 
	{
		int hashValue = GetHashValue(key);

		bucket[hashValue].clear();
	}

	//Maybe use ramdom number generator for the hash function

	// Displays the entire hash table
	void Display() const
	{
		// How would one go about using strings as keys...?
		cout << "This is a hash table." << endl;
		for (int i = 0; i < arraySize; i++)
		{
			cout << "Bucket [" << i << "]:\t";
			bucket[i].printLst();
		}
		cout << endl;
	}
};