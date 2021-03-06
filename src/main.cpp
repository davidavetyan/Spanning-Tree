#include "SpanTree.h"
#include <QtWidgets/QApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setStyle("Fusion");
	//QPalette p;
	//p = qApp->palette();
	//p.setColor(QPalette::Window, QColor(53, 53, 53));
	//p.setColor(QPalette::Button, QColor(53, 53, 53));
	//p.setColor(QPalette::Highlight, QColor(142, 45, 197));
	//p.setColor(QPalette::ButtonText, QColor(255, 255, 255));
	//p.setColor(QPalette::WindowText, QColor(255, 255, 255));
	//qApp->setPalette(p);

#ifdef Q_OS_WIN
    QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", QSettings::NativeFormat);
    if (settings.value("AppsUseLightTheme") == 0) 
    {
        QPalette darkPalette;

        QColor clrDark = QColor(45, 45, 45);
        QColor clrDisabled = QColor(127, 127, 127);

        darkPalette.setColor(QPalette::Window, clrDark);
        darkPalette.setColor(QPalette::WindowText, Qt::white);
        darkPalette.setColor(QPalette::Base, QColor(100, 100, 100));
        darkPalette.setColor(QPalette::AlternateBase, clrDark);
        darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        darkPalette.setColor(QPalette::Text, Qt::white);
        darkPalette.setColor(QPalette::Disabled, QPalette::Text, clrDisabled);
        darkPalette.setColor(QPalette::Button, clrDark);
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::Disabled, QPalette::ButtonText, clrDisabled);
        darkPalette.setColor(QPalette::BrightText, Qt::red);
        darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

        darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::HighlightedText, Qt::black);
        darkPalette.setColor(QPalette::Disabled, QPalette::HighlightedText, clrDisabled);

        qApp->setPalette(darkPalette);

        qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
    }
#endif





	SpanTree w;
	w.show();
	return a.exec();
}
