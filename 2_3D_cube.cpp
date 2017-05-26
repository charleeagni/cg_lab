#include <GLUT/glut.h>
#include<iostream>
#include<stdlib.h>

GLfloat vertices[ ]={ -1.0,-1.0,-1.0,

1.0,-1.0,-1.0,

1.0, 1.0,-1.0,

- 1.0, 1.0,-1.0,

- 1.0,-1.0, 1.0,

1.0,-1.0, 1.0,

1.0, 1.0, 1.0,

-1.0, 1.0, 1.0 };

GLfloat normals[ ]={ -1.0,-1.0,-1.0,

1.0,-1.0,-1.0,

1.0, 1.0,-1.0,

-1.0, 1.0,-1.0,

-1.0,-1.0, 1.0,

1.0,-1.0, 1.0,

1.0, 1.0, 1.0,

-1.0, 1.0, 1.0 };

GLfloat colors[ ]={ 0.0,0.0,0.0,

1.0, 0.0, 0.0,

1.0, 1.0, 0.0,

0.0, 1.0, 0.0,

0.0, 0.0, 1.0,

1.0, 0.0, 1.0,

1.0, 1.0, 1.0,

0.0, 1.0, 1.0};

GLubyte cubeIndices[]={0,3,2,1,

2,3,7,6,

0,4,7,3,

1,2,6,5,

4,5,6,7,

0,1,5,4 };

static GLfloat thetas[]={0.0,0.0,0.0};
static GLint axis = 0;

void myReshape(int h,int w) {

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    if(w<=h)

    glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,10.0,10.0);

    else

    glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);

    glMatrixMode(GL_MODELVIEW);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glRotatef(thetas[0],1.0,0.0,0.0);
  glRotatef(thetas[1],0.0,1.0,0.0);
  glRotatef(thetas[2],0.0,0.0,1.0);
  glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,cubeIndices);
  glFlush();
  glutSwapBuffers();
}

void mouse(int btn,int state,int x, int y) {
  if(state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON) axis = 0;
  if(state == GLUT_DOWN && btn == GLUT_RIGHT_BUTTON) axis = 1;
  if(state == GLUT_DOWN && btn == GLUT_MIDDLE_BUTTON) axis = 2;
}

void spincube() {
  thetas[axis] +=0.1;
  if(thetas[axis] > 360)
    thetas[axis] -= 360;
  glutPostRedisplay();
}


int main(int argc,char **argv)

{

  glutInit(&argc,argv);

  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

  glutInitWindowSize(500,500);

  glutCreateWindow("color cuce");

  glutReshapeFunc(myReshape);

  glutDisplayFunc(display);

  glutMouseFunc(mouse);

  glutIdleFunc(spincube);

  glEnable(GL_DEPTH_TEST);

  glEnableClientState(GL_COLOR_ARRAY);

  glEnableClientState(GL_VERTEX_ARRAY);

  glEnableClientState(GL_NORMAL_ARRAY);

  glVertexPointer(3,GL_FLOAT,0,vertices);

  glColorPointer(3,GL_FLOAT,0,colors);

  glNormalPointer(GL_FLOAT,0,normals);

  glColor3f(1.0,1.0,1.0);

  glutMainLoop();

}
