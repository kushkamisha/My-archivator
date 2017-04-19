//
//  main.cpp
//  Lab3
//
//  Created by  Roman Usherenko on 19.04.17.
//  Copyright © 2017 Kushka Misha & Yazenok Misha. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

unsigned long findIn (map<unsigned long, string>, string); // check is value in map
void showDict (map<unsigned long, string>); // show map on the screen

int main() {
    map<unsigned long, string> dictionary;
    string s = "wabbawabba";
    string p = "", c = "", p_plus_c = "";
    unsigned long n = s.length(),
                  curr_number = 1;
    string line_part, encode = "";
    
    // fill the dictionary by non-repeated letters in s
    for (unsigned long i = 0; i < n; ++i)
    {
        line_part = s[i];
        if (!findIn(dictionary, line_part))
            dictionary[curr_number] = line_part;
        curr_number++;
    }
//    showDict(dictionary);
    
    // encode algorithm
    unsigned long last_index = dictionary.size() + 1;
    for (unsigned long i = 0; i < n; ++i)
    {
        c = s[i];
        p_plus_c = p + c;
        if (findIn(dictionary, p_plus_c))
            p = p_plus_c;
        else
        {
            dictionary[last_index] = p_plus_c;
            last_index++;
            encode += to_string(findIn(dictionary, p));
            p = c;
        }
        if (i == n - 1)
            encode += to_string(findIn(dictionary, p));
    }
//    showDict(dictionary);
    cout << encode << endl;
    
    // decode algorithm
    dictionary = {};
    curr_number = 1;
    p = ""; c = ""; p_plus_c = "";
    unsigned long pw, cw;
    string str_pw = "", str_cw = "";
    string decode = "";
    
    // fill the dictionary by non-repeated letters in s
    for (unsigned long i = 0; i < n; ++i)
    {
        line_part = s[i];
        if (!findIn(dictionary, line_part))
            dictionary[curr_number] = line_part;
        curr_number++;
    }
//    showDict(dictionary);
    
    curr_number = dictionary.size() + 1;
    n = encode.length();
    for (unsigned long i = 0; i < n; ++i)
    {
        cw = encode[i] - '0';
        if (i == 0)
        {
            str_cw = dictionary[cw];
            decode += str_cw;
            str_pw = str_cw;
            continue;
        }
        if (dictionary.find(cw) != dictionary.end())
        {
            str_cw = dictionary[cw];
            decode += str_cw;
            p = str_pw;
            c = str_cw;
            p_plus_c = p + c;
            dictionary[curr_number] = p_plus_c;
            curr_number++;
            pw = cw;
            str_pw = str_cw;
        }
    }
    showDict(dictionary);
    cout << decode << endl;
}

unsigned long findIn (map<unsigned long, string> dict, string value)
{
    for (int i = 0; i < dict.size(); ++i)
        if (dict[i] == value)
            return i;
    return NULL;
}

void showDict (map<unsigned long, string> dict)
{
    for (int i = 0; i < dict.size(); ++i)
        cout << "dict[" << i + 1 << "] = " << dict[i + 1] << endl;
}
