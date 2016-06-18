#include <cassert>
#include <iostream>
#include <string>

#include "Menu_Program.h"

// main functions.

Menu_Program::Menu_Program()
{
	Clear() ;
	Greeting() ;
	Main_Loop() ;
}

void Menu_Program::Greeting()
{
	std::cout << std::endl << "Project 02 Program - Stack , Queue , and Hash Table" << std::endl ;
	std::cout << std::endl << "    by:  Manuel Martinez , John Santoro , and Jim Bui" << std::endl << std::endl ;
}

void Menu_Program::Main_Loop()
{
	int input = 0 ;

	while (true)
	{
		std::cout << "  Main Menu" << std::endl << std::endl ;
		std::cout << "    1.  Stack Menu" << std::endl ;
		std::cout << "    2.  Queue Menu" << std::endl ;
		std::cout << "    3.  Hash Table Menu" << std::endl ;
		std::cout << "    4.  Exit" << std::endl <<std::endl ;

		std::cin >> input ; std::cin.clear() ; std::cin.ignore() ;

		if (input == 1)
		{
			Clear() ;
			Stack_Create() ;
		}

		else if (input == 2)
		{
			Clear() ;
			Queue_Create() ;
		}

		else if (input == 3)
		{
			Clear() ;
			Hash_Table_Create() ;
		}

		else if (input == 4)
		{
			std::cout << std::endl << "Exiting program..." << std::endl << std::endl ;
			break ;
		}

		else
		{
			Clear() ;
			std::cout << std::endl << "Invalid input." << std::endl << std::endl ;
		}
	}
}

void Menu_Program::Clear()
{
	for(int i = 0 ; i < 100 ; i++)
		std::cout << std::endl ;
}

// stack functions.

void Menu_Program::Stack_Create()
{
	int input = 0 ;

	while (true)
	{
		std::cout << "  Stack Menu" << std::endl << std::endl ;
		std::cout << "    1.  Create Stack" << std::endl ;
		std::cout << "    2.  Back" << std::endl <<std::endl ;

		std::cin >> input ; std::cin.clear() ; std::cin.ignore() ;

		if (input == 1)
		{
			int n = 0 ;

			Clear() ; 
			std::cout << "  Please input size of stack." << std::endl << std::endl ;
			std::cin >> n ; std::cin.clear() ; std::cin.ignore() ;
			Clear() ;
			std::cout << "  Created stack of size " << n << "." << std::endl << std::endl ;

			Stack_Loop(n) ;
			Clear() ;	
			break ;
		}

		else if (input == 2)
		{	
			Clear() ;	
			break ;
		}

		else
		{
			Clear() ;
			std::cout << std::endl << "Invalid input." << std::endl << std::endl ;
		}
	}
}

void Menu_Program::Stack_Loop(int size)
{
	int input = 0 ;
	Stack<string> the_stack(size) ;

	while (true)
	{
		std::cout << "  Stack Menu" << std::endl << std::endl ;
		std::cout << "    1.  top()" << std::endl ;
		std::cout << "    2.  size()" << std::endl ;
		std::cout << "    3.  empty()" << std::endl ;
		std::cout << "    4.  capacity()" << std::endl ;
		std::cout << "    5.  display()" << std::endl ;
		std::cout << "    6.  push()" << std::endl ;
		std::cout << "    7.  pop()" << std::endl ;
		std::cout << "    8.  clear()" << std::endl ;
		std::cout << "    9.  erase()" << std::endl ;
		std::cout << "    10. Back" << std::endl << std::endl ;

		std::cin >> input ; std::cin.clear() ; std::cin.ignore() ;

		if (input == 1)
		{
			Clear() ;

			try
			{
				std::cout << "  top():  The top of the stack is: " << the_stack.top() << std::endl << std::endl ;
			}

			catch (const underflow_error& e)
			{
				cerr << e.what() << std::endl << std::endl ;
			}
		}

		else if (input == 2)
		{
			Clear() ;
			std::cout << "  size():  The current size of the stack is: " << the_stack.size() << std::endl << std::endl ;
		}

		else if (input == 3)
		{
			Clear() ;
			if (the_stack.empty())
				std::cout << "  empty():  The stack is currently empty. " << std::endl << std::endl ;
			else
				std::cout << "  empty():  The stack is currently not empty. " << std::endl << std::endl ;

		}

		else if (input == 4)
		{
			Clear() ;
			std::cout << "  capacity():  The current capacity of the stack is: " << the_stack.capacity() << "." << std::endl << std::endl ;
		}

		else if (input == 5)
		{
			Clear() ;
			the_stack.display() ;
		}

		else if (input == 6)
		{
			string temp ;
			Clear() ;
			std::cout << "  push():  Enter item to push: " << std::endl << std::endl ;
			std::cin >> temp ; std::cin.clear() ; std::cin.ignore() ;
			the_stack.Push(temp) ;
			Clear() ;
			std::cout << "  push():  Pushed: " << temp << std::endl << std::endl ;

		}

		else if (input == 7)
		{
			Clear() ;

			try
			{
				std::cout << "  pop():  Popped: " << the_stack.pop() << std::endl << std::endl ;
			}

			catch (const underflow_error& e)
			{
				cerr << e.what() << std::endl << std::endl ;
			}
		}

		else if (input == 8)
		{
			Clear() ;
			the_stack.clear() ;
		}

		else if (input == 9)
		{
			string temp ;
			Clear() ;

			if (the_stack.empty())
			{
				std::cout << "  erase():  The stack is currently empty. " << std::endl << std::endl ;
			}

			else
			{
				std::cout << "  erase():  Enter item to erase: " << std::endl << std::endl ;
				std::cin >> temp ; std::cin.clear() ; std::cin.ignore() ;
				Clear() ;
				std::cout << "  erase():  Erased " << the_stack.erase(temp) << " instances of " << temp << "." << std::endl << std::endl ;
			}
		}

		else if (input == 10)
		{
			Clear() ;
			break ;
		}

		else
		{
			Clear() ;
			std::cout << std::endl << "Invalid input." << std::endl << std::endl ;
		}
	}
}

void Menu_Program::Queue_Create()
{
	int input = 0 ;

	while (true)
	{
		std::cout << "  Queue Menu" << std::endl << std::endl ;
		std::cout << "    1.  Create Queue" << std::endl ;
		std::cout << "    2.  Back" << std::endl <<std::endl ;

		std::cin >> input ; std::cin.clear() ; std::cin.ignore() ;

		if (input == 1)
		{
			int n = 0 ;

			Clear() ; 
			std::cout << "  Please input size of queue." << std::endl << std::endl ;
			std::cin >> n ; std::cin.clear() ; std::cin.ignore() ;
			Clear() ;
			std::cout << "  Created queue of size " << n << "." << std::endl << std::endl ;

			Queue_Loop(n) ;
			Clear() ;	
			break ;
		}

		else if (input == 2)
		{	
			Clear() ;	
			break ;
		}

		else
		{
			Clear() ;
			std::cout << std::endl << "Invalid input." << std::endl << std::endl ;
		}
	}
}


void Menu_Program::Queue_Loop(int size)
{
	int input = 0 ;
	DynQueue<string> the_queue(size) ;

	while (true)
	{
		std::cout << "  Queue Menu" << std::endl << std::endl ;
		std::cout << "    1.  front()" << std::endl ;
		std::cout << "    2.  back()" << std::endl ;
		std::cout << "    3.  size()" << std::endl ;
		std::cout << "    4.  empty()" << std::endl ;
		std::cout << "    5.  capacity()" << std::endl ;
		std::cout << "    6.  display()" << std::endl ;
		std::cout << "    7.  enqueue()" << std::endl ;
		std::cout << "    8.  dequeue()" << std::endl ;
		std::cout << "    9.  clear()" << std::endl ;
		std::cout << "    10. erase()" << std::endl ;
		std::cout << "    11. Back" << std::endl << std::endl ;

		std::cin >> input ; std::cin.clear() ; std::cin.ignore() ;

		if (input == 1)
		{
			Clear() ;

			try
			{
				std::cout << "  front():  The front of the queue is: " << the_queue.front() << std::endl << std::endl ;
			}

			catch (const underflow_error& e)
			{
				cerr << e.what() << std::endl << std::endl ;
			}
		}

		else if (input == 2)
		{
			Clear() ;

			try
			{
				std::cout << "  back():  The back of the queue is: " << the_queue.back() << std::endl << std::endl ;
			}

			catch (const underflow_error& e)
			{
				cerr << e.what() << std::endl << std::endl ;
			}
		}

		else if (input == 3)
		{
			Clear() ;
			std::cout << "  size():  The current size of the queue is: " << the_queue.size() << std::endl << std::endl ;
		}

		else if (input == 4)
		{
			Clear() ;
			if (the_queue.empty())
				std::cout << "  empty():  The queue is currently empty. " << std::endl << std::endl ;
			else
				std::cout << "  empty():  The queue is currently not empty. " << std::endl << std::endl ;
		}

		else if (input == 5)
		{
			Clear() ;
			std::cout << "  capacity():  The current capacity of the queue is: " << the_queue.capacity() << "." << std::endl << std::endl ;
		}

		else if (input == 6)
		{
			Clear() ;
			try
			{
				the_queue.display() ;
			}
			catch (const underflow_error& e)
			{
				cerr << e.what() << std::endl << std::endl ;
			}

		}

		else if (input == 7)
		{
			string temp ;
			Clear() ;
			std::cout << "  enqueue():  Enter item to queue up: " << std::endl << std::endl ;
			std::cin >> temp ; std::cin.clear() ; std::cin.ignore() ;
			the_queue.enqueue(temp) ;
			Clear() ;
			std::cout << "  enqueue():  Queued up: " << temp << std::endl << std::endl ;
		}

		else if (input == 8)
		{
			Clear() ;

			try
			{
				std::cout << "  dequeue():  Dequeued: " << the_queue.dequeue() << std::endl << std::endl ;
			}

			catch (const underflow_error& e)
			{
				cerr << e.what() << std::endl << std::endl ;
			}
		}

		else if (input == 9)
		{
			Clear() ;
			the_queue.clear() ;
		}

		else if (input == 10)
		{
			string temp ;
			Clear() ;

			if (the_queue.empty())
			{
				std::cout << "  erase():  The queue is currently empty. " << std::endl << std::endl ;
			}

			else
			{
				std::cout << "  erase():  Enter item to erase: " << std::endl << std::endl ;
				std::cin >> temp ; std::cin.clear() ; std::cin.ignore() ;
				Clear() ;
				std::cout << "  erase():  Erased " << the_queue.erase(temp) << " instances of " << temp << "." << std::endl << std::endl ;
			}
		}

		else if (input == 11)
		{
			Clear() ;
			break ;
		}

		else
		{
			Clear() ;
			std::cout << std::endl << "Invalid input." << std::endl << std::endl ;
		}
	}
}

void Menu_Program::Hash_Table_Create()
{
	int input = 0;

	while (true)
	{
		std::cout << "  Hash Table Menu" << std::endl << std::endl;
		std::cout << "    1.  Create Hash Table" << std::endl;
		std::cout << "    2.  Back" << std::endl << std::endl;

		std::cin >> input; std::cin.clear(); std::cin.ignore();

		if (input == 1)
		{
			int n = 0;
			double loadFactorCriterion = 0;

			Clear();
			std::cout << "  Please input size of hash table." << std::endl << std::endl;
			std::cin >> n; std::cin.clear(); std::cin.ignore();
			std::cout << "  Please input load factor criterion of hash table." << std::endl << std::endl;
			std::cin >> loadFactorCriterion; std::cin.clear(); std::cin.ignore();
			Clear();
			std::cout << "  Created hash table of size " << n << "." << std::endl << std::endl;

			Hash_Table_Loop(n, loadFactorCriterion);
			Clear();
			break;
		}

		else if (input == 2)
		{
			Clear();
			break;
		}

		else
		{
			Clear();
			std::cout << std::endl << "Invalid input." << std::endl << std::endl;
		}
	}
}

void Menu_Program::Hash_Table_Loop(int size, double loadFactorCriterion)
{
	// Change to string implementation later
	Hash_Table<int, int> hash_brown(size, loadFactorCriterion);
	int input = 0;

	while (true)
	{
		std::cout << "  Hash Table Menu" << std::endl << std::endl;
		std::cout << "    1.  NumberOfDataItems()" << std::endl;
		std::cout << "    2.  NumberOfBuckets()" << std::endl;
		std::cout << "    3.  search()" << std::endl;
		std::cout << "    4.  insert()" << std::endl;
		std::cout << "    5.  erase()" << std::endl;
		std::cout << "    6.  Display()" << std::endl;
		std::cout << "    7.  DisplayDebugInfo()" << std::endl;
		std::cout << "    8.  Back" << std::endl << std::endl;

		std::cin >> input; std::cin.clear(); std::cin.ignore();

		bool breakThis = false;

		// Variables for switch loop
		int keyInput = 0;
		int valueInput = 0;

		if (input == 1)
		{
			Clear();
			cout << "Number of data items:  " << hash_brown.NumberOfDataItems() << endl;
		}
		else if (input == 2)
		{
			Clear();
			cout << "Number of buckets:  " << hash_brown.NumberOfBuckets() << endl;
		}
		else if (input == 3)
		{
			Clear();
			cout << "Enter key to search:  ";
			cin >> keyInput;
			cin.ignore();

			try
			{
				valueInput = hash_brown.search(keyInput);
				cout << valueInput << " found at key.";
			}
			catch (const underflow_error& e)
			{
				cerr << e.what() << endl;
			}
		}
		else if (input == 4)
		{
			Clear();
			cout << "Enter key to insert a value at:  ";
			cin >> keyInput;
			cin.ignore();

			cout << "Enter desired value at key " << keyInput << ":  ";
			cin >> valueInput;
			cin.ignore();

			hash_brown.insert(keyInput, valueInput);
		}
		else if (input == 5)
		{
			Clear();
			cout << "Enter key to erase value at:  ";
			cin >> keyInput;
			hash_brown.erase(keyInput);
		}
		else if (input == 6)
		{
			Clear();
			hash_brown.Display();
		}
		else if (input == 7)
		{
			Clear();
			hash_brown.DisplayDebugInfo();
		}
		else if (input == 8)
		{
			Clear();
			breakThis = true;
		}
		else
		{
			Clear();
			std::cout << std::endl << "Invalid input." << std::endl << std::endl;
		}

		if (breakThis)
			break; // this
	}

	// std::cout << "  This is not yet implemented." << std::endl << std::endl ;
}