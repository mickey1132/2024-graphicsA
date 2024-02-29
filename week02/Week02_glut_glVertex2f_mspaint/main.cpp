#include <GL/glut.h>
void display()
{
    glBegin(GL_POLYGON);
        glVertex2f((85-200)/200.0,-(88-200)/200.0);
        glVertex2f((95-200)/200.0,-(48-200)/200.0);
        glVertex2f((134-200)/200.0,-(12-200)/200.0);
        glVertex2f((168-200)/200.0,-(13-200)/200.0);
        glVertex2f((193-200)/200.0,-(32-200)/200.0);
        glVertex2f((205-200)/200.0,-(59-200)/200.0);
        glVertex2f((210-200)/200.0,-(65-200)/200.0);
        glVertex2f((213-200)/200.0,-(68-200)/200.0);
        glVertex2f((214-200)/200.0,-(77-200)/200.0);
        glVertex2f((221-200)/200.0,-(84-200)/200.0);

    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f((383-200)/200.0,-(79-200)/200.0);
        glVertex2f((348-200)/200.0,-(146-200)/200.0);
        glVertex2f((312-200)/200.0,-(55-200)/200.0);
    glEnd();
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
