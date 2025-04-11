#include <gmock/gmock.h>
#include "baseball.cpp"

TEST(BaseballGame, game_test) {
	EXPECT_EQ(1, 1);
}

int main() {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}