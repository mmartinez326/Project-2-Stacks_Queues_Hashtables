#ifndef MENU_PROGRAM_H
#define MENU_PROGRAM_H

#include <cassert>
#include <iostream>
#include <string>

#include "DynQueue.h"
#include "Hash_Table.h"
#include "Menu_Program.h"
#include "Stack.h"

class Menu_Program
{

public:

	Menu_Program() ;

private:

	void Clear() ;
	void Greeting() ;
	void Main_Loop() ;

	void Stack_Create() ;
	void Stack_Loop(int size) ;

	void Queue_Create() ;
	void Queue_Loop(int size) ;

	void Hash_Table_Create() ;
	void Hash_Table_Loop(int size, double loadFactorCriterion);
} ;

#endif