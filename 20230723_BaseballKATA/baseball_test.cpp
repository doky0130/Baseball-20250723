#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(BaseballGame, ThrowLenException) {
	Baseball game;
	EXPECT_THROW(game.guess("12"), length_error);
}

TEST(BaseballGame, ThrowInvalidCharException) {
	Baseball game;
	EXPECT_THROW(game.guess("12s"), invalid_argument);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
