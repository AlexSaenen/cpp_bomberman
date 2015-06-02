#include "dialog.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMediaPlayer *player = new QMediaPlayer;
    QVideoWidget *w = new QVideoWidget;

    player->setVideoOutput(w);
    player->setMedia(QUrl::fromLocalFile("/home/peauge_t/dwm.webm"));

    w->setGeometry(0, 0, 1920, 1080);
    w->show();
    player->play();

    return a.exec();
}
