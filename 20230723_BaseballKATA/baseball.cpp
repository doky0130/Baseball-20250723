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

		GuessResult result = { false, 0, 0 };
		
		result.strikes = countStrikes(guessNumber);
		result.balls = countBalls(guessNumber);
		if (result.strikes == 3) { result.solved = true; }

		return result;
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
	int countStrikes(const std::string& guessNumber){
		int strikes = 0;
		for (int idx = 0; idx < 3; idx++) {
			if (guessNumber[idx] == question[idx]) {
				strikes++;
			}
		}
		return strikes;
	}

	int  countBalls(const std::string& guessNumber){
		int balls = 0;
		for (int guessIdx = 0; guessIdx < 3; guessIdx++) {
			for (int questionIdx = 0; questionIdx < 3; questionIdx++) {
				if (guessNumber[guessIdx] != question[questionIdx]) continue;
				if (guessIdx == questionIdx) continue;
				else balls++;
			}
		}
		return balls;
	}
};