// Task 2 - Alternative: composition (TA HAS-A Student and HAS-A Staff) vs virtual inheritance
#include <iostream>
#include <string>
using namespace std;

struct Person { string name = "Arun"; int id = 3; string phone = "9000000003"; };

// (A) virtual inheritance: ONE Person sub-object
struct VStudent : virtual Person { double cgpa = 9.1; };
struct VStaff   : virtual Person { double salary = 25000; };
struct TA_Virtual : VStudent, VStaff {};

// (B) composition: each member carries its own Person -> TWO Person copies
struct PStudent : Person { double cgpa = 9.1; };
struct PStaff   : Person { double salary = 25000; };
struct TA_Composed { PStudent st; PStaff sf; };

int main() {
    cout << "sizeof(Person)      = " << sizeof(Person) << "\n";
    cout << "sizeof(TA_Virtual)  = " << sizeof(TA_Virtual) << "  (one Person + virtual-base pointers)\n";
    cout << "sizeof(TA_Composed) = " << sizeof(TA_Composed) << "  (two Person copies)\n";

    TA_Virtual a;  TA_Composed b;
    cout << a.name << "\n";                           // unambiguous; tiny extra indirection to find the virtual base
    cout << b.st.name << " / " << b.sf.name << "\n";  // must choose which copy
    b.st.name = "Changed";
    cout << "after editing st.name -> sf.name is still " << b.sf.name << " (duplicated data can go out of sync)\n";
}
