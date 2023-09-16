#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
  private: 
    std::map<const std::string, ATarget *> _target;

    TargetGenerator(const TargetGenerator &obj);
    TargetGenerator &operator=(const TargetGenerator &obj);
  
  public:
    TargetGenerator();
    ~TargetGenerator();
    void learnTargetType(ATarget*);
    void forgetTargetType(std::string const &);
    ATarget* createTarget(std::string const &);
};