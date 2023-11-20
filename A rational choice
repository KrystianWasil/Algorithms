#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

class Announcement {
  public:
    std::string name;
    long int number_of_turns;
    Announcement(std::string name, long int number_of_turns) {
      this->name = name;
      this->number_of_turns = number_of_turns;

    }
    Announcement() : name("") , number_of_turns(number_of_turns) {}

};

bool comp(Announcement a1, Announcement a2){
  if(a1.number_of_turns!=a2.number_of_turns)
    return a1.number_of_turns<a2.number_of_turns;
  return a1.name<a2.name;
}

  int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);


  int n;
  std::string name;
  long int number_of_turns;
  long double p;
  long  d;


  std::cin >> n;
  std::cin.ignore();

  Announcement announcement[3];

  for (int i = 0; i < n; i++) {
      getline(std::cin,name);
      std::cin >> p;
      std::cin >> d;
      std::cin.ignore();
      number_of_turns = (p/(2*3.141593*((long double)d/2*0.0000254)));
      if (i < 3) {
          announcement[i] = Announcement(name,number_of_turns);
      }

      if ( i >= 3 && number_of_turns < announcement[2].number_of_turns || i >= 3 && (number_of_turns == announcement[2].number_of_turns && name < announcement[2].name)) {
              announcement[2] = Announcement(name,number_of_turns);
          }
      std::sort(announcement,announcement+3,comp);
  }
  for ( int i = 0; i < 3; i++) {
    std::cout << announcement[i].name << std::endl;
    std::cout << (long int)announcement[i].number_of_turns << std::endl;
  }

   return 0;
}
