#include "ASpell.hpp"

ASpell::ASpell() {}
ASpell::ASpell(const std::string &name, const std::string &effects) 
: name(name), effects(effects) {}

ASpell::ASpell(const ASpell &target) { *this = target; }
ASpell &ASpell::operator=(const ASpell &target) { 
  this->name = target.getName(); 
  this->effects = target.getEffects();
  return (*this);
}

ASpell::~ASpell() {}

void ASpell::launch(const ATarget &target) const { target.getHitBySpell(*this); }

const std::string& ASpell::getName() const { return (name); }
const std::string& ASpell::getEffects() const { return (effects); }
