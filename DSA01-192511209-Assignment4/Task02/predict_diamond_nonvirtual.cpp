// Task 2 - same program with "virtual" REMOVED from both bases
#include <iostream>
struct Person { Person() { std::cout << "Person "; } };
struct Student : Person { Student() { std::cout << "Student "; } };
struct Staff : Person { Staff() { std::cout << "Staff "; } };
struct TeachingAssistant : Student, Staff {
    TeachingAssistant() { std::cout << "TA "; }
};
int main()
{
    TeachingAssistant ta;
    std::cout << '\n';
}
