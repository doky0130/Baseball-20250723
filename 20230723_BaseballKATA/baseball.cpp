#include <iostream>

using namespace std;

class Baseball {
public:
	void guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
	}

private:
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