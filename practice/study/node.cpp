#include <iostream>
#include <string>
using namespace std;

struct Node {
  string m_owner;
  Node *m_next;
};

int main() {
  Node *head = nullptr;

  // Create first node
  Node *newNode = new Node;
  newNode->m_owner = "Elliot";
  newNode->m_next = nullptr;
  head = newNode;

  // Print
  cout << head->m_owner << endl;

  delete head;
  return 0;
}