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

#ifndef QACCORDIONWIDGET_HPP
#define QACCORDIONWIDGET_HPP

#include <memory>
#include <QPropertyAnimation>
#include <QWidget>

class QString;
class QVBoxLayout;

class QCollapsibleWidget : public QWidget
{
    Q_OBJECT

public:
    enum ResizeMode {
        UseWidgetHeight,
        UseWidgetSizeHint
    };

private:

    //! Layout
    QVBoxLayout *layout;

    //! Animation speed
    int animationSpeed;

    //! Widget resizing mode
    ResizeMode resizeMode;

public:
    /**
     * @brief Constructor
     * @param resizeMode Resize mode
     * @param parent Owner of the widget
     */
    explicit QCollapsibleWidget(ResizeMode resizeMode, QWidget *parent = 0);

    /**
     * @brief Constructor
     * @param parent Owner of the widget
     */
    explicit QCollapsibleWidget(QWidget *parent = 0);

    /**
     * @brief Set widget resizing mode
     *
     * Use height if you need fixed height, otherwise size hint
     * Default is UseWidgetHeight
     * @param newResizeMode New resize mode
     */
    void setResizeMode(ResizeMode newResizeMode);

    /**
     * @brief Set animation speed in ms
     *
     * Default is 500
     * @param speed New speed
     */
    void setAnimationSpeed(int speed);

    /**
     * @brief Add new widget
     * @param widget Widget to add
     * @param headerTitle Title of the collapsible header
     * @param open Open the current widget
     */
    void addWidget(QWidget *widget, const QString &headerTitle, bool open = false);

signals:

public slots:

    void buttonPressed();
};

#endif // QACCORDIONWIDGET_HPP
