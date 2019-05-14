#ifndef AXUIU_H_INCLUDED
#define AXUIU_H_INCLUDED

const float aureal = 1.618033988;

void drawRect(float sizex, float sizey) {
	glDisable(GL_LIGHTING);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 1); glVertex2f(0.0, 0.0);
	glTexCoord2d(1, 1); glVertex2f(sizex, 0.0);

	glTexCoord2d(1, 0); glVertex2f(sizex, sizey);

	glTexCoord2d(0, 0); glVertex2f(0.0, sizey);
	glColor3f(1.0, 1.0, 1.0);
	glEnd();
	glEnable(GL_LIGHTING);
}

struct ICONS {
	SDL_Surface * axisAPP = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/AXISAPP.png");
	SDL_Surface * axisICO = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/AXISLOGO.png");

	SDL_Surface * newwIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/NEWw.png");
	SDL_Surface * openwIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/OPENw.png");
	SDL_Surface * savewIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/SAVEw.png");

	SDL_Surface * playwIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/PLAYw.png");
	SDL_Surface * pausewIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/PAUSEw.png");
	SDL_Surface * reverswIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/REVERSw.png");
	SDL_Surface * rewindwIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/REWINDw.png");
	SDL_Surface * recIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/REC.png");
	SDL_Surface * reloadwIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/RELOADw.png");

	SDL_Surface * verifIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/VERF.png");
	SDL_Surface * manualIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/MANUAL.png");
	SDL_Surface * meIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/-.png");
	SDL_Surface * resIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/RECOR.png");
	SDL_Surface * maIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/+.png");

	SDL_Surface * verifwIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/VERFw.png");
	SDL_Surface * mewIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/-w.png");
	SDL_Surface * reswIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/RECORw.png");
	SDL_Surface * rewIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/REw.png");
	SDL_Surface * mawIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/+w.png");

	SDL_Surface * moveIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/MOVEw.png");
	SDL_Surface * opIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/OPw.png");
	SDL_Surface * xIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/Xw.png");
	SDL_Surface * ublockIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/UNBLOKw.png");

	SDL_Surface * scroleIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/SCROLE.png");
	SDL_Surface * scrolitIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/SCROLIT.png");
	SDL_Surface * scrolibIC = IMG_Load("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/ICONS/SCROLIB.png");
};

SDL_Surface * AICON(SDL_Surface* ico) {
	SDL_Surface *IC = SDL_ConvertSurfaceFormat(
		ico, SDL_PIXELFORMAT_ABGR8888, 0);
	SDL_FreeSurface(ico);
	return IC;
}

struct ICONST {
	struct ICONS icono;
	SDL_Surface *AXISAPP = AICON(icono.axisAPP);
	SDL_Surface *AXISICO = AICON(icono.axisICO);

	SDL_Surface * NEWICw = AICON(icono.newwIC);
	SDL_Surface * OPENICw = AICON(icono.openwIC);
	SDL_Surface * SAVEICw = AICON(icono.savewIC);

	SDL_Surface *VERFIC = AICON(icono.verifIC);
	SDL_Surface *MANUALIC = AICON(icono.manualIC);
	SDL_Surface *MEIC = AICON(icono.meIC);
	SDL_Surface *RESIC = AICON(icono.resIC);
	SDL_Surface *MAIC = AICON(icono.maIC);

	SDL_Surface *VERFICw = AICON(icono.verifwIC);
	SDL_Surface *MEICw = AICON(icono.mewIC);
	SDL_Surface *RESICw = AICON(icono.reswIC);
	SDL_Surface * REICw = AICON(icono.rewIC);
	SDL_Surface *MAICw = AICON(icono.mawIC);

	SDL_Surface * PLAYICw = AICON(icono.playwIC);
	SDL_Surface * PAUSEICw = AICON(icono.pausewIC);
	SDL_Surface * REVERSICw = AICON(icono.reverswIC);
	SDL_Surface * REWINDICw = AICON(icono.rewindwIC);
	SDL_Surface * RECIC = AICON(icono.recIC);
	SDL_Surface * RELOADICw = AICON(icono.reloadwIC);

	SDL_Surface *MOVEIC = AICON(icono.moveIC);
	SDL_Surface *OPIC = AICON(icono.opIC);
	SDL_Surface *XIC = AICON(icono.xIC);
	SDL_Surface *UBLOCKIC = AICON(icono.ublockIC);

	SDL_Surface * SCROLEIC = AICON(icono.scroleIC);
	SDL_Surface * SCROLITIC = AICON(icono.scrolitIC);
	SDL_Surface * SCROLIBIC = AICON(icono.scrolibIC);
};





class image{
public:
float scale=0.5;
int bon[2];

void draw(SDL_Surface* msg) {
    GLuint img;
    glGenTextures(1, &img);
    glBindTexture(GL_TEXTURE_2D, img);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, msg->w, msg->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, msg->pixels);

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    glDisable(GL_LIGHTING);
   glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

glPushMatrix();
    glScalef(scale,scale,scale);
    glBegin(GL_QUADS);

    glTexCoord2d(0, 1); glVertex2f(0.0, 0.0);
    glTexCoord2d(1, 1); glVertex2f(msg->w, 0.0);
    glTexCoord2d(1, 0); glVertex2f(msg->w, msg->h);
    glTexCoord2d(0, 0); glVertex2f(0.0, msg->h);
bon[0]=msg->w*scale;bon[1]=msg->h*scale;
    glEnd();

glPopMatrix();
    glDeleteTextures(1, &img);
    glEnable(GL_LIGHTING);
    glDisable(GL_BLEND);
    //SDL_FreeSurface( msg );
}
};

class text{
public:
float scale=0.5;
int bon[2];
int width=150;

void draw(TTF_Font* font, SDL_Color color ,const char* text ) {
    SDL_Surface* msg =TTF_RenderText_Blended_Wrapped( font, text, color ,width/scale);
    GLuint tex;
    glGenTextures( 1, &tex );
    glBindTexture( GL_TEXTURE_2D, tex );

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, msg->w, msg->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, msg->pixels );
     bon[0]=msg->w*scale;bon[1]=msg->h*scale;
    glDisable(GL_LIGHTING);
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glBindTexture(GL_TEXTURE_2D, tex );
glPushMatrix();

    glScalef(scale,scale,scale);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 1); glVertex2f(0.0, 0.0);
    glTexCoord2d(1, 1); glVertex2f(msg->w, 0.0);
    glTexCoord2d(1, 0); glVertex2f(msg->w, msg->h);
    glTexCoord2d(0, 0); glVertex2f(0.0, msg->h);
    glEnd();

glPopMatrix();
    glDeleteTextures(1, &tex);
    glEnable(GL_LIGHTING);
    glDisable(GL_BLEND);
    SDL_FreeSurface( msg );
    }
};

class button{
GLfloat mtxpos[16];
bool bk=false;

public:
image im;
text tx;
float scale=0.5;
int bon[4]={0,0,0,0};

bool over=false;
bool click=false;
bool bkclick=false;

void btstyle(){
if(over){
    glColor3f(0.4,0.4,0.4);
    glPushMatrix();glTranslatef(bon[1]-bon[0],0.0,0.0);
drawRect(bon[0]-bon[1],-1);glPopMatrix();}

if(click){
    glColor3f(0.7,0.9,0.05);
    glPushMatrix();glTranslatef(bon[1]-bon[0],0.0,0.0);
drawRect(bon[0]-bon[1],-1);glPopMatrix();}}


void stbutt(){
if(( mosx > bon[0] ) && ( mosx < bon[1] ) && ( mosy > bon[2] ) && ( mosy < bon[3] ) ){
over=true;}else{over=false;}
if(over&&lclick){click=true;}else{click=false;}

}

void bkbutt(){
bkclick=false;
if(( mosx > bon[0] ) && ( mosx < bon[1] ) && ( mosy > bon[2] ) && ( mosy < bon[3] ) ){
over=true;}else{over=false;}

if(!click&&!lclick){bk=false;}
else if(click&&!lclick){bk=true;}

if(over&&lclick&&!bk){bkclick=true;click=true;}
else if(over&&lclick&&bk){click=false;}
}

void swbutt(bool group){
if(( mosx > bon[0] ) && ( mosx < bon[1] ) && ( mosy > bon[2] ) && ( mosy < bon[3] ) ){
over=true;}else{over=false;}
if(over&&lclick){click=true;}//else{click=false;}
if(lclick&&!over&&group){click=false;}
}

void dIBKB(SDL_Surface* msg){
im.scale=scale;
im.draw(msg);
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
bon[0]=mtxpos[12];
bon[2]=mtxpos[13];
bon[1]=bon[0]+im.bon[0];bon[3]=bon[2]+im.bon[1];
bkbutt();
btstyle();
}

void dISTB(SDL_Surface* msg){
im.scale=scale;
im.draw(msg);
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
bon[0]=mtxpos[12];
bon[2]=mtxpos[13];
bon[1]=bon[0]+im.bon[0];bon[3]=bon[2]+im.bon[1];
stbutt();
btstyle();
}

void dTSWB(TTF_Font* font, SDL_Color color ,const char* mnsg,bool group){
tx.draw(font,color,mnsg);
tx.scale=scale;
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
bon[0]=mtxpos[12];
bon[2]=mtxpos[13];
bon[1]=bon[0]+tx.bon[0];bon[3]=bon[2]+tx.bon[1];
swbutt(group);
btstyle();
 //SDL_Log("BUT %dx%dx%dx%d",bon[0],bon[1],bon[2],bon[3]);
  //SDL_Log("MOS %dx%d",mosx,mosy);
}

void dTBKB(TTF_Font* font, SDL_Color color ,const char* mnsg){
tx.draw(font,color,mnsg);
tx.scale=scale;
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
bon[0]=mtxpos[12];
bon[2]=mtxpos[13];
bon[1]=bon[0]+tx.bon[0];bon[3]=bon[2]+tx.bon[1];
bkbutt();
btstyle();
 //SDL_Log("BUT %dx%dx%dx%d",bon[0],bon[1],bon[2],bon[3]);
  //SDL_Log("MOS %dx%d",mosx,mosy);
}

void dTSTB(TTF_Font* font, SDL_Color color ,const char* mnsg){
tx.draw(font,color,mnsg);
tx.scale=scale;
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
bon[0]=mtxpos[12];
bon[2]=mtxpos[13];
bon[1]=bon[0]+tx.bon[0];bon[3]=bon[2]+tx.bon[1];
stbutt();
btstyle();
 //SDL_Log("BUT %dx%dx%dx%d",bon[0],bon[1],bon[2],bon[3]);
  //SDL_Log("MOS %dx%d",mosx,mosy);
}

void dragB(TTF_Font* font, SDL_Color color ,SDL_Color coloro,SDL_Color colorc,const char* mnsg){
tx.scale=scale;

if(over&&!click){
    tx.draw(font,coloro,mnsg);}

else if(click){
tx.draw(font,colorc,mnsg);}

else{
tx.draw(font,color,mnsg);

}

glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
bon[0]=mtxpos[12];
bon[2]=mtxpos[13];
bon[1]=bon[0]+tx.bon[0];bon[3]=bon[2]+tx.bon[1];

if(( mosx > bon[0] ) && ( mosx < bon[1] ) && ( mosy > bon[2] ) && ( mosy < bon[3] ) ){
over=true;}else{over=false;}
if(over&&lclick){click=true;}//else{click=false;}
if(!lclick){click=false;}

}
};

class sedtext{
GLfloat mtxpos[15];

public:
text tx;
float scale=0.5;
int bon[4]={0,0,0,0};

float data;
float inst;

bool over=false;
bool click=false;
char etext[15];


void sbutt(){
if(( mosx > bon[0] ) && ( mosx < bon[1] ) && ( mosy > bon[2] ) && ( mosy < bon[3] ) ){
over=true;}else{over=false;}
if(over&&lclick){click=true;}
if(lclick&&!over){click=false;}
}

void btstyle(){
if(over){
//std::cout<<"shit"<<std::endl;
    glColor3f(0.4,0.4,0.4);

drawRect(bon[1]-bon[0],1);}

if(click){
    glColor3f(0.7,0.9,0.05);

drawRect(bon[1]-bon[0],1);}}



void d(TTF_Font* font, SDL_Color color ){
tx.scale=scale;
tx.draw(font,color,etext);
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
bon[0]=mtxpos[12];
bon[2]=mtxpos[13];
bon[1]=bon[0]+tx.bon[0];bon[3]=bon[2]+tx.bon[1];
sbutt();
btstyle();

}
};

class etext{
GLfloat mtxpos[15];

public:
text tx;
float scale=0.5;
int width;
int bon[4]={0,0,0,0};

float data;
float inst;

bool over=false;
bool click=false;
char *etextc;


void sbutt(){
if(( mosx > bon[0] ) && ( mosx < bon[1] ) && ( mosy > bon[2] ) && ( mosy < bon[3] ) ){
over=true;}else{over=false;}
if(over&&lclick){click=true;}
if(lclick&&!over){click=false;}
}

void btstyle(){
if(over){
    glColor3f(0.4,0.4,0.4);
    glPushMatrix();glTranslatef(bon[1]-bon[0],1.0,0.0);
drawRect(bon[0]-bon[1],1);glPopMatrix();}

if(click){
    glColor3f(0.7,0.9,0.05);
    glPushMatrix();glTranslatef(bon[1]-bon[0],1.0,0.0);
drawRect(bon[0]-bon[1],1);glPopMatrix();}}



void d(TTF_Font* font, SDL_Color color,char *text ){
tx.scale=scale;
tx.width=width;
tx.draw(font,color,text);
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
bon[0]=mtxpos[12];
bon[2]=mtxpos[13];
bon[1]=bon[0]+tx.bon[0];bon[3]=bon[2]+tx.bon[1];
sbutt();
btstyle();

}
};






class scroll{
GLfloat mtxpos[15];

public:
image down;
image up;
image mup;
image mdw;

bool click=false;

int height=123;
int siz=50;
float scale=0.5;
double perc=0;
float pos=0;
double sensibility=0.5;

bool upov=false;
bool updw=false;

bool dwov=false;
bool dwdw=false;

bool dbov=false;
bool dbdw=false;

float Bon[4];

float dwbut[4];
float upbut[4];
float barrbut[4];

void dd(SDL_Surface* msg){
down.scale=scale;
down.draw(msg);
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
dwbut[0]=mtxpos[12];
dwbut[2]=mtxpos[13];
dwbut[1]=dwbut[0]+down.bon[0];dwbut[3]=dwbut[2]+down.bon[1];
}

void du(SDL_Surface* msg){
up.scale=scale;
up.draw(msg);
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
upbut[0]=mtxpos[12];
upbut[2]=mtxpos[13];
upbut[1]=upbut[0]+up.bon[0];upbut[3]=upbut[2]+up.bon[1];
}

void dm(SDL_Surface* msd,SDL_Surface* msu){

glPushMatrix();
glTranslatef(0,pos,0.0);
mup.scale=scale;
mup.draw(msd);
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
barrbut[0]=mtxpos[12];
barrbut[2]=mtxpos[13];
//barrbut[1]=barrbut[0]+mup.bon[0];barrbut[3]=barrbut[2]+mup.bon[1];

glTranslatef(0.0,siz,0.0);

mdw.scale=scale;
mdw.draw(msu);
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
barrbut[1]=mtxpos[12]+mdw.bon[0];
barrbut[3]=mtxpos[13]+mdw.bon[1];

glPopMatrix();

glPushMatrix();
glTranslatef(1.5,pos+8,0.0);
glDisable(GL_LIGHTING);
glBegin(GL_QUADS);
glColor3f(0.45,0.45,0.45);
glTexCoord2d(0, 1); glVertex2f(0.0, 0.0);
glTexCoord2d(1, 1); glVertex2f(7, 0.0);
glTexCoord2d(1, 0); glVertex2f(7, siz-8);
glTexCoord2d(0, 0); glVertex2f(0.0, siz-8);
glColor3f(1.0,1.0,1.0);
glEnd();
glEnable(GL_LIGHTING);
glPopMatrix();
}

void clicks(){
if(( mosx > barrbut[0] ) && ( mosx < barrbut[1] ) && ( mosy > barrbut[2] ) && ( mosy < barrbut[3] ) ){
dbov=true;}else{dbov=false;}
if(dbov&&lclick){dbdw=true;}//else{click=false;}
if(!lclick){dbdw=false;}

if(( mosx > upbut[0] ) && ( mosx < upbut[1] ) && ( mosy > upbut[2] ) && ( mosy < upbut[3] ) ){
upov=true;}else{upov=false;}
if(upov&&lclick){updw=true;}//else{click=false;}
if(!lclick){updw=false;}

if(( mosx > dwbut[0] ) && ( mosx < dwbut[1] ) && ( mosy > dwbut[2] ) && ( mosy < dwbut[3] ) ){
dwov=true;}else{dwov=false;}
if(dwov&&lclick){dwdw=true;}//else{click=false;}
if(!lclick){dwdw=false;}
}

void sf (){
clicks();
if(dbdw){
click=true;
perc-=((mosy-mosdy))/(440*scale);}
else if(dwdw){
click=true;
perc+=sensibility;}

else if(updw){
click=true;
perc-=sensibility;}

else{
click=false;}

//std::cout<<perc<<std::endl;
if(perc>1){perc=1;}
else if(perc<0){perc=0;}

pos=((1-perc)*(height*scale))+4;


}

void d(struct ICONST icon){
sf();

glPushMatrix();
dd(icon.SCROLEIC);
glTranslatef(0.0,height+24,0.0);
du(icon.SCROLEIC);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,pos,0.0);
dm(icon.SCROLIBIC,icon.SCROLITIC);
glPopMatrix();
}
};










class scrollold{
GLfloat mtxpos[15];

public:
image down;
image up;
image mup;
image mdw;

bool click=false;

int height=123;
int siz=50;
float scale=0.5;
double perc=0;
float pos=11;
float sensibility=0.5;

bool upov=false;
bool updw=false;

bool dwov=false;
bool dwdw=false;

bool dbov=false;
bool dbdw=false;

float Bon[4];

float dwbut[4];
float upbut[4];
float barrbut[4];

void dd(SDL_Surface* msg){
down.scale=scale;
down.draw(msg);
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
dwbut[0]=mtxpos[12];
dwbut[2]=mtxpos[13];
dwbut[1]=dwbut[0]+down.bon[0];dwbut[3]=dwbut[2]+down.bon[1];
}

void du(SDL_Surface* msg){
up.scale=scale;
up.draw(msg);
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
upbut[0]=mtxpos[12];
upbut[2]=mtxpos[13];
upbut[1]=upbut[0]+up.bon[0];upbut[3]=upbut[2]+up.bon[1];
}

void dm(SDL_Surface* msd,SDL_Surface* msu){

glPushMatrix();
glTranslatef(0,pos,0.0);
mup.scale=scale;
mup.draw(msd);
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
barrbut[0]=mtxpos[12];
barrbut[2]=mtxpos[13];
//barrbut[1]=barrbut[0]+mup.bon[0];barrbut[3]=barrbut[2]+mup.bon[1];

glTranslatef(0.0,siz,0.0);

mdw.scale=scale;
mdw.draw(msu);
glGetFloatv(GL_MODELVIEW_MATRIX, mtxpos);
barrbut[1]=mtxpos[12]+mdw.bon[0];
barrbut[3]=mtxpos[13]+mdw.bon[1];

glPopMatrix();

glPushMatrix();
glTranslatef(1.5,pos+8,0.0);
glDisable(GL_LIGHTING);
glBegin(GL_QUADS);
glColor3f(0.45,0.45,0.45);
glTexCoord2d(0, 1); glVertex2f(0.0, 0.0);
glTexCoord2d(1, 1); glVertex2f(7, 0.0);
glTexCoord2d(1, 0); glVertex2f(7, siz-8);
glTexCoord2d(0, 0); glVertex2f(0.0, siz-8);
glColor3f(1.0,1.0,1.0);
glEnd();
glEnable(GL_LIGHTING);
glPopMatrix();
}

void sf (){
perc=(pos-4)/(height*scale-siz*scale-16*scale);

if(perc>1){pos-=0.1;}
else if(perc<0){pos+=0.1;}

else{

if(( mosx > barrbut[0] ) && ( mosx < barrbut[1] ) && ( mosy > barrbut[2] ) && ( mosy < barrbut[3] ) ){
dbov=true;}else{dbov=false;}
if(dbov&&lclick){dbdw=true;}//else{click=false;}
if(!lclick){dbdw=false;}

if(( mosx > upbut[0] ) && ( mosx < upbut[1] ) && ( mosy > upbut[2] ) && ( mosy < upbut[3] ) ){
upov=true;}else{upov=false;}
if(upov&&lclick){updw=true;}//else{click=false;}
if(!lclick){updw=false;}

if(( mosx > dwbut[0] ) && ( mosx < dwbut[1] ) && ( mosy > dwbut[2] ) && ( mosy < dwbut[3] ) ){
dwov=true;}else{dwov=false;}
if(dwov&&lclick){dwdw=true;}//else{click=false;}
if(!lclick){dwdw=false;}


if(dbdw){
click=true;
pos=pos+((mosy-mosdy)*scale);}

else if(dwdw){
click=true;
pos-=sensibility;}


else if(updw){
click=true;
pos+=sensibility;}

else{
click=false;}
}
}

void d(struct ICONST icon){
sf();

glPushMatrix();
dd(icon.SCROLEIC);
glTranslatef(0.0,height,0.0);
du(icon.SCROLEIC);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0,pos,0.0);
dm(icon.SCROLIBIC,icon.SCROLITIC);
glPopMatrix();
}
};



void dragpan(bool click,float pos[2]){
if(click){
pos[0]=pos[0]+(mosx-mosdx);
pos[1]=pos[1]-(mosdy-mosy);

}

}

void wcolldet(float bon[4],float pos[2]){
if(bon[0]<0){pos[0]=0;}
if(bon[1]>SCREEN_WIDTH){pos[0]=SCREEN_WIDTH-(bon[1]-bon[0]);}
if(bon[2]<0){pos[1]=0;}
if(bon[3]>SCREEN_HEIGHT-50){pos[1]=(SCREEN_HEIGHT-50)-(bon[3]-bon[2]);}
}


bool colldet(float bon1[4],float pos1[2],bool click1,float bon2[4],float pos2[2],bool click2){
if(((bon1[0]-bon2[1]<0)&&(bon1[1]-bon2[0]>0))&&((bon1[2]-bon2[3]<0)&&(bon1[3]-bon2[2]>0))){


if(abs(bon1[0]-bon2[0])>abs(bon1[2]-bon2[2])){

if(bon1[0]-bon2[0]<0){
if(click1){pos2[0]+=bon1[1]-bon2[0];}
else if(click2){pos1[0]-=bon1[1]-bon2[0];}
else{pos2[0]+=bon1[1]-bon2[0];pos1[0]-=bon1[1]-bon2[0];}
}
else{
if(click1){pos2[0]-=bon2[1]-bon1[0];}
else if(click2){pos1[0]+=bon2[1]-bon1[0];}
else{pos2[0]-=bon2[1]-bon1[0];pos1[0]+=bon2[1]-bon1[0];}
}
}

else{

if(bon1[2]-bon2[2]<0){
if(click1){pos2[1]+=bon1[3]-bon2[2];}
else if(click2){pos1[1]-=bon1[3]-bon2[2];}
else{pos2[1]+=bon1[3]-bon2[2];pos1[1]-=bon1[3]-bon2[2];}
}
else{
if(click1){pos2[1]-=bon2[3]-bon1[2];}
else if(click2){pos1[1]+=bon2[3]-bon1[2];}
else{pos2[1]-=bon2[3]-bon1[2];pos1[1]+=bon2[3]-bon1[2];}
}
}
return true;}

else{return false;}

}

void wrespar(float bon[4],double rpos[2],float pos[2]){
rpos[0]=pos[0]/SCREEN_WIDTH;
rpos[1]=pos[1]/SCREEN_HEIGHT;
if (rpos[0]>0.75){rpos[0]=1;}
if(rpos[1]>0.75){rpos[1]=1;}
if (rpos[0]<0.25){rpos[0]=0;}
if(rpos[1]<0.25){rpos[1]=0;}
}

void wrpopar(float bon[4],double rpos[2],float pos[2]){
pos[0]=SCREEN_WIDTH*rpos[0];
pos[1]=SCREEN_HEIGHT*rpos[1];
}



class timer{
Uint32 ticks;
Uint32 start;

Uint32 frames;
Uint32 framee;


public:
Uint32 frame;
Uint32 framerate;
Uint32 elapse;

void get(){
ticks=SDL_GetTicks();
frame++;
if (ticks>2147480000){ticks=0;}
if (frame>2147480000){frame=0;}
}

void getframerate(){

if(frame>1){
framee=ticks-frames;
frames=ticks;
frame=0;}
framerate=framee;
}

void startt(){
start=ticks;
}

float stopt(){
elapse=ticks-start;
return elapse;}
};


class gline{

float maximun;
float minimun;
float rel;

int ndata=300;
float var;

public:
int width=300;
float height=50;
float *points;
float color[3];

gline(){
    points = new float [width];
}

~gline(){
 delete[] points;
}

void u(float variable){
maximun=0;
minimun=80;
var=variable;
if(ndata>0)ndata--;else{}
points[299]=var;
for (int i=0;i<300;i++){
points[i]=points[i+1];
if(points[i]>maximun){maximun=points[i];rel=height/maximun;}
if(points[i]<minimun){minimun=points[i];}
//points[i]=height/points[i];points[i]=points[i]/rel;
//points[i]=((height/points[i])/height)*1000;
}

}

void d(){

glLineWidth(1);
glColor3f(color[0], color[1], color[2]);
glBegin(GL_LINES);

//for(int i=0;i<sizeof(ypoints);i+=width/sizeof(ypoints)){
for(int i=1;i<299;i++){
if(points[i]==0){}
else{
glVertex3f(i, (points[i])*rel, 0.0);
glVertex3f(i+1, (points[i-1])*rel, 0.0);
}

}

glEnd();
}
};


#endif
