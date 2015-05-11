#ifndef COUNTER
#define COUNTER
#include <QString>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QIODevice>
class counter {
    int freq[256];
public:
    counter() {
        for(int cont = 0; cont < 256; ++cont) {
            freq[cont] = 0;
        }
    }
    int *frequency(QString dir) {
        QFile *archive = new QFile(dir);
        if(archive->open(QIODevice::ReadOnly)) {
            QByteArray binaryFile = archive->readAll();
            for (int var = 0; var < binaryFile.size(); ++var) {
                ++freq[uchar(binaryFile.at(var))];
            }
        } else {
            return NULL;
        }
        return freq;
    }
};

#endif // COUNTER

