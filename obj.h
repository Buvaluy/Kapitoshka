#include <glut.h>
static int zoom = 31;

void keyboard_handler(unsigned char key, int x, int y);
void display();
void resize_window(int width, int height);
void Timer(int value);
void releaseKey(int key, int x, int y);
void pressKey(int key, int xx, int yy);



 class capitoshka{
 public:
	 void draw();//функция рисовки/анимации
	 void game_score();
	 
	 float y_a_body = 0;//анимация тела по Y(прыгает верх вниз тело)
	 float y_a_leg1 = 8;//анимация верхнего кружка(желтый)
	 float y_a_leg2 = 5;//анимация среднего кружка(желтый)
	 float y_a_leg3 = 3;//анимация нижнего кружка(желтый)
	 int forsage = 1;//скорость передвижения
	 int steps_a = 0;//количество шагов для опускания и подымания
	 float x_left_rigth=0;//передвижение по оси X (стрелочки лево право)
	 float z_up_down = 0;//передвижения по оси Z (стрелочки верх вниз)
	 float rotate_angel = 0;//поворот влева вправо Pg_UP,Pg_Down
	 float rotate_for_go = 0;


	 bool a_plus = false;//прыжок(подьем) вверх или вниз. true вверх
	 bool a_x_go = false;//идти в лево-право или нет
	 bool a_z_go = false;//идти в вверх-вниз или нет
	 bool go_left = false;
	 bool look_left = false;
	 bool go_right = false;
	 bool look_up = false;
	 bool go_up = false;
	 bool look_right = false;
	 bool go_down= false;
	 bool look_down = false;

	 bool rotate_right = false;//поворот вправо(Pg_up)
	 bool rotate_left = false;
 };




 