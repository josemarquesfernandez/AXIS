#pragma once

// Including SDKDDKVer.h defines the highest available Windows platform.

// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.

#include <SDKDDKVer.h>
#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <tchar.h>
#include <windows.h>


#include <SDL.h>
//#include "C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINET/COMMON_AXLIBST/RESORUCES/3D/GLee.h"
#include <iostream>


#include<SDL_image.h>
#include<SDL_ttf.h>

//#include <GL/glew.h>




#include <SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

//#include <assimp/Importer.hpp>
#include <assimp/cimport.h>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags


#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>


//Screen dimension constants
#define _USE_MATH_DEFINES

int SCREEN_WIDTH = 1100;
int SCREEN_HEIGHT = 650;

int mosx, mosy, mosdx, mosdy;
int moscx, moscy;
bool rclick = false;
bool lclick = false;
bool mclick = false;
bool released = false;

SDL_GLContext gContext;

SDL_Event e;

const SDL_Color AXgreen = { 9,203,177 };
const SDL_Color AXwhite = { 230,230,230 };
const SDL_Color AXgrey = { 120,120,120 };
const SDL_Color AXblack = { 5,5,5 };


#include "SISTEM\AXFPL.h"
#include "GRAPHICS\AXGL.h"
#include "AXLIB\SISTEM\AXSML.h"

#include "CNC\AX.h"
#include "AI\AXAI.h"

#include "GRAPHICS\AXUIU.h"
#include "GRAPHICS\AXUI.h"
#include "GRAPHICS\AX3DL.h"


float angle = 0.0;

bool pattern = false;
float sensib = 0;
float power = 0;
int timee = 0;

int _tmain(int argc, _TCHAR* argv[]) {

	//struct aiLogStream stream;

	SDL_Window* Window = NULL;
	bool run = true;
	int idse = ISE();
	int idsmi = ISMI();
	int idsmd = ISMD();

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);

	AXH AXIS(idse, idsmi, idsmd);
	AXIS.rss();
	//AXIS.wD();
	//AXIS.uI();
	//AXIS.uD();
	//AXIS.rI();

	AXAI AXIA(AXIS);

	struct ICONST icon;

	AXTOP TOP;

	AXD ALL; ALL.pos[0] = 1000; ALL.pos[1] = 800;

	AXV X(AXIS.X, "X"); X.pos[0] = 800; X.pos[1] = 800;
	AXV Y(AXIS.Y, "Y"); Y.pos[0] = 800; Y.pos[1] = 700;
	AXV Z(AXIS.Z, "Z"); Z.pos[0] = 800; Z.pos[1] = 600;
	AXV T(AXIS.F, "T"); T.pos[0] = 0; T.pos[1] = 0; AXIS.F.AI = 800;
	T.step = 1;
	AXV S(AXIS.S, "S"); S.pos[0] = 0; S.pos[1] = 60;//AXIS.F.AI=800;
	S.step = 0.000100;

	AXV N(AXIS.AN, "N"); N.pos[0] = 0; N.pos[1] = 120;//AXIS.F.AI=800;
	N.step = 0.00100;

	AXG G(AXIS); G.pos[0] = 1000; G.pos[1] = 110;
	AXGRF ALLGRF; ALLGRF.pos[0] = 1000; ALLGRF.pos[1] = 0;


	G.open("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/CNC/GCODE/10021.txt");



	timer AXtime;

	//Use OpenGL 3.1 core
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	//SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

	Window = SDL_CreateWindow("AXIS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED
		, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	SDL_SetWindowMinimumSize(Window, 320, 480);



	//SDL_SetWindowBordered(Window,SDL_FALSE);
	SDL_SetWindowIcon(Window, icon.AXISAPP);
	SDL_GL_SetSwapInterval(1);
	gContext = SDL_GL_CreateContext(Window);
	glClearColor(0.05, 0.05, 0.05, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, SCREEN_WIDTH / SCREEN_HEIGHT, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	//glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	float l0pos[] = { 20,20,20,1 };

	glLightfv(GL_LIGHT0, GL_POSITION, l0pos);
	float ldif[] = { 1.0,0.9,1.0,1.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, ldif);
	//float lamb[]={0.2,0.2,0.2,1.0};
	//glLightfv(GL_LIGHT0,GL_AMBIENT,lamb);

	TTF_Font *Dfont = TTF_OpenFont("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/FONTS/HelveticaLTStd-Roman.otf", 40);
	TTF_Font *Mfont = TTF_OpenFont("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/FONTS/HelveticaLTStd-Roman.otf", 27);
	TTF_Font *Ifont = TTF_OpenFont("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/FONTS/HelveticaLTStd-Roman.otf", 25);
	TTF_Font *Sfont = TTF_OpenFont("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/FONTS/HelveticaLTStd-Roman.otf", 18);

	//int model=loadObject("AX3D/test.obj");
	gpath gpathu;
	gpathu.u(G.memblock);

	ocam camera;
	//initv();
	//init();

	//TDSCEN MPRIM;
	//MPRIM.TDI("RESORUCES/3D/untitled.blend");

	//TDSCEN TOOL;
	//TOOL.TDI("C:/Users/Jose/Documents/MARQ/AXIS_SOFT_PROJECT/AXIS_ENGINE/COMMON_AXLIBS/RESORUCES/3D/tool.blend");
	float toolr = 0;

	SDL_StartTextInput();



	while (run)
	{
		AXtime.get();

		AXIS.uD();

		AXIA.u();


		AXIS.uI();

		AXIS.i();

		//if(TOP.object.click){

		//if(AXIS.inst){
		//if(AXIS.X.A-X.cerop<50)AXIS.X.AI=100+X.cerop;
		//else AXIS.X.AI=0+X.cerop;
		//AXIS.Z.AI-=0.005;
		//}}

		/*if(TOP.object.click){

		if(AXIS.inst){
		if(AXIS.Y.A-Y.cerop<20){AXIS.Y.AI=40+Y.cerop;AXIS.Z.AI-=0.25;}
		else {AXIS.Y.AI=0+Y.cerop; }

		}*/



		/*
		if(AXIS.AN.A<=AXIS.AN.AI+10){
		if(AXIS.inst){
		//if(pattern){AXIS.X.AI+=10; pattern=false;patterny=true;}
		if(AXIS.Z.A-X.cerop>-15){AXIS.S.AI=0.125;AXIS.Z.AI-=0.2;}
		else {AXIS.Z.AI=3+X.cerop;AXIS.S.AI=0.0;pattern=true;}
		//AXIS.Z.AI-=0.005;
		}}

		if(AXIS.AN.A==AXIS.AN.AI+7){
		if(AXIS.inst){
		//if(pattern){AXIS.X.AI+=10; pattern=false;patterny=true;}
		if(AXIS.Z.A-X.cerop>-15){AXIS.S.AI=0.125;AXIS.Z.AI-=0.1;}
		else {AXIS.Z.AI=3+X.cerop;AXIS.S.AI=0.0;pattern=true;}
		//AXIS.Z.AI-=0.005;
		}}*/




		/*if(AXIS.AN.A<=AXIS.AN.AI){
		if(AXIS.inst){
		//if(pattern){AXIS.X.AI+=10; pattern=false; patterny=true;}
		if(AXIS.Z.A-X.cerop>-11){power=AXIS.S.AI;AXIS.Z.AI-=0.05;if(timee==0)timee=AXIS.F.AI;AXIS.F.AI=timee;}
		else {AXIS.Z.AI=3+X.cerop;AXIS.S.AI=0.0;pattern=true;sensib=AXIS.AN.AI;AXIS.AN.AI=200;AXIS.F.AI=0;}
		//AXIS.Z.AI-=0.005;
		}}

		if(AXIS.S.AI<0.5&&AXIS.Z.A>2){if(pattern){AXIS.X.AI+=10; pattern=false;patterny=true;}}

		if(patterny&&AXIS.Z.A>2)
		{AXIS.S.AI=power;patterny=false;AXIS.AN.AI=sensib;
		//if(pattern){AXIS.X.AI+=10; pattern=false;patterny=true;}
		}*/

		/*
		if(TOP.object.click){

		if(AXIS.inst){
		if(AXIS.Y.A-Y.cerop<5&&AXIS.X.A-X.cerop<5){AXIS.Y.AI=7.5+Y.cerop;AXIS.X.AI=-7.5+X.cerop;}
		else if(AXIS.Y.A-Y.cerop>-5&&AXIS.X.A-X.cerop<5){AXIS.X.AI=7.5+X.cerop;}
		else if(AXIS.Y.A-Y.cerop>-5&&AXIS.X.A-X.cerop>-5){AXIS.Y.AI=-7.5+Y.cerop;}
		else if(AXIS.Y.A-Y.cerop<5&&AXIS.X.A-X.cerop>-5){AXIS.X.AI=-7.5+X.cerop;}
		}

		}
		*/


		/*if(TOP.object.click){

		if(AXIS.inst){
		if(AXIS.Y.A-Y.cerop<100&&AXIS.X.A-X.cerop<100){AXIS.Y.AI=120+Y.cerop;AXIS.X.AI=50+X.cerop;}
		else if(AXIS.Y.A-Y.cerop>100&&AXIS.X.A-X.cerop<100){AXIS.X.AI=450+X.cerop;}
		else if(AXIS.Y.A-Y.cerop>100&&AXIS.X.A-X.cerop>100){AXIS.Y.AI=40+Y.cerop;}
		else if(AXIS.Y.A-Y.cerop<100&&AXIS.X.A-X.cerop>100){AXIS.X.AI=50+X.cerop;}
		}

		}*/


		if (TOP.object.click) {
			if (AXIS.inst) {
				if (pattern) { AXIS.X.AI -= 10; pattern = false; pattern = true; AXIS.F.AI = 1000; }
				if (AXIS.Z.A - Z.cerop>-15) { AXIS.Z.AI -= 0.2; AXIS.F.AI = 15000; }
				else { AXIS.Z.AI = 3 + Z.cerop; pattern = true; AXIS.F.AI = 1000; }

			}
		}


		AXIS.smx();

		//std::cout << AXIS.AXi<< std::endl;
		//std::cout << RSMI(idsmi,idse)<< std::endl;

		if (AXIS.FX != AXIS.X.A || AXIS.FY != AXIS.Y.A || AXIS.FZ != AXIS.Z.A) {
			AXIS.timet = AXtime.stopt();

			AXIS.XFedR = AXIS.X.A - AXIS.FX;
			AXIS.XFedR = std::abs(AXIS.XFedR);
			//std::cout<<AXIS.XFedR<< std::endl;
			AXIS.XFedR *= 60000 / AXIS.timet;

			AXIS.YFedR = std::abs(AXIS.FY - AXIS.Y.A);
			//std::cout<<AXIS.YFedR<< std::endl;
			AXIS.YFedR *= 60000 / AXIS.timet;

			AXIS.ZFedR = std::abs(AXIS.FZ - AXIS.Z.A);
			//std::cout<<AXIS.ZFedR<< std::endl;
			AXIS.ZFedR *= 60000 / AXIS.timet;

			AXIS.FedR = AXIS.XFedR + AXIS.YFedR + AXIS.ZFedR;
			//std::cout<<AXIS.FedR<< std::endl;
			AXIS.FX = AXIS.X.A;
			AXIS.FY = AXIS.Y.A;
			AXIS.FZ = AXIS.Z.A;

			AXtime.startt();

		}
		else {
			//AXIS.XFedR=0;
			//AXIS.YFedR=0;
			//AXIS.ZFedR=0;
			//AXIS.FedR=0;
		}


		AXtime.getframerate();
		ALL.AXFRAMERATE = AXtime.framerate;
		ALLGRF.u(AXtime.framerate, AXIS.S.A, AXIS.T.S);//esto ay que cambiarlo
		ALL.updateData(AXIS);

		X.u();
		Y.u();
		Z.u();

		G.u(X.cerop, Y.cerop, Z.cerop);

		T.u();
		S.u();
		N.u();


		camera.u();



		mosdx = mosx; mosdy = mosy;
		moscx = 0; moscy = 0;





		while (SDL_PollEvent(&e) != 0) {

			if (e.type == SDL_MOUSEWHEEL) {
				if (e.wheel.type) {
					moscx = e.wheel.x;
					moscy = e.wheel.y;
				}
			}
			SDL_GetMouseState(&mosx, &mosy);
			mosy = SCREEN_HEIGHT - mosy;


			if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
				lclick = true; rclick = false; mclick = false;
			}
			else if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
				rclick = true; lclick = false; mclick = false;
			}
			else if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE)) {
				mclick = true; rclick = false; lclick = false;
			}
			else { rclick = false; lclick = false; mclick = false; }


			if (e.type == SDL_TEXTINPUT) {
				//T.edit=e.edit.text;
				strcat(T.edit, e.text.text);
				//T.edit= e.text.text;
			}


			//  if( e.type == SDL_MOUSEBUTTONUP ){
			//released=true;       }else {released=false;}

			if (e.type == SDL_WINDOWEVENT) {
				switch (e.window.event) {
				case SDL_WINDOWEVENT_RESIZED:

					wrespar(X.bon, X.rpos, X.pos);
					wrespar(Y.bon, Y.rpos, Y.pos);
					wrespar(Z.bon, Z.rpos, Z.pos);
					wrespar(ALL.bon, ALL.rpos, ALL.pos);

					SCREEN_WIDTH = e.window.data1;
					SCREEN_HEIGHT = e.window.data2;
					glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

					wrpopar(X.bon, X.rpos, X.pos);
					wrpopar(Y.bon, Y.rpos, Y.pos);
					wrpopar(Z.bon, Z.rpos, Z.pos);
					wrpopar(ALL.bon, ALL.rpos, ALL.pos);


					/*
					case SDL_WINDOWEVENT_SHOWN:
					SDL_Log("Window %d shown", event->window.windowID);
					break;
					case SDL_WINDOWEVENT_HIDDEN:
					SDL_Log("Window %d hidden", event->window.windowID);
					break;
					case SDL_WINDOWEVENT_EXPOSED:
					SDL_Log("Window %d exposed", event->window.windowID);
					break;
					case SDL_WINDOWEVENT_MOVED:
					SDL_Log("Window %d moved to %d,%d",
					event->window.windowID, event->window.data1,
					event->window.data2);
					break;
					case SDL_WINDOWEVENT_RESIZED:
					SDL_Log("Window %d resized to %dx%d",
					event->window.windowID, event->window.data1,
					event->window.data2);
					break;
					case SDL_WINDOWEVENT_MINIMIZED:
					SDL_Log("Window %d minimized", event->window.windowID);
					break;
					case SDL_WINDOWEVENT_MAXIMIZED:
					SDL_Log("Window %d maximized", event->window.windowID);
					break;
					case SDL_WINDOWEVENT_RESTORED:
					SDL_Log("Window %d restored", event->window.windowID);
					break;
					case SDL_WINDOWEVENT_ENTER:
					SDL_Log("Mouse entered window %d",
					event->window.windowID);
					break;
					case SDL_WINDOWEVENT_LEAVE:
					SDL_Log("Mouse left window %d", event->window.windowID);
					break;
					case SDL_WINDOWEVENT_FOCUS_GAINED:
					SDL_Log("Window %d gained keyboard focus",
					event->window.windowID);
					break;
					case SDL_WINDOWEVENT_FOCUS_LOST:
					SDL_Log("Window %d lost keyboard focus",
					event->window.windowID);
					break;
					case SDL_WINDOWEVENT_CLOSE:
					SDL_Log("Window %d closed", event->window.windowID);
					break;
					default:
					SDL_Log("Window %d got unknown event %d",
					event->window.windowID, event->window.event);
					break;*/
				}

			}

			//User requests quit
			if (e.type == SDL_QUIT)
			{
				run = false;
				break;
			}
		}




		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 1.0f, 10000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//displaym(model);

		camera.d();

		glDisable(GL_LIGHTING);
		gpathu.d();

		glLineWidth(3);
		glColor3f(0.98, 0.31, 0.08);
		glBegin(GL_LINES);
		glVertex3f(AXIS.X.A - X.cerop, AXIS.Y.A - Y.cerop, AXIS.Z.A - Z.cerop);
		glVertex3f(AXIS.X.AI - X.cerop, AXIS.Y.AI - Y.cerop, AXIS.Z.AI - Z.cerop);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		glEnable(GL_LIGHTING);

		glTranslatef((AXIS.X.A - X.cerop), (AXIS.Y.A - Y.cerop), (AXIS.Z.A - Z.cerop));

		glScalef(50, 50, 50);
		//display();
		//MPRIM.TDD();
		glScalef(0.1, 0.1, 0.1);



		toolr += AXIS.S.A;
		glRotatef(toolr*0.1, 0, 0, 1);
		//TOOL.TDD();
		
		


		glLoadIdentity();

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, ((float)SCREEN_WIDTH), 0, ((float)SCREEN_HEIGHT), -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);

		//comprobando colisiones entre ALL y X;

		X.collision = false; Y.collision = false; Z.collision = false; ALL.collision = false; G.collision = false;

		if (colldet(X.bon, X.pos, X.isdragg, Y.bon, Y.pos, Y.isdragg)) { X.collision = true; Y.collision = true; }
		if (colldet(X.bon, X.pos, X.isdragg, Z.bon, Z.pos, Z.isdragg)) { X.collision = true; Y.collision = true; }
		if (colldet(Z.bon, Z.pos, Z.isdragg, Y.bon, Y.pos, Y.isdragg)) { Z.collision = true; Y.collision = true; }
		if (colldet(ALL.bon, ALL.pos, ALL.isdragg, X.bon, X.pos, X.isdragg)) { X.collision = true; ALL.collision = true; }
		if (colldet(ALL.bon, ALL.pos, ALL.isdragg, Y.bon, Y.pos, Y.isdragg)) { ALL.collision = true; Y.collision = true; }
		if (colldet(ALL.bon, ALL.pos, ALL.isdragg, Z.bon, Z.pos, Z.isdragg)) { ALL.collision = true; Z.collision = true; }

		if (colldet(G.bon, G.pos, G.isdragg, X.bon, X.pos, X.isdragg)) { X.collision = true; G.collision = true; }
		if (colldet(G.bon, G.pos, G.isdragg, Y.bon, Y.pos, Y.isdragg)) { G.collision = true; Y.collision = true; }
		if (colldet(G.bon, G.pos, G.isdragg, Z.bon, Z.pos, Z.isdragg)) { G.collision = true; Z.collision = true; }
		if (colldet(G.bon, G.pos, G.isdragg, ALL.bon, ALL.pos, ALL.isdragg)) { G.collision = true; ALL.collision = true; }


		TOP.draw(icon, Ifont, AXgrey);

		ALL.d(icon, Mfont, Ifont, AXgreen, AXgrey, AXwhite);
		ALLGRF.d(icon, Mfont, Ifont, AXgreen, AXgrey, AXwhite);
		G.d(icon, Mfont, Ifont, Sfont, AXgreen, AXgrey, AXwhite);

		X.d(icon, Dfont, Ifont, AXgreen, AXgrey, AXwhite);
		Y.d(icon, Dfont, Ifont, AXgreen, AXgrey, AXwhite);
		Z.d(icon, Dfont, Ifont, AXgreen, AXgrey, AXwhite);
		T.d(icon, Dfont, Ifont, AXgreen, AXgrey, AXwhite);
		S.d(icon, Dfont, Ifont, AXgreen, AXgrey, AXwhite);
		N.d(icon, Dfont, Ifont, AXgreen, AXgrey, AXwhite);

		SDL_GL_SwapWindow(Window);
	}



	//clean();
	//delete scene;
	SDL_DestroyWindow(Window);

	IMG_Quit();	SDL_Quit();	TTF_Quit();
	AXIS.wss();
	std::cout << "exit" << std::endl; return 0;
}
