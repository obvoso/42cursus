#include "SpellBook.hpp"

SpellBook::SpellBook(const SpellBook &obj){
  *this = obj;
}
SpellBook &SpellBook::operator=(const SpellBook &obj){
  this->spellBook = obj.spellBook;
  return (*this);
}

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {}

void SpellBook::learnSpell(ASpell* spell) {
  if (spell)
    spellBook[spell->getName()] = spell;
}

void SpellBook::forgetSpell(std::string const &name){
    if (spellBook.find(name) != spellBook.end())
      spellBook.erase(spellBook.find(name));
}

ASpell* SpellBook::createSpell(std::string const &name){
  ASpell *tmp = NULL;
  if (spellBook.find(name) != spellBook.end())
    tmp = spellBook[name];
  return (tmp);
}