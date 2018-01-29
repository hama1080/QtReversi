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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QDialogButtonBox *buttonBox;
    QRadioButton *normal_radio;
    QRadioButton *largescale_radio;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_Player0;
    QComboBox *comboBox_Player1;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QStringLiteral("SettingDialog"));
        SettingDialog->resize(356, 88);
        buttonBox = new QDialogButtonBox(SettingDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(260, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        normal_radio = new QRadioButton(SettingDialog);
        normal_radio->setObjectName(QStringLiteral("normal_radio"));
        normal_radio->setGeometry(QRect(20, 20, 81, 16));
        normal_radio->setChecked(true);
        largescale_radio = new QRadioButton(SettingDialog);
        largescale_radio->setObjectName(QStringLiteral("largescale_radio"));
        largescale_radio->setGeometry(QRect(20, 40, 81, 15));
        label = new QLabel(SettingDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 20, 45, 21));
        label_2 = new QLabel(SettingDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 50, 45, 21));
        comboBox_Player0 = new QComboBox(SettingDialog);
        comboBox_Player0->setObjectName(QStringLiteral("comboBox_Player0"));
        comboBox_Player0->setGeometry(QRect(160, 20, 81, 22));
        comboBox_Player1 = new QComboBox(SettingDialog);
        comboBox_Player1->setObjectName(QStringLiteral("comboBox_Player1"));
        comboBox_Player1->setGeometry(QRect(160, 50, 81, 22));

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
        label->setText(QApplication::translate("SettingDialog", "Player1", Q_NULLPTR));
        label_2->setText(QApplication::translate("SettingDialog", "Player2", Q_NULLPTR));
        comboBox_Player0->clear();
        comboBox_Player0->insertItems(0, QStringList()
         << QApplication::translate("SettingDialog", "Human", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Computer", Q_NULLPTR)
        );
        comboBox_Player1->clear();
        comboBox_Player1->insertItems(0, QStringList()
         << QApplication::translate("SettingDialog", "Human", Q_NULLPTR)
         << QApplication::translate("SettingDialog", "Computer", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
