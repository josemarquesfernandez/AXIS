#ifndef AXGL_H_INCLUDED
#define AXGL_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>

float GETGDS  (std::string id,char* in )     {
float result;
char* dat = new char[9];for(int w=0;w<9;w++)dat[w]=0;
std::stringstream inst;
inst<<in;
while (inst!=0){
std::string a;
inst>>a;
     if (a.compare(0,1,id) == 0){
     a.erase(0,1);
     strcpy(dat, a.c_str());
         result=strtod (dat,0);
         delete [] dat;
         return result; }
}}

float GETGDR  (std::string id,char* in,float cur )     {
char* dat = new char[9];for(int w=0;w<9;w++)dat[w]=0;
float result;
std::stringstream inst;
inst<<in;
while (inst!=0){
std::string a;
inst>>a;
     if (a.compare(0,1,id) == 0){
     a.erase(0,1);
     strcpy(dat, a.c_str());
result=strtod (dat,0);
         delete [] dat;
         return result; }
}return cur;}


bool GETC  (std::string cmd,char* in )  {
std::stringstream inst;
inst<<in;
while (inst!=0){
std::string a;
inst>>a;
     if (a.compare(cmd) == 0)return true;
    else return false;
}}


const char *ADDGDS (char* current,std::string id,float data){
char* dat = new char[10];for(int w=0;w<10;w++)dat[w]=0;
char *idt = new char[1];
strcpy(idt, id.c_str());
bool exist=false;
std::stringstream in;
in<<current;
std::stringstream out;
while (in!=0){
std::string a;
in>>a;
     if (a.compare(0,1,id) == 0){
     exist=true;
     a.clear();
  int c = snprintf ( dat, 10, "%s%f", idt, data );
  out<<dat<<" ";
 }
     else{out<<a<<" ";}
}
if(!exist){
int c = snprintf ( dat, 10, "%s%f", idt, data );
  out<<dat<<" ";
}
const std::string tmp = out.str();
const char* cstr = tmp.c_str();
//std::string s = out.str();
//p = s.c_str();
delete []dat;
delete [] idt;
return cstr;
}

#endif // AXGL_H_INCLUDED
