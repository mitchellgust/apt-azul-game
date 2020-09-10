#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template<class T>
struct Node {
    T data;
    Node<T> *next;
};

template<class T>
class LinkedList {

private:
    Node<T> *head;
    int length;

public:
    //Constructor
    LinkedList() {
        head = nullptr;
        length = 0;
    }

    //Deconstructor
    ~LinkedList() {
        Node<T> *temp = head;
        while (temp->next != nullptr) {
            Node<T> *current = temp->next;
            delete temp;
            temp = current;
        }
    }

    //Add Node to the back of the list
    void addBack(T data){
        auto * node = new Node<T>;
        node->data = data;
        node->next = nullptr;
        if (!head){
            head = node;
        }else {
            auto * tail = head;
            while (tail->next) tail = tail-> next;
            tail->next = node;
        }
        length++;
    }

    //Add Node to the front of the list
    void addFront(T data){
        auto * newNode = new Node<T>();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        length++;
    }

    //Check whether list is empty
    bool isEmpty(){
        return length == 0;
    }

    //Retrieve a node at the required position
    T get(int index){
        T result;
        if (index == 0){
            result = head->data;
        }
        else {
            auto * curr = head;
            for (int i = 0; i < index; ++i) {
                curr = curr->next;
            }
            result = curr->data;
        }
        return result;
    }

    //Remove item from front of the list
    void popFront(){
        if (head){
           if (head->next){
                Node<T> * temp = head->next;
                delete head;
                head = temp;
            }
            else {
                std::cout << "HERE" << std::endl;
                delete head;
                head = nullptr;
            }

            length--;
        }
        else {
            throw std::runtime_error("Called popFront() when the list is empty");
        }

    }

    //Delete chosen Node
    void deleteNode(Node<T> * node){
        if (head == node){
            if (head->next == nullptr){
                head == nullptr;
            }
            else {
                head->data = head->next->data;
                node = head->next;

                head->next = head->next->next;

                delete node;
            }
            length--;
        }
        else {
            Node<T> * prev = head;
            while(prev->next != nullptr && prev->next != node){
                prev = prev->next;
            }
            if (prev->next == nullptr){
                std::cout << "This value does not exist in the list" << std::endl;
            }

            prev->next = prev->next->next;

            delete node;
            length--;
        }
    }


    //Retrieve the length of the list at point required
    int getLength() {
        return length;
    }


};

#endif