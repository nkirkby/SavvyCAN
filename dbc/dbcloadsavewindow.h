#ifndef DBCLOADSAVEWINDOW_H
#define DBCLOADSAVEWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include "dbchandler.h"
#include "dbcmaineditor.h"

namespace Ui {
class DBCLoadSaveWindow;
}

class DBCLoadSaveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DBCLoadSaveWindow(const QVector<CANFrame> *frames, QWidget *parent = 0);
    ~DBCLoadSaveWindow();

private slots:
    void loadFile();
    void saveFile();
    void removeFile();
    void moveUp();
    void moveDown();
    void editFile();
    void cellChanged(int row, int col);
    void cellDoubleClicked(int row, int col);
    void newFile();

private:
    Ui::DBCLoadSaveWindow *ui;
    DBCHandler *dbcHandler;
    DBCFile *currentlyEditingFile;
    const QVector<CANFrame> *referenceFrames;
    DBCMainEditor *editorWindow;
    bool inhibitCellProcessing;

    void makeRowForFile(DBCFile &file);
    void swapTableRows(bool up);
    QList<QTableWidgetItem*> takeRow(int row);
    void setRow(int row, const QList<QTableWidgetItem*>& rowItems);
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // DBCLOADSAVEWINDOW_H

