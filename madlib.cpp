#include "madlib.h"

Madlib::Madlib()
  :story{""}, words{vector<struct Prompt>()}
{
}

void Madlib::getAnswers() {
  for (auto & p : words) {
    cout << p.prompt << ": ";
    getline(cin, p.answer);
  }
}

void Madlib::getStory() {
  getline(cin, story);
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

void Madlib::printStory() {
  cout << story << "\n";
}

void Madlib::setStory() {
  std::regex placeholder {"<(.*?)>"};
  for (auto p : words) {
    story = regex_replace(story, placeholder, p.answer,
        std::regex_constants::format_first_only);
  }
}
