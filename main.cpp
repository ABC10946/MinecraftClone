#include <GL/glut.h>
#include <stdio.h>

double vertices[][3] = {
	//前面
	{-0.5, -0.5, -0.5},
	{0.5, -0.5, -0.5},
	{0.5, 0.5, -0.5},
	{-0.5, 0.5, -0.5},

	//後面
	{-0.5, 0.5, 0.5},
	{0.5, 0.5, 0.5},
	{0.5, -0.5, 0.5},
	{-0.5, -0.5, 0.5},

	//右横
	{0.5, -0.5, 0.5},
	{0.5, -0.5, -0.5},
	{0.5, 0.5, -0.5},
	{0.5, 0.5, 0.5},

	//左面
	{-0.5, -0.5, 0.5},
	{-0.5, -0.5, -0.5},
	{-0.5, 0.5, -0.5},
	{-0.5, 0.5, 0.5},

	//上面
	{-0.5, -0.5, -0.5},
	{0.5, -0.5, -0.5},
	{0.5, -0.5, 0.5},
	{-0.5, -0.5, 0.5},

	//下面
	{-0.5, 0.5, -0.5},
	{0.5, 0.5, -0.5},
	{0.5, 0.5, 0.5},
	{-0.5, 0.5, 0.5}
};

double tx = 0.0;
double ty = 0.0;
double tz = 0.0;
double rx = 0.0;
double ry = 0.0;
double rz = 0.0;

double rgb[6][3] = {
	{0.0, 0.0, 1.0},
	{0.0, 1.0, 0.0},
	{0.0, 1.0, 1.0},
	{1.0, 0.0, 0.0},
	{1.0, 0.0, 1.0},
	{1.0, 1.0, 0.0}
};

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	glTranslated(0.0, 0.0, -5.0);
	glTranslated(tx, ty, tz);
	glRotated(rx, 1.0, 0.0, 0.0);
	glRotated(ry, 0.0, 1.0, 0.0);
	glRotated(rz, 0.0, 0.0, 1.0);

	glBegin(GL_QUADS);

	for(int i=0; i< 6; i++) {
		double r = rgb[i][0];
		double g = rgb[i][1];
		double b = rgb[i][2];
		glColor3d(r, g, b);
		for (int j=0; j < 4; j++) {
			int startIdx = i * 4;
			glVertex3dv(vertices[j + startIdx]);
		}
	}
	glEnd();
	glFlush();
}

void resize(int w, int h) {
	printf("%d, %d\n", w, h);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	gluPerspective(30.0, (double)w/(double)h, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 'w':
			tz -= 0.01;
			break;
		case 'a':
			tx -= 0.01;
			break;
		case 's':
			tz += 0.01;
			break;
		case 'd':
			tx += 0.01;
			break;
		case 'e':
			ty -= 0.01;
			break;
		case 'q':
			ty += 0.01;
			break;
		case 'x':
			rx += 2.0;
			break;
		case 'y':
			ry += 2.0;
			break;
		case 'z':
			rz += 2.0;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

void init(void) {
	glClearColor(0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);

	glutInitWindowSize(320, 240);

	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}