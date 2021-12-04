#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include "Word.h"
#include "LanguageSetup.h"

int main()
{
    // set up the data vectors
    std::vector<Word> VD{ 50 };
    getdatafile(VD, "verbdata.txt");
    VD[0].code_vectors();
    std::cout << (char*)VD[0].out();
    /*
    Word blank;
    set_blank(blank);
    VD[0].set_next(&blank);
    VD[0].set_prev(&blank);

    std::vector<Word> ND{ 100 };
    getdatafile(ND, "noundata.txt");
    
    std::vector<Word> subjects{ 2 };
    getdatafile(subjects, "subjectdata.txt");
    Word& subject = subjects[0];
    Word& verb = VD[0];
    for (int a = 0; a < 50; a++)
    {
        subject.set_state(rand() % 3);
        set_subject(subject, ND[0]);

        verb.set_state(rand() % 4);
        verb.set_iX(subject.get_iX());
        verb.set_iY(subject.get_iY());
        verb.set_iZ(VD[0].get_state());
        subject.set_next(&VD[0]);
        std::cout << subject.get_out() << std::endl;
        system("pause");
    }

    std::vector<Word> DD{ 10 };
    getdatafile(DD, "morphologydata.txt");
    
    ///initalize the vectors
//    DD[2].set_next(&blank);
//    ND[0].set_prev(&DD[2]);
//    set_subject(subjects[0], ND[0]);
//    subjects[0].set_iXYZ(1, 2, 0);
//    std::cout << subjects[0].get_out();
*/
    return 0;
}