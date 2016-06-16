#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

template <class type> class Stack {
private:
	type *info;
	int count;					//counts the elements in the array
	int initialSize;			//initial size of array
	int arraySize;				//current array size
	int top_of_array;			//current index for top of array

public:

	Stack(int n=13) 
	{
		if (n<=0) {n=1;}
		
		info = new type[n];
		count = 0;
		initialSize = n;
		arraySize = n;
		top_of_array = -1;

		//initialize
		for (int i=0; i< arraySize; i++) 
		{
			this->info[i] = 0;
		}
	}

	~Stack() {delete[] info;}

	type top() const 
	{
		if (top_of_array == -1) {throw underflow_error ("The Stack is empty (Location: top)");}
		else{return info[top_of_array];}
	}

	int size() const {return count;}
	bool empty() const {return (top_of_array == -1);}
	int capacity() const {return arraySize;} 

	void display() 
	{
		if (empty()) {cout << "The Stack is empty (Location: display)" << endl;}
		else {
			Stack<type> *temp = new Stack (arraySize);

			while(!empty())
			{
				type data = pop();
				cout << data;
				temp->Push(data);
			}
			while (!temp->empty())
			{
				type data = temp->pop();
				this->Push(data);
			}
			delete temp;
			cout << endl;

		}
	}


	//Mutators

	void Push (type const &data) 
	{
		ResizeStacks(0);
	
		top_of_array++;
		info[top_of_array] = data;
		count++;
	}

	type pop() 
	{
		if (empty()) {throw underflow_error ("The Stack is empty (Location: pop)");}
		else 
		{	
			type tmp = this->top();
			this->info[top_of_array] = 0;
			count--;
			top_of_array--;
			
			ResizeStacks(1);
			return tmp;
		}
	
	}

	void clear() 
	{
		if (empty()) {cout << "The Stack is empty" << endl;}
		else {

			delete [] info;
			count = 0;
			top_of_array = -1;
			arraySize = initialSize;
		
			cout << endl << "Stack size was resized to inital size" << endl;
			
			info = new type [initialSize];
		}
		
	}

	
	//If, after the element(s) is/are removed, the array is 1/4 full and the array size is greater than the initial size, 
	//the size of the array is halved. Return the number of elements that were deleted. 
int erase(type const &data) 
	{
		if (empty()) {throw underflow_error ("The Stack is empty (Location: erase)");}
		else
		{
		int numDeleted = 0;
		int tempIndex = -1;
		type *tmp;
		tmp = new type[arraySize];

		for (int n = top_of_array; n>=0; n--)
			{
				if (this->info[n] == data)
				{
					this->info[n] = 0;
					count--;
					top_of_array--;
					//this->pop();
					numDeleted++;
				}
				else
				{
					tempIndex++;
					tmp[tempIndex] = this->info[n];
					this->info[n] = 0;
					count--;
					top_of_array--;
					//this->pop();
				}
			}

		for (int n=tempIndex; n>=0; n--)
		{
			this->Push(tmp[n]);
		}


		//Check if after deleted array needs to be halfed
		ResizeStacks(1);

		return numDeleted;
	}
	}

private:
void ResizeStacks(const double& n)
{
	if (n==1){
		double size_comparison = 0;
		double c = count;
		double s = arraySize;
		size_comparison = c/s;
		
		if (((size_comparison) <= 0.25) && (arraySize>initialSize)) //Half the array size
		{
			int newSize = 0;
			newSize = (arraySize/2);
			type *tmp;
			tmp = new type[newSize];
			copy(info, info + arraySize, tmp);

			info = new type[newSize];
			//initialize new values
			for (int i=0; i< newSize; i++) 
			{
				this->info[i] = 0;
			}
			copy(tmp, tmp + newSize, info);

			arraySize = newSize;
			cout << endl << "Stack size was halfed (erase)" << endl;

		}
	}


		//-----------------------------------------------------------------------------------//
	else
	{
		//Double Stack Size
		if (count == arraySize) //double size of stack
		{
			int newSize = 0;
			newSize = (arraySize * 2);
			type *tmp;
			tmp = new type[newSize];
			copy(info, info + arraySize, tmp);

			info = new type[newSize];
			//initialize new values
			for (int i=0; i< newSize; i++) 
			{
				this->info[i] = 0;
			}
			copy(tmp, tmp + arraySize, info);

			arraySize = newSize;
			cout << "Stack size was doubled" << endl;
		}

	}

	}
};
