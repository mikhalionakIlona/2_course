#pragma once
#include <regex> 


int number_input(std::istream& is, int min, int max);
std::string empty_input(std::istream& is);
std::string word_input(std::istream& is);
int year_input(std::istream& is);
std::string single_word_input(std::istream& is);
std::string time_input(std::istream& is);
double double_input(std::istream& is, double min, double max);