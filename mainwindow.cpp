#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_paintCanvas = new PaintCanvas(this);
    setCentralWidget(m_paintCanvas);

    // Pen width
    QLabel* penWidthLabel = new QLabel("Pen Width", this);
    QSpinBox* penWidthSpinBox = new QSpinBox(this);
    penWidthSpinBox->setValue(2);
    penWidthSpinBox->setRange(1, 15);

    // Pen color
    QLabel* penColorLabel = new QLabel("Pen Color", this);
    m_penColorButton = new QPushButton(this);

    // Fill color
    QLabel* fillColorLabel = new QLabel("Fill Color", this);
    m_fillColorButton = new QPushButton(this);

    // Fill
    m_fillCheckBox = new QCheckBox("Fill Shape", this);

    // Tool buttons
    QPushButton* rectButton = new QPushButton(this);
    rectButton->setIcon(QIcon(":/images/rectangle.png"));

    QPushButton* penButton = new QPushButton(this);
    penButton->setIcon(QIcon(":/images/pen.png"));

    QPushButton* ellipseButton = new QPushButton(this);
    ellipseButton->setIcon(QIcon(":/images/circle.png"));

    QPushButton* eraserButton = new QPushButton(this);
    eraserButton->setIcon(QIcon(":/images/eraser.png"));

    // Slot connections
    connect(penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(penWidthChanged(int)));
    connect(m_penColorButton, SIGNAL(clicked()), this, SLOT(changePenColor()));
    connect(m_fillColorButton, SIGNAL(clicked()), this, SLOT(changeFillColor()));
    connect(m_fillCheckBox, SIGNAL(clicked()), this, SLOT(changeFillProperty()));

    ui->toolBar->addWidget(penWidthLabel);
    ui->toolBar->addWidget(penWidthSpinBox);
    ui->toolBar->addWidget(penColorLabel);
    ui->toolBar->addWidget(m_penColorButton);
    ui->toolBar->addWidget(fillColorLabel);
    ui->toolBar->addWidget(m_fillColorButton);
    ui->toolBar->addWidget(m_fillCheckBox);
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(rectButton);
    ui->toolBar->addWidget(penButton);
    ui->toolBar->addWidget(ellipseButton);
    ui->toolBar->addWidget(eraserButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::penWidthChanged(int width)
{

}

void MainWindow::changePenColor()
{

}

void MainWindow::changeFillColor()
{

}

void MainWindow::changeFillProperty()
{

}

