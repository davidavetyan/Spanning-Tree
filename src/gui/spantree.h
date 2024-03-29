#ifndef SPANTREE_H
#define SPANTREE_H

#include "ui_SpanTree.h"
#include <QMainWindow>

// STL includes
#include <memory>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Forward declarations

class QSpinBox;

namespace gui {

class CCanvasWidget;
class CGridDrawer;

} // namespace gui

namespace core {

class CGridGraph;

} // namespace core

////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace gui {
////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
//
/// Main window of the application
//
class CSpanTree : public QMainWindow
{
    Q_OBJECT

    // Type definitions
    template<class T>
    using SharedPtr = std::shared_ptr<T>;

public:
    CSpanTree(QWidget* parent = Q_NULLPTR);
    ~CSpanTree();

public slots:
    void OnDimensionChanged();
    void OnSTToggled(bool bChecked);
    void OnOrderChanged(QString const& strText);

private:
    Ui::SpanTreeClass ui;
    gui::CCanvasWidget* m_pCanvasWidget;
    SharedPtr<core::CGridGraph> m_pGraph;
    SharedPtr<CGridDrawer> m_pDrawer;
};
////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace gui
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif