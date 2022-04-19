#ifndef LINKLIST_H
#define LINKLIST_H

#include <string>

using namespace std;

struct PieCake_struct
{
    int     id;
    string  lname;
    string  fname;
    char    mi;
    char    sex;
    char    pORc;         // P = pie, C=Cake
    PieCake_struct * prev;
    PieCake_struct * next;
};

class LinkList {

public:
     LinkList();                       // Default constructor.
     ~LinkList();                      // Destructor
     bool Empty();                     // True = link list is empty, False otherwise
     int  Size();                      // Returns number of records minus head and tail
     bool Find(const int idnumber);    // Looks for a record with the id,

                                       // returns true if  found, false otherwise.

                                       // Sets the current to the
                                       //   record found.

                                       //   Sets current to null if not found.
     void Insert( PieCake_struct * p); // Inserts a record into the list.
     bool Delete();                    // Deletes current record.

                                       // Must use Find() to locate the record.
     void Print();                     // Prints the report..see example.
     void List();                      // Lists current record to standard output.

                                       //    See Example.
     int CountPie();                   // Returns number of records that thought

                                       //    Cheese Cake is Pie.
     int CountCake();                  // Returns the number of records that thought

                                       //  Cheese Cake is Cake.
private:
    PieCake_struct * head;         // Points to the dummy head of the list
    PieCake_struct * tail;         // Points to the dummy tail of the list
    PieCake_struct * current;      // Current record, set when find is successful.
    int count;                     // Number of records, modified when records are
                                   //   added and deleted.
};


#endif
