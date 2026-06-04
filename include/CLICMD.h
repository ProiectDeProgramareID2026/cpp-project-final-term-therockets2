#include <string>
#include <vector>

using namespace std;

class CLICMD {
	

public:
	string action;
	vector<string> values;
	bool valid;

	CLICMD();

	void parse_args(int, char**);
	void execute();
};

