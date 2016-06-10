static int num = 0;
template <class type> class Node{
private:
    type data;
    Node * next;
    int ID;
    template<class U>
    friend class SLinkedList;
public:
    Node():data(0),next(0){
        ID = 0;
        this->ID = ++num;
    }
    Node(const type & data):next(0){
        this->data = data;
        this->ID = ++num;
    }

    Node(const type & data, Node * next){
        this->data = data;
        this->next = next;
        this->ID = ++num;
    }

};
