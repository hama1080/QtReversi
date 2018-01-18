/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QDialogButtonBox *buttonBox;
    QRadioButton *normal_radio;
    QRadioButton *largescale_radio;
    QRadioButton *multi_radio;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QStringLiteral("SettingDialog"));
        SettingDialog->resize(211, 90);
        buttonBox = new QDialogButtonBox(SettingDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(110, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        normal_radio = new QRadioButton(SettingDialog);
        normal_radio->setObjectName(QStringLiteral("normal_radio"));
        normal_radio->setGeometry(QRect(20, 20, 81, 16));
        normal_radio->setChecked(true);
        largescale_radio = new QRadioButton(SettingDialog);
        largescale_radio->setObjectName(QStringLiteral("largescale_radio"));
        largescale_radio->setGeometry(QRect(20, 40, 81, 15));
        multi_radio = new QRadioButton(SettingDialog);
        multi_radio->setObjectName(QStringLiteral("multi_radio"));
        multi_radio->setGeometry(QRect(20, 60, 81, 15));

        retranslateUi(SettingDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QApplication::translate("SettingDialog", "Dialog", Q_NULLPTR));
        normal_radio->setText(QApplication::translate("SettingDialog", "Normal", Q_NULLPTR));
        largescale_radio->setText(QApplication::translate("SettingDialog", "LargeScale", Q_NULLPTR));
        multi_radio->setText(QApplication::translate("SettingDialog", "MultiReversi", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
