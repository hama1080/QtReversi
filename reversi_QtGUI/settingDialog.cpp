#include "settingDialog.h"

SettingDialog::SettingDialog(QWidget* parent)
	:QDialog(parent)
{
	setupUi(this);
}

Mode SettingDialog::GetSelectedMode()
{
	if (normal_radio->isChecked())
		return Mode::Default;
	else if (multi_radio->isChecked())
		return Mode::Multi;
	else if (largescale_radio->isChecked())
		return Mode::LargeScale;
	return Mode::Default;
}
