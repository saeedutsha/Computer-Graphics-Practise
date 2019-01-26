

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<bits/stdc++.h>


using namespace std;


/* GLUT callback Handlers */

class Coordinate
{
public :
    float m_x, m_y;


    Coordinate()
    {
        m_x = 0;
        m_y = 0;
    }
};

Coordinate cod;


void myColor(float r, float g, float b)
{
    /*GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { r, g, b, 1.0 };
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {100};
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);*/
    glColor3f(r, g, b);
}


float camera_x = 0.0, camera_y = 8.0, camera_z = 50.0, focus_x = 0.0, focus_y = 3.0, focus_z = 0.0, theta = 0.0;

float Cos(float theta)
{
    return cos(theta*3.1416/180);
}

float Sin(float theta)
{
    return sin(theta*3.1416/180);
}

float tanI(float val)
{
    return atan(val);
}

Coordinate rotateCamera(float refX, float refY, float x, float y, float theta)
{
    float newx = x-refX;
    float newy = y-refY;

    float rx, ry;
    rx = newx*Cos(theta)-newy*Sin(theta);
    ry = newx*Sin(theta)+newy*Cos(theta);

    newx = rx+refX;
    newy = ry+refY;
    cod.m_x = newx;
    cod.m_y = newy;
    //cout<<newx<<" "<<newy<<endl;
    return cod;

}

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


void myMug()
{
    myColor(1, 0, 1);
    float r[] = {2.5, 3.7, 4.3, 4.8, 5.2, 5.4, 5.6, 5.7, 5.7, 5.65, 5.55, 5.5, 5.45, 5.4, 5.35};

    for(int i = 0; i < 14; i++)
    {
        int next = i+1;
        int pre = i;

        glBegin(GL_QUAD_STRIP);
        for(int j = 0; j <= 360; j+=5)
        {
            float x, y, z;
            x = r[next]*Cos(j);
            y = next;
            z = r[next]*Sin(j);
            glVertex3f(x, y, z);
            //cout<<x<<" "<<y<<" "<<z<<endl;
            x = r[pre]*Cos(j);
            y = pre;
            z = r[pre]*Sin(j);
            glVertex3f(x, y, z);
        }
        glEnd();
    }
    /*float p1 = 2.5;
    float p2 = 2.5;
    int inc = 20;
    for(int j = 0; j <= 360-inc; j += inc)
    {
        float px = p1*Cos(j);
        float pz = p2*Sin(j);
        glBegin(GL_TRIANGLES);
        glVertex3f(0, 0, 0);
        glVertex3f(px, 0, pz);
        px = p1*Cos(j+inc);
        pz = p2*Sin(j+inc);
        glVertex3f(px, 0, pz);
        glEnd();
    }*/


}

void mugHandle()
{
    float Hr = 0.85;
    float x[] = {5.6, 5.6, 6.0, 6.5, 7.5, 8.1, 9.0, 9.4, 9.7, 9.9, 10.1, 10.0, 9.4, 9.0, 8.75, 8.2, 7.5, 6.9, 6.25, 5.7, 5.3, 5.2};
    float y[] = {11.0, 11.0, 12.0, 12.5, 13.0, 12.8, 12.5, 11.9, 10.7, 10.0, 9.0, 8.0, 7.0, 6.3, 5.8, 5.3, 5.0, 4.5, 4.2, 3.8, 3.5, 3.8};

    float xval[36];
    float yval[36];
    for(int i = 0; i <= 360; i+=10)
    {
        xval[i/10] = 5.6;
    }
    for(int i = 0; i <= 360; i+=10)
    {
        yval[i/10] = 11.0 + Hr*Cos(i);
    }


    for(int i = 1; i < 21; i++)
    {
        float preX = x[i-1];
        float nextX = x[i];
        float preY = y[i-1];
        float nextY = y[i];
        float slope;
        if(nextX-preX == 0)
        {
            slope = 0;
        }
        else if(nextX-preX < 0)
        {
            slope -= 1;
        }
        else {
            slope = (nextY-preY)/(nextX-preX);
        }
        slope = tanI(slope);
        slope = (slope*180)/3.1416;
        //cout<<slope<<endl;

        Coordinate codd;
        glBegin(GL_QUAD_STRIP);
        for(int j = 0; j <= 360; j+= 10)
        {
            int b = 0;
            if(j == 360)
            {
                j = 0;
                b = 1;
            }
            float zind = Hr*Sin(j);
            float mx = nextX;
            float my = y[i] + Hr*Cos(j);
            codd = rotateCamera(mx, y[i], mx, my, slope);
            glVertex3f(xval[j/10], yval[j/10], zind);
            glVertex3f(codd.m_x, codd.m_y, zind);
            xval[j/10] = codd.m_x;
            yval[j/10] = codd.m_y;
            //cout<<codd.m_x<<" "<<codd.m_y<<" "<<zind<<endl;
            if(b)
            {
                break;
            }
        }
        glEnd();

    }


}


static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 3000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    glPushMatrix();
    gluLookAt(camera_x,camera_y, camera_z, focus_x,focus_y, focus_z, 0,1,0);
    glRotated(a, 0, 1, 1);
    glRotated(30, 1, 0, 0);
    myMug();
    mugHandle();
    glPopMatrix();


    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    float angle = 2.0;
    switch (key)
    {
    case 27:
    case 'j':
    {
        Coordinate codd;
        codd = rotateCamera(focus_x, focus_z, camera_x, camera_z, angle);
        camera_x = codd.m_x;
        camera_z = codd.m_y;
    }
    break;

    case 'k':
    {
        Coordinate codd;
        codd = rotateCamera(focus_x, focus_z, camera_x, camera_z, -1*angle);
        camera_x = codd.m_x;
        camera_z = codd.m_y;
    }
    break;

    case 'i':
    {
        float temp1 = (camera_x-focus_x)*0.04;
        float temp2 = (camera_z-focus_z)*0.04;
        camera_x -= temp1;
        camera_z -= temp2;
        break;
    }

    case 'o':
    {
        float temp3 = (camera_x-focus_x)*0.05;
        float temp4 = (camera_z-focus_z)*0.05;
        camera_x += temp3;
        camera_z += temp4;
        break;
    }

    case 'q':
    {
        Coordinate codd;
        codd = rotateCamera(camera_x, camera_z, focus_x, focus_z, -1*angle);
        focus_x = codd.m_x;
        focus_z = codd.m_y;
    }
    break;

    case 'w':
    {
        Coordinate codd;
        codd = rotateCamera(camera_x, camera_z, focus_x, focus_z, angle);
        focus_x = codd.m_x;
        focus_z = codd.m_y;
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

    glutCreateWindow("Home Work-1");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,0,0,1);
    glDisable(GL_CULL_FACE);  //back side disable or enable
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);

    cout<<"zoom in --> i"<<endl;
    cout<<"zoom out --> o"<<endl;
    cout<<"camera rotate left --> j"<<endl;
    cout<<"camera rotate right --> k"<<endl;

    /*glEnable(GL_LIGHTING);

    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1 };
    GLfloat light_specular[] = { 1, 1, 1, 1 };
    GLfloat light_position[] = {-10.0, 20.0, -10.0, 1.0 };

    glEnable( GL_LIGHT0);
    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv( GL_LIGHT0, GL_POSITION, light_position);

    GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);*/




    /*glEnable(GL_LIGHT0);
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
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);*/

    glutMainLoop();

    return EXIT_SUCCESS;
}
