#pragma once
#include <iostream>
using namespace std;

class MyString
{
    char* str;
    int length;

    static int count;

public:
    MyString();
    MyString(int size);
    MyString(const char* text);
    MyString(const MyString& obj);
    ~MyString();

    void Input();
    void Output() const;

    bool MyStrStr(const char* text);
    int MyChr(char c);
    int MyStrLen();
    void MyStrCat(MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(MyString& b);

    static int GetCount();

    MyString operator+(char c) const;
    MyString operator+(int n) const;

    MyString operator++(int);
    MyString& operator++();

    friend MyString operator+(char c, const MyString& obj);
    friend MyString operator+(int n, const MyString& obj);
};