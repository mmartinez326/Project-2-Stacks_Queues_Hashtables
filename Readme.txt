Project 02 - Stack, Queue, and Hash Table
Programmers:  Manuel Martinez, John Santoro, and Jim Bui

The driver program, main.cpp, utilizes a menu program class(Menu_Program.h and Menu_Program.cpp) in order to display information about the stack, queue, and hash table data structures.  The command processor requires the user to enter a numeric input in order to progress to the next menu or perform a certain function.  For example, 

Main Menu
1.  Stack Menu
2.  Queue Menu
3.  Hash Table Menu
4.  Exit

> [A numeric value expected]

Typing in 1 and hitting enter on this menu will give the user access to all of the functions associated with the stack data structure.  This is the full menu layout, along with a description of what each of the functions accomplish:

1.  Stack Menu
--> Goes to
	1.  Create Stack - Creates a new stack of a user-specified initial size
	--> Goes to
		1.  top() - Returns the top item of the stack.  If the stack is empty, an underflow error is thrown
		2.  size() - Gets the number of elements in the stack
		3.  empty() - Returns whether or not the stack contains no elements
		4.  capacity() - Gets the maximum number of elements the stack can currently hold
		5.  display() - Displays the contents of the stack
		6.  push() - Gets an input from the user, and then pushes that value to the top of the stack
		7.  pop() - Pops the top from the stack and displays its value.  This can throw an underflow error if the stack is empty.
		8.  clear() - Clears all of the items in the stack and resizes it to the initial size value
		9.  erase() - Erases all occurrences of the user-specified value from the stack and then returns the number of elements of that value that were erased
		10.  Back
<--	<-- Goes Back
	2.  Back
<-- Goes Back
2.  Queue Menu
--> Goes to
	1.  Create Queue - Creates a new queue of a user-specified initial size
	--> Goes to
		1.  front() - Returns the front item of the queue.  If the queue is empty, an underflow error is thrown
		2.  back() - Returns the back item of the queue.  If the queue is empty, an underflow error is thrown
		3.  size() - Gets the number of elements in the queue
		4.  empty() - Returns whether or not the queue contains no elements
		5.  capacity() - Gets the maximum number of elements the queue can currently hold
		6.  display() - Displays the contents of the queue
		7.  enqueue() - Gets an input from the user, and then enqueues that value to the back of the queue
		8.  dequeue() - Dequeues the front item from the queue and displays its value.  This can throw an underflow error if the queue is empty.
		9.  clear() - Clears all of the items in the queue and resizes it to the initial size value
		10.  erase() - Erases all occurrences of the user-specified value from the queue and then returns the number of elements of that value that were erased
		11.  Back
<--	<-- Goes Back
	2.  Back
<-- Goes Back
3.  Hash Table Menu
--> Goes to
	1.  Create Hash Table - Creates a new hash table of a user-specified length and with a user-specified load factor criterion.  Note that the value of the load factor criterion should be somewhere between 0 and 1.  0.5 is the default value.
	--> Goes to
		1.  NumberOfDataItems() - Returns the number of values stored in all of the buckets of the hash table.
		2.  NumberOfBuckets() - Returns the number of buckets in the hash table.
		3.  search() - Searches the hash table based on a user input key, and then returns the value at that key.  If the key does not contain a value, this returns an underflow error.
		4.  insert() - Inserts a user-specified item in the hash table according to a user-specified key
		5.  erase() - Erases the item at a user-specified key, if one exists at that key.
		6.  Display() - Displays all of the elements in all of the buckets of the hash table.
		7.  DisplayDebugInfo() - Displays information about the hash table, such as the maximum chain length, the average chain length, the number of buckets, and the percentage of space used.  This method may be used to evaluate how efficiently the hash table utilizes the space allocated for it.
		8.  Back
<--	<-- Goes Back
	2.  Back
<-- Goes Back
4.  Exit						--> Exit Program