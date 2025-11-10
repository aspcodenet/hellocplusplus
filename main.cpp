#include <iostream>
#include <string>
#include <vector> // en array  som kan växa

// FUNKTION
// tar in en eller flera parametrar och returnerar ett värde
//                                      returnerar ett eller flera värden    
// NÄR ???  returnera själva beräkningen PLUS en felkod



// default parameters
void PlayerPrint(std::string fname, std::string lname, std::string country = "Sweden") 
{  
	std::cout << fname << lname << country <<  "\n";
}


int getPlayerJersey(std::string name) 
{  
    if(name == "Stefan")
        return 10;
    else if(name == "Anna")
        return 7;
    return -1;
}

typedef struct {
    std::string name;
    int errorCode;
} PlayerError;

PlayerError getPlayerName(int jersey) 
{  
    PlayerError err;
    if(jersey == 10)
    {
        err.name = "Stefan";
        err.errorCode = 0;
        return err;    
    }
    else if(jersey == 7)
    {
        err.name = "Anna";
        err.errorCode = 0;
        return err;
    }
    err.name = "Unknown";
    err.errorCode = -1;
    return err;
}

std::tuple<double, char, std::string> get_student(int id)
{
    if (id == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson");
    if (id == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
    if (id == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
    throw std::invalid_argument("id");
}

int add(int a, int b){
    return a + b;
}

int add(int a, int b, int c){
    return a + b + c;
}


double add(double a, double b){
    return a + b;
}


typedef struct {
    std::string name;
    int age;
} Player;

void bla(Player *p){ // copy by value (tar mycket minne om Player är stor - kan inte ändra originalet)
    // p.age = p.age + 1; // ändrar bara kopian
    // std::cout << p.age << std::endl;
    p->age = p->age + 1; // ändrar originalet
    std::cout << p->age << std::endl;
}

void bla2(int *p){
    *p = 12;
}



// C++ references /(syntaktiskt socker ) 
void blamedreference(Player &p){  // reference to p
    p.age = p.age + 1; // ändrar originalet    
    std::cout << p.age << std::endl;
    // vi slipper pil
}

void blamedreference2(const Player &p){  // reference to p
    std::cout << p.age << std::endl;
    // vi slipper pil
}




void titleCase(char *texten){ // txt = 1010
    bool beforeWasSpace = false;

    for(int i = 0; i < strlen(texten); i++){
        if(i == 0 || beforeWasSpace)
            texten[i] = toupper(texten[i]);
        if(texten[i] == ' ')
            beforeWasSpace = true;
        else
            beforeWasSpace = false;
    }
}



int main(){

    // a variabeln ligger på stacken
    const int a = 0; // Kopiera 4 bytes från text-seg till stacken
    int *a_ptr = (int*)&a; 
    *a_ptr = 1234;

    std::cout << a << std::endl; 

    char text[20];
    strcpy(text,"hejsan hoppsan");
    titleCase(text);
    // Hejsan Hoppsan
    const int i = 12; // KONSTANT - FÖR ATT FÖRBÄTTRA KODKVALITETEN
    //   REFERENCE är ju en pekare  under huven
    // innebär att man kan ändra i värdet
    Player p11;
    p11.name = "Stefan";
    p11.age = 35;
    blamedreference2(p11); //vi skrivert inte address of
    // RISK ATT P11 är ändrad efter anropet


    //


        // carsPython =["Volvo", "BMW", "Ford", "Mazda"]
        std::vector<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
        // Change the value of the first element
        cars[0] = "Opel";
        std::cout << cars[0]; 

        for (std::string car : cars) {
            std::cout << car << "\n";
        }


        std::vector<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
        // carsPython.append("Tesla")
        cars.push_back("Tesla"); // i push_back görs realloc!
        cars.push_back("VW");
        cars.push_back("Mitsubishi");
        cars.push_back("Mini");

        std::vector<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
        cars.pop_back();  // TA BORT = längst bak

        std::vector<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
        std::cout << cars.size();  // Outputs 4




    Player p1;
    p1.name = "Stefan";
    p1.age = 35;
    blamedreference(p1); //vi skrivert inte address of








    bla(&p1);
    std::cout << p1.age << std::endl; // p1.age is still 35

    auto sum = add(5, 7);
    double sum = add(5.1, 7.1);


    // auto = 
    auto i = 12;               // i blir en int
    auto j = 13.2;             // j blir en double

    auto student0 = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: " << std::get<0>(student0) << ", "
              << "grade: " << std::get<1>(student0) << ", "
              << "name: " << std::get<2>(student0) << '\n';
 

              // Javascript destructuring assignment
    // C++17 structured binding:
    // gpa2 =  std::get<0>(student0);
    // grade2 =  std::get<1>(student0)
    //  name2 = std::get<2>(student0)
    auto [ gpa2, grade2, name2 ] = get_student(2);
    std::cout << "ID: 2, "
              << "GPA: " << gpa2 << ", "
              << "grade: " << grade2 << ", "
              << "name: " << name2 << '\n';



   //std::string playerName = getPlayerName(10);

    int jersey = getPlayerJersey("Stefan");
    if(jersey == -1){
        std::cout << "Player not found!" << std::endl;
    }

    PlayerPrint("Stefan ", "Svensson ", "Sweden");
    PlayerPrint("Anna ", "Andersson ", "USA");
    PlayerPrint("Kalle ", "Svensson"); // uses default parameter
    return 0;
}