#include <GL/glut.h>
#include <stdio.h>
//float angle=0;
float oldX=0,angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(0.8,0,0);
        glRotated(angle++,0,0,1);
        glScalef(0.3,0.3,0.3);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 mouse glscalef");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
