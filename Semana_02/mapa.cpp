#include <iostream>
#include <map>

int main(){

  std::map<std::string, std::string> phonebook; // Notese los argumentos de plantilla
  std::cout << phonebook.size() << std::endl;

  phonebook["Marlon"] = "2345-6789"; // Entrada no existe, se crea
  std::cout << phonebook.size() << std::endl;
  phonebook["Marlon"] = "9876-5432"; // Entrada existe, se modifica
  std::cout << phonebook.size() << std::endl;

  std::cout << phonebook["Marlon"] << std::endl;
  std::cout << phonebook["Fede"] << std::endl; // Entrada en blanco

  return 0;
}


