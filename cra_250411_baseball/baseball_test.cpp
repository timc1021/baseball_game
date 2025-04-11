#include <gmock/gmock.h>
#include "baseball.cpp"
#include "iostream"
#include "stdexcept"

using namespace std;

TEST(BaseballGame, game_test) {
	EXPECT_EQ(1, 1);
}

TEST(BaseballGame, ThrowExceptionInputLengthUnmatch) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExceptionInvalidChar) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}

int main() {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}