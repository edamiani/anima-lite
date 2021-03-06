#include "KeyInfoSdl.h"

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

std::map<AE::Input::KeyCode, int> AE::Input::KeyInfoSdl::mKeyCodesSdl;
std::map<int, AE::Input::KeyCode> AE::Input::KeyInfoSdl::mKeyCodes;

void AE::Input::KeyInfoSdl::Initialize()
{
	if(mKeyCodesSdl.empty())
	{
		mKeyCodesSdl[AE::Input::KC_BACKSPACE] = SDLK_BACKSPACE;
		mKeyCodesSdl[AE::Input::KC_DOWN_ARROW] = SDLK_DOWN;
		mKeyCodesSdl[AE::Input::KC_ENTER] = SDLK_RETURN;
		mKeyCodesSdl[AE::Input::KC_ESCAPE] = SDLK_ESCAPE;
		mKeyCodesSdl[AE::Input::KC_F1] = SDLK_F1;
		mKeyCodesSdl[AE::Input::KC_F2] = SDLK_F2;
		mKeyCodesSdl[AE::Input::KC_F3] = SDLK_F3;
		mKeyCodesSdl[AE::Input::KC_F4] = SDLK_F4;
		mKeyCodesSdl[AE::Input::KC_F5] = SDLK_F5;
		mKeyCodesSdl[AE::Input::KC_F6] = SDLK_F6;
		mKeyCodesSdl[AE::Input::KC_F7] = SDLK_F7;
		mKeyCodesSdl[AE::Input::KC_F8] = SDLK_F8;
		mKeyCodesSdl[AE::Input::KC_F9] = SDLK_F9;
		mKeyCodesSdl[AE::Input::KC_F10] = SDLK_F10;
		mKeyCodesSdl[AE::Input::KC_F11] = SDLK_F11;
		mKeyCodesSdl[AE::Input::KC_F12] = SDLK_F12;
		mKeyCodesSdl[AE::Input::KC_LEFT_ALT] = SDLK_LALT;
		mKeyCodesSdl[AE::Input::KC_LEFT_ARROW] = SDLK_LEFT;
		mKeyCodesSdl[AE::Input::KC_LEFT_CONTROL] = SDLK_LCTRL;
		mKeyCodesSdl[AE::Input::KC_LEFT_SHIFT] = SDLK_LSHIFT;
		mKeyCodesSdl[AE::Input::KC_RIGHT_ALT] = SDLK_RALT;
		mKeyCodesSdl[AE::Input::KC_RIGHT_ARROW] = SDLK_RIGHT;
		mKeyCodesSdl[AE::Input::KC_RIGHT_CONTROL] = SDLK_RCTRL;
		mKeyCodesSdl[AE::Input::KC_RIGHT_SHIFT] = SDLK_RSHIFT;
		mKeyCodesSdl[AE::Input::KC_SPACE] = SDLK_SPACE;
		mKeyCodesSdl[AE::Input::KC_UP_ARROW] = SDLK_UP;
		mKeyCodesSdl[AE::Input::KC_0] = SDLK_0;
		mKeyCodesSdl[AE::Input::KC_1] = SDLK_1;
		mKeyCodesSdl[AE::Input::KC_2] = SDLK_2;
		mKeyCodesSdl[AE::Input::KC_3] = SDLK_3;
		mKeyCodesSdl[AE::Input::KC_4] = SDLK_4;
		mKeyCodesSdl[AE::Input::KC_5] = SDLK_5;
		mKeyCodesSdl[AE::Input::KC_6] = SDLK_6;
		mKeyCodesSdl[AE::Input::KC_7] = SDLK_7;
		mKeyCodesSdl[AE::Input::KC_8] = SDLK_8;
		mKeyCodesSdl[AE::Input::KC_9] = SDLK_9;
		mKeyCodesSdl[AE::Input::KC_A] = SDLK_a;
		mKeyCodesSdl[AE::Input::KC_B] = SDLK_b;
		mKeyCodesSdl[AE::Input::KC_C] = SDLK_c;
		mKeyCodesSdl[AE::Input::KC_D] = SDLK_d;
		mKeyCodesSdl[AE::Input::KC_E] = SDLK_e;
		mKeyCodesSdl[AE::Input::KC_F] = SDLK_f;
		mKeyCodesSdl[AE::Input::KC_G] = SDLK_g;
		mKeyCodesSdl[AE::Input::KC_H] = SDLK_h;
		mKeyCodesSdl[AE::Input::KC_I] = SDLK_i;
		mKeyCodesSdl[AE::Input::KC_J] = SDLK_j;
		mKeyCodesSdl[AE::Input::KC_K] = SDLK_k;
		mKeyCodesSdl[AE::Input::KC_L] = SDLK_l;
		mKeyCodesSdl[AE::Input::KC_M] = SDLK_m;
		mKeyCodesSdl[AE::Input::KC_N] = SDLK_n;
		mKeyCodesSdl[AE::Input::KC_O] = SDLK_o;
		mKeyCodesSdl[AE::Input::KC_P] = SDLK_p;
		mKeyCodesSdl[AE::Input::KC_Q] = SDLK_q;
		mKeyCodesSdl[AE::Input::KC_R] = SDLK_r;
		mKeyCodesSdl[AE::Input::KC_S] = SDLK_s;
		mKeyCodesSdl[AE::Input::KC_T] = SDLK_t;
		mKeyCodesSdl[AE::Input::KC_U] = SDLK_u;
		mKeyCodesSdl[AE::Input::KC_V] = SDLK_v;
		mKeyCodesSdl[AE::Input::KC_W] = SDLK_w;
		mKeyCodesSdl[AE::Input::KC_X] = SDLK_x;
		mKeyCodesSdl[AE::Input::KC_Y] = SDLK_y;
		mKeyCodesSdl[AE::Input::KC_Z] = SDLK_z;

		mKeyCodes[SDLK_BACKSPACE] = AE::Input::KC_BACKSPACE;
		mKeyCodes[SDLK_DOWN] = AE::Input::KC_DOWN_ARROW;
		mKeyCodes[SDLK_RETURN] = AE::Input::KC_ENTER;
		mKeyCodes[SDLK_ESCAPE] = AE::Input::KC_ESCAPE;
		mKeyCodes[SDLK_F1] = AE::Input::KC_F1;
		mKeyCodes[SDLK_F2] = AE::Input::KC_F2;
		mKeyCodes[SDLK_F3] = AE::Input::KC_F3;
		mKeyCodes[SDLK_F4] = AE::Input::KC_F4;
		mKeyCodes[SDLK_F5] = AE::Input::KC_F5;
		mKeyCodes[SDLK_F6] = AE::Input::KC_F6;
		mKeyCodes[SDLK_F7] = AE::Input::KC_F7;
		mKeyCodes[SDLK_F8] = AE::Input::KC_F8;
		mKeyCodes[SDLK_F9] = AE::Input::KC_F9;
		mKeyCodes[SDLK_F10] = AE::Input::KC_F10;
		mKeyCodes[SDLK_F11] = AE::Input::KC_F11;
		mKeyCodes[SDLK_F12] = AE::Input::KC_F12;
		mKeyCodes[SDLK_LALT] = AE::Input::KC_LEFT_ALT;
		mKeyCodes[SDLK_LEFT] = AE::Input::KC_LEFT_ARROW;
		mKeyCodes[SDLK_LCTRL] = AE::Input::KC_LEFT_CONTROL;
		mKeyCodes[SDLK_LSHIFT] = AE::Input::KC_LEFT_SHIFT;
		mKeyCodes[SDLK_RALT] = AE::Input::KC_RIGHT_ALT;
		mKeyCodes[SDLK_RIGHT] = AE::Input::KC_RIGHT_ARROW;
		mKeyCodes[SDLK_RCTRL] = AE::Input::KC_RIGHT_CONTROL;
		mKeyCodes[SDLK_RSHIFT] = AE::Input::KC_RIGHT_SHIFT;
		mKeyCodes[SDLK_SPACE] = AE::Input::KC_SPACE;
		mKeyCodes[SDLK_UP] = AE::Input::KC_UP_ARROW;
		mKeyCodes[SDLK_0] = AE::Input::KC_0;
		mKeyCodes[SDLK_1] = AE::Input::KC_1;
		mKeyCodes[SDLK_2] = AE::Input::KC_2;
		mKeyCodes[SDLK_3] = AE::Input::KC_3;
		mKeyCodes[SDLK_4] = AE::Input::KC_4;
		mKeyCodes[SDLK_5] = AE::Input::KC_5;
		mKeyCodes[SDLK_6] = AE::Input::KC_6;
		mKeyCodes[SDLK_7] = AE::Input::KC_7;
		mKeyCodes[SDLK_8] = AE::Input::KC_8;
		mKeyCodes[SDLK_9] = AE::Input::KC_9;
		mKeyCodes[SDLK_a] = AE::Input::KC_A;
		mKeyCodes[SDLK_b] = AE::Input::KC_B;
		mKeyCodes[SDLK_c] = AE::Input::KC_C;
		mKeyCodes[SDLK_d] = AE::Input::KC_D;
		mKeyCodes[SDLK_e] = AE::Input::KC_E;
		mKeyCodes[SDLK_f] = AE::Input::KC_F;
		mKeyCodes[SDLK_g] = AE::Input::KC_G;
		mKeyCodes[SDLK_h] = AE::Input::KC_H;
		mKeyCodes[SDLK_i] = AE::Input::KC_I;
		mKeyCodes[SDLK_j] = AE::Input::KC_J;
		mKeyCodes[SDLK_k] = AE::Input::KC_K;
		mKeyCodes[SDLK_l] = AE::Input::KC_L;
		mKeyCodes[SDLK_m] = AE::Input::KC_M;
		mKeyCodes[SDLK_n] = AE::Input::KC_N;
		mKeyCodes[SDLK_o] = AE::Input::KC_O;
		mKeyCodes[SDLK_p] = AE::Input::KC_P;
		mKeyCodes[SDLK_q] = AE::Input::KC_Q;
		mKeyCodes[SDLK_r] = AE::Input::KC_R;
		mKeyCodes[SDLK_s] = AE::Input::KC_S;
		mKeyCodes[SDLK_t] = AE::Input::KC_T;
		mKeyCodes[SDLK_u] = AE::Input::KC_U;
		mKeyCodes[SDLK_v] = AE::Input::KC_V;
		mKeyCodes[SDLK_w] = AE::Input::KC_W;
		mKeyCodes[SDLK_x] = AE::Input::KC_X;
		mKeyCodes[SDLK_y] = AE::Input::KC_Y;
		mKeyCodes[SDLK_z] = AE::Input::KC_Z;
	}
}

//std::map<AE::Input::KeyCode, int> AE::Input::KeyInfoSdl::mKeyCodesSdl =
//{ 
//	{ AE::Input::KC_BACKSPACE, (int)SDLK_BACKSPACE },
//	{ AE::Input::KC_DOWN_ARROW, SDLK_DOWN },
//	{ AE::Input::KC_ENTER, SDLK_RETURN },
//	{ AE::Input::KC_ESCAPE, SDLK_ESCAPE },
//	{ AE::Input::KC_F1, SDLK_F1 },
//	{ AE::Input::KC_F2, SDLK_F2 },
//	{ AE::Input::KC_F3, SDLK_F3 },
//	{ AE::Input::KC_F4, SDLK_F4 },
//	{ AE::Input::KC_F5, SDLK_F5 },
//	{ AE::Input::KC_F6, SDLK_F6 },
//	{ AE::Input::KC_F7, SDLK_F7 },
//	{ AE::Input::KC_F8, SDLK_F8 },
//	{ AE::Input::KC_F9, SDLK_F9 },
//	{ AE::Input::KC_F10, SDLK_F10 },
//	{ AE::Input::KC_F11, SDLK_F11 },
//	{ AE::Input::KC_F12, SDLK_F12 },
//	{ AE::Input::KC_LEFT_ALT, SDLK_LALT },
//	{ AE::Input::KC_LEFT_ARROW, SDLK_LEFT },
//	{ AE::Input::KC_LEFT_CONTROL, SDLK_LCTRL },
//	{ AE::Input::KC_LEFT_SHIFT, SDLK_LSHIFT },
//	{ AE::Input::KC_RIGHT_ALT, SDLK_RALT },
//	{ AE::Input::KC_RIGHT_ARROW, SDLK_RIGHT },
//	{ AE::Input::KC_RIGHT_CONTROL, SDLK_RCTRL },
//	{ AE::Input::KC_RIGHT_SHIFT, SDLK_RSHIFT },
//	{ AE::Input::KC_SPACE, SDLK_SPACE },
//	{ AE::Input::KC_UP_ARROW, SDLK_UP },
//	{ AE::Input::KC_0, SDLK_0 },
//	{ AE::Input::KC_1, SDLK_1 },
//	{ AE::Input::KC_2, SDLK_2 },
//	{ AE::Input::KC_3, SDLK_3 },
//	{ AE::Input::KC_4, SDLK_4 },
//	{ AE::Input::KC_5, SDLK_5 },
//	{ AE::Input::KC_6, SDLK_6 },
//	{ AE::Input::KC_7, SDLK_7 },
//	{ AE::Input::KC_8, SDLK_8 },
//	{ AE::Input::KC_9, SDLK_9 },
//	{ AE::Input::KC_A, SDLK_a },
//	{ AE::Input::KC_B, SDLK_b },
//	{ AE::Input::KC_C, SDLK_c },
//	{ AE::Input::KC_D, SDLK_d },
//	{ AE::Input::KC_E, SDLK_e },
//	{ AE::Input::KC_F, SDLK_f },
//	{ AE::Input::KC_G, SDLK_g },
//	{ AE::Input::KC_H, SDLK_h },
//	{ AE::Input::KC_I, SDLK_i },
//	{ AE::Input::KC_J, SDLK_j },
//	{ AE::Input::KC_K, SDLK_k },
//	{ AE::Input::KC_L, SDLK_l },
//	{ AE::Input::KC_M, SDLK_m },
//	{ AE::Input::KC_N, SDLK_n },
//	{ AE::Input::KC_O, SDLK_o },
//	{ AE::Input::KC_P, SDLK_p },
//	{ AE::Input::KC_Q, SDLK_q },
//	{ AE::Input::KC_R, SDLK_r },
//	{ AE::Input::KC_S, SDLK_s },
//	{ AE::Input::KC_T, SDLK_t },
//	{ AE::Input::KC_U, SDLK_u },
//	{ AE::Input::KC_V, SDLK_v },
//	{ AE::Input::KC_W, SDLK_w },
//	{ AE::Input::KC_X, SDLK_x },
//	{ AE::Input::KC_Y, SDLK_y },
//	{ AE::Input::KC_Z, SDLK_z }
//};
//
//std::map<int, AE::Input::KeyCode> AE::Input::KeyInfoSdl::mKeyCodes =
//{ 
//	{ mKeyCodes[SDLK_BACKSPACE], AE::Input::KC_BACKSPACE },
//	{ mKeyCodes[SDLK_DOWN], AE::Input::KC_DOWN_ARROW },
//	{ mKeyCodes[SDLK_RETURN], AE::Input::KC_ENTER },
//	{ mKeyCodes[SDLK_ESCAPE], AE::Input::KC_ESCAPE },
//	{ mKeyCodes[SDLK_F1], AE::Input::KC_F1 },
//	{ mKeyCodes[SDLK_F2], AE::Input::KC_F2 },
//	{ mKeyCodes[SDLK_F3], AE::Input::KC_F3 },
//	{ mKeyCodes[SDLK_F4], AE::Input::KC_F4 },
//	{ mKeyCodes[SDLK_F5], AE::Input::KC_F5 },
//	{ mKeyCodes[SDLK_F6], AE::Input::KC_F6 },
//	{ mKeyCodes[SDLK_F7], AE::Input::KC_F7 },
//	{ mKeyCodes[SDLK_F8], AE::Input::KC_F8 },
//	{ mKeyCodes[SDLK_F9], AE::Input::KC_F9 },
//	{ mKeyCodes[SDLK_F10], AE::Input::KC_F10 },
//	{ mKeyCodes[SDLK_F11], AE::Input::KC_F11 },
//	{ mKeyCodes[SDLK_F12], AE::Input::KC_F12 },
//	{ mKeyCodes[SDLK_LALT], AE::Input::KC_LEFT_ALT },
//	{ mKeyCodes[SDLK_LEFT], AE::Input::KC_LEFT_ARROW },
//	{ mKeyCodes[SDLK_LCTRL], AE::Input::KC_LEFT_CONTROL },
//	{ mKeyCodes[SDLK_LSHIFT], AE::Input::KC_LEFT_SHIFT },
//	{ mKeyCodes[SDLK_RALT], AE::Input::KC_RIGHT_ALT },
//	{ mKeyCodes[SDLK_RIGHT], AE::Input::KC_RIGHT_ARROW },
//	{ mKeyCodes[SDLK_RCTRL], AE::Input::KC_RIGHT_CONTROL },
//	{ mKeyCodes[SDLK_RSHIFT], AE::Input::KC_RIGHT_SHIFT },
//	{ mKeyCodes[SDLK_SPACE], AE::Input::KC_SPACE },
//	{ mKeyCodes[SDLK_UP], AE::Input::KC_UP_ARROW },
//	{ mKeyCodes[SDLK_0], AE::Input::KC_0 },
//	{ mKeyCodes[SDLK_1], AE::Input::KC_1 },
//	{ mKeyCodes[SDLK_2], AE::Input::KC_2 },
//	{ mKeyCodes[SDLK_3], AE::Input::KC_3 },
//	{ mKeyCodes[SDLK_4], AE::Input::KC_4 },
//	{ mKeyCodes[SDLK_5], AE::Input::KC_5 },
//	{ mKeyCodes[SDLK_6], AE::Input::KC_6 },
//	{ mKeyCodes[SDLK_7], AE::Input::KC_7 },
//	{ mKeyCodes[SDLK_8], AE::Input::KC_8 },
//	{ mKeyCodes[SDLK_9], AE::Input::KC_9 },
//	{ mKeyCodes[SDLK_a], AE::Input::KC_A },
//	{ mKeyCodes[SDLK_b], AE::Input::KC_B },
//	{ mKeyCodes[SDLK_c], AE::Input::KC_C },
//	{ mKeyCodes[SDLK_d], AE::Input::KC_D },
//	{ mKeyCodes[SDLK_e], AE::Input::KC_E },
//	{ mKeyCodes[SDLK_f], AE::Input::KC_F },
//	{ mKeyCodes[SDLK_g], AE::Input::KC_G },
//	{ mKeyCodes[SDLK_h], AE::Input::KC_H },
//	{ mKeyCodes[SDLK_i], AE::Input::KC_I },
//	{ mKeyCodes[SDLK_j], AE::Input::KC_J },
//	{ mKeyCodes[SDLK_k], AE::Input::KC_K },
//	{ mKeyCodes[SDLK_l], AE::Input::KC_L },
//	{ mKeyCodes[SDLK_m], AE::Input::KC_M },
//	{ mKeyCodes[SDLK_n], AE::Input::KC_N },
//	{ mKeyCodes[SDLK_o], AE::Input::KC_O },
//	{ mKeyCodes[SDLK_p], AE::Input::KC_P },
//	{ mKeyCodes[SDLK_q], AE::Input::KC_Q },
//	{ mKeyCodes[SDLK_r], AE::Input::KC_R },
//	{ mKeyCodes[SDLK_s], AE::Input::KC_S },
//	{ mKeyCodes[SDLK_t], AE::Input::KC_T },
//	{ mKeyCodes[SDLK_u], AE::Input::KC_U },
//	{ mKeyCodes[SDLK_v], AE::Input::KC_V },
//	{ mKeyCodes[SDLK_w], AE::Input::KC_W },
//	{ mKeyCodes[SDLK_x], AE::Input::KC_X },
//	{ mKeyCodes[SDLK_y], AE::Input::KC_Y },
//	{ mKeyCodes[SDLK_z], AE::Input::KC_Z },
//};