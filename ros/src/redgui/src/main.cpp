/**
 * @file /src/main.cpp
 *
 * @brief Qt based gui.
 *
 * @date November 2010
 **/
/*****************************************************************************
 * Includes
 *****************************************************************************/

#include <QtGui>
#include <QApplication>
#include "../include/redgui/main_window.hpp"

/*****************************************************************************
 * Defines
 *****************************************************************************/
#define GUI_WIDTH_MULTIPLIER  0.75
#define GUI_HEIGHT_MULTIPLIER 0.75

/*****************************************************************************
 * Main
 *****************************************************************************/
int main(int argc, char **argv) {

    /*********************
    ** Qt
    **********************/
    QApplication app(argc, argv);
    redgui::MainWindow w(argc,argv);

    /* Sets the GUI size to 75% of your screens height and width */
    auto qrect = QApplication::desktop()->screenGeometry();
    int gui_width = qrect.height() * GUI_WIDTH_MULTIPLIER;
    int gui_height = qrect.height() * GUI_HEIGHT_MULTIPLIER;
    w.setFixedSize(gui_width,gui_height);

    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    w.show();


    /* start app and return exit code */
    return app.exec();
}
