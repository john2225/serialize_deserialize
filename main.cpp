#include "serialize_deserialize.h"


int main()
{

    
    
    const std::string path = "Person.txt";
    Person firstPerson("John", 31, "ab02222");
    Person secondPerson("Rafo", 27, "aa11111");
    Person thirdPerson("James", 27, "cc696969");
    Person fourthPerson("Malena", 22, "dd76666");
  
    
    std::vector<Person> allPersons;
    allPersons.push_back(firstPerson);
    allPersons.push_back(secondPerson);
    allPersons.push_back(thirdPerson);
    allPersons.push_back(fourthPerson);

//    std::ofstream outFile(path);
//    std::pair<int, Person>* myType = new  std::pair<int, Person>[allPersons.size()];
//    for(int i = 0; i < allPersons.size(); ++i)
//    {
//        myType[i].first = allPersons[i].getPrimaryId();
//        myType[i].second = allPersons[i];
//        outFile << myType[i].first;
//        outFile << myType[i].second;
//    }

    std::ifstream inFile(path);
    
    std::string inputTmp;
    std::vector<std::string> input;
    
    while(!inFile.eof())
    {
        inFile >> inputTmp;
        input.push_back(inputTmp);
    }
    
    Person* tmp = new Person[allPersons.size()];
    for(int i = 0; i < input.size() - 1; ++i)
    {
        //std::cout << input[i];
        if(input[i] == "Name:")
        {
            tmp[i].setName(input[i + 1]);
        }
        if(input[i] == "Age:")
        {
            tmp[i].setAge(std::stoi(input[i + 1]));
        }
        if(input[i] == "ID")
        {
            tmp[i].setSocialId(input[i + 1]);
        }
  }
    
    
    return 0;
}
