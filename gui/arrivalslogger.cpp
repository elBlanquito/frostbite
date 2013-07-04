#include "arrivalslogger.h"

ArrivalsLogger::ArrivalsLogger(QObject *parent) {
}

void ArrivalsLogger::addText(QString text) {
    mMutex.lock();
    dataQueue.enqueue(text);
    mMutex.unlock();
}

void ArrivalsLogger::run() {
    while(!dataQueue.isEmpty()) {
        mMutex.lock();
        localData = dataQueue.dequeue();
        mMutex.unlock();

        logger()->info(localData + "\n");
    }
}

ArrivalsLogger::~ArrivalsLogger() {
}

