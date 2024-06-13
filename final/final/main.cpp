///先把 week08-1_glm_gundam 的程式貼上來
///等一下, 要再加貼圖的 18行程式
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel* pmodel = NULL;
GLMmodel* upperA = NULL;
GLMmodel* upperB = NULL;
GLMmodel* lowerA = NULL;
GLMmodel* lowerB = NULL;
GLMmodel* Body = NULL;
GLMmodel* Head = NULL;
GLMmodel* legupperA = NULL;
GLMmodel* legupperB = NULL;
GLMmodel* leglowerA = NULL;
GLMmodel* leglowerB = NULL;

void drawBody(void)
{
    if (!Body) {
        Body = glmReadOBJ("data2/body.obj");
        if (!Body) exit(0);
        glmUnitize(Body);
        glmFacetNormals(Body);
        glmVertexNormals(Body, 90.0);
    }

    glmDraw(Body, GLM_SMOOTH | GLM_MATERIAL);
}

void drawHead(void)
{
    if (!Head) {
        Head = glmReadOBJ("data2/head.obj");
        if (!Head) exit(0);
        glmUnitize(Head);
        glmFacetNormals(Head);
        glmVertexNormals(Head, 90.0);
    }
    ///glBindTexture(GL_TEXTURE_2D, textureID);
    glmDraw(Head, GLM_SMOOTH | GLM_MATERIAL);
}

void drawupperA(void)
{
    if (!upperA) {
        upperA = glmReadOBJ("data2/upperA.obj");
        if (!upperA) exit(0);
        glmUnitize(upperA);
        glmFacetNormals(upperA);
        glmVertexNormals(upperA, 90.0);
    }

    glmDraw(upperA, GLM_SMOOTH | GLM_MATERIAL);
}

void drawlowerA(void)
{
    if (!lowerA) {
        lowerA = glmReadOBJ("data2/lowerA.obj");
        if (!lowerA) exit(0);
        glmUnitize(lowerA);
        glmFacetNormals(lowerA);
        glmVertexNormals(lowerA, 90.0);
    }

    glmDraw(lowerA, GLM_SMOOTH | GLM_MATERIAL);
}

void drawupperB(void)
{
    if (!upperB) {
        upperB = glmReadOBJ("data2/upperB.obj");
        if (!upperB) exit(0);
        glmUnitize(upperB);
        glmFacetNormals(upperB);
        glmVertexNormals(upperB, 90.0);
    }

    glmDraw(upperB, GLM_SMOOTH | GLM_MATERIAL);
}

void drawlowerB(void)
{
    if (!lowerB) {
        lowerB = glmReadOBJ("data2/lowerB.obj");
        if (!lowerB) exit(0);
        glmUnitize(lowerB);
        glmFacetNormals(lowerB);
        glmVertexNormals(lowerB, 90.0);
    }

    glmDraw(lowerB, GLM_SMOOTH | GLM_MATERIAL);
}

void drawlegupperA(void)
{
    if (!legupperA) {
        legupperA = glmReadOBJ("data2/legupperA.obj");
        if (!legupperA) exit(0);
        glmUnitize(legupperA);
        glmFacetNormals(legupperA);
        glmVertexNormals(legupperA, 90.0);
    }

    glmDraw(legupperA, GLM_SMOOTH | GLM_MATERIAL);
}

void drawlegupperB(void)
{
    if (!legupperB) {
        legupperB = glmReadOBJ("data2/legupperB.obj");
        if (!legupperB) exit(0);
        glmUnitize(legupperB);
        glmFacetNormals(legupperB);
        glmVertexNormals(legupperB, 90.0);
    }

    glmDraw(legupperB, GLM_SMOOTH | GLM_MATERIAL);
}

void drawleglowerA(void)
{
    if (!leglowerA) {
        leglowerA = glmReadOBJ("data2/leglowerA.obj");
        if (!leglowerA) exit(0);
        glmUnitize(leglowerA);
        glmFacetNormals(leglowerA);
        glmVertexNormals(leglowerA, 90.0);
    }

    glmDraw(leglowerA, GLM_SMOOTH | GLM_MATERIAL);
}

void drawleglowerB(void)
{
    if (!leglowerB) {
        leglowerB = glmReadOBJ("data2/leglowerB.obj");
        if (!leglowerB) exit(0);
        glmUnitize(leglowerB);
        glmFacetNormals(leglowerB);
        glmVertexNormals(leglowerB, 90.0);
    }

    glmDraw(leglowerB, GLM_SMOOTH | GLM_MATERIAL);
}

void myBody()
{
    glPushMatrix();
        glColor3f(1,0,0);
        glutSolidCube(0.6);
    glPopMatrix();
}
float angleX[10]={},angleY[10]={};
int angleID = 0;
int oldX = 0, oldY = 0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x, int y){
    angleX[angleID] += y - oldY;
    angleY[angleID] -= x - oldX;
    oldX = x;
    oldY = y;
    glutPostRedisplay();

}

void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}
float oldAngleX[10]={},newAngleX[10]={};
float oldAngleY[10]={},newAngleY[10]={};
void timer(int t)
{
    glutTimerFunc(50,timer,t+1);
    if(t%20==0)
    {
        if(fin==NULL)fin=fopen("angle.txt","r");
        for(int i=0;i<10;i++)
        {
            oldAngleX[i]=newAngleX[i];
            oldAngleY[i]=newAngleY[i];
            fscanf(fin,"%f",&newAngleX[i]);
            fscanf(fin,"%f",&newAngleY[i]);
        }
    }
    float alpha=(t%20)/20.0;
    for(int i=0;i<10;i++)
    {
        angleX[i]=newAngleX[i]*alpha+oldAngleX[i]*(1-alpha);
        angleY[i]=newAngleY[i]*alpha+oldAngleY[i]*(1-alpha);
    }
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {

	if(key=='p' || key=='P')
    {
        glutTimerFunc(0,timer,0);
    }
	if(key=='r' || key=='R')
    {
		if(fin==NULL) fin = fopen("angle.txt", "r");
		for(int i=0; i<20; i++)
		{
			fscanf(fin, "%f", & angleX[i] );
			fscanf(fin, "%f", & angleY[i] );
		}
		glutPostRedisplay();
	}
	else if(key=='S' || key=='s')
    {
        if(fout==NULL) fout = fopen("angle.txt", "w+");
        for(int i=0; i<20; i++)
        {
            printf("%.1f ", angleX[i] );
            printf("%.1f ", angleY[i] );
            fprintf(fout, "%.1f ", angleX[i] );
            fprintf(fout, "%.1f ", angleY[i] );
        }
        printf("\n");
        fprintf(fout, "\n");
    }
    if(key=='0') angleID = 0;
    if(key=='1') angleID = 1;
    if(key=='2') angleID = 2;
    if(key=='3') angleID = 3;
    if(key=='4') angleID = 4;
    if(key=='5') angleID = 5;
    if(key=='6') angleID = 6;
    if(key=='7') angleID = 7;
    if(key=='8') angleID = 8;
    if(key=='9') angleID = 9;
}
void display()
{
    glClearColor(0.3,0.3,0.3,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
        glRotatef(angleX[0], 1, 0, 0);
        glRotatef(angleY[0], 0, 1, 0);
        glRotatef(180,0,1,0);
        drawBody();

        glPushMatrix();
            glScalef(1.4,1.4,1.4);
            glTranslatef(0 , 0.27 , 0.1);
            glRotatef(angleX[1],0,1,0);
            glTranslatef(0 , 0 , 0);
            drawHead();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.215, 0.05, 0.03);
            glRotatef(angleX[2], 1, 0, 0);
            glRotatef(angleY[2], 0, 0, 1);
            glTranslatef(0, -0.07, 0);
            drawupperA();
            glPushMatrix();
                glScalef(0.8, 0.8, 0.8);
                glTranslatef(-0.02, -0.23, -0.03);
                glRotatef(angleX[3], 1, 0, 0);
                glRotatef(angleY[3], 0, 0, 1);
                glTranslatef(0, -0.21, 0);
                drawlowerA();
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.215, 0.05, 0.03);
            glRotatef(angleX[4], 1, 0, 0);
            glRotatef(angleY[4], 0, 0, 1);
            glTranslatef(0, -0.07, 0);
            drawupperB();
            glPushMatrix();
                glScalef(0.8, 0.8, 0.8);
                glTranslatef(0.02, -0.23, -0.03);
                glRotatef(angleX[5], 1, 0, 0);
                glRotatef(angleY[5], 0, 0, 1);
                glTranslatef(0, -0.21, 0);
                drawlowerB();
            glPopMatrix();

            glPushMatrix();
            glScalef(0.8,0.8,0.8);
            glTranslatef(0, -0.5, 0);
            glRotatef(angleX[6], 1, 0, 0);
            glRotatef(angleY[6], 0, 0, 1);
            glTranslatef(0, 0, 0);
            drawlegupperA();
            glPushMatrix();
                glScalef(0, 0, 0);
                glTranslatef(0, 0, 0);
                glRotatef(angleX[7], 1, 0, 0);
                glRotatef(angleY[7], 0, 0, 1);
                glTranslatef(0, 0, 0);
                drawleglowerA();
            glPopMatrix();

            /*glPushMatrix();
            glTranslatef(0.215, 0.08, 0);
            glRotatef(angleX[4], 1, 0, 0);
            glRotatef(angleY[4], 0, 0, 1);
            glTranslatef(0, -0.07, 0);
            drawupperB();
            glPushMatrix();
                glScalef(0.8, 0.8, 0.8);
                glTranslatef(0.02, -0.23, 0);
                glRotatef(angleX[5], 1, 0, 0);
                glRotatef(angleY[5], 0, 0, 1);
                glTranslatef(0, -0.21, 0);
                drawlowerB();
            glPopMatrix();*/


        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///加這行, 讓它轉動

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
///void timer(int t)
///{
///    glutTimerFunc(1000,timer,t+1);
///    printf("現在起床:%d\n",t);
///}
int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week13-1");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///加這行, 讓它轉動
    glutMouseFunc(mouse); ///大象放到冰箱
    glutMotionFunc(motion); ///滑鼠控制
    glutKeyboardFunc(keyboard); ///week13-1新加
///    glutTimerFunc(0,timer,0);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
