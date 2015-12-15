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

#include <QApplication>
#include <QCursor>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QSpacerItem>
#include <QString>
#include <QVBoxLayout>
#include "qcollapsiblewidget.hpp"

QCollapsibleWidget::QCollapsibleWidget(QWidget *parent)
    : QWidget(parent),
      layout(new QVBoxLayout),
      doingStuff(false),
      originalHeight(0),
      animationSpeed(500)
{
    layout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding));
    layout->setSpacing(0);
    setLayout(layout);
    setStyleSheet("QPushButton { background-color: #f90; border: 1px solid #000;"
                  "border-radius: 2; height: 30px; text-align: left; padding-left: 10px;}");
}

void QCollapsibleWidget::setAnimationSpeed(const int speed)
{
    animationSpeed = speed;
}

void QCollapsibleWidget::addWidget(QWidget *widget, const QString &headerTitle, const bool open)
{
    if(widget == nullptr) {
        return;
    }

    if(!open) {
        widget->setHidden(true);
    }

    auto pb = new QPushButton(headerTitle);
    connect(pb, &QPushButton::pressed, this, &QCollapsibleWidget::buttonPressed);
    layout->insertWidget(layout->count() - 1, pb);
    layout->insertWidget(layout->count() - 1, widget);
}

void QCollapsibleWidget::buttonPressed()
{
    if(doingStuff) {
        return;
    }

    doingStuff = true;
    auto header = qApp->widgetAt(QCursor::pos());
    const auto index = layout->indexOf(header);
    auto next = layout->itemAt(index + 1)->widget();
    anim = std::make_unique<QPropertyAnimation>(next, "maximumHeight");
    anim->setDuration(animationSpeed);
    connect(anim.get(), &QPropertyAnimation::finished, this, &QCollapsibleWidget::done);
    if(!next->isVisible()) {
        const auto height = next->height();
        next->setFixedHeight(1);
        next->setHidden(false);
        anim->setStartValue(next->height());
        anim->setEndValue(height);
    }
    else {
        next->setMinimumHeight(1);
        originalHeight = next->height();
        anim->setStartValue(next->height());
        anim->setEndValue(1);
    }

    anim->start();
}

void QCollapsibleWidget::done()
{
    auto widget = static_cast<QWidget *>(anim->targetObject());
    if(widget->height() > 1) {
        widget->setMinimumHeight(widget->height());
    }
    else {
        widget->setHidden(true);
        widget->setFixedHeight(originalHeight);
    }

    doingStuff = false;
}
