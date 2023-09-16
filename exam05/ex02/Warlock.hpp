#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include "SpellBook.hpp"
#include <map>

class Warlock
{
  private:
    std::string name;
    std::string title;
    SpellBook map;

    Warlock();
    Warlock(const Warlock &warlock);
    Warlock &operator=(const Warlock &warlock);

  public:
    ~Warlock();
    Warlock(const std::string &name, const std::string &title);
    void setTitle(const std::string &string);
    const std::string &getName() const;
    const std::string &getTitle() const;
    void introduce() const;

    void learnSpell(ASpell *spell);
    void forgetSpell(std::string name);
    void launchSpell(std::string name, ATarget const &target);
};

#endif