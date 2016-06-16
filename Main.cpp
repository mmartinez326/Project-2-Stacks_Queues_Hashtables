#include <iostream>
#include "Hash_Table.h"
#include "Queue.h"
#include "Stack.h"

void TestBasicHashTable();
void TestStack();
void test_suite_driver() ; 
void test_1() ;
void test_2() ;
void test_3() ;
void test_4() ;

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

void test_suite_driver() 
{
	for (int i = 0 ; i < 60 ; i++)
	{
		std::cout << std::endl ;
	}

	std::cout << std::endl << "hello world!" << std::endl << std::endl ;

	// test_1() ;
	// test_2() ;
	test_3() ;
	test_4() ;
}

void test_1() // type test.
{
	std::cout << "---------------- test_1() ----------------" << std::endl << std::endl ;
	DynQueue<char> new_queue_n20(-20) ;
	DynQueue<float> new_queue_0(0) ;
	DynQueue<int> new_queue_13(13) ; 
	DynQueue<double> new_queue_50(50) ;

	new_queue_n20.test_suite_1() ; // empty , initial -20.			
	new_queue_0.test_suite_1() ; // empty , initial 0.
	new_queue_13.test_suite_1() ; // empty , initial 13.
	new_queue_50.test_suite_1() ; // empty , intial 50.

	std::cout << "---------------- NOT EMPTY ----------------" << std::endl << std::endl ;

	new_queue_n20.enqueue('Z') ;
	new_queue_0.enqueue(34.55) ;
	new_queue_13.enqueue(9001) ;
	new_queue_50.enqueue(99.99) ;

	new_queue_n20.test_suite_1() ;
	new_queue_0.test_suite_1() ;
	new_queue_13.test_suite_1() ;
	new_queue_50.test_suite_1() ;
}

void test_2() // enqueue , dequeue , and reallocation test.
{
	std::cout << "---------------- test_2() ----------------" << std::endl << std::endl ;
	DynQueue<char> overflow_queue(11) ;
	overflow_queue.test_suite_1() ;
	overflow_queue.enqueue('A') ;
	overflow_queue.enqueue('+') ;
	overflow_queue.enqueue('C') ;
	overflow_queue.enqueue('z') ;
	overflow_queue.enqueue('9') ;
	overflow_queue.test_suite_1() ;
	overflow_queue.temp_display_FIXME() ;
	overflow_queue.enqueue('o') ;
	overflow_queue.enqueue('P') ;
	overflow_queue.enqueue('/') ;
	overflow_queue.enqueue('"') ;
	overflow_queue.enqueue('+') ;
	overflow_queue.test_suite_1() ;
	overflow_queue.temp_display_FIXME() ;
	overflow_queue.enqueue('A') ;
	overflow_queue.enqueue('+') ;
	overflow_queue.enqueue('C') ;
	overflow_queue.enqueue('z') ;
	overflow_queue.enqueue('9') ;
	overflow_queue.temp_display_FIXME() ;
	overflow_queue.enqueue('1') ;
	overflow_queue.enqueue('2') ;
	overflow_queue.enqueue('3') ;
	overflow_queue.enqueue('4') ;
	overflow_queue.enqueue('5') ;
	overflow_queue.temp_display_FIXME() ;
	overflow_queue.enqueue('X') ;
	overflow_queue.temp_display_FIXME() ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	overflow_queue.temp_display_FIXME() ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	overflow_queue.temp_display_FIXME() ;
	std::cout << "HEY0000000000000000 I JUST DELETED: " << overflow_queue.dequeue() << "   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<< std::endl << std::endl ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	overflow_queue.temp_display_FIXME() ;
	overflow_queue.dequeue() ;
	overflow_queue.dequeue() ;
	// 19 dequeues so far.
	overflow_queue.temp_display_FIXME() ;
	overflow_queue.dequeue() ;
	overflow_queue.temp_display_FIXME() ;
	overflow_queue.dequeue() ;
	overflow_queue.temp_display_FIXME() ;
	overflow_queue.dequeue() ;
	overflow_queue.temp_display_FIXME() ;
}

void test_3() // clear() and new display() test.
{
	std::cout << "---------------- test_3() ----------------" << std::endl << std::endl ;
	DynQueue<char> overflow_queue(11) ;
	overflow_queue.test_suite_1() ;
	overflow_queue.enqueue('A') ;
	overflow_queue.enqueue('+') ;
	overflow_queue.enqueue('C') ;
	overflow_queue.enqueue('z') ;
	overflow_queue.enqueue('9') ;
	overflow_queue.test_suite_1() ;
	overflow_queue.temp_display_FIXME_short() ;
	overflow_queue.display() ;
	overflow_queue.enqueue('o') ;
	overflow_queue.enqueue('P') ;
	overflow_queue.enqueue('/') ;
	overflow_queue.enqueue('"') ;
	overflow_queue.enqueue('+') ;
	overflow_queue.test_suite_1() ;
	overflow_queue.temp_display_FIXME_short() ;
	overflow_queue.display() ;
	overflow_queue.enqueue('A') ;
	overflow_queue.enqueue('+') ;
	overflow_queue.enqueue('C') ;
	overflow_queue.enqueue('z') ;
	overflow_queue.enqueue('9') ;
	overflow_queue.temp_display_FIXME_short() ;
	overflow_queue.display() ;
	overflow_queue.enqueue('1') ;
	overflow_queue.enqueue('2') ;
	overflow_queue.enqueue('3') ;
	overflow_queue.enqueue('4') ;
	overflow_queue.enqueue('5') ;
	overflow_queue.temp_display_FIXME_short() ;
	overflow_queue.display() ;
	overflow_queue.enqueue('X') ;
	overflow_queue.temp_display_FIXME_short() ;
	overflow_queue.display() ;
	overflow_queue.clear() ;
	overflow_queue.temp_display_FIXME_short() ;
	overflow_queue.display() ;
}

void test_4() // testing erase.
{
	std::cout << "---------------- test_4() ----------------" << std::endl << std::endl ;
	DynQueue<int> erased_queue(5) ;
	erased_queue.display() ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	// erased_queue.enqueue(7) ;
	// erased_queue.enqueue(1) ;
	// erased_queue.enqueue(0) ;
	// erased_queue.enqueue(2) ;
	// erased_queue.enqueue(2) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	erased_queue.enqueue(3) ;
	// erased_queue.enqueue(1) ;
	// erased_queue.enqueue(1) ;
	erased_queue.enqueue(3) ;
	erased_queue.display() ;

	std::cout << "erased " << erased_queue.erase(3) << " items." << std::endl << std::endl ;

	//erased_queue.temp_display_FIXME() ;
	//erased_queue.clear() ;
	// erased_queue.temp_display_FIXME() ;
	// erased_queue.display() ;
	// erased_queue.test_suite_1() ;
	// erased_queue.erase(4) ;
	erased_queue.display() ;
	erased_queue.test_suite_1() ;
}
