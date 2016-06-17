#ifndef DYNQUEUE_H
#define DYNQUEUE_H

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
	int arraySize ; // the current array size.  the end of index is arraySize - 1.

public:

	DynQueue(int n = 13) // O(1).
	{
		if (n <= 0) // has to be at lease 1.
			n = 1 ;
		
		ihead = 0 ;
		itail = 0 ;
		array = new type[n] ; // new array , index from 0 to n - 1.
		count = 0 ; // empty array.
		initialSize = n ;
		arraySize = n ;
	}

	~DynQueue(){delete[] array ; } // O(1).

	type front() const // returns first in queue.  O(1).
	{	
		if (this->empty())
			throw std::underflow_error("front(): the list is empty - underflow_error.") ;
		else
			return array[ihead] ; 
	} 

	type back() const // returns last in queue.  O(1).
	{	
		if (this->empty())
			throw std::underflow_error("back(): the list is empty - underflow_error.") ;
		else
			return array[itail] ; 
	} 

	int size() const {return count ; } // returns number of elements currently in array.  O(1).

	bool empty() const // is this array empty?  O(1).
	{
		if (count == 0)
			return true ;
		else
			return false ; 
	}

	int capacity() const {return arraySize ; } // returns current array size.  O(1).

	void display() // displays from the front to the back.  O(n).
	{	// creates a temporary array.  copy all elements of array to temp_array via dequeue_display() , and output each element.  sets temp_array as array , and reset all indexes to starting values.
		if (this->empty())
			std::cout << "display(): the queue is empty and there is nothing to display." << std::endl << std::endl ;

		else
		{
			std::cout << "display(): " << std::endl << std::endl ;

			type *temp_array = new type[arraySize] ;
			int k = 0 ;
			int i = ihead ;
			int temp_ihead = ihead ;
			int temp_itail = itail ;
			int temp_count = count ;

			while (!this->empty())
			{
				temp_array[i] = this->dequeue_display() ;
				std::cout << "    " << k + 1 << ": " << temp_array[i] << std::endl ;
				i++ ;
				k++ ;

				if (i > arraySize - 1)
					i = 0 ;

			}

			array = temp_array ;
			ihead = temp_ihead ;
			itail = temp_itail ;
			count = temp_count ;

			std::cout << std::endl ;
		}

		return ;
	}

	void enqueue(type const &data) // inserts a new element at the back of the queue.  follows capacity rules.  worst case O(n) , on average O(1).
	{      
		if (count + 1 > arraySize) // resizing array by creating new array and copying all elements over.  worst case scenario O(n).
		{
			type *new_array = new type[arraySize * 2] ; // new array 2x bigger.
			int working_index = ihead ;
			int i = 0 ;

			while (i <= count - 1) // copy old array to new array.  O(n).
			{
				new_array[i] = array[working_index] ;
				// std::cout << "new_array[" << i << "] = array[" << working_index << "] = " << array[working_index] << std::endl ;

				if (working_index + 1 > arraySize - 1)
					working_index = 0 ;

				else
					working_index++ ;

				i++ ;
				// std::cout << i << std::endl ;
			}

			array = new_array ;
			ihead = 0 ;
			itail = count - 1 ;
			arraySize = arraySize * 2 ;
			std::cout << "enqueue(): array ceiling reached , doubled array size to " << arraySize << ".  continuing equeue()..."<< std::endl << std::endl ;
		}

		// everything after this point will be average case.
		// we can assume that there will be enough size in the array for the new item.

		if (count == 0) // this is when the array is empty.
		{
			array[0] = data ;
			count++ ;
			ihead = 0 ;
			itail = 0 ;
		}

		else
		{
			if (itail + 1 > arraySize - 1) // if the new index is larger than the last index of array , loop back around.
				itail = itail + 1 - arraySize ;

			else // if the next value is still within the range.
				itail++ ;

			array[itail] = data ;
			count++ ;
		}

		return ;
	} 

	type dequeue() // O(1) on average , worst case O(n).
	{
		type temp = array[ihead] ;

		if (this->empty())
			throw std::underflow_error("dequeue(): the list is empty - nothing to delete.") ;
		else
		{
			if (ihead + 1 > arraySize - 1)
				ihead = 0 ;

			else
				ihead++ ;

			count-- ;

			if (count == 0)
			{
				ihead = 0 ;
				itail = 0 ;
			}

			// resizing if needed.  worst case scenario , O(n).

			if (count <= arraySize / 2 && arraySize / 2 >= initialSize) // resizing array by creating new array and copying all elements over.  worst case scenario.
			{
				type *new_array = new type[arraySize / 2] ; // new array half sized.
				int working_index = ihead ;
				int i = 0 ;

				while (i <= count) // copy old array to new array.  O(n).
				{
					new_array[i] = array[working_index] ;

					if (working_index + 1 > arraySize - 1)
						working_index = 0 ;

					else
						working_index++ ;

					i++ ;
				}

				array = new_array ;
				arraySize = arraySize / 2 ;
				ihead = 0 ;
				itail = count - 1 ;
				std::cout << "enqueue(): array floor reached , halved array size to " << arraySize << ".  continuing dequeue()..."<< std::endl << std::endl ;
			}

			return temp ; // to do.
		}
	}

	type dequeue_display() // O(1).  does not contain resizing , for display implementation.
	{
		type temp = array[ihead] ;

		if (this->empty())
			throw std::underflow_error("dequeue(): the list is empty - nothing to delete.") ;
		else
		{
			if (ihead + 1 > arraySize - 1)
				ihead = 0 ;

			else
				ihead++ ;

			count-- ;

			if (count == 0)
			{
				ihead = 0 ;
				itail = 0 ;
			}

			return temp ; // to do.
		}
	}

	void clear() // removes all elements in queue.  resize to initial size.  O(1).
	{
		type *new_array = new type[initialSize] ;
		array = new_array ;
		arraySize = initialSize ;
		ihead = 0 ;
		itail = 0 ;
		count = 0 ;
	}

	int erase(type const &data) // deletes a specific element (all of them) , follows capacity rules.  on average , O(n).
	{
		type *temp_array = new type[arraySize] ;
		int j = 0 ;
		int erased = 0 ;
		int temp_count = count ;

		if (this->empty())
			throw std::underflow_error("erase(): the queue is empty and there is nothing to erase.") ;

		else
		{
			while (!this->empty())
			{
				if (this->front() == data)
				{
					// std::cout << "erasing " << this->front() << std::endl ;
					this->dequeue_display() ;
					erased++ ;
				}
				else
				{
					temp_array[j] = this->dequeue_display() ;
					j++ ;
				}
			}
		}

		array = temp_array ;
		ihead = 0 ;
		count = temp_count - erased ;
		itail = count - 1 ;

		// now to resize.
		
		bool flag = true ;

		while (flag == true) // keep resizing until it fits.
		{
			if (count <= arraySize / 2 && arraySize / 2 >= initialSize) // resizing array by creating new array and copying all elements over.  worst case scenario.
			{
				type *new_array = new type[arraySize / 2] ; // new array half sized.
				int working_index = ihead ;
				int i = 0 ;

				while (i <= count) // copy old array to new array.  O(n).
				{
					new_array[i] = array[working_index] ;

					if (working_index + 1 > arraySize - 1)
						working_index = 0 ;

					else
						working_index++ ;

					i++ ;
				}

				array = new_array ;
				arraySize = arraySize / 2 ;
				ihead = 0 ;
				itail = count - 1 ;
				std::cout << "erase(): array floor reached , halved array size to " << arraySize << ".  continuing erase()..."<< std::endl << std::endl ;
			}

			else
				flag = false ;
		}

		return erased ;
	}
} ;

#endif