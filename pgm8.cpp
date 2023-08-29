#include <iostream>
using namespace std;

class Vector {
    int size;
    int array[20];

public:
    Vector() {}
    friend Vector operator*(const Vector& v1, const Vector& v2);
    friend ostream& operator<<(ostream& os, const Vector& v);
    friend istream& operator>>(istream& is, Vector& v);
};

Vector operator*(const Vector& v1, const Vector& v2) {
    Vector v3;
    v3.size = v1.size;  // Assuming sizes are equal for v1 and v2
    for (int i = 0; i < v3.size; i++) {
        v3.array[i] = v1.array[i] * v2.array[i];
    }
    return v3;
}

ostream& operator<<(ostream& os, const Vector& v) {
    os << "(";
    for (int i = 0; i < v.size; i++) {
        os << v.array[i];
        if (i < v.size - 1)
            os << ",";
    }
    os << ")";
    return os;
}

istream& operator>>(istream& is, Vector& v) {
    cout << "Enter array size:";
    cin >> v.size;
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < v.size; i++)
        is >> v.array[i];
    return is;
}

int main() {
    Vector v1, v2, v3;
    cout << "Enter details of first array:" << endl;
    cin >> v1;
    cout << endl;
    cout << "Enter details of 2nd array:" << endl;
    cin >> v2;
    cout << endl;

    cout << "\nVector 1 : " << v1;
    cout << "\nVector 2 : " << v2;

    v3 = v1 * v2;

    cout << "\n\nResult of v1 * v2: " << v3 << endl;

    return 0;
   }