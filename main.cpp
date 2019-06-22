#include "madlib.h"

int main(int argc, char **argv) {
  auto madlib = Madlib();
  if (argc == 2) {
    madlib.getStory(argv[1]);
  } else {
    madlib.getStory();
  }
  cout << "-----MADLIBS!-----\nPick your words:\n";
  madlib.getAnswers();
  madlib.setStory();
  madlib.printStory();
}
