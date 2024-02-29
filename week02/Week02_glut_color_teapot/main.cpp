#include <GL/glut.h>
void display()
{
    glColor3f(122/255.0,146/255.0,190/255.0);
    glutSolidTeapot(0.3);
    glColor3f(191/255.0,255/255.0,255/255.0);
    glutSolidTeapot(0.2);
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week02_color_teapot");
    glutDisplayFunc(display);

    glutMainLoop();
}
