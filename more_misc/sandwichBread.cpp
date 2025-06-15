#include <iostream>
#include <stack>
#include <set>
#include <string>
using namespace std;


//sliding window solution
string findBreadColorsOpt(const string& s) {
    set<char> breadColors; // to store unique bread colors
    int n = s.length();
    int i = 0;

    while (i < n) {
        char currentBread = s[i];
        int j = i + 1;

        // Find the next occurrence of the same bread character
        while (j < n && s[j] != currentBread) {
            j++;
        }

        // If found, add to the set
        if (j < n) {
            breadColors.insert(currentBread);
        }

        // Move i to the next character after the found pair
        i = j + 1;
    }

    // Convert set to sorted string
    string result(breadColors.begin(), breadColors.end());
    return result;
}



//stack solution 
string findBreadColors(const string& s) {
    stack<char> st;
    set<char> breadSet;
    string result;

    for (char ch : s) {
        if (!st.empty() && st.top() == ch) {
            char bread = st.top();
            st.pop(); // found matching bread
            if (breadSet.find(bread) == breadSet.end()) {
                result += bread;
                breadSet.insert(bread);
            }
        } else {
            st.push(ch);
        }
    }

    return result;
}

int main() {
    string input = "ppabppccdcc";
    cout <<"ans: "<< findBreadColors(input) << endl;  // Output: qu
    return 0;
}
