/**
* @file ClickableLabel.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 04.04.2024
 * @brief Declaration of ClickableLabel
 */

#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
        /**
     * @brief Constructor for ClickableLabel class.
     *
     * @param parent The parent QWidget object.
     * @param f Window flags for the QLabel.
     */
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());

    /**
     * @brief Destructor for ClickableLabel class.
     */
    ~ClickableLabel();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // CLICKABLELABEL_H
