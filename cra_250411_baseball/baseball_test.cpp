#include <gmock/gmock.h>
#include "baseball.cpp"
#include "iostream"
#include "stdexcept"

using namespace std;

class BaseballFixture : public testing::Test {
public:
	Baseball game;

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

int main() {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}