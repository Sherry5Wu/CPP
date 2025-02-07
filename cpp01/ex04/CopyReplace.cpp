#include "CopyReplace.hpp"


CopyReplace::CopyReplace(const std::string fileName, const std::string s1, const std::string s2)
	: fileName_(fileName), s1_(s1), s2_(s2) {}
CopyReplace::~CopyReplace(){}

/**
 * @brief Process the file: read, replace, and write the content
 */
bool	process(){
	if (s1_.empty()){
		std::cerr << "Error\ns1 can NOT be an empty string.\n";
		return false;
	}
	if (!readFile()){
		return false;
	}
	if (!replaceAndWriteFile()){
		return false;
	}
	return true;
}

/**
 * @brief Read the entire content of the file into the "content_" string.
 */
bool	readFile(){
	std::ifstream infile(fileName_);
	if (!infile){
		std::cerr << "Error\nCould Not open file" << fileName_ << std::endl;
		return false;
	}
	std::stringstream buffer;
	buffer << infile.rdbuf();
	content_ = buffer.str();
	return true;
}

/**
 * @brief Replace every occurrence of s1_ with s2_, then write the result into
 * a new file with the name '<fileName.replace>'
 */
bool	replaceAndWriteFile(){
	std::string	outFileName = fileName_ + ".replace";
	std::ofstream outfile(outFileName);
	if (!outfile){
		std::cerr << "Error\nCould Not creats file" << outFileName << std::endl;
		return false;
	}

	// Replace s1_ with s2_ using find and substr
	size_t	start = 0;
	size_t end = 0;
	while ((end = content_.find(s1_, start)) != std::string::npos){
		//write part of the string before s1_
		outfile << content_.substr(start, end - start);
		// write the replacement string s2_
		outfile << s2_;
		// Move the start postion past the found s1_
		start = end + s1_.length();
	}
	// Write any remaining content after the last occurrence of s1_
	outfile << content_.substr(start);
	return true;
}