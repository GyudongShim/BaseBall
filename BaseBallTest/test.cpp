#include "pch.h"
#include "../BaseBall/BaseBall.cpp"

class BaseBallFixture : public testing::Test
{
public:
	
	void assertIllegalArgument(string guessNumber)
	{
		string initialDigits = string("123");
		BaseBall game{initialDigits};
		try
		{
			game.Guess(guessNumber);
			FAIL();
		}
		catch (exception e)
		{
			// PASS
		}
	}
};

TEST_F(BaseBallFixture, ThrowExceptionWhenInvalid)
{
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseBallFixture, ReturnSolvedREsultForMatchedNumber)
{
	string expectedString = "123";
	BaseBall game{ expectedString };
	auto result = game.Guess(expectedString);
	EXPECT_TRUE(result.isAllMatched);
	EXPECT_EQ(3, result.numberOfStrikes);
	EXPECT_EQ(0, result.numberOfBalls);
}

TEST_F(BaseBallFixture, ReturnTwoStrikesZeroBall)
{
	string expectedString = "123";
	BaseBall game{ expectedString };

	string aMatches[] = {
	"124", "143", "423" };

	for (const string& tryString : aMatches)
	{
		auto result = game.Guess(tryString);

		EXPECT_FALSE(result.isAllMatched);
		EXPECT_EQ(2, result.numberOfStrikes);
		EXPECT_EQ(0, result.numberOfBalls);
	}
}

TEST_F(BaseBallFixture, ReturnOneStrikesOneBall)
{
	string expectedString = "123";
	BaseBall game{ expectedString };

	string aMatches[] = {
	"134", "152", "324", "421", "513", "253"};

	for (const string& tryString : aMatches)
	{
		// cout << tryString << endl;
		auto result = game.Guess(tryString);
		EXPECT_FALSE(result.isAllMatched);
		EXPECT_EQ(1, result.numberOfStrikes);
		EXPECT_EQ(1, result.numberOfBalls);
	}
}

