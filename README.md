# OOP_5_AsocKont

## Actually Interesting Stuff
### unordered_map
```C++
	std::unordered_map<std::string, std::set<line_number>> contents_;
	std::unordered_map<std::string, std::size_t> amount_;
```

### Regular Expression (regex)
```C++
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
```