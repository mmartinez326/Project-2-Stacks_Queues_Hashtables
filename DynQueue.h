#include <iostream>
#include <stdexcept>

template <class type> class DynQueue 
{

private:

	type *array ; // pointer to array.
	int ihead ; // index of the first item.
	int itail ; // index of the last item.
	int count ; // count of items in array.
	int initialSize ; // initial size of array - what we started off with.
	int arraySize ; // the current array size.

public:

	DynQueue(int n = 13)
	{
		if (n <= 0)
			n = 1 ;
		
		ihead = 0 ;
		itail = 0 ;
		
		array = new type[n] ; // new array.

		count = 0 ;
		initialSize = n ;
		arraySize = n ;
	}

	~DynQueue(){delete[] array ; } // do this later.

	type front() const // returns first in queue.
	{	
		if (this->empty())
			throw std::underflow_error("front(): the list is empty - underflow_error.") ;
		else
			return array[ihead] ; 
	} 

	type back() const // returns last in queue.
	{	
		if (this->empty())
			throw std::underflow_error("back(): the list is empty - underflow_error.") ;
		else
			return array[itail] ; 
	} 

	int size() const {return count ; } // returns number of elements currently in array.

	bool empty() const // is this array empty?
	{
		if (count == 0)
			return true ;
		else
			return false ; 
	}

	int capacity() const {return arraySize ; } // returns current array size.

	void display() // displays from the front to the back.
	{
		if (count == 0)
		{
			std::cout << "the list is empty.  nothing to display." << std::endl ;
		}

		else
		{
			int count_temp = count ;
			int i = 1 ;
			int working_index = 0 ;
			type *temp_array = new type[arraySize] ; // creates a new array.

			while (working_index <= itail) // copies the original array to a temp_array.
			{
				temp_array[working_index] = array[working_index] ;
				working_index++ ;
			}

			// temp_array is now the same as array.

			while (count_temp > 0) // as long as there are still items in the queue , keep dequeueing.
			{
				working_index = 1 ;
				std::cout << i << ": " << temp_array[0] << std::endl ; // print out first item in queue.
				i++ ;

				while (working_index <= count_temp - 1) // creates new array without first item.
				{
					temp_array[working_index - 1] = temp_array[working_index] ; // creates new array minus first item.
					working_index++ ;
				}

				count_temp-- ;
			}
		}

		std::cout << std::endl ;
	}

	void enqueue(type const &data) // inserts a new element at the back of the queue.  follow capacity rules.
	{
		if (count + 1 > arraySize) // if array is full , double it , then proceed.
		{
			type *new_array = new type[arraySize * 2] ; // new array 2x bigger.
			int working_index = 0 ;

			while (working_index <= itail)
			{
				new_array[working_index] = array[working_index] ;
				working_index++ ;
			}

			array = new_array ;
			arraySize = arraySize * 2 ;
			std::cout << "enqueue(): array ceiling reached , doubled array size to " << arraySize << ".  continuing equeue()..."<< std::endl << std::endl ;
		}
		
		if (count == 0) // if queue is empty.
		{

			array[0] = data ;
			count++ ;
			std::cout << "enqueue(): queued " << data << std::endl << std::endl ;
			return ;
		}

		else // add to queue normal.
		{
			array[itail + 1] = data ;
			itail++ ;
			count++ ;
			std::cout << "enqueue(): queued " << data << std::endl << std::endl ;
			return ;
		}
	} 

	type dequeue() // removes element from front of queue.  follow capacity rules.  returns the deleted item.
	{
		try
		{
			if (this->empty())
				throw std::underflow_error("dequeue(): the list is empty - underflow_error.") ;
			else
			{
				type temp_deleted = array[0] ; // for the return.

				if (count - 1 <= (arraySize / 2) && (arraySize / 2) >= initialSize) // dequeue with size reduction.
				{
					type *new_array = new type[arraySize / 2] ;
					int working_index = 1 ;

					while (working_index <= itail) // creates new array without first item.
					{
						new_array[working_index - 1] = array[working_index] ;
						working_index++ ;
					}

					count-- ;
					array = new_array ;
					arraySize = arraySize / 2 ;
					// std::cout << "dequeue(): array size reduced to " << arraySize << ".  continuing dequeue()..."<< std::endl << std::endl ;
				}

				else // dequeue without size reduction.
				{
					type *new_array = new type[arraySize] ;
					int working_index = 1 ;

					while (working_index <= itail) // creates new array without first item.
					{
						new_array[working_index - 1] = array[working_index] ;
						working_index++ ;
					}

					count-- ;
					array = new_array ;
				}

				if (count == 0 || count == 1) // special case.
				{
					ihead = 0 ;
					itail = 0 ;
				}

				else
				{
					itail-- ;
				}

				// std::cout << "dequeue(): item " << temp << " has been dequeued." << std::endl << std::endl ;

				return temp_deleted ; 
			}
		}

		catch (const std::underflow_error& error)
		{
			std::cerr << error.what() << std::endl << std::endl ;
		}
	}

	void clear() // removes all elements in queue.  resize to initial size.
	{
		while (count != 0)
		{
			this->dequeue() ;
		}
	}

	int erase(type const &data) // deletes a specific element (all of them) , follows capacity rules.
	{
		// iterate through array.
		// if item matches parameter , create new array minus the matching item.
		// reduce count.
		// continue iterating through array from the index before the deleted item.
		// repeat until end of list.
		// std::cout << "HERE?" << std::endl ;
		type *erased_array = new type[arraySize] ;
		int working_index = 0 ;

		while (working_index <= itail) // copies the original array to a erased_array.
		{
			erased_array[working_index] = array[working_index] ;
			working_index++ ;
		}

		// erased_array is now a full copy of array.

		int count_temp = count ;
		int itail_temp = itail ;

		int i = 0 ;
		int erased = 0 ;
		working_index = 1 ;
		int mod = 0 ;

		while (i <= count_temp - 1) // do this until end of array.
		{
			if (erased_array[i] == data)
			{
				working_index = i + 1 ;
				// std::cout << "erasing " << erased_array[i] << ", with i = " << i << " and working_index = " << working_index << "." << std::endl ;
				// working_index = i + 1 ;

				while (working_index <= itail_temp) // creates new array without erased_array[i] ;
				{
					erased_array[working_index - 1] = array[working_index + mod] ;
					working_index++ ;
				}

				mod++ ;
				// working_index = i + 1 ;
				itail_temp-- ;
				count_temp-- ;
				erased++ ;
				i-- ;
			}

			i++ ;
			// std::cout << "i = " << i << std::endl ;
		}

		int temp_arraySize  = arraySize ;
		bool flag = true ;

		while (flag == true) // resizing.
		{
			if (count_temp <= (arraySize / 2) && (arraySize / 2) >= initialSize)
			{
				arraySize = arraySize / 2 ;
			}

			else
			{
				flag = false ;
			} 
		}

		type *new_array = new type[arraySize] ;
		working_index = 0 ;

		while (working_index <= itail_temp) // resizing.
		{
			new_array[working_index] = erased_array[working_index] ;
			working_index++ ;
		}

		// std::cout << std::endl << "temp_arraySize: " << temp_arraySize << std::endl << std::endl ;

		count = count_temp ;

		if (count == 0 || count == 1) // special case.
		{
			ihead = 0 ;
			itail = 0 ;
		}

		else
		{
			itail = itail_temp ;
		}

		array = new_array ;
		// std::cout << "HERE?" << std::endl ;
		return erased ;
	}




































	// not specified in prompt , for testing purposes.

	int initial_size(){return initialSize ; } // returns initial size.

	void private_output() // prints the private members.
	{
		std::cout << "     " << "ihead: " << ihead << std::endl ;
		std::cout << "     " << "itail: " << itail << std::endl ;
		std::cout << "     " << "count: " << count << std::endl ;
		std::cout << "     " << "initialSize: " << initialSize << std::endl ;
		std::cout << "     " << "arraySize: " << arraySize << std::endl ;
	}

	void test_suite_1() // displays basic information.
	{

		std::cout << "test_suite_1(): " << std::endl ;

		if (this->empty())
			std::cout << "     " << "empty(): list is empty." << std::endl ;
		else
			std::cout << "     " << "empty(): list contains " << this->size() << " element(s)." << std::endl ;

		try
		{
			std::cout << "     " << "front(): " << this->front() << "." << std::endl ;
		}

		catch (const std::underflow_error& error)
		{
			std::cerr << "     " << error.what() << std::endl ;
		}

		try
		{
			std::cout << "     " << "back(): " << this->back() << "." << std::endl ;
		}

		catch (const std::underflow_error& error)
		{
			std::cerr << "     " << error.what() << std::endl ;
		}

		this->private_output() ;

		std::cout << std::endl ;
	}

	void temp_display_FIXME() // TEMPORARY TESTING FIX , MUST MAKE A "REAL" DISPLAY USING A TEMPORARY STACK AND POP / DEQUEUE.
	{
		int i = 0 ;
		std::cout << "temp_display_FIXME(): " << std::endl ;

		while(i <= arraySize - 1)
		{
			std::cout << i + 1 << ": " << array[i] << std::endl ;
			i++ ;
		}

		std::cout << std::endl ;
	}

	void temp_display_FIXME_short() // TEMPORARY TESTING FIX , MUST MAKE A "REAL" DISPLAY USING A TEMPORARY STACK AND POP / DEQUEUE.
	{
		int i = 0 ;
		std::cout << "temp_display_FIXME_short(): " << std::endl ;

		while(i <= count - 1)
		{
			std::cout << i + 1 << ": " << array[i] << std::endl ;
			i++ ;
		}

		std::cout << std::endl ;
	}
} ;

