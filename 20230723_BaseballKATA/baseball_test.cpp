#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
	void assertionIllegalArgument(const string& string) {
		try {
			game.guess(string);
			FAIL();
		}
		catch (const exception& e) {
			
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionInvalidArgument) {
	assertionIllegalArgument("12");
	assertionIllegalArgument("12s");
	assertionIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");
	
	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
