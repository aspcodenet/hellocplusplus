#include <iostream>
#include <string>
#include <vector>
 // std::string
// namespace = folder
// #include <vector>
// #include <stdio.h> // scanf, printf
// #include <string.h> // strcpy, strcat

// VARFÖR HAR VI LÄRT OSS DUMMA "C" då?
// PÅ IOT devices/embedded systems C vanligare än C++

//Vad är jobbigt i C
// input/output - hej streams och stream insertion operator
//    printf %s %d, scanf (buffer overflow) etc etc      
// strings - japp hej std::string
// pekare - hej referenser
// allokeringar - hej vector
// NYTT:
// loopar for each
// auto

//Övningar: 
// allmänt input/output   ExercisesVecka1.docx
// + funktioner ExercisesWeek3 (1).docx
//using namespace std;

// DEFINITION - funktion
// Metod = funktion som är del av en klass


class Player{
public:
    std::string name;
    int age;
};


int main(){
    // Player  foppa;
    // foppa.name = "Foppa"; // INGEN J-KLA STRCPY I C++
    // foppa.age = 42;

    std::vector<Player> players; // en vector är en abstraktion över dynamiska arrayer
    //players.push_back(... ); // lägger till en ny tom Player i listan

    int selection;
    while(true){
        std::cout << "1. Skapa" << std::endl;
        std::cout << "2. Lista" << std::endl;
        std::cout << "3. Avsluta" << std::endl;
        std::cout << "Ditt val:";
        std::cin >> selection;
        if(selection == 1){
            std::cout << "NY SPELARE:" << std::endl;
            Player player;
            std::cout << "Ange namn:";
            std::cin >> player.name;
            std::cout << "Ange age:";
            std::cin >> player.age;
            players.push_back(player);
        }else if(selection == 2){
            std::cout << "ALLA SPELARE:" << std::endl;
            for(const auto& p : players){
                std::cout << "Namn: " << p.name << ", Age: " << p.age << std::endl;
            }
        }
        else if(selection == 3){
            break;
        }
    }

    // foreach 
    // int arr[]{ 21,9,56,99, 202 }; // arrayer som vanligt - dom är statiska i C++
    // // C = indexbaserade loopar
    // for(int index = 0; index < 5; index++){
    //     std::cout << arr[index] << std::endl;
    // }

    // for(int value : arr){ // for each loop
    //     std::cout << value << std::endl;
    // }

    // int i = 12;
    // auto j = 13.2;
    // // j blir en float

    // float a = 1.1f;
    // auto b = 2.2;
    // // b blir en float

    // // auto
    // for(auto value : arr){
    //     std::cout << value << std::endl;
    // }


    // // int  age ;
    // // age = 12;
    // // int age2 = 12;

    // int year = 20;
    // int price;
    // if (year > 18) {
    //     price = 30;
    // }else{
    //     price = 20;
    // }


    // // SYNTAKTISKT SOCKER ANVÄNDS MEST OM DET ÄR IF OCH ELSE (aldrig med else if osv)
    // price = year > 18 ? 30 : 20;




    // std::string playerName = "Foppa";
    // if(playerName == "Foppa"){
    //     std::cout << "Legend!" << std::endl;
    // }

    
    // // if(playerName.length() < 10 ){
    // //     std::cout << "Vilket kort namn du har" << std::endl;
    // // }


    // // playerName = playerName + " Holmberg";

    // std::string name; // BEST PRACTICE
    // std::cout << "Whats your name:"; // scanf " %s"   fgets  Stefan Hoklnmberg
    // std::getline(std::cin, name); // läser en hel rad
    // // std::cin >> name; // Ingen risk för buffer overflow
    // //                    // Bryts vid mellanslag

    // // Finns nåt som heter COUT = console output 
    // // vi kan skicka dit med den s.k STREAM OPERATOR << 
    // int age = 30;
    // std::cin >> age;
    // //printf("Hello World! %d\n", age);
    // std::cout << "Hello World! " << age << std::endl;

    // // std::string namn;
    // // namn = "Stefan";
    // // namn = namn + " Holmberg";

    // // std::cout << "Hej " << namn << std::endl;

    // // char namn[256];
    // // strcpy(namn, "Stefan");
    // // strcat(namn, " Holmberg");
    // // printf("Hej %s\n", namn);
    // // return 0;
}