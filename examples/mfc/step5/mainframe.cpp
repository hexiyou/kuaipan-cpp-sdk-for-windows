/****************************************************************************
**
** This file is part of a Qt Solutions component.
** 
** Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
** 
** Contact:  Qt Software Information (qt-info@nokia.com)
** 
** Commercial Usage  
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Solutions Commercial License Agreement provided
** with the Software or, alternatively, in accordance with the terms
** contained in a written agreement between you and Nokia.
** 
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
** 
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
** 
** GNU General Public License Usage 
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
** 
** Please note Third Party Software included with Qt Solutions may impose
** additional restrictions and it is the user's responsibility to ensure
** that they have met the licensing requirements of the GPL, LGPL, or Qt
** Solutions Commercial license and the relevant license of the Third
** Party Software they are using.
** 
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
** 
****************************************************************************/

#include <QtGui>

#include "mainframe.h"
#include "childview.h"
#include "ui_optionsdialog.h"

/////////////////////////////////////////////////////////////////////////////
// MainFrame

MainFrame::MainFrame(QWidget *parent)
: QMainWindow(parent)
{
    QMenu *filePopup = menuBar()->addMenu("&File");
    filePopup->addAction("&Exit", this, SLOT(close()));

    QMenu *editPopup = menuBar()->addMenu("&Edit");
    editPopup->addAction("&Undo", 0, 0, Qt::CTRL + Qt::Key_Z);
    editPopup->addSeparator();
    editPopup->addAction("Cu&t", 0, 0, Qt::CTRL + Qt::Key_X);
    editPopup->addAction("&Copy", 0, 0, Qt::CTRL + Qt::Key_C);
    editPopup->addAction("&Paste", 0, 0, Qt::CTRL + Qt::Key_V);
    editPopup->addSeparator();
    editPopup->addAction("&Options...", this, SLOT(editOptions()));

    QMenu *helpPopup = menuBar()->addMenu("&Help");
    helpPopup->addAction("&About QtMfc...", this, SLOT(helpAbout()), Qt::CTRL + Qt::Key_F1);

    view = new ChildView(this);
    setCentralWidget(view);

    statusBar();
}

void MainFrame::editOptions()
{
    QDialog *dialog = new QDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    Ui::OptionsDialog ui;
    ui.setupUi(dialog);

    dialog->show();
}

void MainFrame::helpAbout()
{
    QMessageBox::about(this, "About QtMfc", "QtMfc Version 1.0\nCopyright (C) 2003");
}
