#pragma once
#include <QDialog>
#include "ui_setting.h"
#include <common.h>

class SettingDialog : public QDialog, public Ui::SettingDialog
{
Q_OBJECT
public:
	SettingDialog(QWidget* parent = 0);
	Mode GetSelectedMode();
};