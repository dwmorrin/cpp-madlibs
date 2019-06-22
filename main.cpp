#include "madlib.h"

int main() {
  auto madlib = Madlib();
  cout << "Use angle brackets to indicate the words to replace, ";
  cout << "like an HTML tag.\n";
  cout << "Example: \"The <noun> was <verb>.\"\n";
  cout << "Enter your story:\n";
  madlib.getStory();
  cout << "-----MADLIBS!-----\nPick your words:\n";
  madlib.getAnswers();
  madlib.setStory();
  madlib.printStory();
}
