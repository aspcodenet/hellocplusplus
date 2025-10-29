#include <iostream>
#include <string> // std::string
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

int main(){
    // int  age ;
    // age = 12;
    // int age2 = 12;

    int year = 20;
    int price;
    if (year > 18) {
        price = 30;
    }else{
        price = 20;
    }


    // SYNTAKTISKT SOCKER ANVÄNDS MEST OM DET ÄR IF OCH ELSE (aldrig med else if osv)
    price = year > 18 ? 30 : 20;




    std::string playerName = "Foppa";
    if(playerName == "Foppa"){
        std::cout << "Legend!" << std::endl;
    }

    
    // if(playerName.length() < 10 ){
    //     std::cout << "Vilket kort namn du har" << std::endl;
    // }


    // playerName = playerName + " Holmberg";

    std::string name; // BEST PRACTICE
    std::cout << "Whats your name:"; // scanf " %s"   fgets  Stefan Hoklnmberg
    std::getline(std::cin, name); // läser en hel rad
    // std::cin >> name; // Ingen risk för buffer overflow
    //                    // Bryts vid mellanslag

    // Finns nåt som heter COUT = console output 
    // vi kan skicka dit med den s.k STREAM OPERATOR << 
    int age = 30;
    std::cin >> age;
    //printf("Hello World! %d\n", age);
    std::cout << "Hello World! " << age << std::endl;

    // std::string namn;
    // namn = "Stefan";
    // namn = namn + " Holmberg";

    // std::cout << "Hej " << namn << std::endl;

    // char namn[256];
    // strcpy(namn, "Stefan");
    // strcat(namn, " Holmberg");
    // printf("Hej %s\n", namn);
    // return 0;
}