#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game;
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

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
