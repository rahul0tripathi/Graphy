#ifndef scatter_h
#define scatter_h
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include <GL/glut.h>
#endif
#include "iostream"
#include "../../include/datasource/csv.h"

void renderScatterGraph(parsedCsvBarData data){
    GLint k;
    GLint xRaster = 20, yRaster = 60;
    GLint yRasterTop = 10;
    glColor3f (0.3, 1, 0.5);
    // draw refrence line
    glBegin(GL_LINES);
        glVertex2f(40, 60);
        glVertex2f(940, 960);
    glEnd();
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    for (k = 0; k < data.values.size(); k++)
        glVertex2i (20 + k*10, (yRaster + data.values[k]));
    glEnd();
    glColor3f (1.0, 1.0, 1.0);
    xRaster = 20;
    for (int m = 0; m < data.labels.size(); m++) {
        glRasterPos2i (xRaster, yRaster + yRasterTop + data.values[m]);
        char buffer[20] = "";
        sprintf(buffer,"%d",data.values[m]);
        for (k = 0; k < 3; k++)
            glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12,(GLubyte)buffer[k]);
        xRaster += 10;
    }
}

#endif /* scatter_h */
