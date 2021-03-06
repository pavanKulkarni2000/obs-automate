#ifndef __OBSUTILS_HPP__
#define __OBSUTILS_HPP__
#include<string>
#include<iostream>
#include <QApplication>
#include <QPushButton>
#include <unistd.h>
#include "obs/obs.h"
#include "Logging.hpp"

#define LIBOBS_PLUGINS_PATH "/usr/lib/obs-plugins/"
#define LIBOBS_PLUGINS_DATA_PATH "/usr/share/obs/obs-plugins/"


int ObsInit(int argc, char *argv[]) ;
int loadModule(const char* binPath, const char* dataPath);
#endif //__OBSUTILS_HPP__