

#ifndef bargraph_h
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include <GL/glut.h>
#endif
#include "iostream"
#include "../../include/datasource/csv.h"
#define bargraph_h
void renderBarGraph(parsedCsvBarData data){
    GLint k;
    GLint xRaster = 20, yRaster = 60;
    GLint yRasterTop = 10;
    glColor3f (0.8, 0.8, 1);
    for (k = 0; k < data.values.size(); k++)
        glRecti (20 + k*50, yRaster + 20, 40 + k*50, (yRaster + data.values[k]));
    
    glColor3f (1.0, 1.0, 1.0);
    xRaster = 20;
    for (int m = 0; m < data.labels.size(); m++) {
        glRasterPos2i (xRaster, yRaster);
        string val = data.labels[m];
        for (k = 0; k < 3 + 3; k++)
            glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, (GLubyte)val[k]);
        xRaster += 50;
    }
    xRaster = 20;
    for (int m = 0; m < data.labels.size(); m++) {
        glRasterPos2i (xRaster, yRaster + yRasterTop + data.values[m]);
        char buffer[20] = "";
        sprintf(buffer,"%d",data.values[m]);
        for (k = 0; k < 3; k++)
            glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12,(GLubyte)buffer[k]);
        xRaster += 50;
    }
}

#endif /* bargraph_h */
