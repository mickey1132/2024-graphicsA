#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include <stdio.h>
GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_position[] = { -10.0f, 10.0f, -10.0f, 1.0f }; /// 方竚

GLfloat light1_diffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f }; /// 肂方憨は甮肅︹
GLfloat light1_specular[] = { 0.9f, 0.9f, 0.9f, 1.0f }; ///肂方蔼肅︹
GLfloat light1_position[] = { 0.0f, 10.0f, 0.0f, 1.0f }; ///肂方竚

// 借妮┦
GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat high_shininess[] = { 100.0f };


float teapotX=0, teapotY=0; ///jsyeh
GLuint bgTexture;

// 更瓜ネΘ瞶
GLuint myTexture(const char *filename)
{
    IplImage *img = cvLoadImage(filename);
    if (!img) {
        printf("Error: Could not load image %s\n", filename);
        return -1;
    }
    cvCvtColor(img, img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    cvReleaseImage(&img);
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
        glmScale(Body, 1/7.0);///glmUnitize(leglowerA);
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
        glmScale(Head, 1/7.0);
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
        glmScale(upperA, 1/7.0);
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
        glmScale(lowerA, 1/7.0);
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
        glmScale(upperB, 1/7.0);
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
        glmScale(lowerB, 1/7.0);
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
        glmScale(legupperA, 1/7.0);///glmUnitize(leglowerA);
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
        glmScale(legupperB, 1/7.0);
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
        glmScale(leglowerA, 1/7.0);///glmUnitize(leglowerA);
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
        glmScale(leglowerB, 1/7.0);
        glmFacetNormals(leglowerB);
        glmVertexNormals(leglowerB, 90.0);
    }

    glmDraw(leglowerB, GLM_SMOOTH | GLM_MATERIAL);
}

void drawBackground()
{
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glBindTexture(GL_TEXTURE_2D, bgTexture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(0.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(0.0, 1.0);
    glEnd();

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

float angleX[10]={},angleY[10]={};
int angleID = 0;
int oldX = 0, oldY = 0;

FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x, int y){ ///jsyeh
    if(0){
        teapotX += (x - oldX) / 150.0;
        teapotY -= (y - oldY) / 150.0;
        printf("glTranslatef(%.3f, %.3f, 0);\n", teapotX, teapotY);
    }else{
        angleX[angleID] += y - oldY;
        angleY[angleID] -= x - oldX;
    }
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
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    drawBackground();
    glPushMatrix();
        ///glRotatef(90,0,1,0);
        glTranslatef(0, -0.8, 0);
        ///glutSolidSphere(0.02, 30, 30);
        glPushMatrix();
            glTranslatef(0,0,0);
            glRotatef(angleY[0],0,1,0);
            drawBody();
            ///家繷
            glPushMatrix();
                glTranslatef(0.000, 1.040,-0.067);
                glRotatef(angleX[1],0,1,0);
                glTranslatef(0.000, -1.047,0.060);
                drawHead();
            glPopMatrix();
            ///家オもA
            glPushMatrix();
                glTranslatef(-0.140, 0.940, -0.073);
                glRotatef(-angleX[2], 1, 0, 0);
                glRotatef(angleY[2], 0, 0, 1);
                glTranslatef(0.140, -0.940, 0.073);
                drawupperA();
                glPushMatrix();glRotatef(-angleX[8], 1, 0, 0);
                glRotatef(angleY[8], 0, 0, 1);
                    glTranslatef(-0.207, 0.740, -0.073);
                    glRotatef(-angleX[3], 1, 0, 0);
                    glRotatef(angleY[3], 0, 0, 1);
                    glTranslatef(0.207, -0.713, 0.073);
                    drawlowerA();
                glPopMatrix();
            glPopMatrix();
            ///家もB
            glPushMatrix();
                glTranslatef(0.147, 0.940, -0.073);
                glRotatef(-angleX[4], 1, 0, 0);
                glRotatef(angleY[4], 0, 0, 1);
                glTranslatef(-0.147, -0.940, 0.073);
                drawupperB();
                glPushMatrix();
                    glTranslatef(0.207, 0.707, -0.073);
                    glRotatef(angleX[5], 1, 0, 0);
                    glRotatef(angleY[5], 0, 0, 1);
                    glTranslatef(-0.207, -0.707, 0.073);
                    drawlowerB();
                glPopMatrix();
            glPopMatrix();
            ///家オ竲A
            glPushMatrix();
                glTranslatef(0.033, 0.720, -0.073);
                glRotatef(-angleX[6], 1, 0, 0);
                glRotatef(angleY[6], 0, 0, 1);
                glTranslatef(-0.033, -0.720, 0.073);
                drawlegupperA();
                glPushMatrix();
                    glTranslatef(-0.100, 0.313, -0.073);
                    glRotatef(angleX[7], 1, 0, 0);
                    glTranslatef(0.100, -0.313, 0.073);
                    drawleglowerA();
                glPopMatrix();
            glPopMatrix();
            ///家竲B
            glPushMatrix();
                glTranslatef(0.033, 0.707, -0.093);
                glRotatef(-angleX[8], 1, 0, 0);
                glRotatef(angleY[8], 0, 0, 1);
                glTranslatef(-0.033, -0.707, 0.093);
                drawlegupperB();
                glPushMatrix();
                    glTranslatef(0.280, 0.960, -0.173);
                    glRotatef(angleX[9], 1, 0, 0);
                    glTranslatef(-0.280, -0.960, 0.173);
                    drawleglowerB();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("FinalWork");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    bgTexture = myTexture("background.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    /// 璶方ㄓ弊よ
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    /// 肂方ㄓいよ
    glEnable(GL_LIGHT1);
    GLfloat light1_position[] = { 0.0f, 10.0f, 0.0f, 1.0f }; /// いよ竚
    GLfloat light1_diffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };   /// 肅︹diffuse
    GLfloat light1_specular[] = { 0.9f, 0.9f, 0.9f, 1.0f };  /// 蔼肅︹specular

    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}

