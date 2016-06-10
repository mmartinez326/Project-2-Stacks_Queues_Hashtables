//#include <iostream>
//#include "Command_Processor.h"
//using namespace std;
//
//Command_States Command_Processor::command_state = Initial;
//
//Menu* Command_Processor::menus[NR_CMD_STATES];
//
//bool flag1 = false;
//bool flag2 = false;
//
//void Command_Processor::Create_Menus()
//{
//    // Menu for Initial command state
//    Menu* menu = new Menu("Enter command number");
//    menu->Add_Command("Cyclic Linked List");
//	menu->Add_Command("Doubly Linked List");
//    menu->Add_Command("Quit");
//    menus[0] = menu;
//
//    
//    menu = new Menu("Enter command number");
//    menu->Add_Command("Create Cyclic List");
//	menu->Add_Command("Delete List");
//	menu->Add_Command("Size");
//	menu->Add_Command("Empty");
//	menu->Add_Command("Print Front Data");
//	menu->Add_Command("Print Back Data");
//	menu->Add_Command("Print Head Address");
//	menu->Add_Command("Print Tail Address");
//	menu->Add_Command("Count");
//	menu->Add_Command("Push Front");
//	menu->Add_Command("Push Back");
//	menu->Add_Command("Pop Front");
//	menu->Add_Command("Erase");
//	menu->Add_Command("Print List");
//	menu->Add_Command("Return to previous menu");
//    menu->Add_Command("Quit");
//    menus[1] = menu;
//
//
//	menu = new Menu("Enter command number");
//    menu->Add_Command("Create Doubly List");
//	menu->Add_Command("Delete List");
//	menu->Add_Command("Size");
//	menu->Add_Command("Empty");
//	menu->Add_Command("Print Front Data");
//	menu->Add_Command("Print Back Data");
//	menu->Add_Command("Print Head Address");
//	menu->Add_Command("Print Tail Address");
//	menu->Add_Command("Count");
//	menu->Add_Command("Push Front");
//	menu->Add_Command("Push Back");
//	menu->Add_Command("Pop Front");
//	menu->Add_Command("Erase");
//	menu->Add_Command("Print List");
//	menu->Add_Command("Return to previous menu");
//    menu->Add_Command("Quit");
//    menus[2] = menu;
//}
//
//void Command_Processor::Process_Commands()
//{
//    cout << "Process_Commands starting\n";
//
//	Create_Menus();
//
//    while (command_state != Done)
//    {
//       
//        const string* cmd = menus[command_state]->Get_Command();
//
//
//        switch (command_state)
//        {
//        case Initial:   Process_Command_0(*cmd);
//            break;
//
//        case State_Selected:    Process_Command_1(*cmd);
//            break;
//
//		case State_Selected2:    Process_Command_2(*cmd);
//            break;
//
//        case Done:  break;      // Can't happen
//        }
//    }
//
//   cout << "Process_Commands  exiting\n";
//}
//
//
//
//// Process command in Initial command state
//void Command_Processor::Process_Command_0(const string& cmd)
//{
//    if (cmd == "Cyclic Linked List")
//    {
//        cout << "Select Cyclic Command\n";
//        command_state = State_Selected;
//    }
//	else if (cmd == "Doubly Linked List")
//    {
//        cout << "Select Doubly Command\n";
//        command_state = State_Selected2;
//    }
//    else
//    {
//        command_state = Done;
//    }
//}
//
//// Process command in Cyclic Linked List command state
//void Command_Processor::Process_Command_1(const string& cmd)
//{
//	//CyclicLinkedList<double> Cyclic_list;  
//
//    if (cmd == "Create Cyclic List")
//    {
//		if (flag1 == true) { cout << "The list was already created" << endl; }
//        //CyclicLinkedList<double> Cyclic_list;
//        else 
//		{
//			cout << "List created\n";
//			flag1 = true;
//			command_state = State_Selected;
//		}
//        
//    }
//	else if (cmd == "Delete List")
//	{
//		if (!flag1) { cout << "List has not been created." << endl;}
//		else {
//			delete Cyclic_list;
//			cout << "List deleted" << endl;
//			flag1 = false;
//		}
//
//		command_state = State_Selected;
//	}
//	else if (cmd == "Size")
//	{
//		if (!flag1) { cout << "List has not been created." << endl;}
//		else {
//			cout << "Size of list: " << Cyclic_list->Size() << endl;
//		}
//		command_state = State_Selected;
//	}
//	else if (cmd == "Empty")
//	{
//		if (!flag1) { cout << "List has not been created." << endl;}
//		else 
//		{
//			cout << "Is list Empty? " << (Cyclic_list->empty()?"Yes":"No") << endl;
//		}
//		command_state = State_Selected;
//	}
//	else if (cmd == "Print Front Data")
//	{
//		if (!flag1) { cout << "List has not been created." << endl;}
//		else {
//			try
//			{
//				cout << "Front data: " << Cyclic_list->front() << endl;
//			}
//			catch (const underflow_error& e)
//			{
//				cerr << e.what() << endl;
//			}
//			}
//		command_state = State_Selected;
//	}
//	else if (cmd == "Print Back Data")
//	{
//		if (!flag1) { cout << "List has not been created." << endl;}
//		else {
//			try
//			{
//				cout << "Back data: " << Cyclic_list->back() << endl;
//			}
//			catch (const underflow_error& e)
//			{
//				cerr << e.what() << endl;
//			}
//		}
//		command_state = State_Selected;
//	}
//	else if (cmd == "Print Head Address")
//	{
//		if (!flag1) { cout << "List has not been created." << endl;}
//		else 
//		{
//			cout << "Head Address: " << Cyclic_list->Head() << endl;
//		}
//		command_state = State_Selected;
//	}
//	else if (cmd == "Print Tail Address")
//	{
//		if (!flag1) { cout << "List has not been created." << endl;}
//		else 
//		{
//			cout << "Tail Address: " << Cyclic_list->Tail() << endl;
//		}
//		command_state = State_Selected;
//	}
//	else if (cmd == "Count")
//	{
//		if (!flag1) { cout << "List has not been created." << endl;}
//		else 
//		{
//			double bubble;
//			cout << "Enter value to count: " << endl;
//			cin >> bubble;
//			cin.ignore();
//			cout << "Number of elements of " << bubble << ": " << Cyclic_list->count(bubble) << endl;
//		}
//		command_state = State_Selected;
//	}
//    else if (cmd == "Push Front")
//    {
//		if (!flag1) {
//                cerr << endl << "Cannot insert element. List has not been created yet." << endl;
//				}
//		else {
//				double data;
//                cout << "Enter value to be inserted" << endl;
//                cin >> data;
//				cin.ignore(); //due to error with next menu
//				Cyclic_list->push_front(data);
//				cout << "Element Inserted" << endl << endl;
//            }
//			
//        command_state = State_Selected;
//    }
//	else if (cmd == "Push Back")
//    {
//		if (!flag1) {
//                cerr << endl << "Cannot insert element. List has not been created yet." << endl;
//				}
//		else {
//				double data;
//                cout << "Enter value to be inserted" << endl;
//                cin >> data;
//				cin.ignore(); //due to error with next menu
//				Cyclic_list->push_back(data);
//				cout << "Element Inserted" << endl << endl;
//            }
//			
//        command_state = State_Selected;
//    }
//	else if (cmd == "Pop Front")
//	{
//		if (!flag1) {cerr << endl << "Cannot pop front element. List has not been created yet." << endl;}
//		else {
//		double trouble = 0;
//
//		try
//		{
//			trouble = Cyclic_list->pop_front(); // This method can throw an error instead of returning a value.
//			cout << "Element Erased " << trouble << endl << endl;
//		}
//		catch (const underflow_error& e)
//		{
//			cerr << e.what() << endl;
//		}
//		}
//            
//        command_state = State_Selected;
//    }
//	else if (cmd == "Erase")
//    {
//		if (!flag1) { cout << "List has not been created." << endl;}
//		//else if (Cyclic_list.empty()) { cout << "List is empty." << endl;}
//		else {
//		double data;
//            cout << "Enter value to delete\n-->";
//            cin >> data;
//			cin.ignore(); //due to error with next menu
//        cout <<  Cyclic_list->erase(data) <<" Element(s) Deleted\n";
//		}
//
//		command_state = State_Selected;
//    }
//	else if (cmd == "Print List")
//	{  
//		if (!flag1) {
//                cerr << endl << "Cannot print list. List has not been created yet." << endl;
//				}
//		//else if (Doubly_list.empty()) { cout << "List is empty" << endl;}
//		else Cyclic_list->Display();
//		command_state = State_Selected;
//
//	}
//	else if (cmd == "Return to previous menu")
//	{
//		command_state = Initial;
//	}
//    else
//    {
//        command_state = Done;
//    }
//}
//
//
//// Process command in Doubly Linked List command state
//void Command_Processor::Process_Command_2(const string& cmd)
//{
//
//
//     if (cmd == "Create Doubly List")
//    {
//		if (flag2 == true) { cout << "The list was already created" << endl; }
//		else
//		{
//			Doubly_list = new DoublyLinkedList<double> ();
//			cout << "List created\n";
//			flag2 = true;
//			command_state = State_Selected2;
//		}
//        
//    }
//	else if (cmd == "Delete List")
//	{
//		if (!flag2) { cout << "List has not been created." << endl;}
//		else {
//			delete Doubly_list;
//			cout << "List deleted" << endl;
//			flag2 = false;
//		}
//
//		command_state = State_Selected2;
//	}
//	 	else if (cmd == "Size")
//	{
//		if (!flag2) { cout << "List has not been created." << endl;}
//		else {
//			cout << "Size of list: " << Doubly_list->Size() << endl;
//		}
//		command_state = State_Selected2;
//	}
//	else if (cmd == "Empty")
//	{
//		if (!flag2) { cout << "List has not been created." << endl;}
//		else 
//		{
//			cout << "Is list Empty? " << (Doubly_list->empty()?"Yes":"No") << endl;
//		}
//		command_state = State_Selected2;
//	}
//	else if (cmd == "Print Front Data")
//	{
//		if (!flag2) { cout << "List has not been created." << endl;}
//		else {
//			try
//			{
//				cout << "Front data: " << Doubly_list->front() << endl;
//			}
//			catch (const underflow_error& e)
//			{
//				cerr << e.what() << endl;
//			}
//			}
//		command_state = State_Selected2;
//	}
//	else if (cmd == "Print Back Data")
//	{
//		if (!flag2) { cout << "List has not been created." << endl;}
//		else {
//			try
//			{
//				cout << "Back data: " << Doubly_list->back() << endl;
//			}
//			catch (const underflow_error& e)
//			{
//				cerr << e.what() << endl;
//			}
//		}
//		command_state = State_Selected2;
//	}
//	else if (cmd == "Print Head Address")
//	{
//		if (!flag2) { cout << "List has not been created." << endl;}
//		else 
//		{
//			cout << "Head Address: " << Doubly_list->Head() << endl;
//		}
//		command_state = State_Selected2;
//	}
//	else if (cmd == "Print Tail Address")
//	{
//		if (!flag2) { cout << "List has not been created." << endl;}
//		else 
//		{
//			cout << "Tail Address: " << Doubly_list->Tail() << endl;
//		}
//		command_state = State_Selected2;
//	}
//	else if (cmd == "Count")
//	{
//		if (!flag2) { cout << "List has not been created." << endl;}
//		else 
//		{
//			double bubble;
//			cout << "Enter value to count: " << endl;
//			cin >> bubble;
//			cin.ignore();
//			cout << "Number of elements of " << bubble << ": " << Doubly_list->count(bubble) << endl;
//		}
//		command_state = State_Selected2;
//	}
//    else if (cmd == "Push Front")
//    {
//		if (!flag2) {
//                cerr << endl << "Cannot insert element. List has not been created yet." << endl;
//				}
//		else {
//				double data;
//				cout << "Enter value to be inserted" << endl;
//                cin >> data;
//				cin.ignore(); //due to error with next menu
//				Doubly_list->push_front(data);
//				cout << "Element Inserted" << endl << endl;
//            }
//			
//        command_state = State_Selected2;
//    }
//	else if (cmd == "Push Back")
//    {
//		if (!flag2) {
//                cerr << endl << "Cannot insert element. List has not been created yet." << endl;
//				}
//		else {
//				double data;
//                cout << "Enter value to be inserted" << endl;
//                cin >> data;
//				cin.ignore(); //due to error with next menu
//				Doubly_list->push_back(data);
//				cout << "Element Inserted" << endl << endl;
//            }
//			
//        command_state = State_Selected2;
//    }
//	else if (cmd == "Pop Front")
//	{
//		if (!flag2) {cerr << endl << "Cannot pop front element. List has not been created yet." << endl;}
//		else {
//		double trouble = 0;
//
//		try
//		{
//			trouble = Doubly_list->pop_front(); // This method can throw an error instead of returning a value.
//			cout << "Element Erased " << trouble << endl << endl;
//		}
//		catch (const underflow_error& e)
//		{
//			cerr << e.what() << endl;
//		}
//		}
//        command_state = State_Selected2;
//    }
//	else if (cmd == "Erase")
//    {
//		if (!flag2) { cout << "List has not been created." << endl;}
//		else if (Doubly_list->empty()) { cout << "List is empty" << endl;}
//		else {
//			double data;
//            cout << "Enter value to delete\n-->";
//            cin >> data;
//			cin.ignore(); //due to error with next menu
//        cout << Doubly_list->erase(data) <<" Element(s) Deleted\n";
//		}
//
//		command_state = State_Selected2;
//    }
//	else if (cmd == "Print List")
//	{  
//		if (!flag2) {
//                cerr << endl << "Cannot print list. List has not been created yet or is empty." << endl;
//				}
//		else if (Doubly_list->empty()) { cout << "List is empty" << endl;}
//		else Doubly_list->Display();
//		command_state = State_Selected2;
//
//	}
//	else if (cmd == "Return to previous menu")
//	{
//		command_state = Initial;
//	}
//    else
//    {
//        command_state = Done;
//    }
//}