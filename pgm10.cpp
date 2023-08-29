#include<iostream>
using namespace std;

class Class_2; 

class Class_1{
    int value1;
public:

    void inputdata(int data){
        value1 = data;
    }

    void displaydata(){
        cout << "Value : "<<value1<<endl;
    }

    friend void exchange(Class_1& c1, Class_2& c2);
};

class Class_2{
    int value2;
public:

    void inputdata(int data){
        value2 = data;
    }
    void displaydata(){
        cout << "Value : "<<value2<<endl;
    }

    friend void exchange(Class_1& c1, Class_2& c2); 
};

void exchange(Class_1& c1, Class_2& c2){ 
    int temp = c1.value1;

    c1.value1 = c2.value2;
    c2.value2 = temp;
}

int main(){
    
    int value;

    cout << "Enter the value for Class 1: ";
    cin >> value;
    Class_1 c1;
    c1.inputdata(value);

    cout << "Enter the value for Class 2: ";
    cin >> value;
    Class_2 c2;
    c2.inputdata(value);


    cout << endl << "Class 1:" << endl;
    c1.displaydata();

    cout << endl << "Class 2:" << endl;
    c2.displaydata();

    exchange(c1,c2);

    cout << endl << "Class 1 after swap:" << endl;
    c1.displaydata();

    cout << endl << "Class 2 after swap:" << endl;
    c2.displaydata();

    return 0;
}