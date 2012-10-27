#include "wordcompleter.h"

WordCompleter::WordCompleter(QObject *parent) : QObject(parent) {
    words << "put" << "get" << "fill" << "open" << "close" << "hide"
          << "unhide" << "aim" << "fire" << "load" << "whisper"
          << "say" << "sign" << "stand" << "kneel"
          << "sit" << "face" << "attack" << "circle" << "feint"
          << "draw" << "thrust" << "chop" << "slice";
}

void WordCompleter::findMatches(QStringList commandList) {
    if(match) {
        matchesFound = words.filter(QRegExp("^" + commandList.last()));
        commandCount = commandList.size();
        order = 0;
        match = false;
    }
}

QString WordCompleter::complete(QString commands) {
    QStringList commandList = commands.split(" ");

    this->findMatches(commandList);

    if(matchesFound.size() > 0) {
        commandList.removeLast();
        commandList.append(matchesFound.at(order));

        order = order >= matchesFound.size() - 1 ? 0 : order + 1;

        return commandList.join(" ");
    } else {
        return commands;
    }
}
