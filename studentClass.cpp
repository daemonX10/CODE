#include <bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int rollNumber;

    void setDetails(string n,int roll){
        name = n;
        rollNumber = roll;
    }

    void displayDetails(){
        cout<<"Name : " <<name<<"\n"<<"Roll Number : "<<rollNumber<<endl;
    }

};

int main() {
    Student student1;
    student1.setDetails("damodar",50);
    student1.displayDetails();
}