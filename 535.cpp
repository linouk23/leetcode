// 535. Encode and Decode TinyURL - https://leetcode.com/problems/encode-and-decode-tinyurl

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    unordered_map<string, string> short2long, long2short;
    string alphabet, PREFIX;
    default_random_engine generator;
    int n;
    int START;
public:
    Solution() {
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            alphabet += ch;
        }
        for (char ch = '0'; ch <= '9'; ++ch) {
            alphabet += ch;
        }
        n = (int)alphabet.length();
        START = 19;
        PREFIX = "http://tinyurl.com/";
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long2short.count(longUrl)) {
            return long2short[longUrl];
        }
        string key;
        do {
            key.clear();
            while (key.length() != 6) {
                uniform_int_distribution<int> distribution(0, n - 1);
                auto rand_ind = distribution(generator);
                key += alphabet[rand_ind];
            }
            
        } while (long2short.count(key));
        long2short[longUrl] = key;
        short2long[key] = longUrl;
        return PREFIX + key;
    }
    
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string key = shortUrl.substr(START);
        return short2long[key];
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}
