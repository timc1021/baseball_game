#include "iostream"

using namespace std;

class Baseball {
public:
	void guess(const string& str) {
		throw length_error("must be three letters.");
	}
};