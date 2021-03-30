#include <iostream>
class Employee {
    std::string name;
    std::string location;
    int employeeID;
public:
    Employee() {
        std::cout << "in the default constructor" << std::endl;
    }

public:
    Employee(const std::string &name, const std::string &location, int employeeId) : name(name), location(location),
                                                                                     employeeID(employeeId) {}
    Employee(const Employee& other){
        name = other.name;
        location = other.location;
        employeeID = other.employeeID;
        std::cout << "in the copy constructor" << std::endl;
    }

    void operator = (const Employee& other){
        name = other.name;
        location = other.location;
        employeeID = other.employeeID;
        std::cout << "in the assignment operator" << std::endl;
    }
    bool operator == (const Employee& other) const{
        return employeeID == other.employeeID;
    }

    friend std::ostream& operator << (std::ostream& out, const Employee& employee);
};

std::ostream& operator << (std::ostream& out, const Employee& employee){
    out << employee.name << " " << "ID: " << employee.employeeID << std::endl;
    return out;
}



int main() {
    Employee e1("Fred","1313 Mockingbird Lane", 1435);
    Employee e2 = e1;
    Employee e3;
    e3 = e1;
    std::cout << e3 << std::endl;
    return 0;
}
