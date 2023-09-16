#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class ASpell;
class SpellBook {
  private:
    std::map<std::string, ASpell *> spellBook;

    SpellBook(const SpellBook &obj);
    SpellBook &operator=(const SpellBook &obj);

  public:
    SpellBook();
    ~SpellBook();
    
    void learnSpell(ASpell*);
    void forgetSpell(std::string const &);
    ASpell* createSpell(std::string const &);
};