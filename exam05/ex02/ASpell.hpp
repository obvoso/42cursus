#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;
class ASpell {
  protected:
    std::string name;
    std::string effects;

  public:
    ASpell();
    ASpell(const std::string &name, const std::string &effects);
    ASpell(const ASpell &target);
    ASpell &operator=(const ASpell &target);
    virtual ~ASpell();

    virtual ASpell *clone() const = 0;
    void launch(const ATarget &target) const;

    const std::string &getName() const;
    const std::string &getEffects() const;
};