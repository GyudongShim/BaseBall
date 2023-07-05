#include "pch.h"
#include "../BaseBall/BaseBall.cpp"

TEST(BaseballGame, ThrowExceptoinWhenInputLenghIsUnmatched) {
	BaseBall game;

	EXPECT_THROW(game.Guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidCharacter) {
	BaseBall game;

	EXPECT_THROW(game.Guess(string("12s")), invalid_argument);
}
