#include <iostream>
#include "linklist.h"

using namespace std;

int main() {

    LinkList newList;

    PieCake_struct * one = new PieCake_struct;
    one->fname = "andrewson";
    one->lname = "andrew";
    one->mi = 'a';
    one->sex = 'm';
    one->pORc = 'P';

    newList.Insert(one);
    
    PieCake_struct * two = new PieCake_struct;
    one->fname = "dave";
    one->lname = "davidson";
    one->mi = 'd';
    one->sex = 'm';
    one->pORc = 'P';

    PieCake_struct * three = new PieCake_struct;
    one->fname = "jackson";
    one->lname = "jacksonson";
    one->mi = 'j';
    one->sex = 'm';
    one->pORc = 'P';

    newList.Insert(two);
    newList.Insert(three);
}
