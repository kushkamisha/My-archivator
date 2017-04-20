//
//  functions.cpp
//  Lab3
//
//  Created by  Roman Usherenko on 19.04.17.
//  Copyright © 2017 Kushka Misha & Yazenok Misha. All rights reserved.
//

#include "functions.hpp"
#include "globals.hpp"

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

void encoding (string in, Encode &encode)
{
    map<unsigned long, string> dictionary;
    string p = "", c = "", p_plus_c = "";
    unsigned long n = in.length();
    encode.encoded_text = "";
    
    // fill the dictionary by non-repeated letters in s
    string line_part;
    unsigned long curr_number = 1;
    for (unsigned long i = 0; i < n; ++i)
    {
        line_part = in[i];
        if (!findIn(dictionary, line_part))
            dictionary[curr_number] = line_part;
        curr_number++;
    }
    encode.dict = dictionary;
    
    // encode algorithm
    unsigned long last_index = dictionary.size() + 1;
    for (unsigned long i = 0; i < n; ++i)
    {
        c = in[i];
        p_plus_c = p + c;
        if (findIn(dictionary, p_plus_c))
            p = p_plus_c;
        else
        {
            dictionary[last_index] = p_plus_c;
            last_index++;
            encode.encoded_text += to_string(findIn(dictionary, p));
            p = c;
        }
        if (i == n - 1)
            encode.encoded_text += to_string(findIn(dictionary, p));
    }
    //    showDict(dictionary);
}

string decoding (Encode encoded, unsigned long n)
{
    string p = "", c = "", p_plus_c = "";
    
    string line_part;
    unsigned long curr_number = 1;
    unsigned long pw, cw;
    string str_pw = "", str_cw = "";
    string decode = "";
    
    curr_number = encoded.dict.size() + 1;
    n = encoded.encoded_text.length();
    for (unsigned long i = 0; i < n; ++i)
    {
        cw = encoded.encoded_text[i] - '0';
        if (i == 0)
        {
            str_cw = encoded.dict[cw];
            decode += str_cw;
            str_pw = str_cw;
            continue;
        }
        if (encoded.dict.find(cw) != encoded.dict.end())
        {
            str_cw = encoded.dict[cw];
            decode += str_cw;
            p = str_pw;
            c = str_cw;
            p_plus_c = p + c;
            encoded.dict[curr_number] = p_plus_c;
            curr_number++;
            pw = cw;
            str_pw = str_cw;
        }
    }
    //    showDict(dictionary);
    return decode;
}
