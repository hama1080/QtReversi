#include "manager.h"

Manager::Manager()
{
	w = new MainWindow();
	w->show();
}

void Manager::nextPreprocessSlot(unsigned int next_index)
{
	if (reversi_list_.size() == 1)
		reversi_list_[next_index]->PreProcess();

	// In order to suppress the twice execution of pre-process, keep the index pre-processed before.
	static int before_preprocess_index = -1;
	if (before_preprocess_index != next_index)
	{
		before_preprocess_index = next_index;
		reversi_list_[next_index]->PreProcess();
	}
}


void Manager::restartSlot()
{
	SettingDialog* dialog = new SettingDialog();
	if (dialog->exec())
	{
		Mode mode = dialog->GetSelectedMode();
		PlayerType player0 = dialog->GetPlayer0Type();
		PlayerType player1 = dialog->GetPlayer1Type();
		for (auto reversi : reversi_list_) {
			reversi->ChangeMode(mode);
			reversi->Initialize(player0, player1);
		}
		for (vector<RenderReversi>::iterator i = w->render_reversi_list_.begin(); i != w->render_reversi_list_.end(); i++) {
			i->ChangeMode(mode);
			i->Initialize();
		}
	}
}
