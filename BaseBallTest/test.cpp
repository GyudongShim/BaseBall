#include "pch.h"
#include "../BaseBall/BaseBall.cpp"

class BaseBallFixture : public testing::Test
{
public:
	BaseBall game{};
	void assertIllegalArgument(string guessNumber)
	{
		// game.Guess ���� ��, Exception�� �߻��ؾ� pass�̴�.
	}
};

TEST_F(BaseBallFixture, ThrowExceptionWhenInvalid)
{
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}
