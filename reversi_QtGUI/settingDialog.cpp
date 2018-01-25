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

PlayerType SettingDialog::GetPlayer0Type()
{
	unsigned int index = comboBox_Player0->currentIndex();
	switch (index)
	{
	case 0:
		return PlayerType::Human;

	case 1:
		return PlayerType::Computer;

	default:
		return PlayerType::Human;
	}
}

PlayerType SettingDialog::GetPlayer1Type()
{
	unsigned int index = comboBox_Player1->currentIndex();
	switch (index)
	{
	case 0:
		return PlayerType::Human;

	case 1:
		return PlayerType::Computer;

	default:
		return PlayerType::Human;
	}
}
