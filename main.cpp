#include <GL/glut.h>
#include <stdio.h>
#include "event_handler.hpp"

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