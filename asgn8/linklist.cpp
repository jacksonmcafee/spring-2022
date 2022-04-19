#include "linklist.h"
#include <iostream>
#include <string>

using namespace std;

LinkList::LinkList() {

  // creates a new linked list
  PieCake_struct* list = new PieCake_struct;
  list->id = 1;
  list->prev = nullptr;
  list->next = nullptr;

  head = list;
  tail = list;
  current = list;

  count += 1;
  cout << "created new list" << endl;
}

LinkList::~LinkList() {
  cout << "destroyed" << endl;
}

bool LinkList::Empty() {
  // if true, linked list is empty
  if(count != 0) {
    return false;
  }
  else {
    return true;
  }
}

int LinkList::Size() {
  return count;
}

bool LinkList::Find(const int idnumber) {
  // start at head of linked list
  bool isTrue = false;
  current = head;
  for(int i = 0; i < count; i++) {
    int temp = current->id;
    if(temp == idnumber) {
      isTrue = true;
    }
    current = current->next;
  }
  return isTrue;
}

void LinkList::Insert( PieCake_struct * p) {
  string temp_last = p->lname;
  current = head;

  for(int i = 0; i < count; i++) {
    int temp = temp_last.compare(current->lname);
    switch(temp) {
      case 1: {
        // earlier alpha, create new node
        PieCake_struct* node = new PieCake_struct;
        node->id = current->id + 1;
        node->prev = current;
        node->next = current->next;

        current->next = node;
        goto END;
      }
      case -1: {
        // longer string OR later alpha
        // move to next node
        break;
      }
      case 0: {
        // same strings, create new node
        PieCake_struct* node = new PieCake_struct;
        node->id = current->id + 1;
        node->prev = current;
        node->next = current->next;

        current->next = node;
        goto END;
      }
    }

    current = current->next;
  }
  END:
  cout << " ";
}
