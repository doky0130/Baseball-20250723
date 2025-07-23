#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(BaseballGame, TryGameTest) {
	Baseball game;
	EXPECT_THROW(game.guess("12"), length_error);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
