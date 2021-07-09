#include <windows.h>
#include <gl/glut.h>
#include <stdlib.h>
#include <math.h>
/*Pius Aldi Septio 672019046
Ardhian Akhim Miftahul Huda 672019318
Andika Wahyu Kurniawan 672019278*/
/*  Macro for sin & cos in degrees */
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))
/*  D degrees of rotation */
#define DEF_D 5

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int,int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);

float xrot =0.0f;
float yrot =0.0f;
float xdiff =0.0f;
float ydiff =0.0f;
bool mouseDown = false;
int is_depth;
float gg=3.0;
//deklarasi pembuatan lingkaran
const double PI = 3.142857143;
int i, radius, jumlah_titik, x_tengah, y_tengah,n;
float angle = 0;
//deklarasi gerakan otomatis
int gerak = 0,gerak2 = 0;
bool atas = true,atas2 = true;


void init(void)
{
glClearColor(0.53, 0.8, 0.98, 0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}


void ngon(int n, float cx, float cy, float radius, float rotAngle,float one,float two){
    double angle, angleInc;
    int k;
    if(n<3) return;
    angle=rotAngle*3.14159265/180;
    angleInc=2*3.14159265/n;

    for(k=-1;k<n;k++){
        angle+=angleInc;

        glVertex3f(radius*cos(angle)+cx, radius*sin(angle)+cy,one);
        glVertex3f(radius*cos(angle)+cx, radius*sin(angle)+cy,two);
    }
}

void ngon2(int n, float cx, float cy, float radius, float rotAngle,float one,float two,float tre){
    double angle, angleInc;
    int k;
    if(n<3) return;
    angle=rotAngle*3.14159265/180;
    angleInc=2*3.14159265/n;

    for(k=tre;k<n;k++){
        angle+=angleInc;

        glVertex3f(radius*cos(angle)+cx, radius*sin(angle)+cy,one);
        glVertex3f(radius*cos(angle)+cx, radius*sin(angle)+cy,two);
    }
}

void lemari(void)
{

  //lemari belakang
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(5.0,13.0,1.0);
    glVertex3f(5.0,0.1, 1.0);
    glVertex3f(5.0,0.1, 10.0);
    glVertex3f(5.0,13.0, 10.0);
    glEnd();

     //lemari samping
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(5.0, 13.0,1.0);
    glVertex3f(5.0, 0.1, 1.0);
    glVertex3f(10.0,0.1, 1.0);
    glVertex3f(10.0, 13.0,1.0);
    glEnd();

         //lemari samping belakang
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(5.0, 13.0,10.0);
    glVertex3f(5.0, 0.1, 10.0);
    glVertex3f(10.0,0.1, 10.0);
    glVertex3f(10.0, 13.0,10.0);
    glEnd();
 //lemari atas
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(10.0, 13.0,1.0);
    glVertex3f(5.0, 13.0, 1.0);
    glVertex3f(5.0, 13.0, 10.0);
    glVertex3f(10.0, 13.0, 10.0);
    glEnd();

     //lemari depan
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(10.0, 0.1,10.0);
    glVertex3f(10.0, 13.0, 10.0);
    glVertex3f(10.0, 13.0, 1.0);
    glVertex3f(10.0, 0.1, 1.0);
    glEnd();

        //lemari garis
        glLineWidth(3.0f);
      glBegin(GL_LINES);
    glColor3f(0/255.f, 0/255.f, 0/255.f);
    glVertex3f(10.0, 0.1, 5.5);
    glVertex3f(10.0, 13.0, 5.5);
    glEnd();

    //gagang lemari
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glColor3f(0/255.f, 0/255.f, 0/255.f);
    glVertex3f(10.0, 7.0, 4.5);
    glVertex3f(10.0, 7.0, 6.5);
    glEnd();
}

void kursi(void)
{
        //atas kursi
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(18.0, 3.0,5.0);
    glVertex3f(23.0, 3.0,5.0);
    glVertex3f(23.0, 3.0, 8.0);
    glVertex3f(18.0, 3.0, 8.0);
    glEnd();

            //sandaran kursi
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(18.0, 3.0,5.0);
    glVertex3f(23.0, 3.0,5.0);
    glVertex3f(23.0, 10.0,5.0);
    glVertex3f(18.0, 10.0,5.0);
    glEnd();

            //sandaran kursi
      glBegin(GL_QUADS);
    glColor4f(135/255.f, 122/255.f, 137/255.f, 1.0);
    glVertex3f(19.0, 4.0,5.1);
    glVertex3f(22.0, 4.0,5.1);
    glVertex3f(22.0, 9.0,5.1);
    glVertex3f(19.0, 9.0,5.1);
    glEnd();

            //kaki kursi
    glLineWidth(3.0f);
      glBegin(GL_LINES);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(19.0, 0.1,5.0);
    glVertex3f(19.0, 3.0,5.0);
    glVertex3f(19.0, 0.1,8.0);
    glVertex3f(19.0, 3.0,8.0);
    glVertex3f(22.0, 0.1,5.0);
    glVertex3f(22.0, 3.0,5.0);
    glVertex3f(22.0, 0.1,8.0);
    glVertex3f(22.0, 3.0,8.0);
    glEnd();
}

void meja(void)
{
        //atas meja
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(15.0, 5.0,7.0);
    glVertex3f(25.0, 5.0, 7.0);
    glVertex3f(25.0, 5.0, 13.0);
    glVertex3f(15.0, 5.0, 13.0);
    glEnd();

            //kaki 1
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(16.5, 0.1,8.5);
    glVertex3f(16.5, 5.0, 8.5);
    glVertex3f(16.5, 5.0, 11.5);
    glVertex3f(16.5, 0.1, 11.5);
    glEnd();

            //kaki 2
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(23.5, 0.1,8.5);
    glVertex3f(23.5, 5.0, 8.5);
    glVertex3f(23.5, 5.0, 11.5);
    glVertex3f(23.5, 0.1, 11.5);
    glEnd();
}

void tidur(void)
{

        //selimut
      glBegin(GL_QUADS);
    glColor4f(235/255.f, 159/255.f, 142/255.f, 1.0);
    glVertex3f(26.0, 3.1,3.0);
    glVertex3f(26.0, 3.1, 13.0);
    glVertex3f(33.0, 3.1, 13.0);
    glVertex3f(33.0, 3.1, 3.0);
    glEnd();
        //bantal
      glBegin(GL_QUADS);
    glColor4f(235/255.f, 159/255.f, 142/255.f, 1.0);
    glVertex3f(35.0, 3.1,5.0);
    glVertex3f(35.0, 3.1, 11.0);
    glVertex3f(37.0, 3.1, 11.0);
    glVertex3f(37.0, 3.1, 5.0);
    glEnd();

        //tempat tidur bawah
      glBegin(GL_QUADS);
    glColor4f(85/255.f, 75/255.f, 255/255.f, 1.0);
    glVertex3f(38.0, 0.1,3.0);
    glVertex3f(38.0, 0.1, 13.0);
    glVertex3f(26.0, 0.1, 13.0);
    glVertex3f(26.0, 0.1, 3.0);
    glEnd();

        //tempat tidur atas
      glBegin(GL_QUADS);
    glColor4f(85/255.f, 75/255.f, 255/255.f, 1.0);
   glVertex3f(38.0, 3.0,3.0);
    glVertex3f(38.0, 3.0, 13.0);
    glVertex3f(26.0, 3.0, 13.0);
    glVertex3f(26.0, 3.0, 3.0);
    glEnd();


        //tempat tidur depan
      glBegin(GL_QUADS);
    glColor4f(85/255.f, 75/255.f, 255/255.f, 1.0);
    glVertex3f(38.0, 3.0,13.0);
    glVertex3f(38.0, 0.1, 13.0);
    glVertex3f(26.0, 0.1, 13.0);
    glVertex3f(26.0, 3.0, 13.0);
    glEnd();


            //tempat tidur belakang
      glBegin(GL_QUADS);
    glColor4f(85/255.f, 75/255.f, 255/255.f, 1.0);
    glVertex3f(38.0, 3.0,3.0);
    glVertex3f(38.0, 0.1, 3.0);
    glVertex3f(26.0, 0.1, 3.0);
    glVertex3f(26.0, 3.0, 3.0);
    glEnd();


                //tempat tidur samping
      glBegin(GL_QUADS);
    glColor4f(85/255.f, 75/255.f, 255/255.f, 1.0);
    glVertex3f(38.0, 3.0,3.0);
    glVertex3f(38.0, 0.1, 3.0);
    glVertex3f(38.0, 0.1, 13.0);
    glVertex3f(38.0, 3.0, 13.0);
    glEnd();


                //tempat tidur samping
      glBegin(GL_QUADS);
    glColor4f(85/255.f, 75/255.f, 255/255.f, 1.0);
    glVertex3f(26.0, 3.0,3.0);
    glVertex3f(26.0, 0.1, 3.0);
    glVertex3f(26.0, 0.1, 13.0);
    glVertex3f(26.0, 3.0, 13.0);
    glEnd();


}

void karpet(void)
{
        //lapisan satu
      glBegin(GL_QUADS);
    glColor4f(216/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(12.0, 0.1,3.0);
    glVertex3f(28.0, 0.1, 3.0);
    glVertex3f(28.0, 0.1, 13.0);
    glVertex3f(12.0, 0.1, 13.0);
    glEnd();

            //lapisan 2
      glBegin(GL_QUADS);
    glColor4f(201/255.f, 240/255.f, 0/255.f, 1.0);
    glVertex3f(15.0, 0.2,5.0);
    glVertex3f(25.0, 0.2, 5.0);
    glVertex3f(25.0, 0.2, 10.0);
    glVertex3f(15.0, 0.2, 10.0);
    glEnd();

            //lapisan 3
      glBegin(GL_QUADS);
    glColor4f(201/255.f, 1/255.f, 197/255.f, 1.0);
    glVertex3f(18.0, 0.3,5.5);
    glVertex3f(23.0, 0.3, 5.5);
    glVertex3f(23.0, 0.3, 9.5);
    glVertex3f(18.0, 0.3, 9.5);
    glEnd();
}

void furnitur(void)
{
lemari();
meja();
tidur();
kursi();
karpet();
}

void ac(void)
{
    //ac bawah
      glBegin(GL_QUADS);
    glColor4f(160/255.f, 160/255.f, 160/255.f, 1.0);
    glVertex3f(28.0, 15.1,8.0);
    glVertex3f(28.0, 15.1, 10.0);
    glVertex3f(26.0, 15.1, 10.0);
    glVertex3f(26.0, 15.1, 8.0);
    glEnd();

    // kiri
    glBegin(GL_QUADS);
    glColor4f(160/255.f, 160/255.f, 160/255.f, 1.0);
    glVertex3f(26.0, 15.1,8.0);
    glVertex3f(26.0, 15.1, 10.0);
    glVertex3f(26.0, 18.0, 10.0);
    glVertex3f(26.0, 18.0, 8.0);
    glEnd();

    // kanan
    glBegin(GL_QUADS);
    glColor4f(160/255.f, 160/255.f, 160/255.f, 1.0);
    glVertex3f(28.0, 15.1,8.0);
    glVertex3f(28.0, 15.1, 10.0);
    glVertex3f(28.0, 18.0, 10.0);
    glVertex3f(28.0, 18.0, 8.0);
    glEnd();

    //ac depan
      glBegin(GL_QUADS);
    glColor4f(160/255.f, 160/255.f, 160/255.f, 1.0);
    glVertex3f(28.0, 15.1,10.0);
    glVertex3f(28.0, 18.0, 10.0);
    glVertex3f(26.0, 18.0, 10.0);
    glVertex3f(26.0, 15.1, 10.0);
    glEnd();

    //ac belakang
      glBegin(GL_QUADS);
    glColor4f(160/255.f, 160/255.f, 160/255.f, 1.0);
    glVertex3f(28.0, 15.1,8.0);
    glVertex3f(28.0, 18.0, 8.0);
    glVertex3f(26.0, 18.0, 8.0);
    glVertex3f(26.0, 15.1, 8.0);
    glEnd();

    //gagang lemari
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glColor3f(0/255.f, 0/255.f, 0/255.f);
    glVertex3f(27.0, 18.0, 9.0);
    glEnd();
}

void atas1(void)
{
            //atap 1
      glBegin(GL_QUADS);
    glColor4f(128/255.f, 128/255.f, 128/255.f, 1.0);
    glVertex3f(-7.0, 15.0,3.0);
    glVertex3f(-7.0, 15.0, 12.0);
    glVertex3f(1.0, 15.0, 12.0);
    glVertex3f(1.0, 15.0, 3.0);
    glEnd();
            //atap 1
      glBegin(GL_QUADS);
    glColor4f(128/255.f, 128/255.f, 128/255.f, 1.0);
    glVertex3f(-5.0, 15.0,1.0);
    glVertex3f(-5.0, 15.0, 14.0);
    glVertex3f(1.0, 15.0, 14.0);
    glVertex3f(1.0, 15.0, 1.0);
    glEnd();
            //atap 2
      glBegin(GL_QUADS);
    glColor4f(128/255.f, 128/255.f, 128/255.f, 1.0);
    glVertex3f(1.0, 15.0,0.0);
    glVertex3f(1.0, 15.0, 15.0);
    glVertex3f(40.0, 15.0, 15.0);
    glVertex3f(40.0, 15.0, 0.0);
    glEnd();

    ac();

    glTranslatef(-6.0,0.0,0.0);
    ac();

    glTranslatef(-7.0,0.0,0.0);
    ac();

    glTranslatef(-8.0,0.0,0.0);
    ac();

}

void belakang(void)
{
        //paling kiri 1
    //pintu
    glBegin(GL_QUADS);
    glColor3ub(32, 32, 32);
    glVertex3f(38.5,0.0,-15.0);
    glVertex3f(38.5,7.0,-15.0);
    glVertex3f(37.2,7.0,-15.0);
    glVertex3f(37.2,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(32, 32, 32);
    glVertex3f(39.5,7.0,-17.0);
    glVertex3f(39.5,9.0,-15.0);
    glVertex3f(37.0,9.0,-15.0);
    glVertex3f(37.0,7.0,-17.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(32, 32, 32);
    glVertex3f(39.5,7.0,-15.0);
    glVertex3f(39.5,9.0,-15.0);
    glVertex3f(39.5,7.0,-17.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(32, 32, 32);
    glVertex3f(37.0,7.0,-15.0);
    glVertex3f(37.0,9.0,-15.0);
    glVertex3f(37.0,7.0,-17.0);
    glEnd();

    //paling kiri 2
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(37.0,0.0,-16.0);
    glVertex3f(37.0,9.0,-16.0);
    glVertex3f(36.0,9.0,-16.0);
    glVertex3f(36.0,0.0,-16.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(37.0,0.0,-16.0);
    glVertex3f(37.0,15.0,-16.0);
    glVertex3f(37.0,15.0,-15.0);
    glVertex3f(37.0,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(36.0,0.0,-16.0);
    glVertex3f(36.0,9.0,-16.0);
    glVertex3f(36.0,9.0,-15.0);
    glVertex3f(36.0,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(37.0,15.0,-16.0);
    glVertex3f(37.0,9.0,-16.0);
    glVertex3f(29.0,9.0,-16.0);
    glVertex3f(29.0,15.0,-16.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(29.0,9.0,-16.0);
    glVertex3f(29.0,0.0,-16.0);
    glVertex3f(30.0,0.0,-16.0);
    glVertex3f(30.0,9.0,-16.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(29.0,15.0,-15.0);
    glVertex3f(29.0,0.0,-15.0);
    glVertex3f(29.0,0.0,-16.0);
    glVertex3f(29.0,15.0,-16.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(30.0,9.0,-15.0);
    glVertex3f(30.0,0.0,-15.0);
    glVertex3f(30.0,0.0,-16.0);
    glVertex3f(30.0,9.0,-16.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(30.0,9.0,-15.0);
    glVertex3f(30.0,9.0,-16.0);
    glVertex3f(36.0,9.0,-16.0);
    glVertex3f(36.0,9.0,-15.0);
    glEnd();

    //pintu 2
    glBegin(GL_QUADS);
    glColor3ub(32, 32, 32);
    glVertex3f(31.5,0.0,-15.0);
    glVertex3f(31.5,7.0,-15.0);
    glVertex3f(30.2,7.0,-15.0);
    glVertex3f(30.2,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(32, 32, 32);
    glVertex3f(32.5,7.0,-17.0);
    glVertex3f(32.5,9.0,-15.0);
    glVertex3f(30.0,9.0,-15.0);
    glVertex3f(30.0,7.0,-17.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(32, 32, 32);
    glVertex3f(32.5,7.0,-15.0);
    glVertex3f(32.5,9.0,-15.0);
    glVertex3f(32.5,7.0,-17.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(32, 32, 32);
    glVertex3f(30.0,7.0,-15.0);
    glVertex3f(30.0,9.0,-15.0);
    glVertex3f(30.0,7.0,-17.0);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(32, 32, 32);
    glVertex3f(35.8,2.0,-15.0);
    glVertex3f(35.8,7.0,-15.0);
    glVertex3f(34.0,7.0,-15.0);
    glVertex3f(34.0,2.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(32, 32, 32);
    glVertex3f(36.0,7.0,-17.0);
    glVertex3f(36.0,9.0,-15.0);
    glVertex3f(33.5,9.0,-15.0);
    glVertex3f(33.5,7.0,-17.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(32, 32, 32);
    glVertex3f(36.0,7.0,-15.0);
    glVertex3f(36.0,9.0,-15.0);
    glVertex3f(36.0,7.0,-17.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(32, 32, 32);
    glVertex3f(33.5,7.0,-15.0);
    glVertex3f(33.5,9.0,-15.0);
    glVertex3f(33.5,7.0,-17.0);
    glEnd();

    //kiri3
    //pintu riser room
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(28.8,0.0,-15.0);
    glVertex3f(28.8,5.0,-15.0);
    glVertex3f(27.0,5.0,-15.0);
    glVertex3f(27.0,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(28.2,0.0,-15.0);
    glVertex3f(28.2,5.2,-15.0);
    glVertex3f(26.8,5.2,-15.0);
    glVertex3f(26.8,0.0,-15.0);
    glEnd();

    //tiang
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(26.5,0.0,-16.0);
    glVertex3f(26.5,9.0,-16.0);
    glVertex3f(25.5,9.0,-16.0);
    glVertex3f(25.5,0.0,-16.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(26.5,0.0,-16.0);
    glVertex3f(26.5,9.0,-16.0);
    glVertex3f(26.5,9.0,-15.0);
    glVertex3f(26.5,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(25.5,0.0,-16.0);
    glVertex3f(25.5,9.0,-16.0);
    glVertex3f(25.5,9.0,-15.0);
    glVertex3f(25.5,0.0,-15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(26.7,9.0,-16.2);
    glVertex3f(26.7,9.0,-15.0);
    glVertex3f(25.2,9.0,-15.0);
    glVertex3f(25.2,9.0,-16.2);
    glEnd();

    //atap pintu
    glBegin(GL_QUADS);
    glColor3ub(32, 32, 32);
    glVertex3f(20.5,6.0,-17.0);
    glVertex3f(20.5,8.0,-15.0);
    glVertex3f(23.5,8.0,-15.0);
    glVertex3f(23.5,6.0,-17.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(32, 32, 32);
    glVertex3f(20.5,6.0,-15.0);
    glVertex3f(20.5,8.0,-15.0);
    glVertex3f(20.5,6.0,-17.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(32, 32, 32);
    glVertex3f(23.5,6.0,-15.0);
    glVertex3f(23.5,8.0,-15.0);
    glVertex3f(23.5,6.0,-17.0);
    glEnd();

    //pintu
    glBegin(GL_QUADS);
    glColor3ub(32, 32, 32);
    glVertex3f(23.2,0.2,-15.0);
    glVertex3f(23.2,5.0,-15.0);
    glVertex3f(22.0,5.0,-15.0);
    glVertex3f(22.0,0.2,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(23.5,0.0,-15.0);
    glVertex3f(23.5,5.3,-15.0);
    glVertex3f(21.7,5.3,-15.0);
    glVertex3f(21.7,0.0,-15.0);
    glEnd();


    //kiri 4
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(20.5,8.0,-16.0);
    glVertex3f(20.5,15.0,-16.0);
    glVertex3f(13.5,15.0,-16.0);
    glVertex3f(13.5,8.0,-16.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(14.5,8.0,-16.0);
    glVertex3f(14.5,8.0,-15.0);
    glVertex3f(19.5,8.0,-15.0);
    glVertex3f(19.5,8.0,-16.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(19.5,0.0,-16.0);
    glVertex3f(19.5,8.0,-16.0);
    glVertex3f(20.5,8.0,-16.0);
    glVertex3f(20.5,0.0,-16.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(19.5,0.0,-16.0);
    glVertex3f(19.5,8.0,-16.0);
    glVertex3f(19.5,8.0,-15.0);
    glVertex3f(19.5,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(20.5,0.0,-16.0);
    glVertex3f(20.5,15.0,-16.0);
    glVertex3f(20.5,15.0,-15.0);
    glVertex3f(20.5,0.0,-15.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(13.5,0.0,-16.0);
    glVertex3f(13.5,8.0,-16.0);
    glVertex3f(14.5,8.0,-16.0);
    glVertex3f(14.5,0.0,-16.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(13.5,0.0,-16.0);
    glVertex3f(13.5,15.0,-16.0);
    glVertex3f(13.5,15.0,-15.0);
    glVertex3f(13.5,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(14.5,0.0,-16.0);
    glVertex3f(14.5,8.0,-16.0);
    glVertex3f(14.5,8.0,-15.0);
    glVertex3f(14.5,0.0,-15.0);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(14.7,0.0,-15.0);
    glVertex3f(14.7,5.0,-15.0);
    glVertex3f(16.0,5.0,-15.0);
    glVertex3f(16.0,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(14.7,5.5,-15.0);
    glVertex3f(14.7,7.5,-15.0);
    glVertex3f(16.0,7.5,-15.0);
    glVertex3f(16.0,5.5,-15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(16.2,0.0,-15.0);
    glVertex3f(16.2,5.0,-15.0);
    glVertex3f(17.2,5.0,-15.0);
    glVertex3f(17.2,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(16.2,5.5,-15.0);
    glVertex3f(16.2,7.5,-15.0);
    glVertex3f(17.2,7.5,-15.0);
    glVertex3f(17.2,5.5,-15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(17.4,0.0,-15.0);
    glVertex3f(17.4,5.0,-15.0);
    glVertex3f(18.7,5.0,-15.0);
    glVertex3f(18.7,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(17.4,5.5,-15.0);
    glVertex3f(17.4,7.5,-15.0);
    glVertex3f(18.7,7.5,-15.0);
    glVertex3f(18.7,5.5,-15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(160, 160, 160);
    glVertex3f(18.9,8.0,-15.0);
    glVertex3f(18.9,0.0,-15.0);
    glVertex3f(14.5,0.0,-15.0);
    glVertex3f(14.5,8.0,-15.0);
    glEnd();


    //kiri 5
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(13.5,8.0,-15.5);
    glVertex3f(13.5,15.0,-15.5);
    glVertex3f(10.0,15.0,-15.5);
    glVertex3f(10.0,8.0,-15.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(13.5,8.0,-15.5);
    glVertex3f(13.5,8.0,-15.0);
    glVertex3f(10.0,8.0,-15.0);
    glVertex3f(10.0,8.0,-15.5);
    glEnd();



    //jendela
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(12.5,0.0,-15.0);
    glVertex3f(12.5,5.0,-15.0);
    glVertex3f(13.4,5.0,-15.0);
    glVertex3f(13.4,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(180, 255, 255);
    glVertex3f(12.5,5.5,-15.0);
    glVertex3f(12.5,7.5,-15.0);
    glVertex3f(13.4,7.5,-15.0);
    glVertex3f(13.4,5.5,-15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(180, 255, 255);
    glVertex3f(12.1,1.0,-15.0);
    glVertex3f(12.1,5.0,-15.0);
    glVertex3f(10.1,5.0,-15.0);
    glVertex3f(10.1,1.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(180, 255, 255);
    glVertex3f(12.1,5.5,-15.0);
    glVertex3f(12.1,7.5,-15.0);
    glVertex3f(10.1,7.5,-15.0);
    glVertex3f(10.1,5.5,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(32, 32, 32);
    glVertex3f(13.5,8.0,-15.0);
    glVertex3f(13.5,0.0,-15.0);
    glVertex3f(10.0,0.0,-15.0);
    glVertex3f(10.0,8.0,-15.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,9.0,-16.0);
    glVertex3f(10.0,9.0,-16.0);
    glVertex3f(10.0,15.0,-16.0);
    glVertex3f(0.0,15.0,-16.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,0.0,-16.0);
    glVertex3f(0.0,9.0,-16.0);
    glVertex3f(1.0,9.0,-16.0);
    glVertex3f(1.0,0.0,-16.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(1.0,0.0,-16.0);
    glVertex3f(1.0,9.0,-16.0);
    glVertex3f(1.0,9.0,-15.0);
    glVertex3f(1.0,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,0.0,-16.0);
    glVertex3f(0.0,15.0,-16.0);
    glVertex3f(0.0,15.0,-15.5);
    glVertex3f(0.0,0.0,-15.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(9.0,0.0,-16.0);
    glVertex3f(9.0,9.0,-16.0);
    glVertex3f(10.0,9.0,-16.0);
    glVertex3f(10.0,0.0,-16.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(9.0,0.0,-16.0);
    glVertex3f(9.0,9.0,-16.0);
    glVertex3f(9.0,9.0,-15.0);
    glVertex3f(9.0,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(10.0,0.0,-16.0);
    glVertex3f(10.0,15.0,-16.0);
    glVertex3f(10.0,15.0,-15.0);
    glVertex3f(10.0,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(1.0,9.0,-16.0);
    glVertex3f(1.0,9.0,-15.0);
    glVertex3f(9.0,9.0,-15.0);
    glVertex3f(9.0,9.0,-16.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(1.0,9.0,-15.5);
    glVertex3f(1.0,5.0,-15.5);
    glVertex3f(9.0,5.0,-15.5);
    glVertex3f(9.0,9.0,-15.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(1.0,0.0,-15.5);
    glVertex3f(1.0,5.0,-15.5);
    glVertex3f(5.5,5.0,-15.5);
    glVertex3f(5.5,0.0,-15.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(5.5,5.0,-15.5);
    glVertex3f(5.5,0.0,-15.5);
    glVertex3f(5.5,0.0,-15.0);
    glVertex3f(5.5,5.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(5.5,5.0,-15.5);
    glVertex3f(9.0,5.0,-15.5);
    glVertex3f(9.0,5.0,-15.0);
    glVertex3f(5.5,5.0,-15.0);
    glEnd();

    //pintu
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(8.9,0.0,-15.5);
    glVertex3f(8.9,4.0,-15.5);
    glVertex3f(7.9,4.0,-15.5);
    glVertex3f(7.9,0.0,-15.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(7.8,0.0,-15.5);
    glVertex3f(7.8,4.0,-15.5);
    glVertex3f(6.8,4.0,-15.5);
    glVertex3f(6.8,0.0,-15.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(6.6,0.0,-15.5);
    glVertex3f(6.6,4.0,-15.5);
    glVertex3f(5.7,4.0,-15.5);
    glVertex3f(5.7,0.0,-15.5);
    glEnd();

    //pintu
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex3f(1.2,0.0,-15.6);
    glVertex3f(1.2,4.0,-15.6);
    glVertex3f(2.2,4.0,-15.6);
    glVertex3f(2.2,0.0,-15.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 255);
    glVertex3f(1.2,4.2,-15.6);
    glVertex3f(1.2,5.8,-15.6);
    glVertex3f(2.2,5.8,-15.6);
    glVertex3f(2.2,4.2,-15.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(3.0,0.0,-15.6);
    glVertex3f(3.0,4.0,-15.6);
    glVertex3f(5.0,4.0,-15.6);
    glVertex3f(5.0,0.0,-15.6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(2.8,0.0,-15.6);
    glVertex3f(2.8,4.2,-15.6);
    glVertex3f(5.2,4.2,-15.6);
    glVertex3f(5.2,0.0,-15.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(5.5,0.0,-15.5);
    glVertex3f(5.5,5.0,-15.5);
    glVertex3f(9.0,5.0,-15.5);
    glVertex3f(9.0,0.0,-15.5);
    glEnd();

    //belakang atas
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(40.0,15.0,-15.0);
    glVertex3f(41.0,15.0,-16.0);
    glVertex3f(24.0,15.0,-16.0);
    glVertex3f(24.0,15.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(41.0,15.0,-16.0);
    glVertex3f(40.0,13.0,-15.0);
    glVertex3f(25.0,13.0,-15.0);
    glVertex3f(24.0,15.0,-16.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(40.0,13.0,-15.0);
    glVertex3f(40.0,15.0,-15.0);
    glVertex3f(41.0,15.0,-16.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(25.0,13.0,-15.0);
    glVertex3f(24.0,15.0,-15.0);
    glVertex3f(24.0,15.0,-16.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(37.0,15.0,-15.0);
    glVertex3f(37.0,17.0,-15.0);
    glVertex3f(29.0,17.0,-15.0);
    glVertex3f(29.0,15.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(38.0,17.0,-16.0);
    glVertex3f(37.0,17.0,-15.0);
    glVertex3f(29.0,17.0,-15.0);
    glVertex3f(28.0,17.0,-16.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(38.0,17.0,-16.0);
    glVertex3f(37.0,15.0,-15.0);
    glVertex3f(29.0,15.0,-15.0);
    glVertex3f(28.0,17.0,-16.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(37.0,15.0,-15.0);
    glVertex3f(37.0,17.0,-15.0);
    glVertex3f(38.0,17.0,-16.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(29.0,15.0,-15.0);
    glVertex3f(29.0,17.0,-15.0);
    glVertex3f(28.0,17.0,-16.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(25.0,15.0,-15.0);
    glVertex3f(25.0,17.0,-15.0);
    glVertex3f(20.5,17.0,-15.0);
    glVertex3f(20.5,15.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(26.0,17.0,-16.0);
    glVertex3f(25.0,17.0,-15.0);
    glVertex3f(20.5,17.0,-15.0);
    glVertex3f(19.5,17.0,-16.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(26.0,17.0,-16.0);
    glVertex3f(25.0,15.0,-15.0);
    glVertex3f(20.5,15.0,-15.0);
    glVertex3f(19.5,17.0,-16.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(25.0,15.0,-15.0);
    glVertex3f(25.0,17.0,-15.0);
    glVertex3f(26.0,17.0,-16.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(20.5,15.0,-15.0);
    glVertex3f(20.5,17.0,-15.0);
    glVertex3f(19.5,17.0,-16.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(20.5,15.0,-15.0);
    glVertex3f(21.5,15.0,-17.5);
    glVertex3f(12.5,15.0,-17.5);
    glVertex3f(13.5,15.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(21.5,15.0,-17.5);
    glVertex3f(20.5,14.0,-16.0);
    glVertex3f(13.5,14.0,-16.0);
    glVertex3f(12.5,15.0,-17.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(13.5,15.0,-15.0);
    glVertex3f(13.5,16.0,-15.0);
    glVertex3f(10.0,16.0,-15.0);
    glVertex3f(10.0,15.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(14.5,16.0,-16.0);
    glVertex3f(13.5,16.0,-15.0);
    glVertex3f(10.0,16.0,-15.0);
    glVertex3f(9.0,16.0,-16.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(14.5,16.0,-16.0);
    glVertex3f(13.5,15.0,-15.0);
    glVertex3f(10.0,15.0,-15.0);
    glVertex3f(9.0,16.0,-16.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(13.5,15.0,-15.0);
    glVertex3f(13.5,16.0,-15.0);
    glVertex3f(14.5,16.0,-16.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(10.0,15.0,-15.0);
    glVertex3f(10.0,16.0,-15.0);
    glVertex3f(9.0,16.0,-16.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(0.0,15.0,-15.0);
    glVertex3f(-1.0,15.0,-17.0);
    glVertex3f(11.0,15.0,-17.0);
    glVertex3f(10.0,15.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(-1.0,15.0,-17.0);
    glVertex3f(0.0,13.0,-16.0);
    glVertex3f(10.0,13.0,-16.0);
    glVertex3f(11.0,15.0,-17.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(0.0,13.0,-16.0);
    glVertex3f(0.0,15.0,-16.0);
    glVertex3f(-1.0,15.0,-17.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(10.0,13.0,-16.0);
    glVertex3f(10.0,15.0,-16.0);
    glVertex3f(11.0,15.0,-17.0);
    glEnd();

    //Belakang
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,0.0,-15.0);
    glVertex3f(0.0,15.0,-15.0);
    glVertex3f(40.0,15.0,-15.0);
    glVertex3f(40.0,0.0,-15.0);
    glEnd();
}




   void samping(void)
   {

        //kanan
    //jendela1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(1.0,7.2,-6.2);
    glVertex3f(1.0,8.6,-6.2);
    glVertex3f(1.0,8.6,-4.3);
    glVertex3f(1.0,7.2,-4.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(1.0,1.2,-6.2);
    glVertex3f(1.0,7.0,-6.2);
    glVertex3f(1.0,7.0,-4.3);
    glVertex3f(1.0,1.2,-4.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex3f(1.0,1.0,-6.4);
    glVertex3f(1.0,8.8,-6.4);
    glVertex3f(1.0,8.8,-4.1);
    glVertex3f(1.0,1.0,-4.1);
    glEnd();

    //jendela2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(1.0,7.2,-8.8);
    glVertex3f(1.0,8.6,-8.8);
    glVertex3f(1.0,8.6,-7.3);
    glVertex3f(1.0,7.2,-7.3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(1.0,1.2,-8.8);
    glVertex3f(1.0,7.0,-8.8);
    glVertex3f(1.0,7.0,-7.3);
    glVertex3f(1.0,1.2,-7.3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex3f(1.0,1.0,-8.9);
    glVertex3f(1.0,8.8,-8.9);
    glVertex3f(1.0,8.8,-7.1);
    glVertex3f(1.0,1.0,-7.1);
    glEnd();

    //jendela3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(1.0,7.2,-10.8);
    glVertex3f(1.0,8.6,-10.8);
    glVertex3f(1.0,8.6,-9.7);
    glVertex3f(1.0,7.2,-9.7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(1.0,1.2,-10.8);
    glVertex3f(1.0,7.0,-10.8);
    glVertex3f(1.0,7.0,-9.7);
    glVertex3f(1.0,1.2,-9.7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex3f(1.0,1.0,-10.9);
    glVertex3f(1.0,8.8,-10.9);
    glVertex3f(1.0,8.8,-9.6);
    glVertex3f(1.0,1.0,-9.6);
    glEnd();


    //tembok
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(1.0,0.0,-11.5);
    glVertex3f(1.0,15.0,-11.5);
    glVertex3f(1.0,15.0,-3.5);
    glVertex3f(1.0,0.0,-3.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,9.0,-11.5);
    glVertex3f(0.0,15.0,-11.5);
    glVertex3f(0.0,15.0,-3.5);
    glVertex3f(0.0,9.0,-3.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(0.0,0.0,-11.0);
    glVertex3f(0.0,9.0,-11.0);
    glVertex3f(1.0,9.0,-11.0);
    glVertex3f(1.0,0.0,-11.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(0.0,0.0,-3.5);
    glVertex3f(0.0,15.0,-3.5);
    glVertex3f(1.0,15.0,-3.5);
    glVertex3f(1.0,0.0,-3.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(0.0,0.0,-4.0);
    glVertex3f(0.0,9.0,-4.0);
    glVertex3f(1.0,9.0,-4.0);
    glVertex3f(1.0,0.0,-4.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,0.0,-4.0);
    glVertex3f(0.0,9.0,-4.0);
    glVertex3f(0.0,9.0,-3.5);
    glVertex3f(0.0,0.0,-3.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,0.0,-7.0);
    glVertex3f(0.0,9.0,-7.0);
    glVertex3f(0.0,9.0,-6.5);
    glVertex3f(0.0,0.0,-6.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,0.0,-9.0);
    glVertex3f(0.0,9.0,-9.0);
    glVertex3f(0.0,9.0,-9.5);
    glVertex3f(0.0,0.0,-9.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(0.0,9.0,-3.5);
    glVertex3f(0.0,9.0,-11.5);
    glVertex3f(1.0,9.0,-11.5);
    glVertex3f(1.0,9.0,-3.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(0.0,0.0,-6.5);
    glVertex3f(0.0,9.0,-6.5);
    glVertex3f(1.0,9.0,-6.5);
    glVertex3f(1.0,0.0,-6.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(0.0,0.0,-7.0);
    glVertex3f(0.0,9.0,-7.0);
    glVertex3f(1.0,9.0,-7.0);
    glVertex3f(1.0,0.0,-7.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(0.0,0.0,-9.0);
    glVertex3f(0.0,9.0,-9.0);
    glVertex3f(1.0,9.0,-9.0);
    glVertex3f(1.0,0.0,-9.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(0.0,0.0,-9.5);
    glVertex3f(0.0,9.0,-9.5);
    glVertex3f(1.0,9.0,-9.5);
    glVertex3f(1.0,0.0,-9.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(0.0,0.0,-11.5);
    glVertex3f(0.0,15.0,-11.5);
    glVertex3f(1.0,15.0,-11.5);
    glVertex3f(1.0,0.0,-11.5);
    glEnd();

        glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(0.0,15.0,-11.5);
    glVertex3f(0.0,15.0,-3.5);
    glVertex3f(-1.0,16.0,-3.5);
    glVertex3f(-1.0,16.0,-11.5);
    glEnd();

        glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(-1.0,16.0,-11.5);
    glVertex3f(-1.0,16.0,-3.5);
    glVertex3f(1.0,16.0,-3.5);
    glVertex3f(1.0,16.0,-11.5);
    glEnd();

        glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(-1.0,16.0,-3.5);
    glVertex3f(1.0,16.0,-3.5);
    glVertex3f(1.0,15.0,-3.5);
    glVertex3f(0.0,15.0,-3.5);
    glEnd();

        glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(-1.0,16.0,-3.5);
    glVertex3f(1.0,16.0,-3.5);
    glVertex3f(1.0,15.0,-5.5);
    glVertex3f(-1.0,15.0,-5.5);
    glEnd();

//penutup dinding
        glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(-1.0,16.0,-11.5);
    glVertex3f(1.0,16.0,-11.5);
    glVertex3f(1.0,15.0,-11.5);
    glVertex3f(0.0,15.0,-11.5);
    glEnd();

        glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(1.0,15.0,-2.0);
    glVertex3f(2.5,15.0,-2.0);
    glVertex3f(2.5,0.0,-2.0);
    glVertex3f(1.0,0.0,-2.0);
    glEnd();

        glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(1.0,15.0,-2.0);
    glVertex3f(1.0,15.0,-4.0);
    glVertex3f(1.0,0.0,-4.0);
    glVertex3f(1.0,0.0,-2.0);
    glEnd();

        glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(1.0,15.0,-13.0);
    glVertex3f(2.5,15.0,-13.0);
    glVertex3f(2.5,0.0,-13.0);
    glVertex3f(1.0,0.0,-13.0);
    glEnd();

        glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(1.0,15.0,-13.0);
    glVertex3f(1.0,15.0,-11.0);
    glVertex3f(1.0,0.0,-11.0);
    glVertex3f(1.0,0.0,-13.0);
    glEnd();

        glBegin(GL_QUADS);
glColor3ub(240, 230, 140);
    glVertex3f(8.5,15.0,-2.5);
    glVertex3f(8.5,15.0,0.0);
    glVertex3f(8.5,0.0,0.0);
    glVertex3f(8.5,0.0,-2.5);
    glEnd();

        glBegin(GL_QUADS);
glColor3ub(240, 230, 140);
    glVertex3f(8.5,15.0,-15.5);
    glVertex3f(8.5,15.0,-11.0);
    glVertex3f(8.5,0.0,-11.0);
    glVertex3f(8.5,0.0,-15.5);
    glEnd();


     glTranslatef(5.5,0.0,-5.0);
 glRotatef(90.0f,-1.0f,0.0f,0.0f);
glBegin(GL_QUAD_STRIP);
glColor3ub(240, 230, 140);
ngon(100,0,6,3.5,216,18,0);
	glEnd();
glBegin(GL_QUAD_STRIP);
//jendela belakang
    glColor3ub(255, 255, 255);
ngon2(100,0,6,3.6,60,9,1,80);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,60,9,8,80);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,60,7,6.6,80);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,60,2,1,80);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,60,9,1,98);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,83,9,1,97);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,106,9,1,97);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,130,9,1,98);
	glEnd();
glTranslatef(0.0,-7.0,0.0);
glBegin(GL_QUAD_STRIP);
glColor3ub(240, 230, 140);
ngon(100,0,6,3.5,16,18,0);
	glEnd();
	//samping depan
glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 255, 255);
ngon2(100,0,6,3.6,225,9,1,80);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,225,9,8,80);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,225,7,6.6,80);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,225,2,1,80);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,225,9,1,98);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,248,9,1,97);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,271,9,1,97);
	glEnd();
glBegin(GL_QUAD_STRIP);
    glColor3ub(2, 2, 2);
ngon2(100,0,6,3.7,295,9,1,98);
	glEnd();


   }

void depan(void)
{
    //kiri
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,0.0,1.0);
    glVertex3f(1.0,0.0,1.0);
    glVertex3f(1.0,9.0,1.0);
    glVertex3f(0.0,9.0,1.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,0.0,1.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,15.0,0.0);
    glVertex3f(0.0,15.0,1.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(1.0,0.0,1.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(1.0,9.0,0.0);
    glVertex3f(1.0,9.0,1.0);
    glEnd();

    //ttup atas
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,15.0,1.0);
    glVertex3f(0.0,9.0,1.0);
    glVertex3f(40.0,9.0,1.0);
    glVertex3f(40.0,15.0,1.0);
    glEnd();

    //kaca1
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(1.3,7.0,0.0);
    glVertex3f(1.3,8.7,0.0);
    glVertex3f(2.7,8.7,0.0);
    glVertex3f(2.7,7.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(1.3,0.2,0.0);
    glVertex3f(1.3,6.7,0.0);
    glVertex3f(2.7,6.7,0.0);
    glVertex3f(2.7,0.2,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(1.1,0.0,0.0);
    glVertex3f(1.1,9.0,0.0);
    glVertex3f(2.9,9.0,0.0);
    glVertex3f(2.9,0.0,0.0);
    glEnd();



    //tembok1
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(3.0,0.0,0.0);
    glVertex3f(3.0,9.0,0.0);
    glVertex3f(4.0,9.0,0.0);
    glVertex3f(4.0,0.0,0.0);
    glEnd();


    //kaca2
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(4.3,7.0,0.0);
    glVertex3f(4.3,8.7,0.0);
    glVertex3f(6.7,8.7,0.0);
    glVertex3f(6.7,7.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(4.3,0.2,0.0);
    glVertex3f(4.3,6.7,0.0);
    glVertex3f(6.7,6.7,0.0);
    glVertex3f(6.7,0.2,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(4.1,0.0,0.0);
    glVertex3f(4.1,9.0,0.0);
    glVertex3f(6.9,9.0,0.0);
    glVertex3f(6.9,0.0,0.0);
    glEnd();


    //tembok2
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(7.0,0.0,0.0);
    glVertex3f(7.0,9.0,0.0);
    glVertex3f(8.0,9.0,0.0);
    glVertex3f(8.0,0.0,0.0);
    glEnd();

    //kaca3
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(8.3,1.2,0.0);
    glVertex3f(8.3,6.7,0.0);
    glVertex3f(9.7,6.7,0.0);
    glVertex3f(9.7,1.2,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(8.3,7.0,0.0);
    glVertex3f(8.3,8.7,0.0);
    glVertex3f(9.7,8.7,0.0);
    glVertex3f(9.7,7.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(8.1,1.0,0.0);
    glVertex3f(8.1,9.0,0.0);
    glVertex3f(9.9,9.0,0.0);
    glVertex3f(9.9,1.0,0.0);
    glEnd();

    //tembok timbul 1
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(10.0,0.0,1.0);
    glVertex3f(10.0,9.0,1.0);
    glVertex3f(11.0,9.0,1.0);
    glVertex3f(11.0,0.0,1.0);
    glEnd();
    //ttup1
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(10.0,0.0,1.0);
    glVertex3f(10.0,0.0,0.0);
    glVertex3f(10.0,9.0,0.0);
    glVertex3f(10.0,9.0,1.0);
    glEnd();
    //ttup2
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(11.0,0.0,1.0);
    glVertex3f(11.0,0.0,0.0);
    glVertex3f(11.0,9.0,0.0);
    glVertex3f(11.0,9.0,1.0);
    glEnd();
     //tembok3
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(11.0,0.0,0.5);
    glVertex3f(11.0,9.0,0.5);
    glVertex3f(12.0,9.0,0.5);
    glVertex3f(12.0,0.0,0.5);
    glEnd();
    //ttup1//
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(12.0,0.0,0.5);
    glVertex3f(12.0,9.0,0.0);
    glVertex3f(12.0,0.0,0.0);
    glVertex3f(12.0,9.0,0.5);
    glEnd();

     //kaca4
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(12.3,7.0,0.0);
    glVertex3f(12.3,8.7,0.0);
    glVertex3f(14.7,8.7,0.0);
    glVertex3f(14.7,7.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(12.3,0.2,0.0);
    glVertex3f(12.3,6.7,0.0);
    glVertex3f(14.7,6.7,0.0);
    glVertex3f(14.7,0.2,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(12.1,0.0,0.0);
    glVertex3f(12.1,9.0,0.0);
    glVertex3f(14.9,9.0,0.0);
    glVertex3f(14.9,0.0,0.0);
    glEnd();

     //tembok4
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(15.0,0.0,0.5);
    glVertex3f(15.0,9.0,0.5);
    glVertex3f(16.0,9.0,0.5);
    glVertex3f(16.0,0.0,0.5);
    glEnd();

    //tembok5
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(16.0,0.0,1.0);
    glVertex3f(16.0,9.0,1.0);
    glVertex3f(17.0,9.0,1.0);
    glVertex3f(17.0,0.0,1.0);
    glEnd();

    //ttup kiri
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(16.0,0.0,1.0);
    glVertex3f(16.0,0.0,0.0);
    glVertex3f(16.0,9.0,0.0);
    glVertex3f(16.0,9.0,1.0);
    glEnd();

    //ttup KNAN
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(17.0,0.0,1.0);
    glVertex3f(17.0,0.0,0.0);
    glVertex3f(17.0,9.0,0.0);
    glVertex3f(17.0,9.0,1.0);
    glEnd();

     //kaca5
         glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(17.3,6.0,0.0);
    glVertex3f(17.3,7.3,0.0);
    glVertex3f(18.2,7.3,0.0);
    glVertex3f(18.2,6.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(17.5,1.2,0.0);
    glVertex3f(17.5,5.7,0.0);
    glVertex3f(18.2,5.7,0.0);
    glVertex3f(18.2,1.2,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(17.1,1.0,0.0);
    glVertex3f(17.1,7.5,0.0);
    glVertex3f(18.4,7.5,0.0);
    glVertex3f(18.4,1.0,0.0);
    glEnd();

     //kaca6
         glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(18.7,6.0,0.0);
    glVertex3f(18.7,7.3,0.0);
    glVertex3f(20.2,7.3,0.0);
    glVertex3f(20.2,6.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(18.7,0.2,0.0);
    glVertex3f(18.7,5.7,0.0);
    glVertex3f(20.2,5.7,0.0);
    glVertex3f(20.2,0.2,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(18.5,0.0,0.0);
    glVertex3f(18.5,7.5,0.0);
    glVertex3f(20.4,7.5,0.0);
    glVertex3f(20.4,0.0,0.0);
    glEnd();

    //tembok6
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(20.5,0.0,1.0);
    glVertex3f(20.5,9.0,1.0);
    glVertex3f(21.5,9.0,1.0);
    glVertex3f(21.5,0.0,1.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(20.5,0.0,1.0);
    glVertex3f(20.5,0.0,0.0);
    glVertex3f(20.5,9.0,0.0);
    glVertex3f(20.5,9.0,1.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(21.5,0.0,1.0);
    glVertex3f(21.5,0.0,0.0);
    glVertex3f(21.5,9.0,0.0);
    glVertex3f(21.5,9.0,1.0);
    glEnd();

    ////kaca7
        glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(21.8,7.0,0.0);
    glVertex3f(21.8,8.3,0.0);
    glVertex3f(22.9,8.3,0.0);
    glVertex3f(22.9,7.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(21.8,1.2,0.0);
    glVertex3f(21.8,6.7,0.0);
    glVertex3f(22.9,6.7,0.0);
    glVertex3f(22.9,1.2,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(21.6,1.0,0.0);
    glVertex3f(21.6,8.5,0.0);
    glVertex3f(23.1,8.5,0.0);
    glVertex3f(23.1,1.0,0.0);
    glEnd();



    //kaca8
        glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(23.4,7.0,0.0);
    glVertex3f(23.4,8.3,0.0);
    glVertex3f(25.5,8.3,0.0);
    glVertex3f(25.5,7.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(23.4,0.2,0.0);
    glVertex3f(23.4,6.7,0.0);
    glVertex3f(25.5,6.7,0.0);
    glVertex3f(25.5,0.2,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(23.2,0.0,0.0);
    glVertex3f(23.2,8.5,0.0);
    glVertex3f(25.7,8.5,0.0);
    glVertex3f(25.7,0.0,0.0);
    glEnd();

    //kaca9
        glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(26.0,7.0,0.0);
    glVertex3f(26.0,8.3,0.0);
    glVertex3f(27.1,8.3,0.0);
    glVertex3f(27.1,7.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(26.0,1.2,0.0);
    glVertex3f(26.0,6.7,0.0);
    glVertex3f(27.1,6.7,0.0);
    glVertex3f(27.1,1.2,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(25.8,1.0,0.0);
    glVertex3f(25.8,8.5,0.0);
    glVertex3f(27.3,8.5,0.0);
    glVertex3f(27.3,1.0,0.0);
    glEnd();

    //tembok7
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(27.4,0.0,1.0);
    glVertex3f(27.4,9.0,1.0);
    glVertex3f(28.4,9.0,1.0);
    glVertex3f(28.4,0.0,1.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(27.4,0.0,1.0);
    glVertex3f(27.4,0.0,0.0);
    glVertex3f(27.4,9.0,0.0);
    glVertex3f(27.4,9.0,1.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(28.4,0.0,1.0);
    glVertex3f(28.4,0.0,0.0);
    glVertex3f(28.4,9.0,0.0);
    glVertex3f(28.4,9.0,1.0);
    glEnd();

     //kaca10
         glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(28.7,7.0,0.0);
    glVertex3f(28.7,8.7,0.0);
    glVertex3f(30.3,8.7,0.0);
    glVertex3f(30.3,7.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(28.7,0.2,0.0);
    glVertex3f(28.7,6.7,0.0);
    glVertex3f(30.3,6.7,0.0);
    glVertex3f(30.3,0.2,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(28.5,0.0,0.0);
    glVertex3f(28.5,9.0,0.0);
    glVertex3f(30.5,9.0,0.0);
    glVertex3f(30.5,0.0,0.0);
    glEnd();

     //tembok8
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(30.6,0.0,1.0);
    glVertex3f(30.6,9.0,1.0);
    glVertex3f(31.6,9.0,1.0);
    glVertex3f(31.6,0.0,1.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(30.6,0.0,1.0);
    glVertex3f(30.6,0.0,0.0);
    glVertex3f(30.6,9.0,0.0);
    glVertex3f(30.6,9.0,1.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(31.6,0.0,1.0);
    glVertex3f(31.6,0.0,0.0);
    glVertex3f(31.6,9.0,0.0);
    glVertex3f(31.6,9.0,1.0);
    glEnd();

     //kaca11
         glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(31.9,7.0,0.0);
    glVertex3f(31.9,8.7,0.0);
    glVertex3f(33.5,8.7,0.0);
    glVertex3f(33.5,7.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(31.9,0.2,0.0);
    glVertex3f(31.9,6.7,0.0);
    glVertex3f(33.5,6.7,0.0);
    glVertex3f(33.5,0.2,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(31.7,0.0,0.0);
    glVertex3f(31.7,9.0,0.0);
    glVertex3f(33.7,9.0,0.0);
    glVertex3f(33.7,0.0,0.0);
    glEnd();

    //tembok 9
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(33.7,0.0,1.0);
    glVertex3f(33.7,9.0,1.0);
    glVertex3f(34.7,9.0,1.0);
    glVertex3f(34.7,0.0,1.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(33.7,0.0,1.0);
    glVertex3f(33.7,0.0,0.0);
    glVertex3f(33.7,9.0,0.0);
    glVertex3f(33.7,9.0,1.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(34.7,0.0,1.0);
    glVertex3f(34.7,0.0,0.0);
    glVertex3f(34.7,9.0,0.0);
    glVertex3f(34.7,9.0,1.0);
    glEnd();

    //kaca12
        glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(35.0,7.0,0.0);
    glVertex3f(35.0,8.7,0.0);
    glVertex3f(36.6,8.7,0.0);
    glVertex3f(36.6,7.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(35.0,0.2,0.0);
    glVertex3f(35.0,6.7,0.0);
    glVertex3f(36.6,6.7,0.0);
    glVertex3f(36.6,0.2,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(34.8,0.0,0.0);
    glVertex3f(34.8,9.0,0.0);
    glVertex3f(36.8,9.0,0.0);
    glVertex3f(36.8,0.0,0.0);
    glEnd();


     //tembok 10
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(36.9,0.0,1.0);
    glVertex3f(36.9,9.0,1.0);
    glVertex3f(37.9,9.0,1.0);
    glVertex3f(37.9,0.0,1.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(36.9,0.0,1.0);
    glVertex3f(36.9,0.0,0.0);
    glVertex3f(36.9,9.0,0.0);
    glVertex3f(36.9,9.0,1.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(37.9,0.0,1.0);
    glVertex3f(37.9,0.0,0.0);
    glVertex3f(37.9,9.0,0.0);
    glVertex3f(37.9,9.0,1.0);
    glEnd();





    //segitiga
    glBegin(GL_TRIANGLES);
    glColor3ub(240, 230, 140);
    glVertex3f(11.0,15.0,0.5);
    glVertex3f(13.5,18.0,0.5);
    glVertex3f(16.0,15.0,0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(240, 230, 140);
    glVertex3f(11.0,15.0,0.0);
    glVertex3f(13.5,18.0,0.0);
    glVertex3f(16.0,15.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(16.0,15.0,0.0);
    glVertex3f(16.0,15.0,0.5);
    glVertex3f(13.5,18.0,0.5);
    glVertex3f(13.5,18.0,0.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(11.0,15.0,0.0);
    glVertex3f(11.0,15.0,0.5);
    glVertex3f(13.5,18.0,0.5);
    glVertex3f(13.5,18.0,0.0);
    glEnd();

     //ttup atas
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,15.0,0.0);
    glVertex3f(0.0,15.0,1.5);
    glVertex3f(40.0,15.0,1.5);
    glVertex3f(40.0,15.0,0.0);
    glEnd();

    //ttup atas
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,9.0,0.0);
    glVertex3f(0.0,9.0,1.5);
    glVertex3f(40.0,9.0,1.5);
    glVertex3f(40.0,9.0,0.0);
    glEnd();

    //kotak atas
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(26.3,15.0,0.0);
    glVertex3f(26.3,16.0,0.0);
    glVertex3f(21.0,16.0,0.0);
    glVertex3f(21.0,15.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(27.3,16.0,1.0);
    glVertex3f(26.3,16.0,0.0);
    glVertex3f(21.0,16.0,0.0);
    glVertex3f(20.0,16.0,1.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(27.3,16.0,1.0);
    glVertex3f(26.3,15.0,0.0);
    glVertex3f(21.0,15.0,0.0);
    glVertex3f(20.0,16.0,1.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(26.3,15.0,0.0);
    glVertex3f(26.3,16.0,0.0);
    glVertex3f(27.3,16.0,1.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(21.0,15.0,0.0);
    glVertex3f(21.0,16.0,0.0);
    glVertex3f(20.0,16.0,1.0);
    glEnd();


        //kotak atas 2
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(36.6,15.0,0.0);
    glVertex3f(36.6,16.0,0.0);
    glVertex3f(31.9,16.0,0.0);
    glVertex3f(31.9,15.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(37.6,16.0,1.0);
    glVertex3f(36.6,16.0,0.0);
    glVertex3f(31.9,16.0,0.0);
    glVertex3f(30.9,16.0,1.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(37.6,16.0,1.0);
    glVertex3f(36.6,15.0,0.0);
    glVertex3f(31.9,15.0,0.0);
    glVertex3f(30.9,16.0,1.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(36.6,15.0,0.0);
    glVertex3f(36.6,16.0,0.0);
    glVertex3f(37.6,16.0,1.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(31.9,15.0,0.0);
    glVertex3f(31.9,16.0,0.0);
    glVertex3f(30.9,16.0,1.0);
    glEnd();

        glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(10.0,15.0,0.0);
    glVertex3f(11.0,15.0,1.0);
    glVertex3f(0.0,15.0,1.0);
    glVertex3f(0.0,15.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 205);
    glVertex3f(11.0,15.0,1.0);
    glVertex3f(10.0,13.0,0.0);
    glVertex3f(1.0,13.0,0.0);
    glVertex3f(0.0,15.0,1.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(10.0,13.0,0.0);
    glVertex3f(10.0,15.0,0.0);
    glVertex3f(11.0,15.0,1.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(189, 183, 107);
    glVertex3f(1.0,13.0,0.0);
    glVertex3f(1.0,15.0,0.0);
    glVertex3f(0.0,15.0,1.0);
    glEnd();


    //kaca11
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(40.0,1.0,-0.5);
    glVertex3f(40.0,5.0,-0.5);
    glVertex3f(40.0,5.0,-2.5);
    glVertex3f(40.0,1.0,-2.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(40.0,5.2,-0.5);
    glVertex3f(40.0,7.0,-0.5);
    glVertex3f(40.0,7.0,-2.5);
    glVertex3f(40.0,5.2,-2.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(40.0,0.9,-0.4);
    glVertex3f(40.0,7.2,-0.4);
    glVertex3f(40.0,7.2,-2.6);
    glVertex3f(40.0,0.9,-2.6);
    glEnd();


    //kiri
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(41.0,9.0,-3.0);
    glVertex3f(41.0,15.0,-3.0);
    glVertex3f(41.0,15.0,-12.0);
    glVertex3f(41.0,9.0,-12.0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(40.0,0.0,-3.0);
    glVertex3f(40.0,15.0,-3.0);
    glVertex3f(41.0,15.0,-3.0);
    glVertex3f(41.0,0.0,-3.0);
    glEnd();
         glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(40.0,15.0,-3.0);
    glVertex3f(41.0,15.0,-3.0);
    glVertex3f(41.0,15.0,-12.0);
    glVertex3f(40.0,15.0,-12.0);
    glEnd();
         glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(40.0,0.0,-12.0);
    glVertex3f(40.0,15.0,-12.0);
    glVertex3f(41.0,15.0,-12.0);
    glVertex3f(41.0,0.0,-12.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(40.0,9.0,-3.0);
    glVertex3f(41.0,9.0,-3.0);
    glVertex3f(41.0,9.0,-12.0);
    glVertex3f(40.0,9.0,-12.0);
    glEnd();

    //tembok
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(41.0,9.0,-3.0);
    glVertex3f(41.0,0.0,-3.0);
    glVertex3f(41.0,0.0,-4.0);
    glVertex3f(41.0,9.0,-4.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(40.0,0.0,-4.0);
    glVertex3f(40.0,9.0,-4.0);
    glVertex3f(41.0,9.0,-4.0);
    glVertex3f(41.0,0.0,-4.0);
    glEnd();

    //tembok
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(41.0,9.0,-11.0);
    glVertex3f(41.0,0.0,-11.0);
    glVertex3f(41.0,0.0,-12.0);
    glVertex3f(41.0,9.0,-12.0);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(40.0,0.0,-11.0);
    glVertex3f(40.0,9.0,-11.0);
    glVertex3f(41.0,9.0,-11.0);
    glVertex3f(41.0,0.0,-11.0);
    glEnd();

    //kaca2
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(40.0,1.0,-4.1);
    glVertex3f(40.0,5.0,-4.1);
    glVertex3f(40.0,5.0,-6.0);
    glVertex3f(40.0,1.0,-6.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(40.0,5.2,-4.1);
    glVertex3f(40.0,7.0,-4.1);
    glVertex3f(40.0,7.0,-6.0);
    glVertex3f(40.0,5.2,-6.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(40.0,0.9,-4.0);
    glVertex3f(40.0,7.2,-4.0);
    glVertex3f(40.0,7.2,-6.1);
    glVertex3f(40.0,0.9,-6.1);
    glEnd();

    //kaca3
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(40.0,1.0,-9.1);
    glVertex3f(40.0,5.0,-9.1);
    glVertex3f(40.0,5.0,-10.8);
    glVertex3f(40.0,1.0,-10.8);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(40.0,5.2,-9.1);
    glVertex3f(40.0,7.0,-9.1);
    glVertex3f(40.0,7.0,-10.8);
    glVertex3f(40.0,5.2,-10.8);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(40.0,0.9,-9.0);
    glVertex3f(40.0,7.2,-9.0);
    glVertex3f(40.0,7.2,-10.9);
    glVertex3f(40.0,0.9,-10.9);
    glEnd();

    //kaca4
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(40.0,1.0,-6.3);
    glVertex3f(40.0,5.0,-6.3);
    glVertex3f(40.0,5.0,-8.8);
    glVertex3f(40.0,1.0,-8.8);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(40.0,5.2,-6.3);
    glVertex3f(40.0,7.0,-6.3);
    glVertex3f(40.0,7.0,-8.8);
    glVertex3f(40.0,5.2,-8.8);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(40.0,0.9,-6.2);
    glVertex3f(40.0,7.2,-6.2);
    glVertex3f(40.0,7.2,-8.9);
    glVertex3f(40.0,0.9,-8.9);
    glEnd();

     //kaca5
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(40.0,1.0,-12.6);
    glVertex3f(40.0,5.0,-12.6);
    glVertex3f(40.0,5.0,-14.4);
    glVertex3f(40.0,1.0,-14.4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(175,216,230);
    glVertex3f(40.0,5.2,-12.6);
    glVertex3f(40.0,7.0,-12.6);
    glVertex3f(40.0,7.0,-14.4);
    glVertex3f(40.0,5.2,-14.4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(40.0,0.9,-12.5);
    glVertex3f(40.0,7.2,-12.5);
    glVertex3f(40.0,7.2,-14.5);
    glVertex3f(40.0,0.9,-14.5);
    glEnd();

    //ttup kaca
     glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(27.3,7.0,2.0);
    glVertex3f(27.3,9.0,0.0);
    glVertex3f(21.8,9.0,0.0);
    glVertex3f(21.8,7.0,2.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex3f(27.3,7.0,0.0);
    glVertex3f(27.3,9.0,0.0);
    glVertex3f(27.3,7.0,2.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex3f(21.8,7.0,0.0);
    glVertex3f(21.8,9.0,0.0);
    glVertex3f(21.8,7.0,2.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(30.3,7.0,2.0);
    glVertex3f(30.3,9.0,0.0);
    glVertex3f(28.7,9.0,0.0);
    glVertex3f(28.7,7.0,2.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex3f(30.3,7.0,0.0);
    glVertex3f(30.3,9.0,0.0);
    glVertex3f(30.3,7.0,2.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex3f(28.7,7.0,0.0);
    glVertex3f(28.7,9.0,0.0);
    glVertex3f(28.7,7.0,2.0);
    glEnd();

         glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(33.5,7.0,2.0);
    glVertex3f(33.5,9.0,0.0);
    glVertex3f(31.9,9.0,0.0);
    glVertex3f(31.9,7.0,2.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex3f(33.5,7.0,0.0);
    glVertex3f(33.5,9.0,0.0);
    glVertex3f(33.5,7.0,2.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex3f(31.9,7.0,0.0);
    glVertex3f(31.9,9.0,0.0);
    glVertex3f(31.9,7.0,2.0);
    glEnd();

        glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(36.6,7.0,2.0);
    glVertex3f(36.6,9.0,0.0);
    glVertex3f(35.0,9.0,0.0);
    glVertex3f(35.0,7.0,2.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex3f(36.6,7.0,0.0);
    glVertex3f(36.6,9.0,0.0);
    glVertex3f(36.6,7.0,2.0);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex3f(35.0,7.0,0.0);
    glVertex3f(35.0,9.0,0.0);
    glVertex3f(35.0,7.0,2.0);
    glEnd();



    //ttup kaca kiri
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex3f(40.0,7.0,-0.5);
    glVertex3f(41.0,5.0,-0.5);
    glVertex3f(41.0,5.0,-2.5);
    glVertex3f(40.0,7.0,-2.5);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);
    glVertex3f(40.0,5.0,-0.5);
    glVertex3f(40.0,7.0,-0.5);
    glVertex3f(41.0,5.0,-0.5);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);
    glVertex3f(40.0,5.0,-2.5);
    glVertex3f(40.0,7.0,-2.5);
    glVertex3f(41.0,5.0,-2.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex3f(40.0,7.0,-4.1);
    glVertex3f(41.0,5.0,-4.1);
    glVertex3f(41.0,5.0,-10.8);
    glVertex3f(40.0,7.0,-10.8);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);
    glVertex3f(40.0,5.0,-4.1);
    glVertex3f(40.0,7.0,-4.1);
    glVertex3f(41.0,5.0,-4.1);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);
    glVertex3f(40.0,5.0,-10.8);
    glVertex3f(40.0,7.0,-10.8);
    glVertex3f(41.0,5.0,-10.8);
    glEnd();

        glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex3f(40.0,7.0,-12.6);
    glVertex3f(41.0,5.0,-12.6);
    glVertex3f(41.0,5.0,-14.4);
    glVertex3f(40.0,7.0,-14.4);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);
    glVertex3f(40.0,5.0,-12.6);
    glVertex3f(40.0,7.0,-12.6);
    glVertex3f(41.0,5.0,-12.6);
    glEnd();
     glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);
    glVertex3f(40.0,5.0,-14.4);
    glVertex3f(40.0,7.0,-14.4);
    glVertex3f(41.0,5.0,-14.4);
    glEnd();

    //Belakang
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,15.0,0.0);
    glVertex3f(40.0,15.0,0.0);
    glVertex3f(40.0,0.0,0.0);
    glEnd();

     //kiri
    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(40.0,0.0,0.0);
    glVertex3f(40.0,15.0,0.0);
    glVertex3f(40.0,15.0,-15.0);
    glVertex3f(40.0,0.0,-15.0);
    glEnd();

}

void parkiran(void)
{
    //Parkiran
    //Garis Putih
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.5,0.0,0.0);
    glVertex3f(0.5,0.0,40.0);
    glVertex3f(0.0,0.0,40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(0.0,0.0,10.0);
    glVertex3f(8.0,0.0,10.0);
    glVertex3f(8.0,0.0,10.5);
    glVertex3f(0.0,0.0,10.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(0.0,0.0,15.0);
    glVertex3f(8.0,0.0,15.0);
    glVertex3f(8.0,0.0,15.5);
    glVertex3f(0.0,0.0,15.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(0.0,0.0,20.0);
    glVertex3f(8.0,0.0,20.0);
    glVertex3f(8.0,0.0,20.5);
    glVertex3f(0.0,0.0,20.5);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(0.0,0.0,25.0);
    glVertex3f(8.0,0.0,25.0);
    glVertex3f(8.0,0.0,25.5);
    glVertex3f(0.0,0.0,25.5);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(0.0,0.0,30.0);
    glVertex3f(8.0,0.0,30.0);
    glVertex3f(8.0,0.0,30.5);
    glVertex3f(0.0,0.0,30.5);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(0.0,0.0,35.0);
    glVertex3f(8.0,0.0,35.0);
    glVertex3f(8.0,0.0,35.5);
    glVertex3f(0.0,0.0,35.5);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(0.0,0.0,40.0);
    glVertex3f(8.0,0.0,40.0);
    glVertex3f(8.0,0.0,40.5);
    glVertex3f(0.0,0.0,40.5);
    glEnd();

    //Garis2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(15.0,0.0,18.0);
    glVertex3f(40.5,0.0,18.0);
    glVertex3f(40.5,0.0,18.5);
    glVertex3f(15.0,0.0,18.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(15.0,0.0,10.0);
    glVertex3f(15.5,0.0,10.0);
    glVertex3f(15.5,0.0,26.5);
    glVertex3f(15.0,0.0,26.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(20.0,0.0,10.0);
    glVertex3f(20.5,0.0,10.0);
    glVertex3f(20.5,0.0,26.5);
    glVertex3f(20.0,0.0,26.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(25.0,0.0,10.0);
    glVertex3f(25.5,0.0,10.0);
    glVertex3f(25.5,0.0,26.5);
    glVertex3f(25.0,0.0,26.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(30.0,0.0,10.0);
    glVertex3f(30.5,0.0,10.0);
    glVertex3f(30.5,0.0,26.5);
    glVertex3f(30.0,0.0,26.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(35.0,0.0,10.0);
    glVertex3f(35.5,0.0,10.0);
    glVertex3f(35.5,0.0,26.5);
    glVertex3f(35.0,0.0,26.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(40.0,0.0,10.0);
    glVertex3f(40.5,0.0,10.0);
    glVertex3f(40.5,0.0,26.5);
    glVertex3f(40.0,0.0,26.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(15.0,0.0,35.0);
    glVertex3f(15.5,0.0,35.0);
    glVertex3f(15.5,0.0,40.5);
    glVertex3f(15.0,0.0,40.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(20.0,0.0,35.0);
    glVertex3f(20.5,0.0,35.0);
    glVertex3f(20.5,0.0,40.5);
    glVertex3f(20.0,0.0,40.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(25.0,0.0,35.0);
    glVertex3f(25.5,0.0,35.0);
    glVertex3f(25.5,0.0,40.5);
    glVertex3f(25.0,0.0,40.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(30.0,0.0,35.0);
    glVertex3f(30.5,0.0,35.0);
    glVertex3f(30.5,0.0,40.5);
    glVertex3f(30.0,0.0,40.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(35.0,0.0,35.0);
    glVertex3f(35.5,0.0,35.0);
    glVertex3f(35.5,0.0,40.5);
    glVertex3f(35.0,0.0,40.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(40.0,0.0,35.0);
    glVertex3f(40.5,0.0,35.0);
    glVertex3f(40.5,0.0,40.5);
    glVertex3f(40.0,0.0,40.5);
    glEnd();


    //garis 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(48.0,0.0,18.0);
    glVertex3f(60.0,0.0,18.0);
    glVertex3f(60.0,0.0,18.5);
    glVertex3f(48.0,0.0,18.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(48.0,0.0,10.0);
    glVertex3f(48.5,0.0,10.0);
    glVertex3f(48.5,0.0,26.5);
    glVertex3f(48.0,0.0,26.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(53.0,0.0,10.0);
    glVertex3f(53.5,0.0,10.0);
    glVertex3f(53.5,0.0,26.5);
    glVertex3f(53.0,0.0,26.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(58.0,0.0,10.0);
    glVertex3f(58.5,0.0,10.0);
    glVertex3f(58.5,0.0,26.5);
    glVertex3f(58.0,0.0,26.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(48.0,0.0,35.0);
    glVertex3f(48.5,0.0,35.0);
    glVertex3f(48.5,0.0,40.5);
    glVertex3f(48.0,0.0,40.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(53.0,0.0,35.0);
    glVertex3f(53.5,0.0,35.0);
    glVertex3f(53.5,0.0,40.5);
    glVertex3f(53.0,0.0,40.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(58.0,0.0,35.0);
    glVertex3f(58.5,0.0,35.0);
    glVertex3f(58.5,0.0,40.5);
    glVertex3f(58.0,0.0,40.5);
    glEnd();

    //garis 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(48.0,0.0,-8.0);
    glVertex3f(60.0,0.0,-8.0);
    glVertex3f(60.0,0.0,-8.5);
    glVertex3f(48.0,0.0,-8.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(48.0,0.0,0.0);
    glVertex3f(48.5,0.0,0.0);
    glVertex3f(48.5,0.0,-15.0);
    glVertex3f(48.0,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(53.0,0.0,0.0);
    glVertex3f(53.5,0.0,0.0);
    glVertex3f(53.5,0.0,-15.0);
    glVertex3f(53.0,0.0,-15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(58.0,0.0,0.0);
    glVertex3f(58.5,0.0,0.0);
    glVertex3f(58.5,0.0,-15.0);
    glVertex3f(58.0,0.0,-15.0);
    glEnd();

    //Lahan parkir
    glBegin(GL_QUADS);
    glColor3ub(32, 32, 32);
    glVertex3f(0.0,0.0,-15.0);
    glVertex3f(0.0,0.0,40.5);
    glVertex3f(60.0,0.0,40.5);
    glVertex3f(60.0,0.0,-15.0);
    glEnd();

}

void mobil() {
    //perintah animasi
    glPushMatrix();
    glTranslatef(gerak, 0, 0);

    //tengah
    glBegin(GL_QUADS);
    glColor3ub(202, 144, 101);
    glVertex3f(23.5, -155.0, 55.0);
    glVertex3f(23.5, -145.5, 55.0);
    glVertex3f(70.0, -145.5, 55.0);
    glVertex3f(70.0, -155.0, 55.0);
    glEnd();
    //tengah atas
    glBegin(GL_QUADS);
    glColor3ub(202, 144, 101);
    glVertex3f(28.5, -145.5, 55.0);
    glVertex3f(31.5, -130.5, 55.0);
    glVertex3f(67.0, -130.5, 55.0);
    glVertex3f(70.0, -145.5, 55.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(202, 144, 101);
    glVertex3f(70.0, -155.0, 55.0);
    glVertex3f(70.0, -145.5, 55.0);
    glVertex3f(81.0, -145.5, 55.0);
    glVertex3f(81.0, -155.0, 55.0);
    glEnd();

    //tengah
    glBegin(GL_QUADS);
    glColor3ub(202, 144, 101);
    glVertex3f(23.5, -155.0, 35.0);
    glVertex3f(23.5, -145.5, 35.0);
    glVertex3f(70.0, -145.5, 35.0);
    glVertex3f(70.0, -155.0, 35.0);
    glEnd();
    //tengah atas
    glBegin(GL_QUADS);
    glColor3ub(202, 144, 101);
    glVertex3f(28.5, -145.5, 35.0);
    glVertex3f(31.5, -130.5, 35.0);
    glVertex3f(67.0, -130.5, 35.0);
    glVertex3f(70.0, -145.5, 35.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(202, 144, 101);
    glVertex3f(70.0, -155.0, 35.0);
    glVertex3f(70.0, -145.5, 35.0);
    glVertex3f(81.0, -145.5, 35.0);
    glVertex3f(81.0, -155.0, 35.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3ub(202, 144, 101);
    glVertex3f(31, -130.5, 35.0);
    glVertex3f(67, -130.5, 35.0); //belakang
    glVertex3f(67, -130.5, 55.0); //depan kanan
    glVertex3f(31, -130.5, 55.0); //depan kiri
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(202, 144, 101);
    glVertex3f(67.0, -130.0, 55.0);
    glVertex3f(70.0, -145.0, 55.0);
    glVertex3f(70.0, -145.0, 35.0);
    glVertex3f(67.0, -130.0, 35.0);
    glEnd();
    //kaca-depan
    glBegin(GL_QUADS);
    glColor3ub(250, 234, 221);
    glVertex3f(67.1, -130.0, 53.0);
    glVertex3f(70.1, -145.0, 53.0);
    glVertex3f(70.1, -145.0, 38.0);
    glVertex3f(67.1, -130.0, 38.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
glColor3ub(250, 234, 221);
    glVertex3f(31.0, -130.0, 55.0);
    glVertex3f(28.0, -145.0, 55.0);
    glVertex3f(28.0, -145.0, 35.0);
    glVertex3f(31.0, -130.0, 35.0);
    glEnd();
    //tutup cap depan
    glBegin(GL_QUADS);
    glColor3ub(202, 144, 101);
    glVertex3f(67, -145.5, 55.0);
    glVertex3f(80, -145.5, 55.0);
    glVertex3f(80, -145.5, 35.0);
    glVertex3f(67, -145.5, 35.0);
    glEnd();
    //tutup cap belakang
    glBegin(GL_QUADS);
    glColor3ub(202, 144, 101);
    glVertex3f(23, -145.5, 55.0);
    glVertex3f(28, -145.5, 55.0);
    glVertex3f(28, -145.5, 35.0);
    glVertex3f(23, -145.5, 35.0);
    glEnd();
    //tempat lampu
    //depan
    glBegin(GL_QUADS);
    glColor3ub(205, 222, 222);
    glVertex3f(81.0, -145.0, 55.0);
    glVertex3f(81.0, -155.0, 55.0);
    glVertex3f(81.0, -155.0, 35.0);
    glVertex3f(81.0, -145.0, 35.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(205, 222, 222);
    glVertex3f(23.0, -145.0, 55.0);
    glVertex3f(23.0, -155.0, 55.0);
    glVertex3f(23.0, -155.0, 35.0);
    glVertex3f(23.0, -145.0, 35.0);
    glEnd();
    //jendela 1
    glBegin(GL_QUADS);
    glColor3ub(250, 234, 221);
    glVertex3f(50.5, -145.5, 55.1);
    glVertex3f(50.5, -130.5, 55.1);
    glVertex3f(62.0, -130.5, 55.1);
    glVertex3f(66.0, -145.5, 55.1);
    glEnd();
    //jendela 1
    glBegin(GL_QUADS);
    glColor3ub(250, 234, 221);
    glVertex3f(50.5, -145.5, 34.1);
    glVertex3f(50.5, -130.5, 34.1);
    glVertex3f(62.0, -130.5, 34.1);
    glVertex3f(66.0, -145.5, 34.1);
    glEnd();

    //jendela 1
    glBegin(GL_QUADS);
    glColor3ub(250, 234, 221);
    glVertex3f(32.0, -145.5, 55.1);
    glVertex3f(34.0, -130.5, 55.1);
    glVertex3f(48.5, -130.5, 55.1);
    glVertex3f(48.5, -145.5, 55.1);
    glEnd();
    //jendela 1
    glBegin(GL_QUADS);
    glColor3ub(250, 234, 221);
    glVertex3f(32.0, -145.5, 34.1);
    glVertex3f(34.0, -130.5, 34.1);
    glVertex3f(48.5, -130.5, 34.1);
    glVertex3f(48.5, -145.5, 34.1);
    glEnd();

    //ban depan1
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);

    radius = 400;
    jumlah_titik = 60;
    x_tengah = 3500;
    y_tengah = -15500;

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x / 100, y / 100, 55.1);
    }
    glEnd();
    glFlush();

    //ban depan2
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);

    radius = 400;
    jumlah_titik = 60;
    x_tengah = 6700;
    y_tengah = -15500;

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x / 100, y / 100, 55.1);
    }
    glEnd();
    glFlush();

    //ban belakang1
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);

    radius = 400;
    jumlah_titik = 60;
    x_tengah = 3500;
    y_tengah = -15500;

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x / 100, y / 100, 34.9);
    }
    glEnd();
    glFlush();

    //ban belakang2
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);

    radius = 400;
    jumlah_titik = 60;
    x_tengah = 6700;
    y_tengah = -15500;

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x / 100, y / 100, 34.9);
    }
    glEnd();
    glFlush();
    glPopMatrix();


}



void timer(int t)
{
    if (atas) {
        gerak += 1;
    }
    else {
        gerak -= 1;
    }
    if (gerak > 180) {
        atas = false;
    }
    else if (gerak < -40) {
        atas = true;
    }
    glutPostRedisplay();

    /*
    kecepatan mobil berbanding terbalik
    semakin besar nilai glutTimerFunc maka akan semakin pelan gerakannya
    note: angka 50
    */
    glutTimerFunc(50, timer, 0);
}


void timer2(int t)
{
    if (atas) {
        gerak2 += 1;
    }
    else {
        gerak2 -= 1;
    }
    if (gerak2 > 320) {
        atas = false;
    }
    else if (gerak2 < -320) {
        atas = true;
    }


    glutPostRedisplay();


    glutTimerFunc(200, timer2, 0);
}



void geser(void)
{
  glTranslatef(-7.0,0.0,0.0);
parkiran();
}

void vertex(double th2,double ph2)
{
   double x = Sin(th2)*Cos(ph2);
   double y = Cos(th2)*Cos(ph2);
   double z =          Sin(ph2);
   glVertex3d(x,y,z);
}

void ball(void)
{
        glPushMatrix();
    glTranslatef(gerak2, 20, 0);
    int th2, ph2;
    for (ph2=-90;ph2<90;ph2+=DEF_D) {
      glBegin(GL_QUAD_STRIP);
      for (th2=0;th2<=360;th2+=2*DEF_D) {
	glColor3ub(250, 255, 0);
	vertex(th2,ph2);
	glColor3ub(250, 255, 0);
	vertex(th2,ph2+DEF_D);
      }
      glEnd();
    }
    glFlush();
    glPopMatrix();

}



void tampil(void)
{
        if(is_depth)
        {glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
    else
        {glClear(GL_COLOR_BUFFER_BIT);}

glDisable(GL_LIGHTING);

    glPushMatrix();
  glScalef(2.0f,2.0f,2.0f);
furnitur();
atas1();

 glTranslatef(21.0,0.0,15.0);
belakang();
depan();
geser();
glTranslatef(-1.0,0.0,0.0);
samping();
 glRotatef(-90.0f,-1.0f,0.0f,0.0f);
  glTranslatef(0.0,32.0,20.0);
  glScalef(0.2f,0.2f,0.2f);
mobil();
  glScalef(10.0f,10.0f,10.0f);
  glTranslatef(-20.0,0.0,-10.0);
ball();
	glPopMatrix();
	glutSwapBuffers();
}

void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
        glLoadIdentity();
    gluLookAt(0.0f,0.0f, gg, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    }
}

void keyboard(unsigned char key, int x, int y)
{
switch (key)
{
case 'w':
case 'W':
    glTranslatef(0.0,0.0,3.0);
    break;
    //atur kamera zoom
case '+':
case '=':
    gg=gg-3.0;
    glTranslatef(0.0,0.0,3.0);
    break;
    //atur kamera zoom
case '-':
case '_':
    gg=gg+3.0;
    glTranslatef(0.0,0.0,-3.0);
    break;
    case ']':
case '}':
    gg=gg-3.0;
    glTranslatef(0.0,0.0,-3.0);
    break;
    //atur kamera zoom
case '{':
case '[':
    gg=gg+3.0;
    glTranslatef(0.0,0.0,3.0);
    break;
    case 'd':
case 'D':
    glTranslatef(3.0,0.0,0.0);
    break;
    case 's':
case 'S':
    glTranslatef(0.0,0.0,-3.0);
    break;
    case 'a':
case 'A':
    glTranslatef(-3.0,0.0,0.0);
    break;
    case '7':
    glTranslatef(0.0,3.0,0.0);
    break;

    case '9':
    glTranslatef(0.0,-3.0,0.0);
    break;

    case '2':
    glRotatef(2.0,1.0,0.0,0.0);
    break;
    case '8':
    glRotatef(-2.0,1.0,0.0,0.0);
    break;
    case '6':
    glRotatef(2.0,0.0,1.0,0.0);
    break;
    case '4':
    glRotatef(-2.0,0.0,1.0,0.0);
    break;
    case '1':
    glRotatef(2.0,0.0,0.0,1.0);
    break;
    case '3':
    glRotatef(-2.0,0.0,0.0,1.0);
    break;
    case '5':
        if (is_depth)
        {
            is_depth =0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
}
tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("Grand Canyon Parkway");
    init();
	glutDisplayFunc(tampil);
    glutTimerFunc(1, timer, 0);
    glutTimerFunc(1, timer2, 0);
	glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
	glutReshapeFunc(ukuran);
	glutMotionFunc(mouseMotion);
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}
