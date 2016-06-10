#pragma once
#include <string>
#include "Menu.h"


enum Command_States { Initial, State_Selected, State_Selected2, Done };
using namespace std;
class Command_Processor
{
public:
    static void Process_Commands();

private:
    static const int NR_CMD_STATES = (int)Done + 1;
    static Command_States command_state;

    static Menu* menus[NR_CMD_STATES];
    Command_Processor(void) {};
    static void Create_Menus();
    static void Process_Command_0(const string& cmd);
    static void Process_Command_1(const string& cmd);
	static void Process_Command_2(const string& cmd);

    
 

};


