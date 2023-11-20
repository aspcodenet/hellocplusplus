#include <iostream>
#include <string>
#include <vector>
//#include <stdio.h>

//Vad är jobbigt i C
// input/output - hej streams och stream insertion operator
//    printf %s %d etc etc      
// strings - japp hej std::string
// pekare - hej referenser
// allokeringar - hej vector
// NYTT:
// loopar for each
// auto

//Övningar: 
// allmänt input/output   ExercisesVecka1.docx
// + funktioner ExercisesWeek3 (1).docx

// STREAM är en 


// void test(int *i){
//     *i = *i + 1;
//     std::cout << *i << std::endl;
// }
// void test(int *i)


void test(int &i){
    i = i + 1;
    std::cout << i << std::endl;
}

class Player{
public:
    std::string name;
    int age;
};

// a) 12 13 12
// b) 12 13 13 
int main(){
    //Player *p = new Player();
    std::vector<Player> playersList;

    while(1){
        Player  foppa;
        std::cout << "ange age";
        std::cin >> foppa.age;
        std::cout << "ange namn";
        getline(std::cin, foppa.name);
        playersList.push_back(foppa);

        //playersList.
        //foppa.name.

        for(Player p : playersList){
            std::cout << p.name << std::endl;
        }
    }

    int i;
    i=12;

    std::cout << i << std::endl;
    test(i);
    //test(&i);
    std::cout << i << std::endl;


    int a; // no initializer
    a = 5;
    int b = 5; // initializer after equals sign
    int c( 5 ); // initializer in parenthesis
    int d { 5 }; // initializer in braces    


    // std::string str1;
    // str1 = "Hello";
    // std::string str2 = "Hello";  
    // std::string str3("Hello");



    // std::string s1 = std::to_string(3.1415);
    // int x1 = std::stoi("-17");
    // double d = std::stod("4.3");



    std::string namn;
    std::cout << "Whats your name:";
    getline(std::cin,namn);   // läser en hel rad
    if(namn.length() < 10 ){
        std::cout << "Vilket kort namn du har" << std::endl;
    }
    if(namn.at(0) == 'S'){
        std::cout << "Du börjar på S" << std::endl;
    }
    if(namn[0] == 'S'){
        std::cout << "Du börjar på S" << std::endl;
    }
    int antalS = 0;
    for(int i = 0; i < namn.length();i++){
        if(namn[i] == 'S'){
            antalS++;
        }
    }
    antalS = 0;
    for(char ch : namn){
        if(ch == 'S'){
            antalS++;
        }

    }


    //std::cin >> namn; // denna bryter vid mellanslag Leif Stefan -> Leif

    if(namn == "Stefan"){
        std::cout << "Fint namn";
    }
    namn = namn + " Holmberg";

    int age ;
    std::cout << "How old are you:";
    std::cin >> age;

    std::cout << "Hej " << namn << " du är " << age << " år" << std::endl;
    // char namn[256];
    // strcpy(namn, "Stefan");
    // printf("Hej %s\n", namn);
    return 0;
}