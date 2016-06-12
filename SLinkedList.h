#include "Node.h"
#include<iostream>
#include<cassert>
using namespace std;

template<class T> class SLinkedList{
private:
    Node<T> * head;
    int sz;

public:
    SLinkedList():head(nullptr), sz(0){
    }
    bool isEmpty() const{
        return head == nullptr;
    }

	int Size() const { return sz; };

    void insert(const T & data){
        Node<T> *tmp_node = new Node<T>(data);
        Node<T> *ptr = head;
        if (ptr == nullptr){
            head = tmp_node;
            sz++;
        }
        else{
            while(ptr->next != nullptr){
                ptr = ptr->next;
            }
            ptr->next = tmp_node;
            sz++;
        }
        // SLinkedList::printLst();
    }

    void insertBefore(const T & data, int pos){
        if(pos<=1){
            Node<T> *newNode = new Node<T>(data,head);
            head = newNode;
            sz++;
			SLinkedList::printLst();
        }
        else if(pos > sz){
            SLinkedList::insert(data);
        }
        else{
            int p =1;
            Node<T> *newNode = new Node<T>(data);
            Node<T> *ptr = head;
            while(p!=pos -1){
                ptr = ptr->next;
                p++;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
            SLinkedList::printLst();
        }
    }

    void del(const T & data){
        Node<T> *ptr = head;
        Node<T> *prev = head;
        while(ptr!=nullptr){
            if(ptr->data==data){
                if(ptr==head) head = ptr->next;
                else{
                    prev->next=ptr->next;
                    cout << ptr->ID << endl;
                    ptr = prev;
                }
            }
            prev = ptr;
            ptr = ptr->next;

        }
        SLinkedList::printLst();
    }

    void printLst() const
	{
        Node<T> *ptr = head;
		int counter = 0;

        while(ptr != nullptr)
		{
            cout << /*"Node[" << counter++ << "]=" <<*/ ptr->data << " --> ";
            ptr = ptr->next;
        }

        cout << "[NULL]" << endl;
    }

    void clear(){
        Node<T> *ptr = head;
        Node<T> * prev = head;
        while(ptr!=nullptr){
            ptr = ptr->next;
            delete prev;
            prev = ptr;
        }
        head = nullptr;
    }

    T getHeadValue(){
        return head->data;
    }
};
