#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <stdio.h>

///Yang jadi score nantinya
int nilai = 0;
///Kecepatan tikus
int percepatan[] = {2, 3, 4, 3, 4, 2};
///Kehidupan tanaman
bool isLife[3][3] = {{true, true, true},
                     {true, true, true},
                     {true, true, true}};
///Muterin tongkat
int muter = 0;
///Gerakan
float KK = 0;
float AB = 0;
///Lining atau tempat gerak
int jalanY = 0;
int jalanX = 1;
///scene atau display
bool scene[] = {true, false, false, false};
///pilihan untuk scene awal dan akhir
float pilihan[] = {0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 1.0f};
/// X1, X2, Y1, Y2, kecepatan,batas kiri, batas kanan//pindahY//pindahX;
///variabel tikus
float DPR[6][9] = {
        {242.5f, 265.0f, 11.5f, 22.0f, 10.0f, 0.0f, 0.0f, 0.0f, 10.0f},
        {242.5f, 265.0f, 27.5f, 38.0f, 20.0f, 0.0f, 0.0f, 1.0f, 10.0f},
        {242.5f, 265.0f, 43.5f, 54.0f, 30.0f, 0.0f, 0.0f, 2.0f, 10.0f},
        {242.5f, 265.0f, 11.5f, 22.0f, 20.0f, 0.0f, 0.0f, 0.0f, 10.0f},
        {242.5f, 265.0f, 27.5f, 38.0f, 30.0f, 0.0f, 0.0f, 1.0f, 10.0f},
        {242.5f, 265.0f, 43.5f, 54.0f, 10.0f, 0.0f, 0.0f, 2.0f, 10.0f}
};
///orto
int ortho[] = {0, 228, 0, 120};
void *font = GLUT_BITMAP_HELVETICA_18;
void *font2 = GLUT_BITMAP_TIMES_ROMAN_24;

///Helvetica
void tulis(int x, int y, char *string) {
    glRasterPos2f(x, y);
    int len = (int) strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

///TimesRoman
void tulis2(int x, int y, char *string) {
    glRasterPos2f(x, y);
    int len = (int) strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font2, string[i]);
    }
}

///Seluruh tampilan keterangan
///bahasa inggris objectnya 1 dan belum siap ditampilin
///bahasa indonesia objectnya sudah siap dipanggil
void tentang() {
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(20, 50);
    glVertex2f(70, 50);
    glVertex2f(50, 0);
    glEnd();
}

void penunjuk() {
    glBegin(GL_POLYGON);
    glVertex2f(20, 15);
    glVertex2f(5, 25);
    glVertex2f(10, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(5, 5);
    glVertex2f(20, 15);
    glVertex2f(10, 15);
    glEnd();
}

void grass() {
    glColor3f(0, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex2f(3, 12);
    glVertex2f(4, 11);
    glVertex2f(5, 8);
    glVertex2f(5, 9);
    glVertex2f(5, 10);
    glVertex2f(5, 3);
    glVertex2f(4, 3);
    glVertex2f(4, 10);
    glVertex2f(3, 10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(4, 3);
    glVertex2f(3, 3);
    glVertex2f(3, 4);
    glVertex2f(3.5, 6);
    glVertex2f(3.5, 8);
    glVertex2f(3, 10);
    glVertex2f(3, 11);
    glVertex2f(2.5, 12);
    glVertex2f(3, 12);
    glVertex2f(4, 11);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(2, 12.5);
    glVertex2f(3, 12);
    glVertex2f(2.5, 12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(5, 9);
    glVertex2f(5, 10);
    glVertex2f(5.5, 11);
    glVertex2f(6, 13);
    glVertex2f(6.5, 14);
    glVertex2f(7, 14);
    glVertex2f(7, 11);
    glVertex2f(7.5, 10);
    glVertex2f(7.5, 3);
    glVertex2f(5, 3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(6.5, 14);
    glVertex2f(7.5, 15);
    glVertex2f(7, 14);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(7.5, 10);
    glVertex2f(8, 11);
    glVertex2f(9.5, 11);
    glVertex2f(9.5, 9);
    glVertex2f(8.5, 7);
    glVertex2f(9, 8);
    glVertex2f(9, 3);
    glVertex2f(7.5, 3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(8, 11);
    glVertex2f(8, 13);
    glVertex2f(9.5, 11);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(9, 8);
    glVertex2f(10, 9);
    glVertex2f(11, 9.5);
    glVertex2f(12, 9.5);
    glVertex2f(11, 9);
    glVertex2f(10.5, 8);
    glVertex2f(10.5, 5);
    glVertex2f(11, 4);
    glVertex2f(11, 3);
    glVertex2f(9, 3);
    glEnd();


    glColor3f(0, 1, 0);

    glLineWidth(3);

    glBegin(GL_LINE_STRIP);
    glVertex2f(4, 9);
    glVertex2f(4, 8);
    glVertex2f(4.5, 7);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(6, 10);
    glVertex2f(6, 8);
    glVertex2f(6.5, 7);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(8.5, 11);
    glVertex2f(8.5, 9);
    glVertex2f(8, 8);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(9.5, 7);
    glVertex2f(9, 6);
    glVertex2f(9, 5);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(4, 9);
    glVertex2f(4, 8);
    glVertex2f(4.5, 7);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(5, 9);
    glVertex2f(5, 10);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(7.5, 10);
    glVertex2f(7.5, 9);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(9, 8);
    glVertex2f(8.5, 7);
    glEnd();
}

void tongkat() {
    glColor3f(1, 1, 1);
    glTranslated(-6, -2, 0);
    glBegin(GL_POLYGON);
    glVertex2f(5.5, 3);
    glVertex2f(6, 3.5);
    glVertex2f(8, 3.5);
    glVertex2f(9, 3);
    glVertex2f(9, 2);
    glVertex2f(8, 2.5);
    glVertex2f(7, 2.5);
    glVertex2f(6, 2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(9, 3);
    glVertex2f(9, 2);
    glVertex2f(12, 2.5);
    glVertex2f(12, 2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(13, 3);
    glVertex2f(18, 3.5);
    glVertex2f(27, 3.5);
    glVertex2f(27.5, 3);
    glVertex2f(27.5, 2.5);
    glVertex2f(27, 2);
    glVertex2f(21, 2);
    glVertex2f(20, 2.5);
    glVertex2f(19, 2);
    glVertex2f(9, 2);
    glEnd();

    glColor3f(1, 0.4, 0);
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(6, 2.5);
    glVertex2f(6, 3);
    glVertex2f(6.5, 3);
    glVertex2f(6.5, 2.5);
    glVertex2f(7, 3);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(14, 2.5);
    glVertex2f(16, 2.5);
    glVertex2f(19, 3);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(21, 2.5);
    glVertex2f(23, 3);
    glVertex2f(24, 2.5);
    glVertex2f(26, 2.5);
    glEnd();
}

void snake() {
    //head
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0);
    glVertex2f(1.5, 4);
    glVertex2f(3, 3.5);
    glVertex2f(4, 4);
    glVertex2f(6, 6);
    glVertex2f(5, 7.5);
    glVertex2f(4, 7);
    glVertex2f(3, 7);
    glVertex2f(2, 6);
    glVertex2f(2, 5);
    glEnd();
    glBegin(GL_POLYGON);
    //mata
    glColor3f(1, 1, 1);
    glVertex2f(3, 5);
    glVertex2f(4, 5);
    glVertex2f(4.5, 6);
    glVertex2f(5, 6.5);
    glVertex2f(4, 6);
    glVertex2f(3.5, 5.5);
    glEnd();
    glBegin(GL_POLYGON);
    //retina
    glColor3f((1), (102 / 255), 0);
    glVertex2f(4, 5);
    glVertex2f(4, 6);
    glVertex2f(3.5, 5.5);
    glEnd();

    //body
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0);
    glVertex2f(6, 6);
    glVertex2f(5, 7.5);
    glVertex2f(7, 8);
    glVertex2f(8, 7);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(7, 8);
    glVertex2f(10, 8);
    glVertex2f(13, 7);
    glVertex2f(16, 5);
    glVertex2f(18, 3.5);
    glVertex2f(18, 2.5);
    glVertex2f(15, 4);
    glVertex2f(12, 6);
    glVertex2f(10, 7);
    glVertex2f(8, 7);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(18, 3.5);
    glVertex2f(21, 2.5);
    glVertex2f(21, 1.5);
    glVertex2f(18, 2.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(21, 2.5);
    glVertex2f(23, 2);
    glVertex2f(26, 2);
    glVertex2f(26, 1.5);
    glVertex2f(23, 1);
    glVertex2f(21, 1.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(26, 2);
    glVertex2f(26, 1.5);
    glVertex2f(28, 3);
    glEnd();
}

void mouse() {
    //joint
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(3, 8);
    glVertex2f(2.5, 7.5);
    glVertex2f(2.5, 7);
    glVertex2f(3, 6.5);
    //heada
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(3, 8);
    glVertex2f(3.5, 9);
    glVertex2f(4, 9.5);
    glVertex2f(4.5, 10);
    glVertex2f(5, 10);
    glVertex2f(5.5, 10.5);
    glVertex2f(5.5, 11);
    glVertex2f(8, 11);
    glVertex2f(8, 6);
    glVertex2f(7, 6);
    glVertex2f(6, 5.5);
    glVertex2f(4.5, 5.5);
    glVertex2f(4.5, 6);
    glVertex2f(4, 6);
    glVertex2f(3.5, 6);
    glVertex2f(3, 6.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(5.5, 11);
    glVertex2f(6.5, 13);
    glVertex2f(7.5, 13);
    glVertex2f(8, 12);
    glVertex2f(8, 11);
    glVertex2f(5.5, 11);
    glEnd();
    //body
    glBegin(GL_POLYGON);
    glVertex2f(8, 11);
    glVertex2f(9, 11.5);
    glVertex2f(9.5, 12);
    glVertex2f(11, 12.5);
    glVertex2f(16, 12.5);
    glVertex2f(17, 12);
    glVertex2f(18, 11);
    glVertex2f(18.5, 10);
    glVertex2f(18.5, 9);
    glVertex2f(18.5, 8);
    glVertex2f(18, 7.5);
    glVertex2f(18, 6.5);
    glVertex2f(17.5, 5.5);
    glVertex2f(14.5, 5);
    glVertex2f(14, 5.5);
    glVertex2f(13.5, 5);
    glVertex2f(10.5, 5);
    glVertex2f(10, 5.5);
    glVertex2f(9.5, 5.5);
    glVertex2f(8.5, 5.5);
    glVertex2f(8, 6);
    glEnd();
    //kaki
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(8.5, 5.5);
    glVertex2f(8.5, 4.5);
    glVertex2f(9.5, 4.5);
    glVertex2f(9.5, 5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(8.5, 4.5);
    glVertex2f(7, 3);
    glVertex2f(7, 2.5);
    glVertex2f(8, 2.5);
    glVertex2f(8.5, 3);
    glVertex2f(9.5, 4.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(8.5, 2.5);
    glVertex2f(8.5, 3);
    glVertex2f(9.5, 4.5);
    glVertex2f(9.5, 2.5);
    glEnd();
    //kaki balakang
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(14.5, 5);
    glVertex2f(13, 3);
    glVertex2f(13.5, 2.5);
    glVertex2f(15, 4);
    glVertex2f(16, 4);
    glVertex2f(17.5, 5.5);
    glVertex2f(18, 6.5);
    glVertex2f(18, 7.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(17.5, 5.5);
    glVertex2f(16, 3);
    glVertex2f(16, 2.5);
    glVertex2f(15, 2.5);
    glVertex2f(15.5, 3);
    glVertex2f(16, 4);
    glEnd();
    //telapak kaki balakang
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(13, 3);
    glVertex2f(12, 3);
    glVertex2f(12, 2.5);
    glVertex2f(13.5, 2.5);
    glEnd();
    //tail
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(17.5, 9.5);
    glVertex2f(18, 6.5);
    glVertex2f(20, 7);
    glVertex2f(20, 8);
    glVertex2f(19, 7.5);
    glVertex2f(18.5, 8);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(20, 8);
    glVertex2f(21, 8);
    glVertex2f(23, 8.5);
    glVertex2f(23, 7.5);
    glVertex2f(21, 7);
    glVertex2f(20, 7);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(21, 8);
    glVertex2f(23, 8.5);
    glVertex2f(23, 7.5);
    glVertex2f(21, 7);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(23, 8.5);
    glVertex2f(24.5, 9.5);
    glVertex2f(25, 9);
    glVertex2f(23, 7.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.5, 9.5);
    glVertex2f(24.5, 10);
    glVertex2f(25, 10);
    glVertex2f(25, 9);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.5, 10);
    glVertex2f(24, 11);
    glVertex2f(24.5, 11);
    glVertex2f(25, 10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24, 11);
    glVertex2f(23.5, 11.5);
    glVertex2f(24, 11.5);
    glVertex2f(24.5, 11);
    glEnd();
    //eyesofheaven
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex2f(5.5, 9.5);
    glVertex2f(5.5, 9);
    glVertex2f(6, 9);
    glVertex2f(6, 9.5);
    glEnd();
    //redspot
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(2, 7.5);
    glVertex2f(2, 7);
    glVertex2f(2.5, 7);
    glVertex2f(2.5, 7.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex2f(6, 11);
    glVertex2f(7, 11);
    glVertex2f(6.5, 12);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex2f(4.5, 6);
    glVertex2f(4.5, 5.5);
    glVertex2f(4, 6);
    glEnd();
    //lines
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(4, 8);
    glVertex2f(5.5, 8.5);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(4, 7.5);
    glVertex2f(5, 8);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(5, 8);
    glVertex2f(6, 8);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(4, 7);
    glVertex2f(5, 7.5);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(5, 7.5);
    glVertex2f(6, 7);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(6.5, 12);
    glVertex2f(7, 12.5);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(8, 9);
    glVertex2f(8, 8);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(8, 8);
    glVertex2f(7.5, 7);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(14, 5.5);
    glVertex2f(13.5, 6.5);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(13.5, 6.5);
    glVertex2f(13.5, 8.5);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(14, 9.5);
    glVertex2f(13.5, 8.5);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(14, 9.5);
    glVertex2f(15, 9.5);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(18, 6.5);
    glVertex2f(18, 7.5);
    glEnd();
}

void mountain() {
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(1, 1);
    glVertex2f(1, 6);
    glVertex2f(2, 9);
    glVertex2f(6, 15);
    glVertex2f(7, 16);
    glVertex2f(10, 18);
    glVertex2f(12, 19);
    glVertex2f(17, 24);
    glVertex2f(17, 1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(17, 1);
    glVertex2f(17, 24);
    glVertex2f(18, 27);
    glVertex2f(21, 32);
    glVertex2f(22, 33);
    glVertex2f(26, 39);
    glVertex2f(29, 43);
    glVertex2f(29, 44);
    glVertex2f(31, 45);
    glVertex2f(35, 45);
    glVertex2f(35, 46);
    glVertex2f(36, 46);
    glVertex2f(38, 45);
    glVertex2f(39, 45);
    glVertex2f(41, 43);
    glVertex2f(43, 42);
    glVertex2f(46, 38);
    glVertex2f(48, 36);
    glVertex2f(52, 29);
    glVertex2f(52, 28);
    glVertex2f(54, 25);
    glVertex2f(55, 22);
    glVertex2f(57, 20);
    glVertex2f(63, 15);
    glVertex2f(63, 14);
    glVertex2f(66, 13);
    glVertex2f(67, 12);
    glVertex2f(75, 10);
    glVertex2f(76, 11);
    glVertex2f(80, 5);
    glVertex2f(90, 1);
    glEnd();
}

void cloud() {
    glBegin(GL_POLYGON);
    glVertex2f(5, 2.5);
    glVertex2f(3, 3);
    glVertex2f(2, 4);
    glVertex2f(2, 5);
    glVertex2f(3, 6);
    glVertex2f(5, 6.5);
    glVertex2f(20, 6.5);
    glVertex2f(22, 6);
    glVertex2f(23, 5);
    glVertex2f(23, 4);
    glVertex2f(21, 2.5);
    glEnd();
}

void gunung() {
    glPushMatrix();
    glTranslated(0, 180, 0);
    glScaled(6, 2, 0);
    mountain();
    glPopMatrix();
}

void awan() {
    glPushMatrix();
    glTranslated(0, 250, 0);
//awan1
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslated(-1, -1, 0);
    glScaled(4, 3, 0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
    glTranslated(-2, 0, 0);
    glScaled(4, 3, 0);
    cloud();
    glPopMatrix();
//awan2
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslated(11, 19, 0);
    glScaled(4, 2, 0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
    glTranslated(10, 20, 0);
    glScaled(4, 2, 0);
    cloud();
    glPopMatrix();
//awan3
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslated(161, -16, 0);
    glScaled(3, 4, 0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
    glTranslated(160, -15, 0);
    glScaled(3, 4, 0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslated(101, -21, 0);
    glScaled(6, 3, 0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
    glTranslated(100, -20, 0);
    glScaled(6, 3, 0);
    cloud();
    glPopMatrix();
//awan4
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslated(251, -16, 0);
    glScaled(2, 4, 0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
    glTranslated(250, -15, 0);
    glScaled(2, 4, 0);
    cloud();
    glPopMatrix();
//awan5
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslated(22, -42, 0);
    glScaled(4, 2, 0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
    glTranslated(21, -41, 0);
    glScaled(4, 2, 0);
    cloud();
    glPopMatrix();
//awan6
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
    glTranslated(401, -6, 0);
    glScaled(4, 2, 0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslated(430, -10, 0);
    glScaled(6, 5, 0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslated(320, 0, 0);
    glScaled(6, 3, 0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslated(400, 14, 0);
    glScaled(4, 2, 0);
    cloud();
    glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);

    glPushMatrix();
    glTranslated(400, -5, 0);
    glScaled(4, 2, 0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslated(429, -9, 0);
    glScaled(6, 5, 0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslated(319, 1, 0);
    glScaled(6, 3, 0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslated(399, 15, 0);
    glScaled(4, 2, 0);
    cloud();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}

void rumput() {
    glPushMatrix();
    glTranslated(15, 20, 0);
    if (isLife[0][2]) {
        glPushMatrix();
        glTranslated(0, 0, 0);
        glScaled(3, 3, 1);
        grass();
        glPopMatrix();
    }
    if (isLife[1][2]) {
        glPushMatrix();
        glTranslated(0, 40, 0);
        glScaled(3, 3, 1);
        grass();
        glPopMatrix();
    }
    if (isLife[2][2]) {
        glPushMatrix();
        glTranslated(0, 80, 0);
        glScaled(3, 3, 1);
        grass();
        glPopMatrix();
    }
    if (isLife[0][1]) {
        glPushMatrix();
        glTranslated(40, 0, 0);
        glScaled(3, 3, 1);
        grass();
        glPopMatrix();
    }
    if (isLife[1][1]) {
        glPushMatrix();
        glTranslated(40, 40, 0);
        glScaled(3, 3, 1);
        grass();
        glPopMatrix();
    }
    if (isLife[2][1]) {
        glPushMatrix();
        glTranslated(40, 80, 0);
        glScaled(3, 3, 1);
        grass();
        glPopMatrix();
    }
    if (isLife[0][0]) {
        glPushMatrix();
        glTranslated(80, 0, 0);
        glScaled(3, 3, 1);
        grass();
        glPopMatrix();
    }
    if (isLife[1][0]) {
        glPushMatrix();
        glTranslated(80, 40, 0);
        glScaled(3, 3, 1);
        grass();
        glPopMatrix();
    }
    if (isLife[2][0]) {
        glPushMatrix();
        glTranslated(80, 80, 0);
        glScaled(3, 3, 1);
        grass();
        glPopMatrix();
    }
    glPopMatrix();
}

void background() {
    glPushMatrix();
    glColor3f(1, 0.4, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(570, 0);
    glVertex2f(570, 182);
    glVertex2f(0, 182);
    glEnd();
    glColor3f(0.6, 10, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0, 300);
    glVertex2f(570, 300);
    glVertex2f(570, 182);
    glVertex2f(0, 182);
    glEnd();
    glPopMatrix();
}

void developer() {
    glPushMatrix();
    glTranslated(40, 90, 0);
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glScaled(6, 3, 1);
    tentang();
    glTranslated(1, 1, 1);
    glColor3f(1, 1, 1);
    tentang();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(140, 110, 0);
    glPushMatrix();
    glScaled(3, 3, 0);
    tulis(0, 0, "Project Manager : Mokhamad Asif");
    tulis(0, -10, "Programmer        : Mokhamad Asif");
    tulis(0, -20, "Design Artist      : Mokhamad Asif");
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

}

///membuat tulisan dengan model angka 8
void palang() {
    glBegin(GL_POLYGON);
    glVertex2f(2, 5);
    glVertex2f(8, 5);
    glVertex2f(10, 10);
    glVertex2f(10, 30);
    glVertex2f(8, 35);
    glVertex2f(2, 35);
    glVertex2f(0, 30);
    glVertex2f(0, 10);
    glEnd();

}

void play() {
    glPushMatrix();
//P
    glPushMatrix();
    glTranslated(0, 0, 0);
    //kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
    //kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
    //kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
    //tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    //atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
    //L
    glPushMatrix();
    glTranslated(60, 0, 0);
    //kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
    //kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
    //bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
//A
    glPushMatrix();
    glTranslated(120, 0, 0);
    //kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
    //kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
    //kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
    //kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();

    //tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    //atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();

//Y
    glPushMatrix();
    glTranslated(180, 0, 0);

    //kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
    //kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
    //kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();

    //tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    //bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

}

void about() {
    glPushMatrix();
//A
    glPushMatrix();
    glTranslated(0, 0, 0);
//kiri atas
    glPushMatrix();
    palang();
    glPopMatrix();
    //kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
    //kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
    //kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();

    //tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    //atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
//B
    glPushMatrix();
    glTranslated(60, 0, 0);
    //kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
    //kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();

    //tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();

//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
//0
    glPushMatrix();
    glTranslated(120, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
//kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();

//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
//U
    glPushMatrix();
    glTranslated(180, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
//kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();

    glPopMatrix();
//T
    glPushMatrix();
    glTranslated(240, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();

//tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

}

void delapan() {
//8
    glPushMatrix();
    glTranslated(0, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
//kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();
//tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();

}

void exit() {
    glPushMatrix();
//E
    glPushMatrix();
    glTranslated(0, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
//X
    glPushMatrix();
    glTranslated(60, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
//kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();
//tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
//I
    glPushMatrix();
    glTranslated(120, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
    glPopMatrix();
//T
    glPushMatrix();
    glTranslated(140, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

}

void BACK() {
    glPushMatrix();
    //B
    glPushMatrix();
    glTranslated(0, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
//kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();
//tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
//A
    glPushMatrix();
    glTranslated(60, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
//kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();
//tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
//C
    glPushMatrix();
    glTranslated(120, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
//K
    glPushMatrix();
    glTranslated(180, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
//kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();
//tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}

void gameover() {
    glPushMatrix();
//G
    glPushMatrix();
    glTranslated(0, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();
//tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
//A
    glPushMatrix();
    glTranslated(60, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
//kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();
//tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
//M
    glPushMatrix();
    glTranslated(120, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
//kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();
//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//kanan atas
    glPushMatrix();
    glTranslated(80, 40, 0);
    palang();
    glPopMatrix();
//kanan bawah
    glPushMatrix();
    glTranslated(80, 0, 0);
    palang();
    glPopMatrix();
//atas
    glPushMatrix();
    glTranslated(85, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();

    glPopMatrix();
//E
    glPushMatrix();
    glTranslated(220, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();

//O
    glPushMatrix();
    glTranslated(300, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
//kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();
//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
//V
    glPushMatrix();
    glTranslated(360, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//kanan atas
    glPushMatrix();
    glTranslated(40, 40, 0);
    palang();
    glPopMatrix();
//kanan bawah
    glPushMatrix();
    glTranslated(40, 0, 0);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();

//E
    glPushMatrix();
    glTranslated(420, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//tengah
    glPushMatrix();
    glTranslated(45, 35, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
//bawah
    glPushMatrix();
    glTranslated(45, -5, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
//R
    glPushMatrix();
    glTranslated(480, 0, 0);
//kiri bawah
    glPushMatrix();
    palang();
    glPopMatrix();
//kiri atas
    glPushMatrix();
    glTranslated(0, 40, 0);
    palang();
    glPopMatrix();
//atas
    glPushMatrix();
    glTranslated(45, 75, 0);
    glRotated(90, 0, 0, 1);
    palang();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

}

///scene
void backgroundawal() {
    glPushMatrix();
    glScaled(0.4, 0.4, 1);
    background();
    gunung();
    awan();
    glPushMatrix();
    glTranslated(150, 190, 0);
    glTranslated(pilihan[0], pilihan[1], 0);

    glScaled(2, 2, 0);
    glColor3f(0.4, 0.4, 0.4);
    penunjuk();
    glTranslated(2, 0, 0);
    glColor3f(1, 1, 1);
    glPushMatrix();
    penunjuk();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 0, 0);
    rumput();
    glPopMatrix();
    glPushMatrix();
    glTranslated(200, 0, 0);
    rumput();
    glPopMatrix();
    glPushMatrix();
    glTranslated(400, 0, 0);
    rumput();
    glPopMatrix();
    glPushMatrix();
    glTranslated(200, 200, 0);
    glScaled(0.5, 0.5, 1);
    glPushMatrix();
    if (pilihan[2] == 2) {
        glColor3f(1, 1, 1);
    } else { glColor3f(0, 0, 0); }
    play();
    glPopMatrix();
    glPushMatrix();
    if (pilihan[2] == 1) {
        glColor3f(1, 1, 1);
    } else { glColor3f(0, 0, 0); }
    glTranslated(0, -100, 0);
    about();
    glPopMatrix();
    glPushMatrix();
    if (pilihan[2] == 0) {
        glColor3f(1, 1, 1);
    } else { glColor3f(0, 0, 0); }
    glTranslated(0, -200, 0);
    exit();
    glPopMatrix();
    glPopMatrix();
    if (scene[3]) {
        developer();
    }


    glPopMatrix();
}

void backgroundakhir() {
    glPushMatrix();
    glScaled(0.4, 0.4, 1);
    background();
    gunung();
    awan();

    glPushMatrix();
    glTranslated(120, 105, 0);
    glTranslated(0, pilihan[4], 0);
    glScaled(2, 2, 0);
    glColor3f(0.4, 0.4, 0.4);
    penunjuk();
    glTranslated(2, 0, 0);
    glColor3f(1, 1, 1);
    glPushMatrix();
    penunjuk();
    glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    glTranslated(80, 190, 0);
    glScaled(0.8, 0.8, 0.8);
    glColor3f(0, 0, 0);
    gameover();
    glTranslated(120, -100, 0);
    glScaled(0.75, 0.75, 0.75);
    glColor3f(0, 0, 0);
    glPushMatrix();
    if (pilihan[5] == 1) {
        glColor3f(1, 1, 1);
    } else glColor3f(0, 0, 0);
    BACK();
    glPopMatrix();
    glTranslated(0, -100, 0);
    glPushMatrix();
    if (pilihan[5] == 0) {
        glColor3f(1, 1, 1);
    } else glColor3f(0, 0, 0);
    exit();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslated(200, 170, 0);
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslated(-10, -10, 1);
    glScaled(3, 3, 1);
    cloud();
    glPopMatrix();
    glColor3f(0, 0, 0);
    tulis(0, 0, "Score :");
    char score[100] = {"0"};
    sprintf(score, "%i", nilai); //konversi time ke label
    tulis(30, 0, score);
    glPopMatrix();
    glPopMatrix();
}

///Penempatan tikus/musuh
void tikus1() {
    glPushMatrix();
    glTranslated(240, 9, 0);
    mouse();
    glPopMatrix();
}

void tikus2() {
    glPushMatrix();
    glTranslated(240, 25, 0);
    mouse();
    glPopMatrix();
}

void tikus3() {
    glPushMatrix();
    glTranslated(240, 41, 0);
    mouse();
    glPopMatrix();
}

///biar tongkatnya muter muter
void putar(int a) {
    muter -= 10;
    glutPostRedisplay();
    glutTimerFunc(10, putar, 1);
}

///Pergerakan logic pembunuhan penghabisan rumput
void timer(int a) {
    if (scene[1]) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (DPR[i][7] == j) {
                    if (DPR[i][4] <= -195 && isLife[j][0]) {
                        DPR[i][4] += 195;
                        isLife[j][0] = false;
                    }
                    if (DPR[i][4] <= -210 && isLife[j][1]) {
                        DPR[i][4] += 210;
                        isLife[j][1] = false;
                    }
                    if (DPR[i][4] <= -225 && isLife[j][2]) {
                        DPR[i][4] += 225;
                        isLife[j][2] = false;
                    }
                }
            }
        }
        for (int i = 0; i < 6; i++) {
            DPR[i][4] -= percepatan[i];
            if (DPR[i][4] <= -75) {
                DPR[i][8] = 7;
            }
            if (DPR[i][4] <= -91) {
                DPR[i][8] = 6;
            }
            if (DPR[i][4] <= -107) {
                DPR[i][8] = 5;
            }
            if (DPR[i][4] <= -123) {
                DPR[i][8] = 4;
            }
            if (DPR[i][4] <= -139) {
                DPR[i][8] = 3;
            }
            if (DPR[i][4] <= -155) {
                DPR[i][8] = 2;
            }
            if (DPR[i][4] <= -171) {
                DPR[i][8] = 1;
            }
            if (DPR[i][4] <= -187) {
                DPR[i][8] = 0;
            }
            if (DPR[i][4] <= -203) {
                DPR[i][8] = -1;
            }
            if (DPR[i][4] <= -219) {
                DPR[i][8] = -2;
            }
            if (jalanX == DPR[i][8] && jalanY == DPR[i][7]) {
                DPR[i][4] += 219;
                DPR[i][8] = 10;
                nilai += 1;
            }
            if (DPR[i][4] <= -250) {
                scene[1] = false;
                scene[2] = true;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(100, timer, 1);
}

///Pemanggilan tikus/musuh
void musuh() {
    glPushMatrix();
    glPushMatrix();
    glTranslated(DPR[0][4], 0, 0);
    tikus1();
    glPopMatrix();

    glPushMatrix();
    glTranslated(DPR[1][4], 0, 0);
    tikus2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(DPR[2][4], 0, 0);
    tikus3();
    glPopMatrix();

    glPushMatrix();
    glTranslated(DPR[3][4], 0, 0);
    tikus1();
    glPopMatrix();

    glPushMatrix();
    glTranslated(DPR[4][4], 0, 0);
    tikus2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(DPR[5][4], 0, 0);
    tikus3();
    glPopMatrix();

    glPopMatrix();
}

///Logic inputan
void kanankiriatasbawah(int key, int x, int y) {
    if (scene[0]) {
        switch (key) {
            case 103:
                if (pilihan[2] != 0 && !scene[3]) {
                    pilihan[1] -= 50;
                    pilihan[2] -= 1;
                }
                break;
            case 101:
                if (pilihan[2] != 2 && !scene[3]) {
                    pilihan[1] += 50;
                    pilihan[2] += 1;
                }
                break;
            case 102:
            case 100:
                if (pilihan[2] == 2) {
                    scene[0] = false;
                    scene[1] = true;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            isLife[i][j] = true;
                        }
                    }
                    DPR[0][4] = 10;
                    DPR[1][4] = 20;
                    DPR[2][4] = 30;
                    DPR[3][4] = 20;
                    DPR[4][4] = 30;
                    DPR[5][4] = 10;
                    nilai = 0;
                } else if (pilihan[2] == 1) {
                    if (scene[3]) {
                        scene[3] = false;
                    } else scene[3] = true;
                } else if (pilihan[2] == 0) {
                    exit(1);
                }
                break;
        }
    }
    if (scene[1]) {
        switch (key) {
            case 103:
                if (jalanY != 0) {
                    AB -= 16;
                    jalanY -= 1;
                }
                break;
            case 101:
                if (jalanY != 2) {
                    AB += 16;
                    jalanY += 1;
                }
                break;
            case 102:
                if (jalanX != 7) {
                    KK += 16;
                    jalanX += 1;
                }
                break;
            case 100:
                if (jalanX != -2) {
                    KK -= 16;
                    jalanX -= 1;
                }
                break;
        }
    }
    if (scene[2]) {
        switch (key) {
            case 103:
                if (pilihan[5] != 0) {
                    pilihan[4] -= 50;
                    pilihan[5] -= 1;
                }
                break;
            case 101:
                if (pilihan[5] != 1) {
                    pilihan[4] += 50;
                    pilihan[5] += 1;
                }
                break;
            case 102:
            case 100:
                if (pilihan[5] == 1) {
                    scene[0] = true;
                    scene[2] = false;
                } else if (pilihan[5] == 0) {
                    exit(1);
                }
                break;
        }
    }
    glutPostRedisplay();
}

///Persiapan sebelum dipanggil dimain
void pentung() {
    glPushMatrix();
    glTranslated(60, 15, 0);
    glRotated(muter, 0, 0, 1);
    tongkat();
    glPopMatrix();
}

///main
void maen() {
    glPushMatrix();
    glScaled(0.4, 0.4, 1);
    background();
    gunung();
    awan();
    rumput();
    glPopMatrix();
    glPushMatrix();
    glTranslated(11, 104, 0);
    glColor3f(0, 0, 0);
    tulis(0, 0, "Score :");
    char score[100] = {"0"};
    sprintf(score, "%i", nilai); //konversi time ke label
    tulis(15, 0, score);
    glPopMatrix();
    musuh();
    glPushMatrix();
    glTranslated(KK, AB, 0);
    pentung();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (scene[0]) {
        backgroundawal();
    }
    if (scene[1]) {
        maen();
    }
    if (scene[2]) {
        backgroundakhir();
    }
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1368, 728);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Kelompok A");
    gluOrtho2D(ortho[0], ortho[1], ortho[2], ortho[3]);
    glClearColor(1, 1, 1, 1);
    glutSpecialFunc(kanankiriatasbawah);
    glutTimerFunc(10, timer, 0);
    glutTimerFunc(10, putar, 1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
