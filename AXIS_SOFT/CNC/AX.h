#ifndef AX_H_INCLUDED
#define AX_H_INCLUDED

class AXA{

public:
float A=0;
float AI=0;
float AS=0;
float AR=0;
};

class AXS{


public:
float S=0;
};

class AXNF{
public:
float NF;
float NFI;
float N;
float NI;
};

class AXH{

char AXd [729];
char AXi [729];
int idse;
int idsmi;
int idsmd;
public:
bool EME=false;
bool RES=false;

bool inst=false;

float FedR;
float timet;
float XFedR;
float YFedR;
float ZFedR;
float FX;
float FY;
float FZ;

float AXNW=0;

float MXS=0;
float CSS=0;

const int MaxFR=450;
int MinFR;
int CompFR;

AXA X;
AXA Y;
AXA Z;
AXA S;

AXA F;

AXS RPM;
AXS T;
AXS WAT;
AXS db;
AXS XF;
AXS YF;
AXS ZF;
AXS SF;

AXNF XN;
AXNF YN;
AXNF ZN;
AXA AN;

AXH(){}

AXH(int idset,int idsmit,int idsmdt){
idse=idset;idsmi=idsmit;idsmd=idsmdt;

for(int i=0;i<729;i++)AXd[i]=0;
for(int i=0;i<729;i++)AXi[i]=0;
strncpy(AXd,RSMD(idsmd,idse),sizeof(AXd));

strncpy(AXi,RSMI(idsmi,idse),sizeof(AXi));
X.AI=GETGDR("X",AXi,X.AI);
Y.AI=GETGDR("Y",AXi,Y.AI);
Z.AI=GETGDR("Z",AXi,Z.AI);

F.AI=GETGDR("T",AXi,F.AI);

S.AI=GETGDR("S",AXi,S.AI);
}

void wss(){
 std::ofstream DS;
  DS.open ("DSS.txt");
  DS << AXd;
  DS.close();

   std::ofstream IS;
  IS.open ("ISS.txt");
  IS << AXi;
  IS.close();
}

void rss(){
std::ifstream DS;
DS.open ("DSS.txt", std::ios::in|std::ios::ate);
  if (DS.is_open())
  {
    //size = DS.tellg();

    DS.seekg (0, std::ios::beg);
    DS.read (AXd, 729);
    DS.close();
}

std::ifstream IS;
IS.open ("ISS.txt", std::ios::in|std::ios::ate);
  if (IS.is_open())
  {
    //size = IS.tellg();

    IS.seekg (0, std::ios::beg);
    IS.read (AXi, 729);
    IS.close();
}
WSMD(AXd,idsmd,idse);
WSMI(AXi,idsmi,idse);
}

void uD(){
strncpy(AXd,RSMD(idsmd,idse),sizeof(AXd));

X.A=GETGDR("X",AXd,X.A);
Y.A=GETGDR("Y",AXd,Y.A);
Z.A=GETGDR("Z",AXd,Z.A);
S.A=GETGDR("S",AXd,S.A);

F.A=GETGDR("T",AXd,F.A);
//F.A=FedR;

RPM.S=GETGDR("S",AXd,RPM.S);
WAT.S=GETGDR("P",AXd,WAT.S);
T.S=GETGDR("C",AXd,T.S);
db.S=GETGDR("D",AXd,T.S);

}

void rD(){
strncpy(AXd,RSMD(idsmd,idse),sizeof(AXd));

X.A=GETGDR("X",AXd,X.A);
Y.A=GETGDR("Y",AXd,Y.A);
Z.A=GETGDR("Z",AXd,Z.A);
S.A=GETGDR("S",AXd,S.A);

F.A=GETGDR("T",AXd,F.A);
//F.A=FedR;

RPM.S=GETGDR("R",AXd,RPM.S);
WAT.S=GETGDR("P",AXd,WAT.S);
T.S=GETGDR("C",AXd,T.S);
db.S=GETGDR("D",AXd,T.S);

}

void wD(){

X.A=roundf(X.A * 200) / 200.0;
Y.A=roundf(Y.A * 200) / 200.0;
Z.A=roundf(Z.A * 200) / 200.0;
S.A=roundf(S.A * 1000) / 1000.0;

strncpy(AXd,ADDGDS(AXd,"X",X.A),sizeof(AXd));
strncpy(AXd,ADDGDS(AXd,"Y",Y.A),sizeof(AXd));
strncpy(AXd,ADDGDS(AXd,"Z",Z.A),sizeof(AXd));

strncpy(AXd,ADDGDS(AXd,"T",F.A),sizeof(AXd));

strncpy(AXd,ADDGDS(AXd,"S",S.A),sizeof(AXd));

//std::cout<<AXi<< std::endl;



//S.AI/=100;

WSMD(AXd,idsmd,idse);
//std::cout<<RSMI(idsmi,idse)<< std::endl;
//std::cout<<RSMD(idsmd,idse)<< std::endl;
}



void uI(){
if(EME){
strncpy(AXi,ADDGDS(AXi,"X",X.A),sizeof(AXi));
strncpy(AXi,ADDGDS(AXi,"Y",Y.A),sizeof(AXi));
strncpy(AXi,ADDGDS(AXi,"Z",Z.A),sizeof(AXi));
//strncpy(AXd," stop ",sizeof(AXd));
}
else if(RES){
//strncpy(AXd," reset ",sizeof(AXd));
}
else{
strncpy(AXi,ADDGDS(AXi,"X",X.AI),sizeof(AXi));
strncpy(AXi,ADDGDS(AXi,"Y",Y.AI),sizeof(AXi));
strncpy(AXi,ADDGDS(AXi,"Z",Z.AI),sizeof(AXi));

if(F.AI<0)F.AI=0;
strncpy(AXi,ADDGDS(AXi,"T",F.AI),sizeof(AXi));

if(S.AI<0)S.AI=0;
strncpy(AXi,ADDGDS(AXi,"S",S.AI),sizeof(AXi));


}
//std::cout<<AXi<< std::endl;
X.AI=roundf(X.AI * 200) / 200.0;
Y.AI=roundf(Y.AI * 200) / 200.0;
Z.AI=roundf(Z.AI * 200) / 200.0;


//S.AI/=100;

WSMI(AXi,idsmi,idse);
//std::cout<<RSMI(idsmi,idse)<< std::endl;
//std::cout<<RSMD(idsmd,idse)<< std::endl;
}
void rI(){
strncpy(AXi,RSMI(idsmi,idse),sizeof(AXi));

if(GETC("stop",AXi)){
X.AI=X.A;
Y.AI=Y.A;
Z.AI=Z.A;
}

else{
X.AI=GETGDR("X",AXi,X.AI);
Y.AI=GETGDR("Y",AXi,Y.AI);
Z.AI=GETGDR("Z",AXi,Z.AI);}
S.AI=GETGDR("S",AXi,S.AI);

F.AI=GETGDR("T",AXi,F.AI);
if(F.AI<0)F.AI=0;

//F.A=FedR;

X.AI=roundf(X.AI * 200) / 200.0;
Y.AI=roundf(Y.AI * 200) / 200.0;
Z.AI=roundf(Z.AI * 200) / 200.0;
//S.AI=roundf(S.AI * 1000) / 1000.0;
}

void wI(){

X.AI=roundf(X.AI*200)/200.0;
Y.AI=roundf(Y.AI*200)/200.0;
Z.AI=roundf(Z.AI*200)/200.0;
//S.AI=roundf(S.AI*1000)/1000.0;

if(EME){
strncpy(AXd,"stop",sizeof(AXd));
}
else if(RES){
strncpy(AXd,"reset",sizeof(AXd));
}
else{
strncpy(AXi,ADDGDS(AXi,"X",X.AI),sizeof(AXi));
strncpy(AXi,ADDGDS(AXi,"Y",Y.AI),sizeof(AXi));
strncpy(AXi,ADDGDS(AXi,"Z",Z.AI),sizeof(AXi));

if(F.AI<0)F.AI=0;
strncpy(AXi,ADDGDS(AXi,"T",F.AI),sizeof(AXi));

//if(S.AI<0)S.AI=0;
//strncpy(AXi,ADDGDS(AXi,"S",S.AI),sizeof(AXi));
}
//std::cout<<AXi<< std::endl;



//S.AI/=100;

WSMI(AXi,idsmi,idse);
//std::cout<<RSMI(idsmi,idse)<< std::endl;
//std::cout<<RSMD(idsmd,idse)<< std::endl;
}

void i(){
if(FPC(X.A,X.AI,0.01)&&FPC(Y.A,Y.AI,0.01)&&FPC(Z.A,Z.AI,0.01)){
inst= true;}
else{inst= false;}
}

void smx(){
if(CSS!=S.AI){CSS=S.AI;MXS=0;}
else if(MXS<RPM.S){MXS=RPM.S;}

//if(RPM.S<=MXS-sens){EME=true;}
//else{EME=false;}


if(FedR!=0){
if(XFedR!=0)XN.NF=XFedR/FedR;else XN.NF= 0;
if(YFedR!=0)YN.NF=YFedR/FedR;else YN.NF= 0;
if(ZFedR!=0)ZN.NF=ZFedR/FedR;else ZN.NF= 0;
}
else{
//XN.NF=0;
//YN.NF=0;
//ZN.NF=0;
}
//XN.NF=XFedR*std::abs(MXS-RPM.S);
//YN.NF=YFedR*MXS-RPM.S;
//ZN.NF=ZFedR*MXS-RPM.S;

AN.A=abs(MXS-RPM.S);
AN.A*=0.01;

//AN.A*=(XN.NF*1)+(YN.NF*0.8)+(ZN.NF*0.4);

AXNW=abs(MXS-RPM.S);
AXNW*=0.01;

}


};

#endif
