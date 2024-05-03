#ifndef TSP_COMP_H
#define TSP_COMP_H

#include <QWidget>

namespace Ui {
class Tsp_Comp;
}

class Tsp_Comp : public QWidget
{
    Q_OBJECT

public:
    explicit Tsp_Comp(QWidget *parent = nullptr);
    ~Tsp_Comp();

private:
    Ui::Tsp_Comp *ui;
};

#endif // TSP_COMP_H
