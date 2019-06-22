#include <iostream>
#include <regex>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;

struct Prompt {
  string prompt;
  string answer;
};

class Madlib {
  public:
    Madlib();
    void getAnswers();
    void getStory();
    void setStory();
    void printStory();
  private:
    string story;
    vector<struct Prompt> words;
};
