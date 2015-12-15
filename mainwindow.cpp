/******************************************************************************
The MIT License (MIT)

Copyright (c) 2015 https://github.com/labyrinthofdreams

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
******************************************************************************/

#include <QListWidget>
#include "mainwindow.hpp"
#include "qcollapsiblewidget.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);

    auto l = new QListWidget;
    l->addItem("one");
    l->addItem("two");
    l->addItem("three");
    l->setFixedHeight(100);

    auto d = new QListWidget;
    d->addItem("one");
    d->addItem("two");
    d->addItem("three");
    d->setFixedHeight(100);

    auto c = new QListWidget;
    c->addItem("one");
    c->addItem("two");
    c->addItem("three");
    c->setFixedHeight(100);

    QCollapsibleWidget *w = new QCollapsibleWidget(QCollapsibleWidget::UseWidgetHeight);
    w->addWidget(l, "Hello", true);
    w->addWidget(d, "World");
    w->addWidget(c, "AAA");
    setCentralWidget(w);
}
