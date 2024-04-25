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
        glColor3f(0,1,0);///綠色的
        glScalef(1,0.4,0.4);///Arm
        glutWireCube(0.3);
	glPopMatrix();
}
float angle=0;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	myBody();
    glPushMatrix();///右邊
        glTranslatef(0.3,0.3,0);///(3)放到肩膀上
        glRotatef(angle,0,0,1);///(2)旋轉角度
        glTranslatef(0.15,0,0);///(1)把旋轉中心放到正中間
        myArm();///右手臂
        glPushMatrix();
            glTranslatef(0.15,0,0);///(3)放到肩膀上
            glRotatef(angle,0,0,1);///(2)旋轉角度
            glTranslatef(0.15,0,0);///(1)把旋轉中心放到正中間
            myArm();///右上臂
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左邊
        glTranslatef(-0.3,0.3,0);///(3)放到肩膀上
        glRotatef(-angle,0,0,1);///(2)旋轉角度
        glTranslatef(-0.15,0,0);///(1)把旋轉中心放到正中間
        myArm();///左手臂
        glPushMatrix();
            glTranslatef(-0.15,0,0);///(3)放到肩膀上
            glRotatef(-angle,0,0,1);///(2)旋轉角度
            glTranslatef(-0.15,0,0);///(1)把旋轉中心放到正中間
            myArm();///左上臂
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
	glutMotionFunc(motion);///wrrk10-7加上mouse motion
	glutIdleFunc(display);
	glutMainLoop();
}
