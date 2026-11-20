// Task 2.2 - Without virtual, ta.name is AMBIGUOUS.
// Compile as-is to see the error; compile with -DFIXED to see the virtual-base version work.
#include <iostream>
#include <string>
struct Person { std::string name = "Asha"; };
#ifdef FIXED
struct Student : virtual Person { double cgpa = 8.5; };
struct Staff   : virtual Person { double salary = 30000; };
#else
struct Student : Person { double cgpa = 8.5; };
struct Staff   : Person { double salary = 30000; };
#endif
struct TeachingAssistant : Student, Staff {};
int main() {
    TeachingAssistant ta;
    std::cout << ta.name << "\n";      // non-virtual: error "request for member 'name' is ambiguous"
}
