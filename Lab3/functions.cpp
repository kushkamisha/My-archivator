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

string toBinary (unsigned long numb, int n)
{
    unsigned long divided = 0;
    string answer = "";
    if (numb == 1)
        answer += to_string(1);
    while (numb >= 2)
    {
        divided = numb / 2;
        answer.insert(0, to_string(numb - divided * 2));
        numb = divided;
    }
    answer.insert(0, to_string (divided));
    int m = answer.length();
    if (m < n)
        for (int i = 0; i < n - m; ++i)
            answer.insert(0, "0");
    return answer;
}

unsigned long toDecimal (unsigned long num)
{
    unsigned long bin, dec = 0, rem, base = 1;
    bin = num;
    while (num > 0)
    {
        rem = num % 10;
        dec = dec + rem * base;
        base = base * 2;
        num = num / 10;
    }
    return dec;
}

void encoding (string in, Encode &encode, unsigned long n)
{
    map<unsigned long, string> dictionary;
    string p = "", c = "", p_plus_c = "";
    encode.encoded_text = "";
    
    // fill the dictionary by non-repeated letters in s
    string line_part;
    unsigned long curr_number = 1;
    for (unsigned long i = 0; i < n; ++i)
    {
        line_part = in[i];
        if (!findIn(dictionary, line_part))
        {
            dictionary[curr_number] = line_part;
            curr_number++;
        }
    }
    encode.dict = dictionary;
    
    // encode algorithm
    unsigned long last_index = encode.dict.size() + 1;
    int bits = 2;
    while (bits <= log2(last_index))
        bits++;
    
    for (unsigned long i = 0; i < n; ++i)
    {
        if (bits <= log2(last_index))
            bits++;
        c = in[i];
        p_plus_c = p + c;
        if (findIn(dictionary, p_plus_c))
            p = p_plus_c;
        else
        {
            dictionary[last_index] = p_plus_c;
            last_index++;
            encode.encoded_text += /*to_string(findIn(dictionary, p));*/toBinary(findIn(dictionary, p), bits);
//            cout << findIn(dictionary, p) << " " << toBinary(findIn(dictionary, p), bits) << " " << bits << endl;
            p = c;
        }
        if (i == n - 1)
            encode.encoded_text += /*to_string(findIn(dictionary, p));*/toBinary(findIn(dictionary, p), bits);
    }
        showDict(dictionary);
}

string decoding (Encode encoded, unsigned long n)
{
    unsigned long i = 0, curr_number = encoded.dict.size() + 1, pw, cw;
    string p = "", c = "", p_plus_c = "", str_pw = "", str_cw = "", decode = "", line_part = "";
    
    int bits = 2;
    while (bits <= log2(curr_number))
        bits++;
    
    n = encoded.encoded_text.length();
    unsigned long iteration_numb = 1;
    while (i + bits <= n)
    {
        if (bits <= log2(iteration_numb + curr_number - 2))
            bits++;
        cout << "Bits: " << bits << endl;
        cw = toDecimal(atoll(encoded.encoded_text.substr(i, bits).c_str()));
        cout << encoded.encoded_text.substr(i, bits) << " " << atoll(encoded.encoded_text.substr(i, bits).c_str()) << " " << cw << endl;
        i += bits;
        if (i == bits)
        {
            str_cw = encoded.dict[cw];
            cout << "str_cw: " << str_cw << endl;
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
        iteration_numb++;
    }
    showDict(encoded.dict);
    return decode;
}
