#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(const std::string  &name, const std::string &title) 
: name(name), title(title) {
  std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock  &warlock) { *this = warlock; }

Warlock& Warlock::operator=(Warlock const &warlock){
    name = warlock.name;
    title = warlock.title;
    return *this;
}

Warlock::~Warlock () { std::cout << name << ": My job here is done!" << std::endl; }

void Warlock::setTitle(const std::string &string){ title = string; }
const std::string &Warlock::getName() const{ return name; }
const std::string &Warlock::getTitle() const{ return title; }
void Warlock::introduce() const { std::cout << name << ": I am " << name << ", " << title << "!" << std::endl; }

void Warlock::learnSpell(ASpell *spell) {
 if (spell)
  map[spell->getName()] = spell;
}

void Warlock::forgetSpell(std::string name) {
 if (map.find(name) != map.end())
  map.erase(map.find(name));
}
void Warlock::launchSpell(std::string name, ATarget const &target) {
 if (map.find(name) != map.end())
  map[name]->launch(target);
}