#include "madlib.h"

Madlib::Madlib()
  :story{""}, words{vector<struct Prompt>()}
{
}

// getAnswers gets player's input for the replacement words
void Madlib::getAnswers() {
  for (auto & p : words) {
    cout << p.prompt << ": ";
    getline(std::cin, p.answer);
  }
}

// getStory from stdin
void Madlib::getStory() {
  cout << "Use angle brackets to indicate the words to replace, "
   "like an HTML tag.\n"
   "Example: \"The <noun> was <verb>.\"\n"
   "Enter your story:\n";
  getline(std::cin, story);
  setWords();
}

// getStory from a file
void Madlib::getStory(string filename) {
  std::ifstream file(filename);
  if (! file.is_open()) {
    std::cerr << "can't open " << filename << "\n";
    exit(EXIT_FAILURE);
  }
  string line;
  while (getline(file, line)) {
      story += line + "\n";
  }
  file.close();
  setWords();
}

void Madlib::printStory() {
  cout << story << "\n";
}

// setStory replaces <placeholder> with results from getAnswers
void Madlib::setStory() {
  std::regex placeholder {"<(.*?)>"};
  for (auto p : words) {
    story = regex_replace(story, placeholder, p.answer,
        std::regex_constants::format_first_only);
  }
}

// setWords scans story for <word> placeholders
void Madlib::setWords() {
  std::regex placeholder {"<(.*?)>"};
  std::smatch match;
  string storyCopy = story;
  while (regex_search(storyCopy, match, placeholder)) {
    struct Prompt p{"", ""};
    p.prompt = match[1];
    words.push_back(p);
    storyCopy = match.suffix();
  }
}
