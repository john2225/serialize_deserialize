#ifndef SERIALIZE_H
#define SERIALIZE_H
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <sstream>



class Person
{
public:
    Person();
    Person(std::string name, int age, std::string social_id);
    ~Person(){}

public:
    friend std::ostream& operator<< (std::ostream& out, const Person& rhs)
    {
        out << ". "  << "Name: " << rhs.m_name << " Age: " <<  rhs.m_age << " Social ID "<< rhs.m_social_id;
        out << '\n';
        return out;
    }
    
    void setName(const std::string& name);
    void setAge(const int);
    void setSocialId(const std::string& social_id);
    static std::size_t getPrimaryId()
    {
        return ++primary_id;
    }
    
private:
    static int primary_id;
    std::string m_name;
    int m_age;
    std::string m_social_id;
};

std::vector<std::string> splitText(const std::string& str);


#endif /* SERIALIZE_H */
