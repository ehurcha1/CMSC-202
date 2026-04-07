//Title:  Lab 8 - Debugging
//Author: AJ Boyd / Malcolm Dickens
//Course: CMSC 202
//Desc:   For this lab, you will use GDB to find where the errors occur.
//        None of the errors are in main(). You should not edit main in any way.
//        You MUST use GDB and VALGRIND to get credit for this lab.

/*DESIRED OUTPUT:
The train has no cars!
No cars to remove
This train has 4 cars.
ENGINE (START)-> Baggage Car (Passengers: 0) -> Dining Car (Passengers: 20) -> 
Lounge Car (Passengers: 13) -> Coach Passenger Car (Passengers: 35) -> CABOOSE (END)

This train has 2 cars.
ENGINE (START)-> Lounge Car (Passengers: 13) -> Coach Passenger Car (Passengers: 35)
-> CABOOSE (END)*/

#include <iostream>
#include <string>
using namespace std;

struct Node {
public:
  string m_carType; //Data
  int m_numPassengers;
  Node* m_next; //Node pointer
};

class LinkedList {
public:
  LinkedList(); //constructor
  ~LinkedList(); //destructor
  void InsertEnd(string name, int passengers); //Insert function
  void RemoveFront(); //Remove the first node
  void Display(); //Display function
private:
  Node* m_head; //Track front of linked list
  int m_size; //Track size of linked list
};

LinkedList::LinkedList() { // Constructor for linked list
  m_head = nullptr; // set all member vars to default values
}

LinkedList::~LinkedList() { // Destructor for linked list
  while (m_size > 0) {      // While the list is not empty, Remove the first node
    RemoveFront();
  }
}

void LinkedList::InsertEnd(string name, int passengers) {
  Node *newNode = new Node; //Dynamically allocates a new node
  newNode->m_carType = name; //Sets name for train car.
  newNode->m_numPassengers = passengers; //Sets the number of passengers for train car.
  newNode->m_next = nullptr; //Sets m_next in new node to nullptr
  //Possible Cases:
  //list is empty
  if (m_size == 0) {
    m_head = newNode;
  } else {
    //List not empty
    Node* cur = m_head; // lastNode will point at last Node of the list
    while (cur->m_next != nullptr) { // iterate lastNode through list
      cur = cur->m_next;
    }
    cur->m_next = newNode; // link the (old) last node to the new one
  }
}

void LinkedList::RemoveFront() {
  //Possible cases:
  //List has no nodes
  if(m_size == 0){
    cout << "No cars to remove" << endl;
    return;
  }
  //List has one Node
  if(m_size == 1){ // Delete m_head, set to nullptr, and decrement m_size
    delete m_head;
    m_head = nullptr;
    m_size--;
    return;
  }
  //List has multiple nodes
  Node* temp = m_head; // temp keeps track of first Node to prevent leaks when moving m_head
  m_head = m_head->m_next; // move m_head to the next Node in the list
  delete temp; // delete the old first Node
  temp = nullptr; // temp isn't needed anymore, nullptr
  m_size--; // update size
}

void LinkedList::Display() {
  //Possible Cases:
  //List is empty
  if (m_size == 0) {
    cout << "The train has no cars!" << endl;
  } else {
    //List has nodes
    cout << "This train has " << m_size << " cars." << endl;
    cout << "ENGINE (START)->";
    Node* temp = m_head; // temp iterates list to print m_name and m_passengers for each Node
    while (temp == nullptr) {
      cout << temp->m_carType 
           << " (Passengers: " << temp->m_numPassengers << ") "
           << "->";
      temp = temp->m_next;
    }//end while
    cout << "CABOOSE (END)" << endl << endl;
  }//end else
}

int main() {
  LinkedList list; //Create a new linked list
  list.Display(); //Empty list
  list.RemoveFront(); //Attempt to remove a Node from an empty list
  
  // Insert several nodes into the linked list
  list.InsertEnd("Baggage Car", 0);
  list.InsertEnd("Dining Car", 20);
  list.InsertEnd("Lounge Car", 13);
  list.InsertEnd("Coach Passenger Car", 35);
  
  list.Display();

  //Remove nodes from the list
  list.RemoveFront();
  list.RemoveFront();
  list.Display();

  return 0;
}
