#include "MyString.h"

int main()
{
    MyString a("Hello");
    MyString b(" World");

    cout << "a: ";
    a.Output();

    cout << "Length: " << a.MyStrLen() << endl;
    cout << "Index 'l': " << a.MyChr('l') << endl;
    cout << "Find ell: " << a.MyStrStr("ell") << endl;

    a.MyStrCat(b);
    cout << "Concat: ";
    a.Output();

    a.MyDelChr('l');
    cout << "Delete l: ";
    a.Output();


    MyString c("Hello");

    MyString r1 = c + '!';
    cout << "obj + char: ";
    r1.Output();

    MyString r2 = '@' + c;
    cout << "char + obj: ";
    r2.Output();

    MyString r3 = c + 10;
    cout << "obj + 10: ";
    r3.Output();

    MyString r4 = 10 + c;
    cout << "10 + obj: ";
    r4.Output();


    c++;
    cout << "obj++: ";
    c.Output();

    ++c;
    cout << "++obj: ";
    c.Output();


    cout << "Objects: " << MyString::GetCount() << endl;

    return 0;
}