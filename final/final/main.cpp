#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "CMP3_MCI.h"

CMP3_MCI myMP3;
float teapotX=0, teapotY=0; ///jsyeh
GLuint bgTexture; /// 背景紋理

/// 載入紋理
GLuint myTexture(const char *filename) {
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

    // 設置材質
    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    // 設置模型位置和光源
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

    // 繪製模型
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

    // 設置材質
    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    // 設置模型位置和光源
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

    // 繪製模型
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

    // 設置材質
    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    // 設置模型位置和光源
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

    // 繪製模型
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

    // 設置材質
    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    // 設置模型位置和光源
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

    // 繪製模型
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

    // 設置材質
    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    // 設置模型位置和光源
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

    // 繪製模型
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

    // 設置材質
    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    // 設置模型位置和光源
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

    // 繪製模型
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

    // 設置材質
    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    // 設置模型位置和光源
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

    // 繪製模型
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

    // 設置材質
    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    // 設置模型位置和光源
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

    // 繪製模型
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

    // 設置材質
    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    // 設置模型位置和光源
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

    // 繪製模型
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

    // 設置材質
    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    // 設置模型位置和光源
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

    // 繪製模型
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
    switch (key) {
        case 'p': case 'P':
            myMP3.Load("song.mp3");
            myMP3.Play();
            glutTimerFunc(0, timer, 0);
            break;
        case 'r': case 'R':
            if (fin == NULL) fin = fopen("angle.txt", "r");
            for (int i = 0; i < 10; i++) {
                fscanf(fin, "%f", &angleX[i]);
                fscanf(fin, "%f", &angleY[i]);
            }
            glutPostRedisplay();
            break;
        case 's': case 'S':
            if (fout == NULL) fout = fopen("angle.txt", "w+");
            for (int i = 0; i < 10; i++) {
                printf("%.1f ", angleX[i]);
                printf("%.1f ", angleY[i]);
                fprintf(fout, "%.1f ", angleX[i]);
                fprintf(fout, "%.1f ", angleY[i]);
            }
            printf("\n");
            fprintf(fout, "\n");
            break;
        case '0': angleID = 0; break;
        case '1': angleID = 1; break;
        case '2': angleID = 2; break;
        case '3': angleID = 3; break;
        case '4': angleID = 4; break;
        case '5': angleID = 5; break;
        case '6': angleID = 6; break;
        case '7': angleID = 7; break;
        case '8': angleID = 8; break;
        case '9': angleID = 9; break;
        default:
            break;
    }
}


void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    drawBackground();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    /// 绘制背景


    glPushMatrix();
        glTranslatef(0, -0.8, 0);

        glPushMatrix();
            glTranslatef(0, 0, 0);
            glRotatef(angleY[0], 0, 1, 0);
            drawBody();

            /// 绘制头部
            glPushMatrix();
                glTranslatef(0.000, 1.040, -0.067);
                glRotatef(angleY[1], 0, 1, 0);
                glTranslatef(0.000, -1.047, 0.060);
                drawHead();
            glPopMatrix();

            /// 绘制手臂 A
            glPushMatrix();
                glTranslatef(-0.140, 0.940, -0.073);
                glRotatef(angleX[2], 1, 0, 0);
                glRotatef(angleY[2], 0, 0, 1);
                glTranslatef(0.140, -0.940, 0.073);
                drawupperA();
                glPushMatrix();
                    glTranslatef(-0.207, 0.740, -0.073);
                    glRotatef(angleX[3], 1, 0, 0);
                    glRotatef(angleY[3], 0, 0, 1);
                    glTranslatef(0.207, -0.713, 0.073);
                    drawlowerA();
                glPopMatrix();
            glPopMatrix();

            /// 绘制手臂 B
            glPushMatrix();
                glTranslatef(0.147, 0.940, -0.073);
                glRotatef(angleX[4], 1, 0, 0);
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

            /// 绘制腿部 A
            glPushMatrix();
                glTranslatef(0.033, 0.720, -0.073);
                glRotatef(angleX[6], 1, 0, 0);
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

            /// 绘制腿部 B
            glPushMatrix();
                glTranslatef(0.033, 0.707, -0.093);
                glRotatef(angleX[8], 1, 0, 0);
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
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);

    glutSwapBuffers();
}

int main(int argc, char* argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("FinalWork");

    // 初始化和配置光源
    GLfloat light_position[] = { 0.0, 10.0, 0.0, 1.0 };   // 光源位置在正上方
    GLfloat light_direction[] = { 0.0, -1.0, 0.0 };      // 光源方向向下
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };    // 光源散射光的颜色（白色）

    GLfloat increased_diffuse_intensity = 20; // 提升 1.5 倍的强度
    light_diffuse[0] *= increased_diffuse_intensity;
    light_diffuse[1] *= increased_diffuse_intensity;
    light_diffuse[2] *= increased_diffuse_intensity;

    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);

    // 新增前方光源
    GLfloat front_light_position[] = { 0.0, 0.0, 10.0, 1.0 };   // 光源位置在前方
    GLfloat front_light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };    // 光源散射光的颜色（白色）

    // 调整光强度
    GLfloat front_light_intensity = 50; // 调整光强度为原来的0.8倍
    front_light_diffuse[0] *= front_light_intensity;
    front_light_diffuse[1] *= front_light_intensity;
    front_light_diffuse[2] *= front_light_intensity;

    glLightfv(GL_LIGHT1, GL_DIFFUSE, front_light_diffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, front_light_position);
    glEnable(GL_LIGHT1);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    bgTexture = myTexture("background.jpg");

    glutMainLoop();
    return 0;
}
