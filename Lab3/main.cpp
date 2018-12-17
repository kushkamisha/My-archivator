//
//  main.cpp
//  Lab3
//
//  Created by  Roman Usherenko on 19.04.17.
//  Copyright © 2017 Kushka Misha & Yazenok Misha. All rights reserved.
//

#include "functions.hpp"
#include "globals.hpp"

int main() {
    string s = "wabbawabba";
//    string s = "mishamashapasha";
//   string s = "The main unifying theme is the idea of an intelligent agent. We define AI as the study of agents that receive percepts from the environment and perform actions. Each such agent im- plements a function that maps percept sequences to actions, and we cover different ways to represent these functions, such as reactive agents, real-time planners, and decision-theoretic systems. We explain the role of learning as extending the reach of the designer into unknown environments, and we show how that role constrains agent design, favoring explicit knowl- edge representation and reasoning. We treat robotics and vision not as independently defined problems, but as occurring in the service of achieving goals. We stress the importance of the task environment in determining the appropriate agent design.Our primary aim is to convey the ideas that have emerged over the past fifty years of AI research and the past two millennia of related work. We have tried to avoid excessive formal- ity in the presentation of these ideas while retaining precision. We have included pseudocode algorithms to make the key ideas concrete; our pseudocode is described in Appendix B.This book is primarily intended for use in an undergraduate course or course sequence. The book has 27 chapters, each requiring about a week’s worth of lectures, so working through the whole book requires a two-semester sequence. A one-semester course can use selected chapters to suit the interests of the instructor and students. The book can also be used in a graduate-level course (perhaps with the addition of some of the primary sources suggested in the bibliographical notes). Sample syllabi are available at the book’s Web site, aima.cs.berkeley.edu. The only prerequisite is familiarity with basic concepts of computer science (algorithms, data structures, complexity) at a sophomore level. Freshman calculus and linear algebra are useful for some of the topics; the required mathematical back- ground is supplied in Appendix A.Exercises are given at the end of each chapter. Exercises requiring significant pro- gramming are marked with a keyboard icon. These exercises can best be solved by taking advantage of the code repository at aima.cs.berkeley.edu. Some of them are large enough to be considered term projects. A number of exercises require some investigation of the literature; these are marked with a book icon.Throughout the book, important points are marked with a pointing icon. We have in- cluded an extensive index of around jjjjj items to make it easy to find things in the book. Wherever a new term is first defined, it is also marked in the margin.";
//    string s = "jjjjaaakkkkkkfffffeeeeeeeee";
//    string s = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989380952572010654858632788659361533818279682303019520353018529689957736225994138912497217752834791315155748572424541506959508295331168617278558890750983817546374649393192550604009277016711390098488240128583616035637076601047101819429555961989467678374494482553797747268471040475346462080466842590694912933136770289891521047521620569660240580381501935112533824300355876402474964732639141992726042699227967823547816360093417216412199245863150302861829745557067498385054945885869269956909272107975093029553211653449872027559";
    unsigned long n = s.length();
    Encode encoded;
    string decoded;
    map<unsigned long, string> dict;

    // Process
    dict = encoding(s, encoded, n); // encode
    decoded = decoding (encoded, n); // decode
    
    // Print data
    cout << "Dictionary:" << endl;
    showDict(dict);
    cout << "Encoded text: " << encoded.encoded_text << endl;
    cout << "Decoded text: " << decoded << endl;
    cout << "Encoded size: " << encoded.encoded_text.size() << " bits" << endl;
    cout << "Original size: " << s.size() * 8 << " bits" << endl << endl;
    
    // Find small text
    string looking_for = "bba";
    cout << "Is " << looking_for << " in dictionary: " << !!findIn(dict, "bba") << endl;
    cout << "Is decoding successfully completed: " << (s == decoded) << endl << endl;
}
