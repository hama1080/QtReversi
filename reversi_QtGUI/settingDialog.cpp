#include "settingDialog.h"

SettingDialog::SettingDialog(QWidget* parent)
	:QDialog(parent)
{
	setupUi(this);
}

PlayerType SettingDialog::GetPlayerType(unsigned int index)
{
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
	return GetPlayerType(comboBox_Player0->currentIndex());
}

PlayerType SettingDialog::GetPlayer1Type()
{
	return GetPlayerType(comboBox_Player1->currentIndex());
}
