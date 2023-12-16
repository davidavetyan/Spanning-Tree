#include "spantree.h"

// Qt includes
#include <QSettings>
#include <QSpinBox>

#include "core_gridgraph.h"

#include "canvaswidget.h"
#include "griddrawer.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace gui {
////////////////////////////////////////////////////////////////////////////////////////////////////

CSpanTree::CSpanTree(QWidget* parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    QWidget* window = ui.canvasWidget;

    QSpinBox* pRowBox = ui.rowSpinBox;
    QSpinBox* pColBox = ui.colSpinBox;

    connect(pRowBox, QOverload<int>::of(&QSpinBox::valueChanged), this,
            &CSpanTree::OnDimensionChanged);
    connect(pColBox, QOverload<int>::of(&QSpinBox::valueChanged), this,
            &CSpanTree::OnDimensionChanged);

    QComboBox* pOrderComboBox = ui.orderComboBox;
    pOrderComboBox->addItem("Random");
    pOrderComboBox->addItem("LIFO");
    pOrderComboBox->addItem("FIFO");

    connect(pOrderComboBox, &QComboBox::currentTextChanged, this, &CSpanTree::OnOrderChanged);

    QCheckBox* pSTCheckBox = ui.stCheckBox;
    connect(pSTCheckBox, &QCheckBox::toggled, this, &CSpanTree::OnSTToggled);

    m_pGraph = std::make_shared<core::CGridGraph>(0, 0);
    m_pDrawer = std::make_shared<CGridDrawer>(m_pGraph);

    m_pCanvasWidget = new CCanvasWidget(this, m_pDrawer);

    QLayout* pMainLayout = new QVBoxLayout;
    pMainLayout->addWidget(m_pCanvasWidget);

    window->setLayout(pMainLayout);
}

CSpanTree::~CSpanTree()
{}

void CSpanTree::OnSTToggled(bool bChecked)
{
    if (m_pDrawer != nullptr)
        m_pDrawer->SetDrawST(bChecked);

    if (m_pCanvasWidget != nullptr)
        m_pCanvasWidget->repaint();
}

void CSpanTree::OnOrderChanged(QString const& strText)
{
    core::CSTGenerator& oGenerator = core::CSTGenerator::GetInstance();
    oGenerator.SetOrder(strText);

    if (m_pDrawer != nullptr)
        m_pDrawer->ResetSTCache();

    if (m_pCanvasWidget != nullptr)
        m_pCanvasWidget->repaint();
}

void CSpanTree::OnDimensionChanged()
{
    QSpinBox* pRowBox = ui.rowSpinBox;
    QSpinBox* pColBox = ui.colSpinBox;

    if (m_pDrawer != nullptr)
        m_pDrawer->ResetGraphDimensions(pRowBox->value(), pColBox->value(), true);

    if (m_pCanvasWidget != nullptr)
        m_pCanvasWidget->repaint();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace gui
////////////////////////////////////////////////////////////////////////////////////////////////////