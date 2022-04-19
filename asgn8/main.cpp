#include <iostream>
#include "linklist.h"

using namespace std;

int main() {


    PieCake_struct * one;
    // assign vals
    one->id = 1;
    one->lname = "davids";
    one->fname = "larry";
    one->mi = 'c';
    one->sex = 'm';
    one->pORc = 'p';

    PieCake_struct * two;
    two->id = 2;
    two->lname = "andrews";
    two->fname = "andy";
    two->mi = 'a';
    two->sex = 'm';
    two->pORc = 'p';

    LinkList();

    LinkList::Insert(one);
    LinkList::Insert(two);
}
