//
//  keyboard.h
//  Graphy
//
//  Created by ATS on 15/06/22.
//

#ifndef keyboard_h
#define keyboard_h
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include <GL/glut.h>
#endif
#include "iostream"
graphType type;

void windowKey(unsigned char key,int x,int y)
{
  /*  Exit on ESC,Q,q */
  if (key == 27 || key == 'Q' || key=='q') exit(0);
  else if (key == 's' || key == 'S')
      type = scatter;
  else if (key == 'b' || key == 'B')
      type = bar;
    
  glutPostRedisplay();
}
#endif /* keyboard_h */
