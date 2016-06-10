#include <iostream>

template <class type> class Queue {
private:
	type *data;
	int ihead;  
	int itail;
	int count;
	int initialSize;
	int arraySize;


public:

	Queue (int n=13) {
		if (n<=0) {n=1;}
		
		ihead = 0;
		itail = 0;
		data = new type [n]; 
		count = 0;
		initialSize = n;
		arraySize = 0;
	}

	~Queue () {}

	type front () const {return data[ihead];}  //check if queue is empty for underflow error 

	type back () const {return data[itail];} //check if queue is empty for underflow error 

	int size() const {return count}

	bool empty() const {return 0;}

	int capacity() const {return 0;}

	void display() {}

	//Mutators

	void enqueue (type const &data) {}

	type dequeue() {return 0;}

	void clear() {}

	int erase (type const &data) {return 0;}

};