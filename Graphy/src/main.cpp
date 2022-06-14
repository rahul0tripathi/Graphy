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
int main (int argc, char** argv){
    initConfig config = {
        (char*)"Graphy", // window name
        getWindowSize(), // get default window sizes
        false // set full screen to false
    };
    setupGLUT(argc, argv,config);
    init(config);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}


