#include <gmock/gmock.h>
#include "baseball.cpp"
#include "baseball_test.h"
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

int main() {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}