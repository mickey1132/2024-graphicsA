#include <GL/glut.h>
#include <math.h>
void display()
{
    glBegin(GL_POLYGON);
        for(float a=0;a<=3.1415926*2;a+=0.001)
            {
                glVertex2f(cos(a),sin(a));
            }
    glEnd();
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week02_circle");
    glutDisplayFunc(display);

    glutMainLoop();
}
