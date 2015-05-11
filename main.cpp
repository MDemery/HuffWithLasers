#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include "counter.h"

int main()
{
    counter *file = new counter();
    int *m = file->frequency("//home//Intel//Documents//huffinho//teste.txt");
    for(int count = 0 ; count < 256 ; ++count) {
        if(m[count]) {
            qDebug() << "ASCII:" << count << "|" << "symbol:" << char(count)
                     << "|" << "repeats:" << m[count];
        }
    }
    return 0;
}
