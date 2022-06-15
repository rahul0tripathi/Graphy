// setup glut
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include <GL/glut.h>
#endif
#include "iostream"
using namespace std;
struct windowSize {
    GLint width;
    GLint height;
};
enum graphType{ bar,scatter};
struct initConfig {
    char* title;
    windowSize size;
    bool isFullScreen;
    char* filePath;
    graphType type;
};
windowSize getWindowSize() {
    windowSize defaultConfig = {(glutGet(GLUT_SCREEN_WIDTH) == 0) ? 1000 : glutGet(GLUT_SCREEN_WIDTH),(glutGet(GLUT_SCREEN_HEIGHT) == 0) ? 1000 : glutGet(GLUT_SCREEN_HEIGHT)};
    cout<<"windowSize "<<defaultConfig.width<<" "<<defaultConfig.height;
    return defaultConfig;
}
void makeFullScreeen(){
    glutFullScreen();
}
void setupGLUT(int argc,char** argv,initConfig conf){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(conf.size.width,conf.size.height);
    glutInitWindowPosition(0,0);
    glutCreateWindow(conf.title);
    if(conf.isFullScreen){
        makeFullScreeen();
    }
}

void init(initConfig conf){
    glClearColor(0.0f, 0.0f, 0.0f,0.0f);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0,conf.size.width,0.0,conf.size.height);
}
