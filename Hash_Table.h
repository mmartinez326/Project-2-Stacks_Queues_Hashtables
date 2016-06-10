#include <iostream>

template <class type1, class type2> class Hash_Table {
private:
	int size;



public:

	Hash_Table() {}

	~Hash_Table() {}

	void insert (const type1 & key, const type2 & value) {}

	type2 search (const type1 &key) {return 0;}

	void erase (const type1 &key) {}

	//Maybe use ramdom number generator for the hash function

};