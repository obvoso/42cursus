#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;
class ATarget {
  private:
    std::string type;

  public: 
    ATarget();
    ATarget(const std::string& type);
    virtual ~ATarget();
    ATarget(const ATarget &target);
    ATarget &operator=(const ATarget &target);

    const std::string &getType() const;
    virtual ATarget *clone() const = 0;
    void getHitBySpell(const ASpell &target) const;
};

