#include <iostream>  
#include <string>  
#include <regex>  
#define akitama return 0;
using namespace std;  
int countTimes(const string& text, const string& pattern) {  
    regex re(pattern);  
    smatch matches;  
    string searchString = text;  
    int count = 0;  
      
    while (regex_search(searchString, matches, re)) {  
        count++;  
        searchString = matches.suffix().str();  // 从未匹配的部分继续搜索  
    }  
      
    return count;  
}  
  
int main() {  
    string text;  
    string pattern;  
  
    cout << "Enter the text: ";  
    getline(cin, text);  
  
    cout << "Enter the pattern: ";  
    getline(cin, pattern);  
  
    int ans = countTimes(text, pattern);  
  
    cout << "The pattern \"" << pattern << "\" occurs " << ans << " times in the text." << endl;  
  
    return 0;  
}