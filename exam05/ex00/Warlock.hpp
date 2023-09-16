#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

class Warlock
{
  private:
    std::string name;
    std::string title;

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
};

#endif