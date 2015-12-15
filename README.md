# QCollapsibleWidget

A simple and easy-to-use collapsible widget that can be styled with CSS.

##API usage

```c++
auto a = new QListWidget;
a->addItem("one");
a->addItem("two");
a->addItem("three");
a->setFixedHeight(100);

auto b = new QListWidget;
b->addItem("one");
b->addItem("two");
b->addItem("three");
b->setFixedHeight(100);

QCollapsibleWidget *w = new QCollapsibleWidget;
w->setStyleSheet("QPushButton { CSS HERE! }");
w->setAnimationSpeed(500);
w->addWidget(a, "First list", true);
w->addWidget(b, "Second list");
// Add to a layout...
```

