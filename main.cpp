#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <regex>
#include <cctype>
#include <boost/range/algorithm/remove_if.hpp>

#if defined(WITH_GTEST)
#   include <gtest/gtest.h>
#endif

struct Node
{
   char letter;
   int count;
   struct Node *next;
};

/* 
 * when new node count is less (or egual)than compare node
 * insert new node at the end of the compare node
 * otherwise insert ad the first of the compare node
 */
void append(struct Node** head, char letter, int count)
{
	struct Node* newNode = new Node;
	struct Node *last = *head;
 
	newNode->letter = letter;
	newNode->count = count;
	newNode->next = nullptr;
 
	if (*head == nullptr)
	{
		*head = newNode;
		return;
	}

	struct Node *tmp = new Node;
	tmp->next = nullptr;
	while (1){
		if(last->count >= newNode->count){
			if(last->next == nullptr){
				last->next = newNode;
				return;
			}
			tmp = last;
			last = last->next;
		}else{
			newNode->next = last;
			if(tmp->next == nullptr)
				*head = newNode;
			else
				tmp->next = newNode;
			return;
		}
	}
}

void crypt_input_display_list(const std::string &input, std::ostream &os)
{
	int n = input.length();
    char char_array[n + 1];
 
    strcpy(char_array, input.c_str());
	struct Node* head = NULL;
    int count = 1;
    for (int i = 1; i < n; i++){
		if(char_array[i] == char_array[i-1]){
			count++;
			if( i == (n-1))
				append(&head, char_array[i-1], count);
		}else{
			append(&head, char_array[i-1], count);
			count = 1;
			if( i == (n-1))
				append(&head, char_array[i], count);
		}
	}

	// show output
	while (head != nullptr)
	{
		os << head->letter << " " << head->count << std::endl;
		head = head->next;
	}
}

/*
 * [:alpha:] is mean alphabetic characters [A-Za-z] POSIX
 */
std::string character_filter(const std::string &original_input)
{
	std::regex rx("\[^[:alpha:]]+");
	std::string input = original_input;
	std::string result;
	std::regex_replace(std::back_inserter(result),input.begin(),input.end(),rx,"");
    std::transform(result.begin(), result.end(), result.begin(),toupper);
	return result;
}

/*
 * ToDo
 * 1. get the number of lines which follow in the input
 * 2. remove all of not Alphabetic characters on input lines and transform characters to upper
 * 3. sort characters from A to Z
 * 4. crypt the input to count the letter number and display
 *
 */

void solve_uva_problem(std::istream & is, std::ostream & os)
{
    std::string input;
	std::getline(is, input);	
    if (input == "0")
		return;

	int row_lines = std::stoi(input);
    std::string analysis_string;
	while(row_lines != 0){
		input.clear();
		std::getline(is, input);	
		analysis_string += character_filter(input);
		row_lines--;
	}
	
	std::sort(analysis_string.begin(), analysis_string.end());
//	std::cout << "match :" << analysis_string << std::endl;
	crypt_input_display_list(analysis_string, os);
}

int main(int argc, char ** argv)
{
#if !defined(WITH_GTEST)
    solve_uva_problem(std::cin, std::cout);
#else
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif
}
