#include "SpanTree.h"

// Qt includes
#include <QSpinBox>
#include <QSettings>

#include "CanvasWidget.h"
#include "GridDrawer.h"
#include "GridGraph.h"

SpanTree::SpanTree(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QWidget* window = ui.canvasWidget;

	QSpinBox* pRowBox = ui.rowSpinBox;
	QSpinBox* pColBox = ui.colSpinBox;

	connect(pRowBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &SpanTree::OnDimensionChanged);
	connect(pColBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &SpanTree::OnDimensionChanged);

	QComboBox* pOrderComboBox = ui.orderComboBox;
	pOrderComboBox->addItem("Random");
	pOrderComboBox->addItem("LIFO");
	pOrderComboBox->addItem("FIFO");

	connect(pOrderComboBox, &QComboBox::currentTextChanged, this, &SpanTree::OnOrderChanged);

	QCheckBox* pSTCheckBox = ui.stCheckBox;
	connect(pSTCheckBox, &QCheckBox::toggled, this, &SpanTree::OnSTToggled);

	m_pGraph = std::make_shared<CGridGraph>(0, 0);
	m_pDrawer = std::make_shared<CGridDrawer>(m_pGraph);

	m_pCanvasWidget = new CCanvasWidget(this, m_pDrawer);

	QLayout* pMainLayout = new QVBoxLayout;
	pMainLayout->addWidget(m_pCanvasWidget);

	window->setLayout(pMainLayout);
}

SpanTree::~SpanTree()
{
	 
}

void SpanTree::OnSTToggled(bool bChecked)
{
	if (m_pDrawer != nullptr)
		m_pDrawer->SetDrawST(bChecked);

	if (m_pCanvasWidget != nullptr)
		m_pCanvasWidget->repaint();
}

void SpanTree::OnOrderChanged(QString const& strText)
{
	CSTGenerator& oGenerator = CSTGenerator::GetInstance();
	oGenerator.SetOrder(strText);
	
	if (m_pDrawer != nullptr)
		m_pDrawer->ResetSTCache();

	if (m_pCanvasWidget != nullptr)
		m_pCanvasWidget->repaint();
}

void SpanTree::OnDimensionChanged()
{
	QSpinBox* pRowBox = ui.rowSpinBox;
	QSpinBox* pColBox = ui.colSpinBox;
	
	if (m_pDrawer != nullptr)
		m_pDrawer->ResetGraphDimensions(pRowBox->value(), pColBox->value(), true);
	
	if (m_pCanvasWidget != nullptr)
		m_pCanvasWidget->repaint();
}