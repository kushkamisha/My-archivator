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
        cout << "  d[" << i + 1 << "] = " << dict[i + 1] << endl;
    cout << endl;
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

map<unsigned long, string> encoding (string in, Encode &encode, unsigned long n)
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
//            cout << "i = " << i << endl;
//            cout << "c = " << c << endl;
//            cout << "p = " << p << endl;
////            showDict(dictionary);
//            cout << endl;
            last_index++;
            encode.encoded_text += /*to_string(findIn(dictionary, p));*/toBinary(findIn(dictionary, p), bits);
//            cout << findIn(dictionary, p) << " " << toBinary(findIn(dictionary, p), bits) << " " << bits << endl;
            p = c;
        }
        if (i == n - 1)
            encode.encoded_text += /*to_string(findIn(dictionary, p));*/toBinary(findIn(dictionary, p), bits);
    }
//        showDict(dictionary);
    
    return dictionary;
}

string decoding (Encode encoded, unsigned long n)
{
    string p = "", c = "", p_plus_c = "", str_pw = "", str_cw = "", decode = "", line_part;
    
    unsigned long curr_number = encoded.dict.size() + 1, pw = 1, cw = 1;
    
    // change bit string to decimal string
    n = encoded.encoded_text.length();
    int bits = 2;
    unsigned long i = 0, iteration_numb = 1;
    vector<unsigned long> decimal_arr;
    while (bits <= log2(curr_number))
        bits++;
    while (i + bits <= n)
    {
        if (bits <= log2(iteration_numb + curr_number - 1))
            bits++;
        decimal_arr.push_back(toDecimal(atoll(encoded.encoded_text.substr(i, bits).c_str())));
//        cout << toDecimal(atoll(encoded.encoded_text.substr(i, bits).c_str())) << endl;
        i += bits;
        iteration_numb++;
    }
//    for (unsigned long i = 0; i < decimal_arr.size(); ++i)
//        cout << decimal_arr[i] << " ";
//    cout << endl;
//    showDict(encoded.dict);
    
    n = decimal_arr.size();
//    cout << "n = " << n << endl;
    for (unsigned long i = 0; i < n; ++i)
    {
        cw = decimal_arr[i];
        if (i == 0)
        {
            str_cw = encoded.dict[cw];
            decode += str_cw;
            pw = cw;
            str_pw = str_cw;
//            cout << endl;
            continue;
        }
        if (encoded.dict.find(cw) != encoded.dict.end())
        {
//            cout << "Inside" << endl;
            str_cw = encoded.dict[cw];
            str_pw = encoded.dict[pw];
            decode += str_cw;
            p = str_pw;
            c = str_cw[0];
            p_plus_c = p + c;
            encoded.dict[curr_number] = p_plus_c;
//            pw = cw;
            curr_number++;
        }
        else
        {
//            cout << "Second" << endl;
            str_pw = encoded.dict[pw];
            p = str_pw;
            c = str_pw[0];
            p_plus_c = p + c;
            decode += p_plus_c;
            encoded.dict[curr_number] = p_plus_c;
            curr_number++;
        }
//        cout << "cw = " << cw << endl;
//        cout << "pw = " << pw << endl;
//        cout << "str_pw = " << str_pw << endl;
//        cout << "p = " << p << endl;
//        cout << "  c = " << c << endl;
//        showDict(encoded.dict);
//        cout << endl;
        pw = cw;
//        str_pw = str_cw;
    }
//    showDict(encoded.dict);
    return decode;
}
