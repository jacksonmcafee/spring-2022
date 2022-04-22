#include <iostream>
#include <fstream>
#include <string>
#include "linklist.h"

using namespace std;

string getFile();
PieCake_struct* assignNode(string fName, int count);
int lineCount(string fName);

int main() {

int l_count = 0;

string fName = getFile();
int lines = lineCount(fName);
LinkList myList;

// populates Linked List myList
for(int i = 0; i < lines; i++) {
  PieCake_struct* node = assignNode(fName, l_count);
  myList.Insert(node);
  l_count++;
  }

}

string getFile() {
  string fileName;
  CHECK:
  cout << "Provide a valid .dat file you want opened: ";
  cin >> fileName;
  ifstream fileStream;
  fileStream.open(fileName);
  if(fileStream) {
    fileStream.close();
    return fileName;
  }
  else {
    goto CHECK;
  }
}

int lineCount(string fName) {
    int lineNum = 0;
    string line;
    ifstream myfile(fName);

    while (getline(myfile, line))
        ++lineNum;
    return lineNum;
}

PieCake_struct* assignNode(string fName, int l_count) {
  PieCake_struct* node = new PieCake_struct;

  fstream inFile;
  inFile.open(fName);

  for(int i = 0; i < l_count; i++) {
    string temp;
    getline(inFile, temp);
  }

  inFile >> node->id >> node->fname >> node->lname >> node->mi >> node->sex >> node->pORc;
  inFile.close();

  return node;
}
