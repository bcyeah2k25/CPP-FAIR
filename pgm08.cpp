#include <iostream>
using namespace std;

class Vector
{
    int size;
    int array[10];

public:
    Vector() {}
    friend Vector operator*(const Vector &v1, const Vector &v2);
    friend ostream &operator<<(ostream &os, const Vector &v);
    friend istream &operator>>(istream &is, Vector &v);
    friend bool checksize(Vector &v1, Vector &v2);
};

Vector operator*(const Vector &v1, const Vector &v2)
{
    Vector v3;
    v3.size = v1.size;
    for (int i = 0; i < v3.size; i++)
    {
        v3.array[i] = v1.array[i] * v2.array[i];
    }
    return v3;
}

ostream &operator<<(ostream &os, const Vector &v)
{
    os << "(";
    for (int i = 0; i < v.size; i++)
    {
        os << v.array[i];
        if (i < v.size - 1)
            os << ",";
    }
    os << ")";
    return os;
}

istream &operator>>(istream &is, Vector &v)
{
    while (true)
    {
        cout << "Enter vector size: ";
        cin >> v.size;
        if (v.size < 1 || v.size > 10)
        {
            cout << endl
                 << "Size should be from 1 to 10!...Re-Try..!" << endl;
        }
        else
        {
            break;
        }
    }
    cout << "Enter vector elements: " << endl;
    for (int i = 0; i < v.size; i++)
        is >> v.array[i];
    return is;
}
bool checksize(Vector &v1, Vector &v2)
{
    if (v1.size == v2.size)
        return true;
    else
        return false;
}

int main()
{
    Vector v1, v2, v3;
    cout << "Enter details of 1st vector:-" << endl;
    cin >> v1;
    cout << endl;
    cout << "Enter details of 2nd vector:-" << endl;
    cin >> v2;
    cout << endl;

    cout << "\nVector 1 : " << v1;
    cout << "\nVector 2 : " << v2;

    if (!checksize(v1, v2))
        cout << endl
             << endl
             << "Vector  multiplication not possible. Vectors must be of same size." << endl;
    else
    {
        v3 = v1 * v2;
        cout << "\n\nResult of v1 * v2: " << v3 << endl;
    }
    return 0;
}
