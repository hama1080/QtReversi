#include "renderReversi.h"

RenderReversi::RenderReversi(Reversi * reversi, Vec2d render_pos, Vec2d render_board_size)
	:reversi_(reversi), render_pos_(render_pos), render_board_size_(render_board_size)
{
}
