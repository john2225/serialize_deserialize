#include "serialize_deserialize.h"


int Person::primary_id = 0;

Person::Person()
    : m_name{"No name"},
    m_age{0},
    m_social_id{"_______"}
{
}

Person::Person(std::string name, int age, std::string social_id)
    : m_name{name},
    m_age{age},
    m_social_id{social_id}
{
}

void Person::setName(const std::string& name)
{
    m_name = name;
}
void Person::setAge(const int age)
{
    m_age = age;
}
void Person::setSocialId(const std::string& social_id)
{
    m_social_id = social_id;
}

std::vector<std::string> splitText(const std::string& str)
{
    char delim = '|';
    std::vector<std::string> tokens;
    std::stringstream check(str);
    std::string intermediate;
    while(getline(check, intermediate, delim))
    {
        tokens.push_back(intermediate);
    }
    return tokens;
}

    

