#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) 
  : name(name), title(title)
  {
    std::cout << name << ": This looks like another boring day." << std::endl;
  }

Warlock::~Warlock(void) {
  std::cout << name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(void){

}

Warlock& Warlock::operator=(const Warlock& obj) {
  this->name = obj.name;
  this->title = obj.title;
  return *this;
}

Warlock::Warlock(Warlock const& obj) {
  *this = obj;
}

std::string const& Warlock::getName(void) const {
  return this->name;
}

std::string const& Warlock::getTitle(void) const {
  return this->title;
}

void Warlock::setTitle(std::string const &title) {
  this->title = title;
}

void Warlock::introduce(void) const{
  std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}