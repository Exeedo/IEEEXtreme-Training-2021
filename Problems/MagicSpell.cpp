// Problem link: https://csacademy.com/ieeextreme-practice/task/magic-spell/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

map<string,long long> num;

void fillMap() {
    num["zero"]     =  0;
    num["one"]      =  1;
    num["two"]      =  2;
    num["three"]    =  3;
    num["four"]     =  4;
    num["five"]     =  5;
    num["six"]      =  6;
    num["seven"]    =  7;
    num["eight"]    =  8;
    num["nine"]     =  9;
    num["ten"]      = 10;
    num["eleven"]   = 11;
    num["twelve"]   = 12;
    num["thirteen"] = 13;
    num["fourteen"] = 14;
    num["fifteen"]  = 15;
}

string letters = "qwertyuiopasdfghjklzxcvbnm";

string translate(string in){
    string out;
    int n = letters.length();
    int m = in.length();
    for(int i=0;i<m;i++){
        char c = in[i];
        for(int j=0;j<n;j++){
            if (letters[j] == c){
                out += letters[j-1];
                break;
            }
        }
    }
    return out;
}

int main() {
    fillMap();
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    
    vector<long long> decimal_numbers;
    for(int i = 0; i < n; i++) {
        getline(cin, s);
        vector<string> words;
        vector<long long> numbers;
        
        // Reading of single line (input)
        string word;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                words.push_back(word);
                word = "";
            }
            else{
                word += s[i];
            }
        }
        words.push_back(word);
        
        // Translate words into numbers
        for (string w : words){
            w = translate(w);
            numbers.push_back(num[w]);
        }
        
        long long decimal_number = 0;
        /*
        // Convert hexadecimal numbers into decimal (By multiplication)
        reverse(numbers.begin(), numbers.end());
        long long factor = 1;
        for(long long number : numbers){
            decimal_number += number * factor;
            factor *= 16;
        }
        */
        
        // Convert hexadecimal numbers into decimal (By shifting)
        for(long long number : numbers){
            decimal_number <<= 4; // shift to the left (in-place)
            decimal_number |= number;
        }
        
        decimal_numbers.push_back(decimal_number);
    }
    
    long long answer = 1;
    for(long long number: decimal_numbers){
        answer *= number;
    }
    cout << answer;
    return 0;
}
