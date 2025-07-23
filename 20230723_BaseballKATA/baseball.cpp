#include <iostream>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) : question(question) { }

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		return { true,3,0 };
	}

private:
	string question;

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicated(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicated(const string& guessNumber) {
		if (guessNumber[0] == guessNumber[1]) return true;
		if (guessNumber[0] == guessNumber[2]) return true;
		if (guessNumber[1] == guessNumber[2]) return true;
		return false;
	}
};