#include <iostream>

template <class type> class Stack {
private:
	type *data;
	int count;
	int initialSize;
	int arraySize;

public:

	Stack(int n=13) {
		if (n<=0) {n=1;}
		
		data = new type [n]; 
		count = 0;
		initialSize = n;
		arraySize = 0;
	}

	~Stack() {}

	type top() const {return 0;}

	type size() const {return count;}

	bool empty() const {retrun 0;}

	int capacity() const {return 0;}

	void display() {}


	//Mutators

	void Push (type const &data) {}

	type pop() {return 0;}

	void clear() {}

	int erase(type const &data) {return 0;}


};