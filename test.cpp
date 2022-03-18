#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include "main.cpp"

TEST(UVA10008Test, character_filter)
{
    EXPECT_EQ("", character_filter(std::to_string(23145)));
    EXPECT_EQ("WOWISTHISQUESTIONEASY", character_filter(std::string("Wow!!!! Is this question easy?")));
    EXPECT_EQ("COUNTME", character_filter(std::string("Count me 1 2 3 4 5.")));
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
            "Y 1\n",
            oss.str());
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
              "Y 1\n",
              oss.str());
}

TEST(UVA10008Test, solve_uva_problem_file1)
{
    std::ifstream fs("./data/file1");
    std::ostringstream oss;
    solve_uva_problem(fs, oss);
    EXPECT_EQ("E 115\nT 66\nR 61\nA 56\nN 55\nO 54\nI 52\nS 51\nD 36\nH 33\nM 32\nL 30\nU 25\nY 22\nC 18\nP 17\nF 10\nW 10\nB 8\nG 8\nV 8\nJ 4\nX 4\nK 3\nQ 3\nZ 1\n", oss.str());
}

TEST(UVA10008Test, solve_uva_problem_file2)
{
    std::ifstream fs("./data/file2");
    std::ostringstream oss;
    solve_uva_problem(fs, oss);
    EXPECT_EQ("T 7\nE 6\nO 6\nS 5\nA 4\nH 4\nL 4\nG 3\nI 2\nP 2\nU 2\nB 1\nD 1\nF 1\nK 1\nN 1\nR 1\nW 1\nY 1\n", oss.str());
}

TEST(UVA10008Test, solve_uva_problem_file3)
{
    std::ifstream fs("./data/file3");
    std::ostringstream oss;
    solve_uva_problem(fs, oss);
    EXPECT_EQ("E 62\nT 52\nN 29\nI 27\nS 24\nO 23\nA 21\nR 21\nL 18\nU 16\nP 15\nD 14\nH 14\nC 12\nF 7\nG 6\nM 6\nB 4\nW 4\nY 3\nQ 2\nV 1\nX 1\n", oss.str());
}

TEST(UVA10008Test, solve_uva_problem_file4)
{
    std::ifstream fs("./data/file4");
    std::ostringstream oss;
    solve_uva_problem(fs, oss);
    EXPECT_EQ("S 7\nT 6\nI 5\nE 4\nO 3\nA 2\nH 2\nN 2\nU 2\nW 2\nC 1\nM 1\nQ 1\nY 1\n", oss.str());
}

TEST(UVA10008Test, solve_uva_problem_file5)
{
    std::ifstream fs("./data/file5");
    std::ostringstream oss;
    solve_uva_problem(fs, oss);
    EXPECT_EQ("O 21\nT 17\nA 16\nE 12\nH 12\nR 10\nS 10\nW 9\nY 9\nL 8\nC 7\nD 7\nI 7\nM 6\nP 4\nU 4\nF 3\nK 3\nN 2\nV 2\nG 1\nX 1\n", oss.str());
}

// test code reference from coldnew
TEST(UVa10008Test, Solution) {
  auto Solve = [](std::istream& is) -> std::string {
//    testing::internal::CaptureStdout(); can't get stdout display 
    std::ostringstream oss;
    solve_uva_problem(is,oss);
    //return testing::internal::GetCapturedStdout();
    return std::string("\n") + oss.str();
  };

  {
    std::stringstream fake_cin;
    fake_cin << R"(3
This is a test
Count me 1 2 3 4 5
Wow!!!! Is this question easy?)";

    EXPECT_EQ(
        R"(
S 7
T 6
I 5
E 4
O 3
A 2
H 2
N 2
U 2
W 2
C 1
M 1
Q 1
Y 1
)",
Solve(fake_cin));
  }
}

/*
can't use  testing::internal::CaptureStdout(); can't get stdout display 
TEST(UVa10008Test, Solution_2) {
  auto Solve = [](std::istream& is) -> std::string {
    testing::internal::CaptureStdout();
    std::ostringstream oss;
    solve_uva_problem(is,oss);
    return oss.str();
  };

  {
    std::stringstream fake_cin;
    fake_cin << R"(3
This is a test
Count me 1 2 3 4 5
Wow!!!! Is this question easy?)";

    EXPECT_EQ(
        R"(
S 7
T 6
I 5
E 4
O 3
A 2
H 2
N 2
U 2
W 2
C 1
M 1
Q 1
Y 1
)",
Solve(fake_cin));
  }
}
*/

TEST(UVa10008Test, Solution_3)
{
	auto Solve = []() -> std::string{
		std::ifstream fs("./data/file5");
		std::ostringstream oss;
		solve_uva_problem(fs,oss);
		return std::string("\n") + oss.str();
	};

  {
    EXPECT_EQ(
	R"(
O 21
T 17
A 16
E 12
H 12
R 10
S 10
W 9
Y 9
L 8
C 7
D 7
I 7
M 6
P 4
U 4
F 3
K 3
N 2
V 2
G 1
X 1
)",
Solve());
  }
}

