#include <stdexcept>
#include "iostream"

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) : question{ question } {

	}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question)
			return { true, 3, 0 };

		GuessResult result = { false, 0, 0 };
		
		checkStrikesAndBalls(guessNumber, result);

		return result;
	}

	void checkStrikesAndBalls(const std::string& guessNumber, GuessResult& result)
	{
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == question[i]) {
				result.strikes++;
			}
			else {
				for (int j = 0; j < 3; j++) {
					if (guessNumber[i] == question[j]) {
						result.balls++;
					}
				}
			}
		}
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw length_error("must be three letters.");

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("must be number");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("no same number");
		}
	}

	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return (guessNumber[0] == guessNumber[1]
			|| guessNumber[1] == guessNumber[2]
			|| guessNumber[0] == guessNumber[2]);
	}

private:
	string question;
};