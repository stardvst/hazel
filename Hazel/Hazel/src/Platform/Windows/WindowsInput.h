#pragma once

#include "Hazel/Input.h"

namespace Hazel
{

class WindowsInput : public Input
{
protected:
	bool isKeyPressed_impl(int nKeyCode) const override;

	bool isMouseButtonPressed_impl(int nButton) const override;
	std::pair<float, float> getMousePosition_impl() const override;
	float getMouseX_impl() const override;
	float getMouseY_impl() const override;
};

Input *Input::s_pInstance = new WindowsInput;

}
