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

/**
 * @class ClickableLabel
 * @brief This class represents a custom QLabel that emits a signal when clicked.
 *
 * The ClickableLabel class extends QLabel and provides functionalities for handling
 * mouse press events and emitting a signal when such an event occurs.
 */
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
    /**
     * @brief This signal is emitted when a mouse press event occurs on the ClickableLabel.
     */
    void clicked();

protected:
    /**
     * @brief This method is called whenever a mouse press event occurs on this widget.
     *
     * @param event Provides details about the mouse press event such as the position of the mouse cursor, the button that was pressed, and the state of keyboard modifiers.
     */
    void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLELABEL_H
