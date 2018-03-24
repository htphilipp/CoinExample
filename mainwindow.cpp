#include "mainwindow.h"
#include "ui_mainwindow.h"

//added to github testing QT integration

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    ui->graphOne->addGraph();
   // ui->graphOne->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    ui->graphOne->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));


    int pN = 1001;  // number of probability partitions

//    LogProb  prior;
//    LogProb  prob;
//    QVector< double> probToPlot;
//    QVector< double> probHeads;

//    std::vector < std::vector < double> > hist;

    for(auto i = 0; i<pN; i++)
    {
        prior.prb.push_back( log(1.0/double(pN)));  // assuming head probability is maximum of 1 (of course)
        prob.prb.push_back(1);
    }
    prior.normfull();
    prob.normfull();

    connect(ui->graphOne,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(crement(QMouseEvent*)));
    connect(ui->graphOne,SIGNAL(mouseWheel(QWheelEvent*)),this,SLOT(crement(QWheelEvent*)));

    auto  p =[](int h, double ho)
    {
        if(h==1)
        {
            if(ho<=0)
            {
                return -99999.0;
            }
            else
            {
            return log(ho);
            }
        }
        else
        {
            if((1-ho)<=0)
            {
             return -999999.0;
            }
            else
            {
            return log(1.0-ho);
            }
        }
    };
    hist.push_back(prob.prb);
    int data[]={1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,
                1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,
                1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,
                1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,
                1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,
                1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,
                1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,
                1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,
                1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,
                1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,
                1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,
                1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    countmax = sizeof(data)/sizeof(data[0]);

    for(auto j: data)
    {
        for(auto k=0; k<prior.prb.size();k++)
        {
            prob.prb[k]=p(j,(1.0/(double(prior.prb.size())-1.0))*double(k));

            //ui->textBrowser->append(QString::number(p(j,(1.0/(double(prior.prb.size())-1.0))*double(k))));
        }

        prob.normfull();

        for(auto k=0; k<prior.prb.size();k++)
        {
            prob.prb[k]+=prior.prb[k];
            //ui->textBrowser->append(QString::number(prob.prb[k]));
        }

        prob.normfull();
        hist.push_back(prob.prb);

        for(auto k=0; k<prior.prb.size();k++)
        {
            prior.prb[k] = prob.prb[k];
        }

    }

    count=countmax-1;

    //double temp;
    for(auto k=0; k<prior.prb.size();k++)
    {
        probHeads.push_back(double(k*1.0/pN));
        probToPlot.push_back(exp(hist[count][k]));
        //probToPlot.push_back(exp(prior.prb[k]));
    }

    ui->graphOne->graph(0)->setData(probHeads,probToPlot);
    ui->graphOne->yAxis->grid()->setSubGridVisible(true);
    ui->graphOne->xAxis->grid()->setSubGridVisible(true);


    //ui->graphOne->yAxis->setScaleType(QCPAxis::stLogarithmic);
    ui->label->setText(QString::number(count));

    ui->graphOne->graph(0)->rescaleAxes();
    ui->graphOne->graph(0)->visible();

    ui->graphOne->replot();

    //connect(ui->graphOne,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(crement(QMouseEvent*)));

}

void MainWindow::crement(QMouseEvent *event)
{

    //double sum=0;

    if((event->button()==Qt::RightButton))
    {
        if(count<(countmax-2))
        {
            count++;
        }
        else
        {
            count = 0;
        }
    }

    if(event->button()==Qt::LeftButton)
    {
        if(count>0)
        {
            count--;
        }
        else
        {
            count=countmax-1;
        }
    }

    probToPlot.clear();

    for(auto k=0; k<prior.prb.size();k++)
    {

        probToPlot.push_back(exp(hist[count][k]));

    }

//    for(auto j:probToPlot)
//    {
//        sum += j;
//    }

    ui->label->setText(QString("# of coins: ")+QString::number(count));//+QString("  int_norm")+QString::number(sum));


    ui->graphOne->graph(0)->setData(probHeads,probToPlot);
    ui->graphOne->yAxis->grid()->setSubGridVisible(true);
    ui->graphOne->xAxis->grid()->setSubGridVisible(true);
    ui->graphOne->graph(0)->rescaleAxes();
    ui->graphOne->graph(0)->visible();

    ui->graphOne->replot();

}


void MainWindow::crement(QWheelEvent *event)
{
    //double sum=0;

    if(event->delta()>0)
    {
        if(count<(countmax-2))
        {
            count++;
        }
        else
        {
            count = 0;
        }
    }

    if(event->delta()<0)
    {
        if(count>0)
        {
            count--;
        }
        else
        {
            count=countmax-1;
        }
    }

    probToPlot.clear();

    for(auto k=0; k<prior.prb.size();k++)
    {

        probToPlot.push_back(exp(hist[count][k]));

    }

//    for(auto j:probToPlot)
//    {
//        sum += j;
//    }

    ui->label->setText(QString("# of coins: ")+QString::number(count)); //+QString("  int_norm")+QString::number(sum));



    ui->graphOne->graph(0)->setData(probHeads,probToPlot);
    ui->graphOne->yAxis->grid()->setSubGridVisible(true);
    ui->graphOne->xAxis->grid()->setSubGridVisible(true);
    ui->graphOne->graph(0)->rescaleAxes();
    ui->graphOne->graph(0)->visible();

    ui->graphOne->replot();

}





// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}
