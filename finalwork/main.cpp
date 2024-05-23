#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel*pmodel =NULL;
GLMmodel*HandA =NULL;
GLMmodel*HandB =NULL;
GLMmodel*upperA =NULL;
GLMmodel*lowerA =NULL;
GLMmodel*Body =NULL;
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
void drawHandA(void)
{
    if (!HandA) {
	HandA = glmReadOBJ("data2/HandA.obj");
	if (!HandA) exit(0);
	glmUnitize(HandA);
	glmFacetNormals(HandA);
	glmVertexNormals(HandA, 90.0);
    }

    glmDraw(HandA, GLM_SMOOTH | GLM_MATERIAL);
}
void drawHandB(void)
{
    if (!HandB) {
	HandB = glmReadOBJ("data2/HandB.obj");
	if (!HandB) exit(0);
	glmUnitize(HandB);
	glmFacetNormals(HandB);
	glmVertexNormals(HandB, 90.0);
    }

    glmDraw(HandB, GLM_SMOOTH | GLM_MATERIAL);
}
#include <stdio.h>
void myBody()
{
    glPushMatrix();
        glColor3f(1,0,0);
        glutSolidCube(0.6);///Body
	glPopMatrix();
}
///float angle=0, da=1;
float angle[20]={};
int angleID=0;
int oldX=0,oldY=0;
FILE * fin=NULL;
FILE * fout=NULL;
void motion(int x,int y)
{
    angle[angleID]+=y-oldY;
    oldX=x;
    oldY=y;
    glutPostRedisplay();
    if(fout==NULL) fout=fopen("angle.txt","w+");
    for(int i=0;i<20;i++){
        printf("%.1f ",angle[i]);
        fprintf(fout,"%.1f ",angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
}
void mouse(int botton,int state,int x,int y)
{
    oldX=x;
    oldY=y;
}
void keyboard(unsigned char key, int x ,int y)
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
    if(key=='r' || key=='R'){
        if(fin==NULL)fin=fopen("angle.txt","r");
        for(int i=0;i<20;i++){
            fscanf(fin,"%f",&angle[i]);
        }
        glutPostRedisplay();
    }
}
void display()
{

    glClearColor(0.3,0.3,0.3,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
        glRotatef(angle[0],0,1,0);
        drawBody();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1,1,1);

        glPushMatrix();
            glTranslatef(-0.215,0.08,0);
            glRotatef(angle[1],0,0,1);
            glRotatef(angle[2],1,0,0);
            glTranslatef(0,-0.07,0);
            drawupperA();
            glPushMatrix();
                glScalef(0.8,0.8,0.8);
                glTranslatef(-0.02,-0.23,0);
                glRotatef(angle[3],0,0,1);
                glTranslatef(0,-0.21,0);
                drawlowerA();
            glPopMatrix();
        glPopMatrix();

    glutSwapBuffers();
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13-1 gundam");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutIdleFunc(display);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    myTexture("data/Diffuse.jpg");

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
