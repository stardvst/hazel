#pragma once

#include "Hazel/Core.h"

namespace Hazel
{

class HAZEL_API Input
{
public:
	static bool isKeyPressed(int nKeyCode);

	static bool isMouseButtonPressed(int nButton);
	static std::pair<float, float> getMousePosition();
	static float getMouseX();
	static float getMouseY();

protected:
	virtual bool isKeyPressed_impl(int nKeyCode) const = 0;
	virtual bool isMouseButtonPressed_impl(int nButton) const = 0;
	virtual std::pair<float, float> getMousePosition_impl() const = 0;
	virtual float getMouseY_impl() const = 0;
	virtual float getMouseX_impl() const = 0;

private:
	static Input *s_pInstance;
};

inline bool Input::isKeyPressed(int nKeyCode)
{
	return s_pInstance->isKeyPressed_impl(nKeyCode);
}

inline bool Input::isMouseButtonPressed(int nButton)
{
	return s_pInstance->isMouseButtonPressed_impl(nButton);
}

inline std::pair<float, float> Input::getMousePosition()
{
	return s_pInstance->getMousePosition_impl();
}

inline float Input::getMouseX()
{
	return s_pInstance->getMouseX_impl();
}

inline float Input::getMouseY()
{
	return s_pInstance->getMouseY_impl();
}

}
