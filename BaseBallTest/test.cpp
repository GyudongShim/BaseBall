#include "pch.h"
#include "../BaseBall/BaseBall.cpp"

class BaseBallFixture : public testing::Test
{
public:
	BaseBall game{};
	void assertIllegalArgument(string guessNumber)
	{
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
