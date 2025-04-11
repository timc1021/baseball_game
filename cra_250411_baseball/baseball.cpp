#include "iostream"

using namespace std;

class Baseball {
public:
	void guess(const string& str) {
		if (str.length() != 3)
			throw length_error("must be three letters.");

		for (char ch : str) {
			if (ch < '0' || ch > '9')
				throw invalid_argument("must be number");
		}
	}
};