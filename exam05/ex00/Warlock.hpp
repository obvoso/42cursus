
#include <iostream>

class Warlock {
  private:
    Warlock& operator=(const Warlock& obj); // 대입연산자
    Warlock(Warlock const& obj); //복사생성자
    Warlock();// 기본생성자
    std::string name;
    std::string title;

  public:
    Warlock(std::string name, std::string title); // 생성자
    ~Warlock(); // 소멸자

    std::string const& getName(void) const;
    std::string const& getTitle(void) const;

    void setTitle(std::string const& title);
    void introduce(void) const;
};
