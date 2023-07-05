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
