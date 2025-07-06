#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <class T>
list<const iostream*> fun(vector<ostream*>& v) {
  list<const iostream*> list;
  vector<ostream*>::iterator p;
  for (p = v.begin(); p != v.end(); ++p) {
    fstream* f = dynamic_cast<fstream*>(*p);
    if (p != nullptr && f && !f->good()) {
      p = nullptr;
    } else {
      stringstream* s = dynamic_cast<stringstream*>(*p);
      if (p && s && s->good()) {
        list.push_back(dynamic_cast<iostream*>(*p));
      }
    }
  }
  if (list.empty()) {
    throw T();
  }
  return list;
};
