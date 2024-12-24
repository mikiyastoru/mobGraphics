#include<GL/glut.h>

GLint px = 320;
GLint py = 240;
GLint ps = 10;

void myInit() {
    glClearColor(0.5, 0.5, 0.5, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 680, 680, 0);
}

void NormalKey(unsigned char key, int x, int y) {
    switch (key) {
        case 'A': case 'a':
            px -= 5;
            break;
        case 'D': case 'd':
            px += 5;
            break;
        case 'W': case 'w':
            py -= 5;
            break;
        case 'X': case 'x':
            py += 5;
            break;
    }
    glutPostRedisplay();
}

void mySpecialKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            px -= 5;
            break;
        case GLUT_KEY_RIGHT:
            px += 5;
            break;
        case GLUT_KEY_UP:
            py -= 5;
            break;
        case GLUT_KEY_DOWN:
            py += 5;
            break;
    }
    glutPostRedisplay();
}

void myMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        px -= 2;
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        px += 2;
    }
    glutPostRedisplay();
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glPointSize(ps);
    glBegin(GL_POINTS);
    glVertex2i(px, py);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Interactive Point Movement");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(NormalKey);
    glutSpecialFunc(mySpecialKey);
    glutMouseFunc(myMouse);
    myInit();
    glutMainLoop();

    return 0;
}
