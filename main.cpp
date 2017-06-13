#include <iostream>
#include <fstream>                                          //for file stream
class Person
{
protected:
    char name[80];                                          // person name
    short age;                                              // person age
public:
    void getData()                                          // get person data
    {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter age: ";
        std::cin >> age;
    }
    void showData()
    {
        std::cout << " Name: " << name;
        std::cout << " Age: " << age;
    }
};

int main() {

    char ch;
    Person person;                                          // create person
    std::fstream file;                                      // create input output file
    file.open("Group.dat", std::ios::app | std::ios::out | std::ios::in | std::ios::binary);

    do {
        std::cout << "Enter person data: ";
        person.getData();

        file.write(reinterpret_cast<char*>(&person), sizeof(person));
        std::cout << "Enter another person (y/n)? ";
        std::cin >> ch;
    }
    while (ch == 'y');
    file.seekg(0);                                          // reset to start of file
    file.read(reinterpret_cast<char*>(&person), sizeof(person));
    while ( !file.eof())                                    // quit on EOF
    {
        std::cout << "Person: ";                            // display person
        person.showData();
        file.read(reinterpret_cast<char*>(&person), sizeof(person));
    }
    std::cout << std::endl;
    std::cin.get();
    return 0;
}