#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
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
    void getStory(string filename);
    void printStory();
    void setStory();
    void setWords();
  private:
    string story;
    vector<struct Prompt> words;
};
