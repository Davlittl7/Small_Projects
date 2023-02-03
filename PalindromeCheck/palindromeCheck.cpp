
#include <iostream>
#include <vector>
#include <string>
#include <compare>

using std::vector; using std::string;
using std::cout; using std::cin; using std::endl;

bool isPalindrome(int x);

int main() {
	int input;
	cout << "Enter a number to determine if it is a palindrome: ";
	cin >> input;
	if (isPalindrome(input))
		cout << input << " is a palindrome";
	else
		cout << input << " is not a palindrome";
	
}

bool isPalindrome(int x) {
	string a = std::to_string(x);
	int pLength = a.length();
	int end = pLength - 1;
	for (int start = 0; start < pLength - 1; ++start) {
		if (a[start] != a[end]) return false;
		--end;
	}
	return true;
}
