/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

static int slices = 16;
static int stacks = 16;
double r = 1.85;

/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}


void myRoom()
{
    glColor3d(0,0.3,0.2);
    glBegin(GL_QUADS);
        glVertex3f(-10.0, -3.0, 10.0);
        glVertex3f(10.0, -3.0, 10.0);
        glVertex3f(10.0, -3.0, -10.0);
        glVertex3f(-10.0, -3.0, -10.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-10.5, -3.5, 10);
        glVertex3f(10.5, -3.5, 10);
        glVertex3f(10.5, -3.5, -10.5);
        glVertex3f(-10.5, -3.5, -10.5);
    glEnd();

    glBegin(GL_QUAD_STRIP);
        glVertex3f(-10.5, -3.0, 10.0);
        glVertex3f(-10.5, -3.5, 10.0);
        glVertex3f(10.5, -3.5, 10.0);
        glVertex3f(10.5, -3.0, 10.0);
        glVertex3f(10.5, -3.0, -10.5);
        glVertex3f(10.5, -3.5, -10.5);
        glVertex3f(-10.5,-3.5,-10.5);
        glVertex3f(-10.5,-3.0,-10.5);
        glVertex3f(-10.5, -3.0, 10.0);
        glVertex3f(-10.5, -3.5, 10.0);
    glEnd();

    glColor3d(0,0.3,0.2);
    glBegin(GL_QUADS);
        glVertex3f(-10.0, 7.0, 10.0);
        glVertex3f(10.0, 7.0, 10.0);
        glVertex3f(10.0, 7.0, -10.0);
        glVertex3f(-10.0, 7.0, -10.0);
    glEnd();

    glColor3d(0,0.3,0.2);
    glBegin(GL_QUADS);
        glVertex3f(-10.5, 7.5, 10);
        glVertex3f(10.5, 7.5, 10);
        glVertex3f(10.5, 7.5, -10.5);
        glVertex3f(-10.5, 7.5, -10.5);
    glEnd();

    glBegin(GL_QUAD_STRIP);
        glVertex3f(-10.5, 7.5, 10.0);
        glVertex3f(-10.5, 7.5, 10.0);
        glVertex3f(10.5, 7.0, 10.0);
        glVertex3f(10.5, 7.5, 10.0);
        glVertex3f(10.5, 7.5, -10.5);
        glVertex3f(10.5, 7.0, -10.5);
        glVertex3f(-10.5,7.0,-10.5);
        glVertex3f(-10.5,7.5,-10.5);
        glVertex3f(-10.5, 7.0, 10.0);
        glVertex3f(-10.5, 7.5, 10.0);
    glEnd();

    //inner walls
    glColor3d(0.4,0,0);
    glBegin(GL_QUAD_STRIP);
        glVertex3f(-10.0, 7.0, 10.0);
        glVertex3f(-10.0, -3.0, 10.0);
        glVertex3f(-10.0, 7.0, -10.0);
        glVertex3f(-10.0, -3.0, -10.0);
        glVertex3f(10.0, 7.0, -10.0);
        glVertex3f(10.0, -3.0, -10.0);
        glVertex3f(10.0, 7.0, 10.0);
        glVertex3f(10.0, -3.0, 10.0);
    glEnd();

    glColor3d(0,0.3,0.2);
    glBegin(GL_QUAD_STRIP);
        glVertex3f(-10.5, 7.0, 10.0);
        glVertex3f(-10.5, -3.0, 10.0);
        glVertex3f(-10.5, 7.0, -10.5);
        glVertex3f(-10.5, -3.0, -10.5);
        glVertex3f(10.5, 7.0, -10.5);
        glVertex3f(10.5, -3.0, -10.5);
        glVertex3f(10.5, 7.0, 10.0);
        glVertex3f(10.5, -3.0, 10.0);
    glEnd();


    glColor3d(0,0.3,0.2);
    glBegin(GL_QUADS);
        glVertex3f(10.5, 7.0, 10.0);
        glVertex3f(10.0, 7.0, 10.0);
        glVertex3f(10.0, -3.0, 10.0);
        glVertex3f(10.5, -3.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-10.5, 7.0, 10.0);
        glVertex3f(-10.0, 7.0, 10.0);
        glVertex3f(-10.0, -3.0, 10.0);
        glVertex3f(-10.5, -3.0, 10.0);
    glEnd();
}

void myTable()
{
    glColor3f(1,0.7,0.5);
    glBegin(GL_QUADS);
        glVertex3f(-3.0, 0, 1.5);
        glVertex3f(3.0, 0, 1.5);
        glVertex3f(3.0, 0, -3.0);
        glVertex3f(-3.0, 0, -3.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-3.0, -0.1, 1.5);
        glVertex3f(3.0, -0.1, 1.5);
        glVertex3f(3.0, -0.1, -3.0);
        glVertex3f(-3.0, -0.1, -3.0);
    glEnd();


    //tables edges
    glColor3f(1,0.7,0.5);

    glBegin(GL_QUAD_STRIP);
        glVertex3f(-3.0, 0, 1.5);
        glVertex3f(-3.0, -0.1, 1.5);
        glVertex3f(3.0, 0, 1.5);
        glVertex3f(3.0, -0.1, 1.5);
        glVertex3f(3.0, 0, -3.0);
        glVertex3f(3.0, -0.1, -3.0);
        glVertex3f(-3.0, 0, -3.0);
        glVertex3f(-3.0, -0.1, -3.0);
        glVertex3f(-3.0, 0, 1.5);
        glVertex3f(-3.0, -0.1, 1.5);
    glEnd();

    glBegin(GL_QUAD_STRIP);
        glVertex3f(-2.5, -.1, 1.0);
        glVertex3f(-2.5, -3.0, 1.0);
        glVertex3f(-2.2, -.1, 1.0);
        glVertex3f(-2.2, -3.0, 1.0);
        glVertex3f(-2.2, -.1, 0.7);
        glVertex3f(-2.2, -3.0, 0.7);
        glVertex3f(-2.5, -.1, 0.7);
        glVertex3f(-2.5, -3.0, 0.7);
        glVertex3f(-2.5, -.1, 1.0);
        glVertex3f(-2.5, -3.0, 1.0);
    glEnd();

    glBegin(GL_QUAD_STRIP);
        glVertex3f(2.5, -.1, 1.0);
        glVertex3f(2.5, -3.0, 1.0);
        glVertex3f(2.2, -.1, 1.0);
        glVertex3f(2.2, -3.0, 1.0);
        glVertex3f(2.2, -.1, 0.7);
        glVertex3f(2.2, -3.0, 0.7);
        glVertex3f(2.5, -.1, 0.7);
        glVertex3f(2.5, -3.0, 0.7);
        glVertex3f(2.5, -.1, 1.0);
        glVertex3f(2.5, -3.0, 1.0);
    glEnd();

    glBegin(GL_QUAD_STRIP);
        glVertex3f(-2.5, -.1, -2.5);
        glVertex3f(-2.5, -3.0, -2.5);
        glVertex3f(-2.2, -.1, -2.5);
        glVertex3f(-2.2, -3.0, -2.5);
        glVertex3f(-2.2, -.1, -2.2);
        glVertex3f(-2.2, -3.0, -2.2);
        glVertex3f(-2.5, -.1, -2.2);
        glVertex3f(-2.5, -3.0, -2.2);
        glVertex3f(-2.5, -.1, -2.5);
        glVertex3f(-2.5, -3.0, -2.5);
    glEnd();

    glBegin(GL_QUAD_STRIP);
        glVertex3f(2.5, -.1, -2.5);
        glVertex3f(2.5, -3.0, -2.5);
        glVertex3f(2.2, -.1, -2.5);
        glVertex3f(2.2, -3.0, -2.5);
        glVertex3f(2.2, -.1, -2.2);
        glVertex3f(2.2, -3.0, -2.2);
        glVertex3f(2.5, -.1, -2.2);
        glVertex3f(2.5, -3.0, -2.2);
        glVertex3f(2.5, -.1, -2.5);
        glVertex3f(2.5, -3.0, -2.5);
    glEnd();


}




void myDesign()
{

    float x1 = 0.2, x2, _x1 = -.2, _x2, _z1 = -0.2, _z2, y1 = 3.0, y2, top = 0;
    float r = 1, g = 1, b = 1;

    for(int i = 0; i < 7; i++) {
        x2 = x1+0.1;
        _x2 = _x1-0.1;
        _z2 = _z1-0.1;
        y2 = y1+0.1;

        glColor3d(r,g,b);
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(0, 0, _z1);//v2
            glVertex3f(x1, 0, 0);//v1
            glVertex3f(0, y1, _z1);//v3
            glVertex3f(_x1, 0, 0);//v4
        glEnd();


        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(0, 0, _z2);//v2
            glVertex3f(x2, 0, 0);//v1
            glVertex3f(0, y2, _z1-0.1);//v3
            glVertex3f(_x2, 0, 0);//v4
        glEnd();

        glColor3d(r-.1,g-.1,b-.1);
        glBegin(GL_QUADS);
            glVertex3f(x1, 0, 0);
            glVertex3f(x2, 0, 0);
            glVertex3f(0, y2, _z1-0.1);
            glVertex3f(0, y1, _z1);
        glEnd();


        glBegin(GL_QUADS);
            glVertex3f(_x1, 0, 0);
            glVertex3f(_x2, 0, 0);
            glVertex3f(0, y2, _z1-0.1);
            glVertex3f(0, y1, _z1);
        glEnd();

        x1 += 0.3;
        _x1 -= 0.3;
        _z1 -= 0.3;
        y1 -= 0.4;
        top -= 0.2;

        r -= 0.05;
        g -= 0.05;
        b -= 0.05;
    }
}

void myFront()
{
    glColor3d(.9,0.9,0.9);
        glBegin(GL_QUADS);
            glVertex3f(-0.1, 1.55, -0.1);
            glVertex3f(-0.1, 1.45, -0.1);
            glVertex3f(0.1, 1.45, -0.1);
            glVertex3f(0.1, 1.55, -0.1);
        glEnd();

        glColor3d(0.8,0.8,0.8);
        glBegin(GL_TRIANGLES);
            glVertex3f(0, 0.25, -0.2);//v2
            glVertex3f(-0.1, 1.45, -0.1);//v1
            glVertex3f(0.1, 1.45, -0.1);//v3
        glEnd();

        glBegin(GL_TRIANGLES);
            glVertex3f(0, 2.7, -0.2);//v2
            glVertex3f(-0.1, 1.55, -0.1);//v1
            glVertex3f(0.1, 1.55, -0.1);//v3
        glEnd();
}

void myFlag()
{
    glColor3f(0.8,0.4,0.2);
    glBegin(GL_QUADS);
        glVertex3f(1.5,0,0.5);
        glVertex3f(1.6,0,0.5);
        glVertex3f(1.6,2.5,0.5);
        glVertex3f(1.5,2.5,0.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(1.5,0,0.45);
        glVertex3f(1.6,0,0.45);
        glVertex3f(1.6,2.5,0.45);
        glVertex3f(1.5,2.5,0.45);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(1.5,0,0.5);
        glVertex3f(1.5,0,0.45);
        glVertex3f(1.5,2.5,0.45);
        glVertex3f(1.5,2.5,0.5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(1.6,0,0.5);
        glVertex3f(1.6,0,0.45);
        glVertex3f(1.6,2.5,0.45);
        glVertex3f(1.6,2.5,0.5);
    glEnd();

    glColor3f(0,0.5,0.1);

    glBegin(GL_QUADS);
        glVertex3f(1.6,2.3,0.5);
        glVertex3f(1.6,1.6,0.5);
        glVertex3f(2.5,1.6,0.5);
        glVertex3f(2.5,2.3,0.5);
    glEnd();

    glColor3f(0.96, 0.16, 0.26);
    glScalef(0.1,0.12,0);

	glBegin(GL_POLYGON);
        for (int i=0; i<100; i++) {
            double theta = (2 * 3.1416 * i) / 100;
            glVertex3f((20+r * cos(theta)), (16+r * sin(theta)), -10);
        }

	glEnd();


}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 2000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
        glTranslated(0, -2, -27);
        glRotated(0,0,0,0);
        glRotated(a,0,1,0);
        myDesign();
        myFront();
        myTable();
        myRoom();
        //myFlag();
    glPopMatrix();


    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Home Work");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,0,0,1);
    glDisable(GL_CULL_FACE);  //back side disable or enable
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glutMainLoop();

    return EXIT_SUCCESS;
}
