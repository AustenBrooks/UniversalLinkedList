#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

/*
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

Function Prototypes
(you cant use templates if you have both a .h and .cpp)

&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
*/

template<typename T>
struct Node{
    T data;
    Node<T>* next;
};

template<typename T>
class LinkedList{
    private:
    Node<T>* head = nullptr;
    
    public:
    // Constructor
    LinkedList();
    // Destructor
    ~LinkedList();
    // Copy Constructor
    LinkedList(const LinkedList& listToCopy);
    // Copy Assignment Override
    LinkedList& operator=(const LinkedList& listToCopy);
    
    void push(T); // Add new value to head of list
    
    T pop(); // return value at head and remove head
    
    void print() const; // print list contents
    
    T get(int) const; // get value at specified index
    
    int size() const; // Returns numnber of nodes in the list
    
    void insert(T, int); // Adds a node at the specified index within the list
};

/*
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

Function Definitions
(you cant use templates if you have both a .h and .cpp)

&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
*/

// Constructor
template<typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;
}

// Destructor
template<typename T>
LinkedList<T>::~LinkedList(){
    // pop all items off list
    while(head != nullptr){
        pop();
    }
}

// Copy Constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& listToCopy){
    // Copy linked list conents to new object
    head = nullptr;
    for(int i = listToCopy.size() - 1; i >= 0; i--){
        push(listToCopy.get(i));
    }
}

// Copy Assignment Override
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& listToCopy) {
   // ensure assignment operator isn't to itself
   if (this != &listToCopy) {
       // deallocate previous list
        while(head != nullptr){
            pop();
        }
        
        // create deep copy of new list
        head = nullptr;
        for(int i = listToCopy.size() - 1; i >= 0; i--){
            push(listToCopy.get(i));
        }
   }
   
   return *this;
}

template<typename T>
T LinkedList<T>::get(int idx) const{
    Node<T>* p = head;
    for(int i = 0; i < idx; i++){
        p = p->next;
    }
    return p->data;
}

template<typename T>
void LinkedList<T>::push(T new_data) { 
   Node<T>* new_node = new Node<T>;
   new_node->data = new_data; 
   new_node->next = head; 
   head = new_node; 
}

template<typename T>
T LinkedList<T>::pop(){
    T returnVal = head->data;
    
    Node<T>* oldHead = head;
    head = head->next;
    
    delete oldHead;
    
    return returnVal;
}

template<typename T>
void LinkedList<T>::print() const{ 
   Node<T>* ptr = head;

   while (ptr != nullptr) { 
      cout<< ptr->data <<" "; 
      ptr = ptr->next; 
   } 
   cout << endl;
}

template<typename T>
int LinkedList<T>::size() const{
    Node<T>* ptr = head;
    int count = 0;
    while (ptr != nullptr) { 
      count++;
      ptr = ptr->next; 
    }
    return count;
}

template<typename T>
void LinkedList<T>::insert(T value, int index){
    if(index >= this->size())
        return;
    else if(index == 0){
        push(value);
        return;
    }
    
    Node<T>* ptr = head;
    Node<T>* lastPtr = nullptr;
    int idx = 0;
    while(idx < index){
        idx++;
        lastPtr = ptr;
        ptr = ptr->next;
    }
    
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->next = ptr;
    
    lastPtr->next = newNode;
}

#endif