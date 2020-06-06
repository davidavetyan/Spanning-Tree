#include "SpanTree.h"

// STL includes
#include <memory>

// Qt includes
#include <QSpinBox>
#include <QSettings>

#include "CanvasWidget.h"

SpanTree::SpanTree(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QWidget* window = ui.canvasWidget;

	QSpinBox* pRowBox = ui.rowSpinBox;
	QSpinBox* pColBox = ui.colSpinBox;

	connect(pRowBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &SpanTree::OnDimensionChanged);
	connect(pColBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &SpanTree::OnDimensionChanged);

	SharedPtr<CGridDrawer> pDrawer(std::make_shared<CGridDrawer>(std::make_shared<CGridGraph>(0, 0)));

	m_pcCanvasWidget = new CCanvasWidget(this, pDrawer);
	m_pcCanvasWidget->SetGridDimensions(0, 0);

	QLayout* pMainLayout = new QVBoxLayout;
	pMainLayout->addWidget(m_pcCanvasWidget);

	QCheckBox* pSTCheckBox = ui.stCheckBox;
	connect(pSTCheckBox, &QCheckBox::toggled, m_pcCanvasWidget, &CCanvasWidget::OnSTToggled);

	window->setLayout(pMainLayout);
}

SpanTree::~SpanTree()
{
	 
}

void SpanTree::OnDimensionChanged()
{
	QSpinBox* pRowBox = ui.rowSpinBox;
	QSpinBox* pColBox = ui.colSpinBox;

	m_pcCanvasWidget->SetGridDimensions(pRowBox->value(), pColBox->value());
}