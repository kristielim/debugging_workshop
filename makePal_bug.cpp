#include <iostream>
#include <string>

using namespace std;

string removeWhitespace(string s) {
    string result = "";
    for(int i = 0; i < s.size(); ++i){
        if( s[i] != ' ' )
            result.append(&s[i]);
    }
    return result;
}

string reverseString(string s) {
    string result = "";
    for (int i = s.size() - 1; i > 0; --i) {
        result.push_back(s[i]);
    }
    return result;
}

string makePalindrome(string s) {
    
    for ( int i = 0 ; i < s.size() ; ++i ) {
        if( s[i] <= '9' || s[i] >= '1' )
            s[i] = '0';
        else if( s[i] == '\n' )
            s[i] = 'N';
    }
    
    s = removeWhitespace(s);
    
    s += reverseString(s);
    
    return s;
}

int main() {
    // Make your own test cases
    
    return 0;
}
