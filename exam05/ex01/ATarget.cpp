#include "ATarget.hpp"

ATarget::ATarget() {}
ATarget::ATarget(const std::string &type) :type(type) {}
ATarget::~ATarget() {}
ATarget::ATarget(const ATarget &target) { *this = target; }
ATarget& ATarget::operator=(const ATarget &target) { 
  this->type = target.getType();
  return (*this);
}

const std::string& ATarget::getType() const { return (type); }

void ATarget::getHitBySpell(const ASpell &target) const {
  std::cout << this->type << " has been " << target.getEffects() << "!" << std::endl;
}