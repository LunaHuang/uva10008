#include <gtest/gtest.h>
#include <sstream>
#include "main.cpp"

TEST(UVA10008Test, character_filter)
{
    EXPECT_EQ("",character_filter(std::to_string(23145)));
    EXPECT_EQ("WOWISTHISQUESTIONEASY",character_filter(std::string("Wow!!!! Is this question easy?")));
    EXPECT_EQ("COUNTME",character_filter(std::string("Count me 1 2 3 4 5.")));
}


TEST(UVA10008Test, solve_uva_problem_1)
{
	std::istringstream iss("3\nthat's Asif's book \"The Outsider\".\n"
			"\nGo to 29th page.Let's play !!!!   [[((well enough))]]");
	std::ostringstream oss;
	solve_uva_problem(iss, oss);
EXPECT_EQ(
"T 7\n"
"E 6\n"
"O 6\n"
"S 5\n"
"A 4\n"
"H 4\n"
"L 4\n"
"G 3\n"
"I 2\n"
"P 2\n"
"U 2\n"
"B 1\n"
"D 1\n"
"F 1\n"
"K 1\n"
"N 1\n"
"R 1\n"
"W 1\n"
"Y 1\n"
, oss.str());
}

TEST(UVA10008Test, solve_uva_problem_2)
{
	std::istringstream iss("3\nThis is a test.\nCount me 1 2 3 4 5.\n"
                       "Wow!!!! Is this question easy?\n");
	std::ostringstream oss;
	solve_uva_problem(iss, oss);
EXPECT_EQ("S 7\n"
"T 6\n"
"I 5\n"
"E 4\n"
"O 3\n"
"A 2\n"
"H 2\n"
"N 2\n"
"U 2\n"
"W 2\n"
"C 1\n"
"M 1\n"
"Q 1\n"
"Y 1\n"
, oss.str());
}
