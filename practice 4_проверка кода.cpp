#include <iostream>
#include <string>

int main() {
	std::string str = "Hello, world!";
	std::string result = "";

	for (char c : str) {
		if (c != ' ') {
			result += c;
		}
	}

	std::cout << "String without spaces: " << result << std::endl;
	return 0;
}