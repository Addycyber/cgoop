#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class Student {
    int roll;
    string name, Class, Div, dob, bg, contact, phone, license;

public:
    static int stdno;
    
    Student() : roll(0), name("Sachin"), Class("I"), Div("A"), dob("11/11/1111"),
                bg("A"), contact("city"), phone("9000000000"), license("A0101010") {
        ++stdno;
    }

    // Copy constructor
    Student(const Student &ob) : roll(ob.roll), name(ob.name), Class(ob.Class), Div(ob.Div),
                                  dob(ob.dob), bg(ob.bg), contact(ob.contact), phone(ob.phone),
                                  license(ob.license) {
        ++stdno;
    }

    void getData() {
        cout << "\nEnter: name, roll, Class, Div, Dob, bg, contact, phone, license\n";
        cin >> name >> roll >> Class >> Div >> dob >> bg >> contact >> phone >> license;
    }

    friend void display(const Student &d);

    ~Student() {
        cout << "\n\n" << name << " (Object) is destroyed!";
    }
};

void display(const Student &d) {
    cout << "\n" << setw(12) << d.name << setw(5) << d.roll << setw(4) << d.Class << setw(3) << d.Div
         << setw(12) << d.dob << setw(4) << d.bg << setw(12) << d.contact << " " << setw(12) << d.phone
         << " " << setw(12) << " " << d.license;
}

int Student::stdno;

int main() {
    int n, i;
    Student d1, *ptr[5];

    cout << "\nDefault values:";
    display(d1);

    d1.getData();
    display(d1);

    Student d2 = d1;
    cout << "\n\nUse of copy constructor :\n";
    display(d2);

    cout << "\nHow many objects do you want to create?:";
    cin >> n;

    for (i = 0; i < n; ++i) {
        ptr[i] = new Student();
        ptr[i]->getData();
    }

    cout << "\n" << setw(12) << "name" << setw(5) << "roll" << setw(4) << "Class" << setw(4) << "Div"
         << setw(12) << "dob" << setw(4) << "bg" << setw(12) << "contact" << setw(12) << "phone"
         << setw(12) << "license";

    for (i = 0; i < n; ++i)
        display(*ptr[i]);

    cout << "\nNo. of objects created: " << Student::stdno;

    for (i = 0; i < n; ++i)
        delete ptr[i];

    cout << "\nObjects deleted!";
    return 0;
}
