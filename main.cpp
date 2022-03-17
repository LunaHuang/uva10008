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

/* insert new node at the end of the linked list */
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
	while (last->next != nullptr){
//		std::cout << "last "<< last->letter << " "<<last->count<<std::endl;
//		std::cout << "newNode "<< newNode->letter << " "<<newNode->count<<std::endl;
		if(last->count >= newNode->count){
			tmp = last;
			last = last->next;
		}else{
			newNode->next = last;
			if(tmp->next == nullptr){
				*head = newNode;
			}else{
				tmp->next = newNode;
			}
			while (last->next != nullptr)
				last = last->next;
			return;
		}
	}

	if(last->count >= newNode->count){
		last->next = newNode;
	}else{
		tmp->next = newNode;
		newNode->next = last;
	}
	return;
}


void displayList(struct Node *node)
{
	while (node != nullptr)
	{
		std::cout<< node->letter << " "<<node->count<<std::endl;
		node = node->next;
	}
//	std::cout<<std::endl;
}

void order_serial(const std::string &input)
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
	displayList(head);
}

std::string crypt_analysis(const std::string &original_input)
{
	std::regex rx("\[^[:alpha:]]+");
	std::string input = original_input;
	std::string result;
	std::regex_replace(std::back_inserter(result),input.begin(),input.end(),rx,"");
    std::transform(result.begin(), result.end(), result.begin(),toupper);
	return result;
}

void solve_uva_problem(std::istream &is)
{
    std::string input;
	std::getline(is, input);	
    if (input == "0")
		return;

    std::string analysis_string;
	int row = std::stoi(input);
	while(row != 0){
		input.clear();
		std::getline(is, input);	
		//std::cin.getline(input_string, sizeof(input_string));
        //input.assign(input_string, sizeof(input_string));
		analysis_string += crypt_analysis(input);
		row--;
	}
	
	std::sort(analysis_string.begin(), analysis_string.end());
	//std::cout << "match :" << analysis_string << std::endl;
	order_serial(analysis_string);
}

int main(int argc, char ** argv)
{
#if !defined(WITH_GTEST)
    solve_uva_problem(std::cin);
#else
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif
}
