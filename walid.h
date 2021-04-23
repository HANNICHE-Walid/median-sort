#include <bits/stdc++.h>
using namespace std;

#define BEGEND(x) begin(x), end(x)

string to_string(bool b) {
  return (b ? "true" : "false");
}
string to_string(const string& s) {
  return '"' + s + '"';
}

//#define WSKIP_EMPTY 1

vector<string> py_split(const string& str, const string& delim=", "){
    vector<string> tokens;
    size_t prev = 0, pos = 0;

#ifdef WSKIP_EMPTY
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();

        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);

        prev = pos + delim.length();
    }
    while (prev < str.length());
#else //!WSKIP_EMPTY
    while ((pos = str.find (delim, prev)) != string::npos) {
        tokens.push_back(str.substr(prev, pos-prev));
        prev = pos + delim.length();
    }

    tokens.push_back (str.substr (prev));

#endif //WSKIP_EMPTY
    
    return tokens;
}