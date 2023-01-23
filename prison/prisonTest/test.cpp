#include "pch.h"
#include "../prison/Header.h"

std::vector <int> score = { 7, 9, 15};
std::vector <int> score1 = { 15, 9, 15 };
std::vector <std::vector<char>> roundes = { {'D', 'D', 'C'}, {'D', 'C', 'C'}, {'C', 'C', 'C'} };
std::vector <char> roundchoises1 = { 'C', 'C', 'C' };
std::vector <char> roundchoises2 = { 'D', 'D', 'C' };
std::vector <char> roundchoises3 = { 'C', 'D', 'D' };

TEST(strategyAlwaysC, TestName) {
	StrategyAlwaysC cls;
	char answer = 'C';
	char tmp = cls.Getchoice(0, 0, score, roundes, roundchoises1);
	ASSERT_EQ(answer, tmp);
}

TEST(strategyAlwaysD, TestName) {
	StrategyAlwaysD cls;
	char answ = 'D';
	char tmp = cls.Getchoice(0, 0, score, roundes, roundchoises1);
	ASSERT_EQ(answ, tmp);
}

TEST(strategyWinRound1, TestName) {
	StrategyWinRound cls;
	char answ = 'D';
	char tmp = cls.Getchoice(0, 1, score, roundes, roundchoises1);
	ASSERT_EQ(answ, tmp);
}

TEST(strategyWinRound2, TestName) {
	StrategyWinRound cls;
	char answ = 'D';
	char tmp = cls.Getchoice(0, 0, score, roundes, roundchoises1);
	ASSERT_EQ(answ, tmp);
}

TEST(strategyTeamplay1, TestName) {
	StrategyTeamplay cls;
	char answ = 'C';
	char tmp = cls.Getchoice(0, 0, score, roundes, roundchoises1);
	ASSERT_EQ(answ, tmp);
}

TEST(strategyTeamplay2, TestName) { 
	StrategyTeamplay cls;
	char answ = 'C';
	char tmp = cls.Getchoice(0, 1, score, roundes, roundchoises1);
	ASSERT_EQ(answ, tmp);
}


TEST(strategyRevengful1, TestName) {
	StrategyRevengeful cls;
	char answ = 'C';
	char tmp = cls.Getchoice(0, 0, score, roundes, roundchoises1);
	ASSERT_EQ(answ, tmp);
}

TEST(strategyRevengful2, TestName) {
	StrategyRevengeful cls;
	char answ = 'C';
	char tmp = cls.Getchoice(0, 2, score1, roundes, roundchoises2);
	ASSERT_EQ(answ, tmp);
}

///////

TEST(funcGameRoundScore, TestName)
{
	Score scr;
	std::vector<int> answer = { 0, 0, 0 };
	std::vector<int> tmp = scr.GetRoundScore(5, 6, 7);
	ASSERT_EQ(answer, tmp);
}

TEST(funcChangeRoundScore, TestName)
{
	Score scr;
	std::vector<int> answer = { 5, 6, 7 };
	scr.ChangeRoundScore(5, 6, 7);
	std::vector<int> tmp = scr.GetRoundScore(5, 6, 7);
	ASSERT_EQ(answer, tmp);
}

TEST(funcMakeItZero, TestName)
{
	Score scr;
	std::vector<int> answer = { 0, 0, 0 };
	scr.ChangeRoundScore(5, 6, 7);
	scr.MakeItZero();
	std::vector<int> tmp = scr.GetRoundScore(5, 6, 7);
	ASSERT_EQ(answer, tmp);
}