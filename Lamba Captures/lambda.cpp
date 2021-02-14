#include "lambda.h"
#include <iostream>
using namespace std;
Resource::Resource(std::string n)  : name(n)
{
    cout << "constructing " << name << endl;
}
Resource::Resource(const Resource & r) : name(r.name)
{
    cout << "copy constructing " << name << endl;
}
Resource & Resource::operator=(const Resource & r)
{
    name = r.GetName();
    cout << "copy assigning " << name << "\n";
    return *this;
}
Resource::~Resource(void)
{
    cout << "destructing " << name << endl;
}
