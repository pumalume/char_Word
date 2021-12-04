
#pragma once
#include <stddef.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>


class Word
{
private:
    int X[300]{}; //sequence of char parsed with \0
    int* vX[50]{}; //sequence of pointers to char string parsed with a \0 char
    int** vY[10]{};//sequence of pointers to those strings 
    int*** vZ[10]{}; //sequence of pointers to XY relations

    int  iX = 0;
    int iY = 0;
    int iZ = 0;
    int state = 0;
    int last_X = 0;
    int last_vX = 0;
    Word* next = nullptr;
    Word* prev = nullptr;
    Word* ref = nullptr;

public:
    Word()
    {
        vX[0] = &X[0];
        vY[0] = &vX[0];
        vZ[0] = &vY[0];
    }

    int* out();

    void set_X(char c, int i);
    void set_vX(int v, int i);

    void set_vXY(int x, int y);
    void set_vYZ(int y, int z);

    void set_state(int i);
    int get_state();


    //set index
    void set_iY(int y);
    void set_iX(int x);
    void set_iZ(int z);
    void set_iXYZ(int x, int y, int z);

    //get pointers

    int get_X(int i);
    int* get_vX();
    int* get_vX(int i);
    int** get_vY();
    int** get_vY(int i);
    int*** get_vZ();
    int*** get_vZ(int i);

    int get_iX();
    int get_iY();
    int get_iZ();
    void set_last_X(int xx);
    void set_last_vX(int vv);
    int get_last_vX();
    bool check_condition(int i, int c);
    //get and set the next and prev pointer
    Word* get_next();
    Word* get_prev();
    Word* get_ref();

    void set_next(Word* w);
    void set_prev(Word* w);
    void set_ref(Word* w);

    //void set_word(void(*f)(Word& w));
    std::string get_out();
    void code_vectors();

};

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

int* Word::out(){return vZ[iZ][iY][iX];}

void Word::set_X(char c, int i) { X[i] = c;}
void Word::set_last_X(int xx){last_X = xx;}
void Word::set_last_vX(int vv) {last_vX = vv;}
void Word::set_vX(int v, int i) {vX[v] = &X[i];}
void Word::code_vectors() {


    int* code = vX[last_vX];
    int code_index = 0;
    int** temp_vX = new int * [last_vX];
    int size_of_X = code[code_index++];
    int size_of_Y = code[code_index++];
    int size_of_Z = code[code_index++];
    for (int i = 0; i < last_vX; i++) temp_vX[i] = vX[i];
    for (int i = 0; i < size_of_X; i++) vX[i] = temp_vX[code[code_index++]];
    for (int i = 0; i < size_of_Y; i++) vY[i] = &vX[code[code_index++]];
    for (int i = 0; i < size_of_Z; i++) vZ[i] = &vY[code[code_index++]];
    delete[] temp_vX;
    last_vX = code[0];
}

//link vectors
void Word::set_vXY(int x, int y) { vY[y] = &vX[x]; }
void Word::set_vYZ(int y, int z) { vZ[z] = &vY[y]; }

//set/get state
void Word::set_state(int i) { state = i; }
int Word::get_state() { return state; }


//set index
void Word::set_iY(int y) { iY = y; }
void Word::set_iX(int x) { iX = x; }
void Word::set_iZ(int z) { iZ = z; }
void Word::set_iXYZ(int x, int y, int z)
{
    iX = x;
    iY = y;
    iZ = z;
}

//get pointers

int Word::get_X(int i) { return *X + i; }
int* Word::get_vX() { return vX[iX]; }
int* Word::get_vX(int i) { return vX[i]; }
int** Word::get_vY() { return vY[iY]; }
int** Word::get_vY(int i) { return vY[i]; }
int*** Word::get_vZ() { return vZ[iY]; }
int*** Word::get_vZ(int i) { return vZ[i]; }

int Word::get_iX() { return iX; }
int Word::get_iY() { return iY; }
int Word::get_iZ() { return iZ; }
int Word::get_last_vX() { return last_vX; }
bool Word::check_condition(int i, int c)
{
    if (*vX[i] == c)return true;
    else return false;
}

//get and set the next and prev pointer

Word* Word::get_next() { return next;}
Word* Word::get_prev() { return prev; }
Word* Word::get_ref() { return ref; }


void Word::set_next(Word* w){ next = w;}
void Word::set_prev(Word* w) { prev = w; }
void Word::set_ref(Word* w) {ref = w;}

 std::string Word::get_out()
{
    std::string temp = "";
    std::string temp_p = "";
    std::string temp_n = "";
    if (prev)
    {
        Word* p = get_prev();
        temp_p = p->get_out();
    }
    if (next)
    {
        Word* n = get_next();
        temp_n = n->get_out();
    }
    std::stringstream ss;
    ss << out();
    temp = ss.str();
    
    return temp_p + temp + temp_n;
}
