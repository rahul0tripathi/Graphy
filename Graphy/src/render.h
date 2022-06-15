#ifdef __APPLE__
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include <GL/glut.h>
#endif
#include "iostream"
#include "./bar/bargraph.h"
#include "./scatter/scatter.h"
#include "../include/datasource/csv.h"
#include "keyboard.h"
initConfig config;
parsedCsvBarData dataset;
void loadDataAndRender(){
    switch (type) {
        case bar:
            renderBarGraph(dataset);
            break;
        case scatter:
            renderScatterGraph(dataset);
            break;
        default:
            std::cout<<"invalid graph type "<<config.type;
            break;
    }
}
void persistConfig(initConfig init){
    config = init;
    type = config.type;
    dataset = parseCsvBarData(config.filePath);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    loadDataAndRender();
    glutPostRedisplay();
    glutSwapBuffers();
}

