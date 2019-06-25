#include <iostream>
#include <string>
#include "list.h"

using namespace std;

template<typename T>
void testCopyConstructor(LinkedList<T> list);


// Test of linked list functions
int main() {
    LinkedList <int> list;
    list.push(7);
    list.push(10);
    list.push(3);
   
    list.print();
    // 3, 10, 7
   
    cout << list.pop() << endl;
    // 3
   
    list.print();
    // 10, 7
    
    cout << list.size() << endl;
    // 2
    
    list.insert(4, 1); // Insert 4 at index 1
    
    list.print();
    // 10, 4, 7
    
    list.insert(5, 10); // Attempt to insert value at invalid location (should do nothing)
   
    list.print();
    // 10, 4, 7
    
    testCopyConstructor(list);
    // 4, 7
    
    LinkedList<int> list2;
    list2 = list; // Call = operator overloaded function
    
    list.push(14);
    list2.push(5);
    list2.print();
    // CORRECT: 5, 10, 4, 7;

    return 0;
}

template<typename T>
void testCopyConstructor(LinkedList<T> list){
    list.pop();
    list.print();
    // CORRECT: 4, 7
}