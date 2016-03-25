#include "obj.h"

capitoshka kap;


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.6, 0.8, 0.8, 0.9);//цвет фона
	glPushMatrix();
	glOrtho(-zoom, zoom, -zoom, zoom, -180, 180);//постраение камеры(как далеко)
	gluLookAt(0, 2, 10, 0, 0, 0, 0, 1, 0); //положение камеры
	glViewport(-50, -164, 500, 500);//размеры сцены
	
	kap.draw();
	
	glPopMatrix();
	glFlush();//вывод на экран с буфера
}

int main(int argc, char **argv){
	float pos[4] = { 56, 113, 30, -10 };
	float dir[3] = { -1, -1, -1 };
	
	
	glutInitWindowSize(400, 300);//размеры приложения
	glutInit(&argc, argv);//по умолчанию нужно
	glutCreateWindow("Капитошка");//заголовок
	glutKeyboardFunc(&keyboard_handler);

	glutReshapeFunc(&resize_window);//функци создания матрицы сцены(3D или 2D)
	glutDisplayFunc(&display);//функция прорисовки
	glutTimerFunc(40, &Timer, 0);//таймер

	glutSpecialFunc(pressKey);//нажатия кнокпи
	glutIgnoreKeyRepeat(0);
	glutSpecialUpFunc(releaseKey);
	

	//все для сцены
	glShadeModel(GL_SMOOTH);//подели теней гладкие;
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
	glEnable(GL_LIGHTING); // здесь включается расчет освещения 
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE); // делаем так, чтобы освещались обе стороны полигона
	glEnable(GL_NORMALIZE); //делам нормали одинаковой величины во избежание артефактов
	glutMainLoop();
	return 1;
}

void keyboard_handler(unsigned char key, int x, int y) {

	do {
		if (key == 'z'){
			zoom -= 4;
			break;
		}
		if (key == 'x'){
			zoom += 4;
			break;
		}
		if (key == '+'){
			if (kap.forsage == 5)break;
			kap.forsage++;
			break;
		}
		if (key == '-'){
			if (kap.forsage == 1)break;
			kap.forsage--;
			break;
		}
	} while (0);
}

void Timer(int value){
	glutPostRedisplay();
	glutTimerFunc(40, Timer, 0);
}


void resize_window(int width, int height) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void releaseKey(int key, int x, int y) {
	
	switch (key) {
	case GLUT_KEY_LEFT:kap.go_left = false; break;
	case GLUT_KEY_RIGHT:kap.go_right = false; break;
	case GLUT_KEY_UP: kap.go_up = false;  break;
	case GLUT_KEY_DOWN: kap.go_down = false;  break;

	case GLUT_KEY_PAGE_DOWN:kap.rotate_left = false; break;
	case GLUT_KEY_PAGE_UP:kap.rotate_right = false; break;
	}
}


void pressKey(int key, int xx, int yy) {

	switch (key) {
	case GLUT_KEY_LEFT:kap.go_left = true; break;
	case GLUT_KEY_RIGHT:kap.go_right = true;  break;
	case GLUT_KEY_UP: kap.go_up = true;  break;
	case GLUT_KEY_DOWN: kap.go_down = true; break;

	case GLUT_KEY_PAGE_DOWN:kap.rotate_left = true;break;
	case GLUT_KEY_PAGE_UP:kap.rotate_right = true; break;
	}
}