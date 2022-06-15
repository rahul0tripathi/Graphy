// created by rahul-tripati USN 1DT19CS122
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include <GL/glut.h>
#endif
#include "iostream"
#include "setup.h"
#include "render.h"
#include "reshape.h"
#include "keyboard.h"
int main (int argc, char** argv){
    initConfig config = {
        (char*)"Graphy", // window name
        getWindowSize(), // get default window sizes
        true, // set full screen to false
        (char*)"/Users/ats/Desktop/github/Graphy/Graphy/sample/dense.csv", // filepath
        scatter
    };
    setupGLUT(argc, argv,config);
    init(config);
    persistConfig(config);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(windowKey);
    glutMainLoop();
    return 0;
}


