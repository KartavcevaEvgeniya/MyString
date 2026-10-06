#include "MyString.h"
#include <cstring>

int MyString::count = 0;

// Конструктор за замовчуванням
MyString::MyString()
{
    length = 80;
    str = new char[length + 1];
    str[0] = '\0';
    count++;
}

// Конструктор з розміром
MyString::MyString(int size)
{
    length = size;
    str = new char[length + 1];
    str[0] = '\0';
    count++;
}

// Конструктор з рядком
MyString::MyString(const char* text)
{
    length = strlen(text);
    str = new char[length + 1];
    strcpy_s(str, length + 1, text);
    count++;
}

// Конструктор копіювання
MyString::MyString(const MyString& obj)
{
    length = obj.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, obj.str);
    count++;
}

// Деструктор
MyString::~MyString()
{
    delete[] str;
    count--;
}

// Введення
void MyString::Input()
{
    char temp[1000];
    cin.getline(temp, 1000);

    delete[] str;

    length = strlen(temp);
    str = new char[length + 1];

    strcpy_s(str, length + 1, temp);
}

// Виведення
void MyString::Output() const
{
    cout << str << endl;
}

// Пошук підрядка
bool MyString::MyStrStr(const char* text)
{
    return strstr(str, text) != nullptr;
}

// Пошук символу
int MyString::MyChr(char c)
{
    for (int i = 0; i < length; i++)
    {
        if (str[i] == c)
        {    
            return i;
        }
    }
    return -1;
}

// Довжина
int MyString::MyStrLen()
{
    return length;
}

// Об'єднання
void MyString::MyStrCat(MyString& b)
{
    int newLength = length + b.length;

    char* temp = new char[newLength + 1];

    strcpy_s(temp, newLength + 1, str);
    strcat_s(temp, newLength + 1, b.str);

    delete[] str;

    str = temp;
    length = newLength;
}

// Видалення символу
void MyString::MyDelChr(char c)
{
    int j = 0;

    for (int i = 0; i < length; i++)
    {
        if (str[i] != c)
        {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0';
    length = j;
}

// Порівняння
int MyString::MyStrCmp(MyString& b)
{
    int result = strcmp(str, b.str);

    if (result < 0)
    {    
        return -1;
    }

    if (result > 0)
    {    
        return 1;
    }
    return 0;
}

// Кількість об'єктів
int MyString::GetCount()
{
    return count;
}

// obj + 'A'
MyString MyString::operator+(char c) const
{
    MyString temp(length + 1);

    strcpy_s(temp.str, length + 2, str);

    temp.str[length] = c;
    temp.str[length + 1] = '\0';

    return temp;
}

// 'A' + obj
MyString operator+(char c, const MyString& obj)
{
    MyString temp(obj.length + 1);

    temp.str[0] = c;

    strcpy_s(temp.str + 1, obj.length + 1, obj.str);

    return temp;
}

// obj + 10
MyString MyString::operator+(int n) const
{
    MyString temp(length + n);

    strcpy_s(temp.str, length + n + 1, str);

    for (int i = length; i < length + n; i++)
    {   
        temp.str[i] = ' '; 
    }

    temp.str[length + n] = '\0';

    return temp;
}

// 10 + obj
MyString operator+(int n, const MyString& obj)
{
    return obj + n;
}

// obj++
MyString MyString::operator++(int)
{
    MyString old(*this);

    *this = *this + '*';

    return old;
}

// ++obj
MyString& MyString::operator++()
{
    MyString temp = '*' + *this;

    delete[] str;

    length = temp.length;
    str = new char[length + 1];

    strcpy_s(str, length + 1, temp.str);

    return *this;
}