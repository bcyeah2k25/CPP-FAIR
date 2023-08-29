#include <iostream>
#include <string>
using namespace std;

class pntr_obj {
    int roll_no;
    string name;

public:
    void set_data(int roll, string& student_name) {
        this->roll_no = roll;
        this->name = student_name;
    }

    void print() {
        cout << "Object with roll number " << this->roll_no << " and name " << this->name
             << " invoked the print() function." << endl;
    }
};

int main() {
    pntr_obj obj1, obj2, obj3;
     string name;
     int roll;
     
     cout << "Enter the 1st roll number:" ;
     cin >> roll;
     cout << "Enter the name:";
     cin >> name;
    obj1.set_data(roll,name);
    cout << endl;
     cout << "Enter the 2nd roll number:" ;
     cin >> roll;
     cout << "Enter the name:";
     cin >> name;
    obj2.set_data(roll,name);
    cout<<endl;
     cout << "Enter the 3rd roll number:" ;
     cin >> roll;
     cout << "Enter the name:";
     cin >> name;
    obj3.set_data(roll,name);
     cout << endl;
    obj1.print();
    cout << endl;
    obj2.print();
    cout  << endl;
    obj3.print();

    return 0;
}