#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "C:\\Users\\Hugh\\Documents\\programming\\Qt\\LogProbProj\\logProb\\logprob.h"
#include "logprob.h"
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    int count;
    int countmax;

  //  void crement(QMouseEvent*);

    LogProb  prior;
    LogProb  prob;
    QVector< double> probToPlot;
    QVector< double> probHeads;

    std::vector < std::vector < double> > hist;




    ~MainWindow();
private slots:

    void crement(QMouseEvent*);
    void crement(QWheelEvent*);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
