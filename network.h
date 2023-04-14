
#ifndef MISC_H
#define MISC_H

#include "person.h"
#include <iostream>
#include <string>
using namespace std;

void printMe(string type);

class Network {
  Person *head;
  Person *tail;
  int count;

public:
  Network();
  Network(string fileName);
  ~Network();
  Person *search(Person *searchEntry);
  Person *search(string fname, string lname);
  void print_lnames(string last);
  void loadDB(string filename);
  void saveDB(string filename);
  void printDB();
  void push_front(Person *newEntry);
  void push_back(Person *newEntry);
  bool remove(string fname, string lname);
  void showMenu();
};

#endif