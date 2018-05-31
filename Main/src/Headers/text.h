#ifndef TEXT_H_
#define TEXT_H_

#include <iostream>

#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <fstream>
#include <regex>

class text {
  public:
	typedef std::vector<std::string>::size_type line_number;
  private:
	std::vector<std::string> text_;
	std::unordered_map<std::string, std::set<line_number>> contents_;
	std::unordered_map<std::string, std::size_t> amount_;
  public:
	text(std::istream& input);
	void print_contents();
};

text::text(std::istream& input) {
	std::string temp_text;
	while (std::getline(input, temp_text)) {
		text_.push_back(temp_text);
		int line_numb = text_.size();
		std::string word;
		std::regex match("(([[:w:]]|[\x27])+)");
		std::sregex_token_iterator pos(temp_text.begin(), temp_text.end(), match);
		std::sregex_token_iterator end;
		while (pos != end) {
			word = pos->str();
			pos++;
			contents_[word].insert(line_numb);
			amount_[word]++;
		}
	}
}

void text::print_contents(){
	for(auto i:contents_){
		std::cout<< "Word '" << i.first << "' repeats " << amount_[i.first] << " times in " << i.second.size() <<" lines: " << std::endl;
		for(auto j:i.second){
			std::cout << "	" << j << std::endl;
		}
	}
	std::cout << std::endl;
}

#endif