#pragma once
#include <string>
#include <vector>
#include "Word.h"

enum verb_state_enum { predicate, particode_indexple };
enum tense_enum { present, past };
enum subject_enum { firstPerson, secondPerson, thirdPerson };
enum noun_state_enum {def, undef};
enum plural_enum{singular, plural};


void copy_string_to_word(Word& w, std::string STR)
{
    size_t sz = STR.length();
    int x_index = 0;
    int vX_index = 0;
    int t[50];
    int temp_count = 0;
    w.set_vX(vX_index++, x_index);
    while (x_index < sz)
    {
        if (STR[x_index] == ',')
        {
            int temp_int = STR[++x_index];
            t[temp_count++] = temp_int;
            x_index++;
        }
        else if (STR[x_index] == '/')
        {
            w.set_X('\0', x_index++);
            w.set_X(STR[x_index], x_index);
            w.set_vX(vX_index++, x_index);
            x_index++;
        }
        else
        {
            w.set_X(STR[x_index], x_index);
            x_index++;
        }
    }
    w.set_X('\0', x_index++);
    w.set_vX(vX_index, x_index);
    for (int i = 0; i < temp_count; i++){w.set_X(t[i], x_index++);}
    w.set_last_X(x_index);
    w.set_last_vX(vX_index);
    while (x_index < 300)w.set_X(0, x_index++);
    
}

void getdatafile(std::vector<Word>& WORD_VECTOR, std::string datafile)
{

    std::ifstream infile;
    std::string raw_str_of_txt, word_list;
    std::vector<std::string> row_of_str;
    int index = 0;
    infile.open(datafile);

    while (!infile.eof())
    {
        row_of_str.clear();
        getline(infile, raw_str_of_txt);
        if (raw_str_of_txt.empty()) { continue; };
        copy_string_to_word(WORD_VECTOR[index++], raw_str_of_txt);
    }
    infile.close();
}
/*
void set_noun(Word& noun, int plural)
{
    int index = 0;
    noun.set_vXY(1, 1);
    noun.set_vYZ(1, 1);
    if (noun.check_condition(2, 'u'))
    {
        noun.set_vXY(0, 1);
        noun.set_state(1);
    }
    noun.set_iX(plural);
    noun.set_state(plural);
}
void set_determiner(Word& det, int state, int plural)
{
    det.set_vXY(2, 1);
    det.set_vYZ(1, 1);
    det.set_iXYZ(state, plural, 0);
    det.set_state(state);
}

void set_subject(Word& subject, Word& noun)
{            //             Y0          Y1 
    int temp[]{ 9,3,2,  0,1,2,  6,7,8,  3,4,5, 0,3,6, 0,2 };
    subject.code_vectors(temp);
    subject.set_iX(subject.get_state());
    subject.set_ref(&noun);
    subject.set_iY( subject.get_ref()->get_state() );  
}


void set_blank(Word& blank)
{
    copy_string_to_word(blank, " ");

    blank.set_vX(0, 0);
    blank.set_iXYZ(0, 0, 0);

}

void set_predicate(Word& verb, Word& subject)
{
    int i = 0;
    int x = 0;
    while (i < 8)
    {
        verb.set_vXY(x, i++);
        x = x + 3;
    }
    verb.set_vXY(24, 8);
    verb.set_vXY(25, 9);
    verb.set_vYZ(4, 1);
    verb.set_vYZ(8, 2);
    verb.set_vYZ(9, 3);
}
*/