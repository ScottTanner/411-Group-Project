

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Win32 calling conventions. */
#ifndef CALLBACK
#define CALLBACK
#endif

#define MAX_POINTS 200
#define MAX_CONTOURS 50

int menu;
typedef enum {
  QUIT, TESSELATE, CLEAR
} menu_entries;
typedef enum {
  DEFINE, TESSELATED
} mode_type;
struct {
  GLint p[MAX_POINTS][2];
  GLuint point_cnt;
} contours[MAX_CONTOURS];
GLuint contour_cnt;
GLsizei width, height;
mode_type mode;

void CALLBACK
my_error(GLenum err)
{
  int len, i;
  const char *str;

  glColor3f(0.9, 0.9, 0.9);
  glRasterPos2i(5, 5);
  str = (char *) gluErrorString(err);
  len = (int) strlen(str);
  for (i = 0; i < len; i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]);
}

void 
set_screen_wh(GLsizei w, GLsizei h)
{
  width = w;
  height = h;
}



void 
left_down(int x1, int y1)
{
  GLint P[2];
  GLuint point_cnt;

  /* translate GLUT into GL coordinates */
  P[0] = x1;
  P[1] = height - y1;
  point_cnt = contours[contour_cnt].point_cnt;
  contours[contour_cnt].p[point_cnt][0] = P[0];
  contours[contour_cnt].p[point_cnt][1] = P[1];
  glBegin(GL_LINES);
  if (point_cnt) {
    glVertex2iv(contours[contour_cnt].p[point_cnt - 1]);
    glVertex2iv(P);
  } else {
    glVertex2iv(P);
    glVertex2iv(P);
  }
  glEnd();
  glFlush();
  ++(contours[contour_cnt].point_cnt);
  if (contours[contour_cnt].point_cnt >= MAX_POINTS) {
    printf("Too many points specified.\n");
    exit(1);
  }
}

/* ARGSUSED */
void 
middle_down(int x1, int y1)
{
  GLuint point_cnt;

  point_cnt = contours[contour_cnt].point_cnt;
  if (point_cnt > 2) {
    glBegin(GL_LINES);
    glVertex2iv(contours[contour_cnt].p[0]);
    glVertex2iv(contours[contour_cnt].p[point_cnt - 1]);
    contours[contour_cnt].p[point_cnt][0] = -1;
    glEnd();
    glFlush();
    contour_cnt++;
    if (contour_cnt >= MAX_CONTOURS) {
      printf("Too many contours specified.\n");
      exit(1);
    }
    contours[contour_cnt].point_cnt = 0;
  }
}

void 
mouse_clicked(int button, int state, int x, int y)
{
  x -= x % 10;
  y -= y % 10;
  switch (button) {
  case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN)
      left_down(x, y);
    break;
  case GLUT_MIDDLE_BUTTON:
    if (state == GLUT_DOWN)
      middle_down(x, y);
    break;
  }
}

void 
display(void)
{
  GLuint i, j;
  GLuint point_cnt;

  glClear(GL_COLOR_BUFFER_BIT);
  switch (mode) {
  case DEFINE:
    /* draw grid */
    glColor3f(0.6, 0.5, 0.5);
    glBegin(GL_LINES);
    for (i = 0; i < width; i += 10)
      for (j = 0; j < height; j += 10) {
        glVertex2i(0, j);
        glVertex2i(width, j);
        glVertex2i(i, height);
        glVertex2i(i, 0);
      }
    glColor3f(1.0, 1.0, 0.0);
    for (i = 0; i <= contour_cnt; i++) {
      point_cnt = contours[i].point_cnt;
      glBegin(GL_LINES);
      switch (point_cnt) {
      case 0:
        break;
      case 1:
        glVertex2iv(contours[i].p[0]);
        glVertex2iv(contours[i].p[0]);
        break;
      case 2:
        glVertex2iv(contours[i].p[0]);
        glVertex2iv(contours[i].p[1]);
        break;
      default:
        --point_cnt;
        for (j = 0; j < point_cnt; j++) {
          glVertex2iv(contours[i].p[j]);
          glVertex2iv(contours[i].p[j + 1]);
        }
        if (contours[i].p[j + 1][0] == -1) {
          glVertex2iv(contours[i].p[0]);
          glVertex2iv(contours[i].p[j]);
        }
        break;
      }
      glEnd();
    }
    glFlush();
    break;
 
  }

  glColor3f(1.0, 1.0, 0.0);
}

void 
clear(void)
{
  contour_cnt = 0;
  contours[0].point_cnt = 0;
  glutMouseFunc(mouse_clicked);
  mode = DEFINE;
  display();
}

void 
quit(void)
{
  exit(0);
}

void 
menu_selected(int entry)
{
  switch (entry) {
  case CLEAR:
    clear();
    break;
  
  case QUIT:
    quit();
    break;
  }
}

/* ARGSUSED1 */

void 
myinit(void)
{
  /* clear background to gray */
  glClearColor(0.4, 0.4, 0.4, 0.0);
  glShadeModel(GL_FLAT);

  menu = glutCreateMenu(menu_selected);
  glutAddMenuEntry("clear", CLEAR);
  
  glutAddMenuEntry("quit", QUIT);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutMouseFunc(mouse_clicked);

  contour_cnt = 0;
  glPolygonMode(GL_FRONT, GL_FILL);
  mode = DEFINE;
}

static void 
reshape(GLsizei w, GLsizei h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, (GLdouble) w, 0.0, (GLdouble) h, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  set_screen_wh(w, h);
}

static void 
usage(void)
{
  printf("Use left mouse button to place vertices.\n");
  printf("Press middle mouse button when done.\n");
  printf("Select tesselate from the pop-up menu.\n");
}

/*  Main Loop
 *  Open window with initial window size, title bar, 
 *  RGBA display mode, and handle input events.
 */
int 
main(int argc, char **argv)
{
  usage();
  glutInitWindowSize(400, 400);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow(argv[0]);
  myinit();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}