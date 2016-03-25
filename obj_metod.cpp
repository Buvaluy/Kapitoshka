#include "obj.h"
#include <iostream>
using namespace std;
void capitoshka::draw(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	if (this->rotate_left == true){ this->rotate_right = false; this->rotate_angel += 2; }
	if (this->rotate_right == true){ this->rotate_left = false; this->rotate_angel -= 2; }
	
	if (this->steps_a == 20 && this->a_plus == false){ this->a_plus = true; this->steps_a = 0; }
	if (this->steps_a == 20 && this->a_plus == true){ this->a_plus = false; this->steps_a = 0; }
	if (go_left == true){ this->x_left_rigth -= 0.2*this->forsage; this->look_left = true; this->look_right = false; this->look_down = false; this->look_up = false; }
	if (go_right == true){ this->x_left_rigth += 0.2*this->forsage; this->look_right = true; this->look_left = false; this->look_down = false; this->look_up = false; }
	if (go_up == true){ this->z_up_down -= 0.4*this->forsage; this->look_up = true; this->look_right = false; this->look_left = false; this->look_down = false; }
	if (go_down == true){ this->z_up_down += 0.4*this->forsage; this->look_down = true; this->look_left = false; this->look_right = false; this->look_up = false; }
	///////////////////////////
	if (this->rotate_left==true || this->rotate_right==true){ this->look_left = false; this->look_right = false; this->look_up = false; this->look_down = false;}
	////
	if (this->a_plus == true){ this->y_a_body = this->y_a_body + 0.4; }
	if (this->a_plus == false){ this->y_a_body = this->y_a_body - 0.4; }

	glPushMatrix();
	glTranslated(this->x_left_rigth, 0, this->z_up_down);//перемещение оси координат к рисунку
	glRotated(this->rotate_angel, 0, 1, 0);//поворот на месте
	glTranslated(-this->x_left_rigth, 0, -this->z_up_down);//перемещение на исходное место

	glPushMatrix();
	
	glTranslated(this->x_left_rigth, 0, this->z_up_down);

	if (look_down == true || look_left == true || look_right == true || look_up == true){ glRotated(this->rotate_angel*-1, 0, 1, 0);this->rotate_angel=0; }
	if (look_left == true && look_up == false && look_down == false && look_right == false){ this->rotate_for_go = -90; glRotated(this->rotate_for_go, 0, 1, 0); }
	if (look_right == true && look_up == false && look_down == false && look_left == false){ this->rotate_for_go = 90; glRotated(this->rotate_for_go, 0, 1, 0); }
	if (look_up == true && look_left == false && look_down == false && look_right == false){ this->rotate_for_go = 180; glRotated(this->rotate_for_go, 0, 1, 0); }
	

	glPushMatrix();
	glTranslated(0, this->y_a_body, 0);
	//тело
	glColor3d(0.019, 0.57, 0.96);
	glPushMatrix();
	glTranslated(0, 15, 0);
	glutSolidSphere(5, 30, 30);
	glPopMatrix();

	//шапка
	glColor3d(0.019, 0.1, 0.5);
	glPushMatrix();
	glScaled(0.9, 0.2, 0.8);
	glTranslated(0, 99, 0);
	glutSolidSphere(4, 30, 30);
	glPopMatrix();
	//круг на шапку
	glColor3d(0.9, 0.1, 0.8);
	glPushMatrix();
	glTranslated(0, 21, 0);
	glutSolidSphere(0.8, 30, 30);
	glPopMatrix();
	
	//глаза левый
	glColor3d(1, 1, 1);
	glPushMatrix();
	glTranslated(-1.5, 16.5, 4.3);
	glutSolidSphere(0.9, 20, 20);
	glPopMatrix();
	//зрачок
	glColor3d(0, 0, 0);
	glPushMatrix();
	glTranslated(-1.5, 16.5, 5);
	glutSolidSphere(0.3, 30, 30);
	glPopMatrix();
	//глаза правый
	glColor3d(1, 1, 1);
	glPushMatrix();
	glTranslated(1.5, 16.5, 4.3);
	glutSolidSphere(0.9, 20, 20);
	glPopMatrix();
	//зрачек 
	glColor3d(0, 0, 0);
	glPushMatrix();
	glTranslated(1.5, 16.5, 5);
	glutSolidSphere(0.3, 30, 30);
	glPopMatrix();

	glPopMatrix();
	///////////////////////////
	
	
	//типо нога
	if (this->a_plus == true){ this->y_a_leg1 = this->y_a_leg1 + 0.4; }
	if (this->a_plus == false){ this->y_a_leg1 = this->y_a_leg1 - 0.4; }
	glColor3d(0.8, 0.8, 0.016);
	glPushMatrix();
	glTranslated(0, this->y_a_leg1, 0);
	glutSolidSphere(1.5, 30, 30);
	glPopMatrix();
	//
	if (this->a_plus == true){ this->y_a_leg2 = this->y_a_leg2 + 0.25; }
	if (this->a_plus == false){ this->y_a_leg2 = this->y_a_leg2 - 0.25; }
	glColor3d(0.019, 0.77, 0.96);
	glPushMatrix();
	glTranslated(0, this->y_a_leg2, 0);
	glutSolidSphere(0.8, 30, 30);
	glPopMatrix();
	//
	if (this->a_plus == true){ this->y_a_leg3 = this->y_a_leg3 + 0.15; }
	if (this->a_plus == false){ this->y_a_leg3 = this->y_a_leg3 - 0.15; }
	glColor3d(0.019, 0.57, 0.96);
	glPushMatrix();
	glTranslated(0, this->y_a_leg3, 0);
	glutSolidSphere(0.5, 30, 30);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	///////////////////////////////
	//дорога(пол)
	glColor3f(0.2, 0.73, 0.1);
	glPushMatrix();
	for (int k = 0,coll=1; k <= 400; k += 10,coll++){
		if (coll == 2){ coll = 0; }
		for (int i = 0, col = 1; i <= 400; i += 10){
			if (coll==1){
				if (col == 1){ glColor3f(0.9, 0.9, 0.9); col = 0; }
				else{ glColor3f(0.2, 0.2, 0.2); col = 1; }
			}
			else{
				if (col == 0){ glColor3f(0.9, 0.9, 0.9); col = 1; }
				else{ glColor3f(0.2, 0.2, 0.2); col = 0; }
			}
			glBegin(GL_QUADS);
			glVertex3f(-205 + i, -1, -200 + k);
			glVertex3f(-205 + i, -1, -190 + k);
			glVertex3f(-195 + i, -1, -190 + k);
			glVertex3f(-195 + i, -1, -200 + k);
			glEnd();
		}
	}
	glPopMatrix();


	this->steps_a++;
	glPopMatrix();
}