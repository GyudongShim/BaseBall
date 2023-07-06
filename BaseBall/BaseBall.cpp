#pragma once
#include <stdexcept>
using namespace std;

struct GuessResult
{
	bool isAllMatched;
	int numberOfStrikes;
	int numberOfBalls;
};

class BaseBall
{
public:
	BaseBall(string& initialDigits) :
		m_initialDigits(initialDigits)
	{
	}

	GuessResult Guess(const string& guessNumber)
	{
		GuessResult result{false, 0, 0};

		// Throws exception for invalid inputs
		ValidateInput(guessNumber);

		// Check one digit
		for (int indexOfGuess = 0; indexOfGuess < 3; indexOfGuess++)
		{
			const char verifyDigit = guessNumber[indexOfGuess];
			// 1. Check strike
			if (CheckStrike(result, indexOfGuess, verifyDigit)) continue;

			// 2. Check ball at different index
			CheckBall(result, indexOfGuess, verifyDigit);
		}

		if (result.numberOfStrikes == 3)
			result.isAllMatched = true;

		return result;
	}

private:
	bool CheckStrike(GuessResult& result, int indexOfGuess, const char verifyDigit)
	{
		if (CheckDigit(indexOfGuess, verifyDigit))
		{
			result.numberOfStrikes++;
			return true;
		}
		return false;
	}

	void CheckBall(GuessResult& result, int indexOfGuess, const char verifyDigit)
	{
		for (int delta = 1; delta < 3; delta++)
		{
			const int checkIndex = (indexOfGuess + delta) % 3;
			if (CheckDigit(checkIndex, verifyDigit))
			{
				result.numberOfBalls++;
				break;
			}
		}
	}

	bool CheckDigit(int index, char digit)
	{
		if (m_initialDigits[index] != digit)
			return false;

		return true;
	}

	bool IsCharacter(char aCharacter)
	{
		if (aCharacter < '0')
			return false;

		if (aCharacter > '9')
			return false;

		return true;
	}

	bool IsDuplicated(string guessNumber)
	{
		if (guessNumber[0] == guessNumber[1])
			return true;

		if (guessNumber[0] == guessNumber[2])
			return true;
			
		if (guessNumber[1] == guessNumber[2])
			return true;

		return false;
	}

	void ValidateInput(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw length_error("Must be three letters.");

		for (const auto aDigit : guessNumber)
		{
			if (false == IsCharacter(aDigit))
			{
				throw invalid_argument("Not a valid digit from 0 to 9");
			}
		}

		if (IsDuplicated(guessNumber))
			throw invalid_argument("Duplicated digit");
	}

	// 3 digits and mutually different.
	string m_initialDigits;
};