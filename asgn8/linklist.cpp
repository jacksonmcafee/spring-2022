#include "linklist.h"
#include <iostream>
#include <string>

using namespace std;

LinkList::LinkList() {

  // creates a new linked list
  PieCake_struct* node = new PieCake_struct;
  node->prev = nullptr;
  node->next = nullptr;

  head = node;
  tail = node;
  current = node;

  cout << "created base node for dll" << endl;
}

// unfinished
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

void LinkList::Insert(PieCake_struct * p) {

  if(count == 0) {
    PieCake_struct* node = new PieCake_struct;
    node->id = current->id + 1;

    node->prev = head;
    node->next = head->next;
    head->next = node;

    node->lname = p->lname;
    node->fname = p->fname;
    node->mi = p->mi;
    node->sex = p->sex;
    node->pORc = p->pORc;

    cout << "placing after head node" << endl;

    current = node;
    count += 1;
  }

  string temp_last = p->lname;
  current = head;

  for(int i = 0; i < count; i++) {
    int temp = temp_last.compare(current->lname);
    switch(temp) {
      case 1: {
        // earlier alpha, create new node
        PieCake_struct* node = new PieCake_struct;
        node->id = current->id + 1;

        // set node prev/next
        node->prev = current;
        // set prev node next to node
        node->next = current->next;
        // set next next prev to node
        current->next = node;

        node->lname = p->lname;
        node->fname = p->fname;
        node->mi = p->mi;
        node->sex = p->sex;
        node->pORc = p->pORc;

        current = node;
        count += 1;
        cout << "early alpha, listing after" << current->id << endl;

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

        // set node prev/next
        node->prev = current;
        // set prev node next to node
        node->next = current->next;
        // set next next prev to node
        current->next = node;

        node->lname = p->lname;
        node->fname = p->fname;
        node->mi = p->mi;
        node->sex = p->sex;
        node->pORc = p->pORc;

        current = node;
        count += 1;

        cout << "equal alpha, listing after" << current->id << endl;
        goto END;
      }
    }
    cout << "not in " << current->id << endl;
    current = current->next;
  }
  END:
  cout << "";
}

void LinkList::Print() {
  cout << "ID    First    M    Last    Sex    Choice" << endl;
  bool nextNodeExists = true;
  current = head->next;
  while(nextNodeExists) {
    cout << current->fname << " " << current->mi << " " << current->lname << " " << current->sex << " " << current->pORc << endl;
    if(current->next != nullptr) {
      current = current->next; }
    else {
      nextNodeExists = false;
      cout << "node didnt exist" << endl;
    }
  }
}

void LinkList::List() {
  cout << "Current Record ID: " << current->id << endl;
  cout << "Name (last, first mi): " << current->lname << ", ";
  cout << current->fname << " " << current->mi << endl;
  cout << "Sex: " << current->sex << endl;
  cout << "Choice: " << current->pORc << endl;
}
