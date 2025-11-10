#include <iostream>
#include <string>


typedef enum {
    ENGLISH,
    SWEDISH
} LANG;  


std::string greet(std::string name, LANG lang) {
    if(lang == SWEDISH)
        return "Hej, " + name + "!";
    else
        return "Hello, " + name + "!";
}




int main(){
    std::string greeting = greet("Stefan", SWEDISH);
    // char texten[100];
    // greet("Stefan", SWEDISH, texten);
    // std::cout << texten << std::endl;
    return 0;
}