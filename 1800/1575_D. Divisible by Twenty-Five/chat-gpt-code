#include <iostream>
#include <string>
#include <set>

using namespace std;

bool isValidDivisibleBy25(const string& s) {
    // The number must end with 00, 25, 50, or 75
    int n = s.size();
    if (n < 2) return false;

    string lastTwoDigits = s.substr(n-2, 2);
    return lastTwoDigits == "00" || lastTwoDigits == "25" || lastTwoDigits == "50" || lastTwoDigits == "75";
}

int countPossibleIntegers(string s) {
    int n = s.size();
    set<string> possibleNumbers;
    
    // Iterate over all possible choices for `X` digits (if any)
    // For each possible value of X (from 0 to 9), we try replacing X and _ with digits
    for (int digitX = 0; digitX <= 9; ++digitX) {
        string current = s;
        
        // Replace all Xs with the current digit
        for (char &ch : current) {
            if (ch == 'X') {
                ch = '0' + digitX;
            }
        }
        
        // Now we need to replace all _ with any digit from 0 to 9
        for (int d = 0; d <= 9; ++d) {
            string candidate = current;
            // Replace all _ with the current digit
            for (char &ch : candidate) {
                if (ch == '_') {
                    ch = '0' + d;
                }
            }
            
            // Check if the number is valid
            if (candidate[0] == '0' && candidate != "0") continue; // Avoid leading zeros except for "0"
            if (isValidDivisibleBy25(candidate)) {
                possibleNumbers.insert(candidate);
            }
        }
    }
    
    return possibleNumbers.size();
}

int main() {
    string s;
    cin >> s;
    
    cout << countPossibleIntegers(s) << endl;
    return 0;
}
