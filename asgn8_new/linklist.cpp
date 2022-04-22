#include <iostream>
#include "linklist.h"

using namespace std;

  LinkList::LinkList() {
    count = 0;

    PieCake_struct* node = new PieCake_struct;
    node->id = 0;
    node->prev = nullptr;
    node->next = nullptr;

    head = node;
    tail = node;
    current = node;
  }

  LinkList::~LinkList() {
    cout << "" << endl;
  }

  bool LinkList::Empty() {
    if(count == 0) {
      return true;
    }
    else {
      return false;
    }
  }

  int LinkList::Size() {
    return count;
  }

  bool LinkList::Find(const int idnumber) {
    // set current to beginning of list
    current = head;
    bool nextIsNull = false;

    // search until current->next = nullptr
    while(nextIsNull == false) {
      // if found, return true and set that node to current
      if(current->id == idnumber) {
        return true;
      }
      // else return false
      if(current->next == nullptr) {
        nextIsNull = true;
      }
      current = current->next;
    }
    current = head->next;
    cout << "Find failed, setting first node as current." << endl;
    return false;
  }

  void LinkList::Insert(PieCake_struct * p) {
    // check if list is empty
    if(count == 0) {
      // sets current to head of list, next node will be placed after head
      current = head;
      count++;
      goto ASSIGN;
    }

    count++;
    current = head->next;

    // check if p->lname == current->lname
    // using string::compare() and set correct node as current
    int case_int;
    for(int i = 0; i < count; i++) {
      case_int = p->lname.compare(current->lname);
      if(case_int == 0 || case_int == 1) {
        // new node needs to be placed after current node
        goto ASSIGN;
      }
      if(case_int == -1) {
        // correct node not located, move to next node
        current = current->next;
      }
    }

    ASSIGN:
    // create new PieCake_struct* node
    // set all node->values to p->values
    PieCake_struct* node = new PieCake_struct;

    node->next = current->next;
    node->prev = current;
    current->next = node;

    node->id = p->id;
    node->lname = p->lname;
    node->fname = p->fname;
    node->mi = p->mi;
    node->sex = p->sex;
    node->pORc = p->pORc;
    current = node;
  }

/*
  bool LinkList::Delete() {
    if(current->next != nullptr) {
      current->prev->next = current->next; }
    // set current->next->prev to current->prev
    if(current->prev != nullptr) {
      current->next->prev = current->prev; }
    // set current->prev->next to current->next
    // removes current node by freeing current alloc

    free(current);
    // free literally can't fail unless handed wrong pointer so should always be true
    count--;
    return true;
  }
*/
  void LinkList::Print() {
    // prints entire list
    cout << "ID     First Name    MI   Last Name   Sex    Answer" << endl;
    current = head->next;
    for(int i = 0; i < count; i++) {
      cout << current->id << " " << current->fname << " " << current->mi << " "<< current->lname << " " << current->sex << " " << current->pORc << endl;
      current = current->next;
    }
  }

  void LinkList::List() {
    // prints current node
    cout << "ID: " << current->id << endl;
    cout << "Name: " << current->lname << ", " << current->fname << " " << current->mi << endl;
    cout << "Sex: " << current->sex << endl;
    cout << "Choice: " << current->pORc << endl;
  }

  int LinkList::CountPie() {
    // iterate until current->next == nullptr
    // count number of current->pORc == 'P'
    bool nextIsNull = false;
    int p_count = 0;
    current = head->next;
    while(nextIsNull == false) {
      if(current->pORc == 'P') {
        p_count++;
      }
      if(current->next == nullptr) {
        nextIsNull = true;
      }
      current = current->next;
    }
    return p_count;
  }

  int LinkList::CountCake() {
    // iterate until current->next == nullptr
    // count number of current->pORc == 'C'
    bool nextIsNull = false;
    int c_count = 0;
    current = head->next;
    while(nextIsNull == false) {
      if(current->pORc == 'C') {
        c_count++;
      }
      if(current->next == nullptr) {
        nextIsNull = true;
      }
      current = current->next;
    }
    return c_count;
  }
