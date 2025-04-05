#include "dialogabout.h"
#include "ui_dialogabout.h"
#include <QDialogButtonBox>

DialogAbout::DialogAbout(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAbout)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
}

DialogAbout::~DialogAbout()
{
    delete ui;
}
