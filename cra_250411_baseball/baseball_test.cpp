#include <gmock/gmock.h>
#include "baseball.cpp"

using namespace std;

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };

	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			//PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowException) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, solved) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(result.strikes, 3);
	EXPECT_EQ(result.balls, 0);
}

TEST_F(BaseballFixture, strike2ball0) {
	GuessResult result = game.guess("153");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strikes, 2);
	EXPECT_EQ(result.balls, 0);
}

int main() {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}