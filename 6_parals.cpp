#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<GLUT/glut.h>


void myinit() {
  glClearColor(0.0,0.0,0.0,1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,500.0,0.0,500.0);
}
void draw_tilt(int x1,int x2,int y1,int y2,int y3,int y4) {
  glBegin(GL_LINE_LOOP);
  glVertex2f(x1,y1);
  glVertex2f(x2,y2);
  glVertex2f(x2,y3);
  glVertex2f(x1,y4);
  glEnd();
}
void display_paralls() {
  int mac = 10;
  int x1=100,x2=200,y1=100,y2=100,y3=300,y4=300;
  for (int i = 0; i < mac; i++) {
    draw_tilt(x1+i*10,x2+i*10,y1+i*10,y2+i*10,y3+i*10,y4+i*10);
  }

}
void draw_pixel(int h,int k,int x,int y) {
  glBegin(GL_POINTS);
    glVertex2f(h+x,k+y);
    glVertex2f(h-x,k+y);
    glVertex2f(h+x,k-y);
    glVertex2f(h-x,k-y);
    glVertex2f(h+y,k+x);
    glVertex2f(h-y,k+x);
    glVertex2f(h+y,k-x);
    glVertex2f(h-y,k-x);
  glEnd();
}
void draw_circle(int h, int k, int r) {

  float d = 1-r,x=0,y=r;

  while(y>x) {
    draw_pixel(h,k,x,y);
    if(d<0)
      d += 2*x+3;
    else{
      d += 2*(x-y)+5;
      --y;
    }x++;
  }
  draw_pixel(h,k,x,y);
}
void draw_cylinder(int h, int k, int r){
  for (int i = 0; i < 20; i++) {
    draw_circle(h,k+i*5,r);
  }
}
void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(1);
  glBegin(GL_POINTS);
  glVertex2f(100,100);
  glEnd();
  display_paralls();
  draw_cylinder(350,150,75);
  glFlush();
  glutSwapBuffers();
}
int main(int argc, char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
  glutInitWindowSize(1000,1000);
  glutCreateWindow("prallel and cylz");
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
}
