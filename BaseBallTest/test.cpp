#include "pch.h"
#include "../BaseBall/BaseBall.cpp"

class BaseBallFixture : public testing::Test
{
public:
	BaseBall game{};
	void assertIllegalArgument(string guessNumber)
	{
		// game.Guess 수행 후, Exception이 발생해야 pass이다.
	}
};

TEST_F(BaseBallFixture, ThrowExceptionWhenInvalid)
{
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}
