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
		ValidateInput(guessNumber);

		if (guessNumber == m_initialDigits)
		{
			result.isAllMatched = true;
			result.numberOfStrikes = 3;
			result.numberOfBalls = 0;

			return result;
		}

		// Check strikes
		for (int indexOfGuess = 0; indexOfGuess < 3; indexOfGuess++)
		{
			int matchedIndex = -1;
			const char verifyDigit = guessNumber[indexOfGuess];

			// 1. Check strike
			if (verifyDigit == m_initialDigits[indexOfGuess])
			{
				result.numberOfStrikes++;
				continue;
			}

			// 2. Check balls
			for (int delta = 1; delta < 3; delta++)
			{
				const int checkIndex = (indexOfGuess + delta) % 3;
				if (verifyDigit == m_initialDigits[checkIndex])
				{
					result.numberOfBalls++;
					break;
				}
			}
		}

		if (result.numberOfStrikes == 3)
			result.isAllMatched = true;

		return result;
	}

private:
	int GetNextIndex(int indexOfMine)
	{
		return (indexOfMine + 1) % 3;
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
	string m_initialDigits;
};