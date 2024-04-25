#include <GL/glut.h>
#include <mmsystem.h>
void myBody()
{
    glPushMatrix();
        glColor3f(1,0,0);
        glutWireCube(0.6);///Body
	glPopMatrix();
}
void myArm()
{
    glPushMatrix();
        glColor3f(0,1,0);///��⪺
        glScalef(1,0.4,0.4);///Arm
        glutWireCube(0.3);
	glPopMatrix();
}
float angle=0;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	myBody();
    glPushMatrix();///�k��
        glTranslatef(0.3,0.3,0);///(3)���ӻH�W
        glRotatef(angle,0,0,1);///(2)���ਤ��
        glTranslatef(0.15,0,0);///(1)����त�ߩ�쥿����
        myArm();///�k���u
        glPushMatrix();
            glTranslatef(0.15,0,0);///(3)���ӻH�W
            glRotatef(angle,0,0,1);///(2)���ਤ��
            glTranslatef(0.15,0,0);///(1)����त�ߩ�쥿����
            myArm();///�k�W�u
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///����
        glTranslatef(-0.3,0.3,0);///(3)���ӻH�W
        glRotatef(-angle,0,0,1);///(2)���ਤ��
        glTranslatef(-0.15,0,0);///(1)����त�ߩ�쥿����
        myArm();///�����u
        glPushMatrix();
            glTranslatef(-0.15,0,0);///(3)���ӻH�W
            glRotatef(-angle,0,0,1);///(2)���ਤ��
            glTranslatef(-0.15,0,0);///(1)����त�ߩ�쥿����
            myArm();///���W�u
        glPopMatrix();
    glPopMatrix();
	glutSwapBuffers();
}
void motion(int x,int y)
{
    angle=x;
    glutPostRedisplay();
}
int main(int argc, char*argv[])
{
    PlaySound("C:\\Users\\Administrator\\Desktop\\2024-graphicsA\\week10\\horse.wav",NULL,SND_ASYNC);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week10-7");
	glutDisplayFunc(display);
	glutMotionFunc(motion);///wrrk10-7�[�Wmouse motion
	glutIdleFunc(display);
	glutMainLoop();
}
