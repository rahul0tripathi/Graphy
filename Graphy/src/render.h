#ifdef __APPLE__
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include <GL/glut.h>
#endif
#include "./bar/bargraph.h"
#include "../include/datasource/csv.h"
initConfig config;
parsedCsvBarData dataset;
void loadDataAndRender(){
    renderBarGraph(dataset);
}
void persistConfig(initConfig init){
    config = init;
    dataset = parseCsvBarData(config.filePath);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    loadDataAndRender();
    glutPostRedisplay();
    glutSwapBuffers();
}
