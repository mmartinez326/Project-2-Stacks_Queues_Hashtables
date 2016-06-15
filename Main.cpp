#include <iostream>
#include "Hash_Table.h"
#include "Queue.h"
#include "Stack.h"

void TestBasicHashTable();
void TestStack();

int main () {

	//TestBasicHashTable();
	TestStack();

	cin.get();
	return 0;
}

void TestStack () 
{
	Stack<char> S;

	cout << "Is Stack empty ?" <<(S.empty()?" YES":" NO") << endl;
	cout << "Number of elements: " << S.size() << endl;
	cout << "Current Size: " << S.capacity() << endl;
	try
	{
		cout << "Top data: " << S.top() << endl;
	}
	catch (const underflow_error& e)
	{
		cerr << e.what() << endl;
	}
	S.display();
	
	try
	{
		cout << endl << "Erased: " << S.erase('M') << endl;
	}
	catch (const underflow_error& e)
	{
		cerr << e.what() << endl;
	}

	cout << "--------------------------------------------------------" <<  endl << endl << endl;

	cout << "Adding more than allocated size: " << endl;

	S.Push('M');
	S.Push('A');
	S.Push('N');
	S.Push('U');
	S.Push('E');
	S.Push('L');
	S.Push('M');
	S.Push('A');
	S.Push('R');
	S.Push('T');
	S.Push('I');
	S.Push('N');
	S.Push('E');
	S.Push('C');
	S.Push('A');
	S.Push('R');

	//S.display();
	//S.clear();
	//S.display();


	cout << "Is Stack empty ?" <<(S.empty()?" YES":" NO") << endl;
	cout << "Number of elements: " << S.size() << endl;
	cout << "Current Size: " << S.capacity() << endl;
	try
	{
		cout << "Top data: " << S.top() << endl;
	}
	catch (const underflow_error& e)
	{
		cerr << e.what() << endl;
	}
	S.display();
	cout << endl << endl << endl;

	try
	{
		cout << endl << "Erased: " << S.erase('M') << endl;
	}
	catch (const underflow_error& e)
	{
		cerr << e.what() << endl;
	}try
	{
		cout << endl << "Erased: " << S.erase('N') << endl;
	}
	catch (const underflow_error& e)
	{
		cerr << e.what() << endl;
	}try
	{
		cout << endl << "Erased: " << S.erase('A') << endl;
	}
	catch (const underflow_error& e)
	{
		cerr << e.what() << endl;
	}
	S.display();
	cout << endl;

	cout << "--------------------------------------------------------" <<  endl << endl << endl;


	cout << "Using clear() function to resize" << endl;
	S.clear();
	S.display();

	cout << "--------------------------------------------------------" <<  endl << endl << endl;

	cout << "adding 'Racecar' : " << endl;

	S.Push('R');
	S.Push('A');
	S.Push('C');
	S.Push('E');
	S.Push('C');
	S.Push('A');
	S.Push('R');


	
	cout << endl << "Is Stack empty ?" <<(S.empty()?" YES":" NO") << endl;
	cout << "Number of elements: " << S.size() << endl;
	cout << "Current Size: " << S.capacity() << endl;
	try
	{
		cout << "Top data: " << S.top() << endl;
	}
	catch (const underflow_error& e)
	{
		cerr << e.what() << endl;
	}
	S.display();
	
	try
	{
		S.pop();
	}
	catch (const underflow_error& e)
	{
		cerr << e.what() << endl;
	}
	try
	{
		S.pop();
	}
	catch (const underflow_error& e)
	{
		cerr << e.what() << endl;
	}
	

	cout << endl << endl << endl;
	cout << "Is Stack empty ?" <<(S.empty()?" YES":" NO") << endl;
	cout << "Number of elements: " << S.size() << endl;
	cout << "Current Size: " << S.capacity() << endl;
	try
	{
		cout << "Top data: " << S.top() << endl;
	}
	catch (const underflow_error& e)
	{
		cerr << e.what() << endl;
	}
	S.display();

	S.clear();

	cout << endl << endl << endl;
	cout << "Is Stack empty ?" <<(S.empty()?" YES":" NO") << endl;
	cout << "Number of elements: " << S.size() << endl;
	cout << "Current Size: " << S.capacity() << endl;
	try
	{
		cout << "Top data: " << S.top() << endl;
	}
	catch (const underflow_error& e)
	{
		cerr << e.what() << endl;
	}
	S.display();

	//delete[] S;
			
}

void TestBasicHashTable()
{
	Hash_Table<int, int> hash_brown;

	hash_brown.insert(29, 29);
	hash_brown.insert(10, 10);
	hash_brown.insert(23, 23);

	hash_brown.Display();
	cout << endl;

	SLinkedList<int> dat = hash_brown.search(10);

	cout << "Key(10).Info:  " << endl;
	dat.printLst();

	cout << endl;

	cout << "Hash table after delete is called:  " << endl;
	hash_brown.erase(10);
	hash_brown.Display();
}